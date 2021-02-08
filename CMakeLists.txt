# The highest version available on the tested system.
cmake_minimum_required(VERSION 3.10)

# Register project
project(
	Matrix
	VERSION 1.0.0
	DESCRIPTION "A header-only linear algebra library for Matrix multiplication and transpose operations")

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
add_subdirectory(test)
