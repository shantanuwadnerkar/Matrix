# The highest version available on the tested system.
cmake_minimum_required(VERSION 3.10)

project(test_matrix)

# Include the library to test and the testing framework
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("../include")

# Create executables for the tests and register with CMake.
set(TEST_MAIN test_matrix)

add_library(${TEST_MAIN} OBJECT src/${TEST_MAIN}.cpp)

add_executable(test_square_multiplication src/test_square_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_rectangle_multiplication src/test_rectangle_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_vector_multiplication src/test_vector_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_transpose_size src/test_transpose_size.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_associative_multiplication src/test_associative_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_double_multiplication src/test_double_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_time_multiplication src/test_time_multiplication.cpp)

add_test(
	NAME 	test_square_multiplication
	COMMAND test_square_multiplication)

add_test(
	NAME 	test_rectangle_multiplication
	COMMAND test_rectangle_multiplication)

add_test(
	NAME 	test_vector_multiplication
	COMMAND test_vector_multiplication)

add_test(
	NAME 	test_transpose_size
	COMMAND test_transpose_size)

add_test(
	NAME 	test_associative_multiplication
	COMMAND test_associative_multiplication)

add_test(
	NAME 	test_double_multiplication
	COMMAND test_double_multiplication)
