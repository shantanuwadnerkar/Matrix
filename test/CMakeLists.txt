# The highest version available on the tested system.
cmake_minimum_required(VERSION 3.10)

# Set the variable project name as test_matrix. The project() macro isn't called here since this isn't a standalone project.
set(PROJECT_NAME test_matrix)

# Create executables for the tests and register with CMake.
set(TEST_MAIN ${PROJECT_NAME})

# Include directories for the library to test and the testing framework
set(${PROJECT_NAME}_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/external")

# Create a target for the main executable
add_library(${TEST_MAIN} OBJECT "src/${TEST_MAIN}.cpp")
target_include_directories(${TEST_MAIN} PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

####################
# Test Cases
# TODO: Can this repetition be gotten rid of by using functions or macros?

# Create test case executables
add_executable(test_square_multiplication src/test_square_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_rectangle_multiplication src/test_rectangle_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_vector_multiplication src/test_vector_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_transpose_size src/test_transpose_size.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_associative_multiplication src/test_associative_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_double_multiplication src/test_double_multiplication.cpp $<TARGET_OBJECTS:${TEST_MAIN}>)

add_executable(test_time_multiplication src/test_time_multiplication.cpp)

target_include_directories(test_square_multiplication PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

target_include_directories(test_rectangle_multiplication PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

target_include_directories(test_vector_multiplication PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

target_include_directories(test_transpose_size PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

target_include_directories(test_associative_multiplication PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

target_include_directories(test_double_multiplication PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

target_include_directories(test_time_multiplication PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

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
