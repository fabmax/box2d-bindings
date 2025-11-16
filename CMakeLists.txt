cmake_minimum_required(VERSION 3.16)
project(box2d_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG        v3.1.1
)

FetchContent_MakeAvailable(box2d)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE box2d)

# WebIDL Bindings shared library
set(JAVA_AWT_LIBRARY NotNeeded)
set(JAVA_JVM_LIBRARY NotNeeded)
find_package(JNI REQUIRED)

add_library(Box2dJniBindings SHARED
    src/webidlbindings/jni/box2d.cpp
)

target_include_directories(Box2dJniBindings PRIVATE
    src/webidlbindings/jni
     ${JNI_INCLUDE_DIRS}
)

target_link_libraries(Box2dJniBindings PRIVATE box2d)

# Note: jni-bindings subdirectory is intentionally not included in CMake build