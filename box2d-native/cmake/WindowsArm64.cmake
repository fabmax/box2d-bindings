# CMake toolchain file for Windows ARM64 cross-compilation
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR ARM64)

# Specify the cross compiler
set(CMAKE_C_COMPILER cl)
set(CMAKE_CXX_COMPILER cl)

# Set the architecture for MSVC
set(CMAKE_GENERATOR_PLATFORM ARM64)

# Set compiler flags for ARM64
set(CMAKE_C_FLAGS_INIT "/arch:ARM64EC")
set(CMAKE_CXX_FLAGS_INIT "/arch:ARM64EC")

# Where to find libraries and headers in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Set runtime library
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")