cmake_minimum_required(VERSION 3.16)
project(box2d_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform detection and architecture configuration
if(APPLE)
    message(STATUS "Building for macOS")
    
    # Set architectures for universal binary on macOS
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
    message(STATUS "Building universal binary for architectures: ${CMAKE_OSX_ARCHITECTURES}")
    
    # Set minimum macOS version
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15")
    message(STATUS "Minimum macOS deployment target: ${CMAKE_OSX_DEPLOYMENT_TARGET}")
    
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
    
else()
    message(STATUS "Building for unknown platform")
endif()

include(FetchContent)

FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG        v3.1.1
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(box2d)

set(JAVA_AWT_LIBRARY NotNeeded)
set(JAVA_JVM_LIBRARY NotNeeded)
find_package(JNI REQUIRED)

add_library(Box2dJniBindings SHARED
    src/webidlbindings/jni/box2d.cpp
)

target_include_directories(Box2dJniBindings PRIVATE
    ${JNI_INCLUDE_DIRS}
    src/webidlbindings/jni
    src/webidlbindings
)

target_link_libraries(Box2dJniBindings PRIVATE box2d)

# Platform-specific configurations
if(APPLE)
    # Set proper install name and rpath for macOS
    set_target_properties(Box2dJniBindings PROPERTIES
        MACOSX_RPATH ON
        INSTALL_RPATH "@loader_path"
        BUILD_WITH_INSTALL_RPATH ON
    )
    
    # Ensure we're building a universal binary
    set_target_properties(Box2dJniBindings PROPERTIES
        OSX_ARCHITECTURES "${CMAKE_OSX_ARCHITECTURES}"
    )
endif()

# Set output directory for better organization
if(WIN32)
    set_target_properties(Box2dJniBindings PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${WIN_ARCH}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${WIN_ARCH}"
    )
elseif(UNIX AND NOT APPLE)
    set_target_properties(Box2dJniBindings PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${LINUX_ARCH}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${LINUX_ARCH}"
    )
else()
    set_target_properties(Box2dJniBindings PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()