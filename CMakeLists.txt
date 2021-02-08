# The highest version available on the tested system.
cmake_minimum_required(VERSION 3.10)

# Register project
project(
	Matrix
	VERSION 1.0.0
	DESCRIPTION "A header-only linear algebra library for Matrix multiplication and transpose operations")

# Set compiler options to C++11.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build type to release
# This is only set by default if the argument is not passed from 
# console or if it's not already cached.
if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

# This option builds unit tests. 
# ON for building OFF for skipping.
option(BUILD_TEST "Build unit tests" ON)

enable_testing()

include(GNUInstallDirs)

# Addd the library as an interface
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
			$<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Only for testing
add_executable(main main.cpp)

# Add the test folder CMakeLists.txt
if (BUILD_TEST)
	add_subdirectory(test)
endif()
