# The highest version available on the tested system.
cmake_minimum_required(VERSION 3.10)

project(test_matrix)

# Include the library to test and the testing framework
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("../include")

# Create executables for the tests and register with CMake.
set(TEST_MAIN test_matrix)

add_library(${TEST_MAIN} OBJECT src/${TEST_MAIN}.cpp)

# add_executable(test1 src/test1.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_square_multiplication src/test_square_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_vector_multiplication src/test_vector_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_time_multiplication src/test_time_multiplication.cpp)

# target_link_libraries(test1 INTERFACE Matrix)

# target_link_libraries(test1 INTERFACE 
# 			$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
#             $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# target_include_directories(test1 INTERFACE
# 			$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
#             $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# add_test(
# 	NAME 	test1
# 	COMMAND test1)

add_test(
	NAME 	test_square_multiplication
	COMMAND test_square_multiplication)

add_test(
	NAME 	test_vector_multiplication
	COMMAND test_vector_multiplication)
