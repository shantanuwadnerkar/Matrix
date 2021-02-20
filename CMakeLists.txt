# Source:
# http://dominikberner.ch/cmake-interface-lib/
# https://cliutils.gitlab.io/modern-cmake/

# The highest version available on the tested system.
cmake_minimum_required(VERSION 3.10)

# Use the below line instead for CMake version 3.12 and more.
# cmake_minimum_required(VERSION 3.1 ... 3.10)

if(${CMAKE_VERSION} VERSION_LESS 3.19)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.19)
endif()

# Set project
project(
	Matrix
	VERSION 1.0.0
	DESCRIPTION "A header-only linear algebra library for Matrix multiplication and transpose operations")

# Set compiler options to C++11.
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build type to release
# This is only set by default if the argument is not passed from 
# console or if it's not already cached.
if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

# A better way to do the above function is the following.
# It sets the value only if the arguments is not passed from the
# console.
# Not working. Always defaults to Debug. (last checked: 2021/2/19) (CMake: 3.10, GCC: 7.5)
# set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type is Release unless specified differently from command line")

# This option builds unit tests. 
# ON for building OFF for skipping.
option(BUILD_TEST "Build unit tests" ON)

enable_testing()

include(GNUInstallDirs)

# Addd the library as an interface
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
			$<BUILD_INTERFACE:"${${PROJECT_NAME}_SOURCE_DIR}/include/${PROJECT_NAME}">
            $<INSTALL_INTERFACE:"${CMAKE_INSTALL_INCLUDEDIR}">)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

# -OR-

# To set the same property to multiple targets.
# set_property(TARGET ${PROJECT_NAME}
# 			 PROPERTY CXX_STANDARD 11)

# -OR-

# To set multiple properties to the same target.
# set_target_properties(${PROJECT_NAME} PROPERTIES
# 						CXX_STANDARD 11)

# Only for testing
add_executable(main main.cpp)

target_include_directories(main PUBLIC "${${PROJECT_NAME}_SOURCE_DIR}/include/${PROJECT_NAME}")

# Add the test folder CMakeLists.txt
if (BUILD_TEST)
	add_subdirectory(test)
endif()

####################
# Installation

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(EXPORT ${PROJECT_NAME}_Targets
		FILE ${PROJECT_NAME}Targets.cmake
		# NAMESPACE ${PROJECT_NAME}::
		DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake")

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}" DESTINATION include)
