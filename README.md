# libmatmul

This is a header-only library for matrix multiplication and transposition.

## Development and Testing

To compile the library standalone for development and testing purposes, clone the library.
```Shell
git clone git@github.com:shantanuwadnerkar/matmul.git
cd matmul
```

If the library is already available, go to the top-most CMakeLists.txt file.

```Shell
cd matmul/
```

Create a build folder and compile.

```Shell
mkdir build && cd build
cmake ../ -DCMAKE_BUILD_TYPE=Release
make
```

This will configure the workspace and make the library Matrix.h an interface library.

To compile and run unit tests, change the cmake configuration. Perform this commands inside the build/ folder created in the previous step.

```Shell
cmake ../ -DCMAKE_BUILD_TYPE=Release -DAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA ADD UNIT TESTS FLAG.
make
make test
```

You can also run `ctest` instead of `make test`. This will run all the test cases and show the performance on the console.

There is an additional test case which does time profiling by using steady_clock() from chrono library. To run, the library and test cases should be compiled from the previous step.

```Shell
./test/test_time_multiplication
```

## Design Choices


## How to use the library

Clone this library using the following command in the directory which holds the top level CMakeLists.txt

`git clone git@github.com:shantanuwadnerkar/matmul.git`


Next, configure the top level CMakeLists.txt,

```CMake
# Add the library's CMakeLists.txt to the project
add_subdirectory(matmul)

# User's project executable
add_executable(new_exe new_project/src/tt.cpp)

# Link the library to user's executable
target_link_libraries(new_exe Matrix)
```