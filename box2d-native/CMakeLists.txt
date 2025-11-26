cmake_minimum_required(VERSION 3.16)
project(box2d_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform detection and architecture configuration
if(EMSCRIPTEN)
    message(STATUS "Building for Emscripten/WebAssembly")
    set(WASM_ARCH "wasm")
    # Skip JNI for Emscripten builds
    set(BUILD_JNI FALSE)

elseif(APPLE)
    # Detect architecture on macOS
    if(CMAKE_OSX_ARCHITECTURES)
        # Use explicitly set architecture
        set(MACOS_ARCH "${CMAKE_OSX_ARCHITECTURES}")
    elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
        set(MACOS_ARCH "arm64")
        set(CMAKE_OSX_ARCHITECTURES "arm64")
    else()
        set(MACOS_ARCH "x64")
        set(CMAKE_OSX_ARCHITECTURES "x86_64")
    endif()
    message(STATUS "Building for macOS x64")
    set(BUILD_JNI TRUE)

elseif(WIN32)
    # Detect Windows architecture
    if(CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM64")
        message(STATUS "Building for Windows ARM64")
        set(WIN_ARCH "arm64")
    else()
        message(STATUS "Building for Windows x64")
        set(WIN_ARCH "x64")
    endif()
    message(STATUS "Windows architecture: ${WIN_ARCH}")
    set(BUILD_JNI TRUE)

elseif(UNIX AND NOT APPLE)
    # Detect architecture on Linux
    if(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
        message(STATUS "Building for Linux ARM64")
        set(LINUX_ARCH "arm64")
    else()
        message(STATUS "Building for Linux x64")
        set(LINUX_ARCH "x64")
    endif()
    message(STATUS "Linux architecture: ${LINUX_ARCH}")
    set(BUILD_JNI TRUE)

else()
    message(STATUS "Building for unknown platform")
    set(BUILD_JNI TRUE)
endif()

include(FetchContent)
FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG        v3.1.1
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(box2d)

# Only build JNI bindings for non-Emscripten platforms
if(BUILD_JNI)
    set(JAVA_AWT_LIBRARY NotNeeded)
    set(JAVA_JVM_LIBRARY NotNeeded)
    set(JAVA_AWT_INCLUDE_PATH NotNeeded)
    find_package(JNI REQUIRED)

    add_library(Box2dJniBindings SHARED
        src/webidlbindings/jni/box2d_jni.cpp
    )
    target_include_directories(Box2dJniBindings PRIVATE
        ${JNI_INCLUDE_DIRS}
        src/webidlbindings/jni
        src/webidlbindings
    )
    target_link_libraries(Box2dJniBindings PRIVATE box2d)

    if(WIN32)
        set_target_properties(Box2dJniBindings PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${WIN_ARCH}"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${WIN_ARCH}"
        )
    elseif(APPLE)
        set_target_properties(Box2dJniBindings PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${MACOS_ARCH}"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${MACOS_ARCH}"
        )
    elseif(UNIX)
        set_target_properties(Box2dJniBindings PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${LINUX_ARCH}"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${LINUX_ARCH}"
        )
    endif()

else()
    # WebIDL Binder generates glue code from the IDL file
    set(WEBIDL_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/webidlbindings/wasm/box2d.idl")
    set(WEBIDL_BINDER "${EMSCRIPTEN_ROOT_PATH}/tools/webidl_binder.py")
    set(GLUE_CPP "${CMAKE_CURRENT_BINARY_DIR}/generated/glue.cpp")
    set(GLUE_JS "${CMAKE_CURRENT_BINARY_DIR}/generated/glue.js")
    set(BOX2D_INCLUDE_DIR "_deps/box2d-src/include")
    set(GLUE_WRAPPER "../src/webidlbindings/wasm/box2d_wasm.cpp")

    set(EMCC_WASM_ARGS
        --post-js ${GLUE_JS}
        -sMODULARIZE=1
        -sEXPORT_ES6=1
        -sEXPORT_NAME=Box2D
        -sENVIRONMENT=web,worker
        -sNO_FILESYSTEM=1
        -sALLOW_TABLE_GROWTH=1
        -sALLOW_MEMORY_GROWTH=1
        -sTOTAL_MEMORY=268435456
        -fno-rtti
        -fno-exceptions
    )
    set(EMCC_GLUE_ARGS
        -c
        -DNDEBUG
        -O3
        -I${BOX2D_INCLUDE_DIR}
        -Igenerated
    )

    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/generated")

    add_custom_command(
        OUTPUT ${GLUE_CPP} ${GLUE_JS}
        BYPRODUCTS parser.out WebIDLGrammar.pkl
        COMMAND python3 ${WEBIDL_BINDER} ${WEBIDL_FILE} generated/glue
        DEPENDS ${WEBIDL_FILE}
        COMMENT "Generating WebIDL glue code from box2d.idl"
        VERBATIM
    )

    add_custom_command(
        OUTPUT glue.o
        COMMAND em++ ${GLUE_WRAPPER} ${EMCC_GLUE_ARGS} -o glue.o
        DEPENDS ${GLUE_CPP}
        COMMENT "Building box2d bindings"
        VERBATIM
    )
    add_custom_target(box2d-bindings ALL DEPENDS ${GLUE_JS} glue.o)

    add_custom_command(
        OUTPUT box2d-wasm.mjs box2d-wasm.wasm
        COMMAND em++ glue.o $<TARGET_FILE:box2d> ${EMCC_WASM_ARGS} -o box2d-wasm.mjs
        DEPENDS box2d-bindings box2d
        COMMENT "Building box2d webassembly"
        VERBATIM
    )
    add_custom_target(Box2dWasmBindings ALL DEPENDS box2d-wasm.mjs box2d-wasm.wasm)

endif()