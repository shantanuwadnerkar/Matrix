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
cmake
make
```

This will configure the workspace and make the library Matrix.h an interface library. The defualt compiler options are `CMAKE_BUILD_TYPE=Release` and `BUILD_TEST=ON`.

/// To compile and run unit tests, change the cmake configuration. Perform this commands inside the build/ folder created in the previous step.

```Shell
cmake ../ -DCMAKE_BUILD_TYPE=Release -DBULD_TEST=ON
make
make test
```

/// By default, unit tests will be compiled. To turn that off, set this flag `-DBUILD_TEST=OFF` when configuring CMake.

/// You can also run `ctest` instead of `make test`. This will run all the test cases and show the performance on the console.

/// There is an additional test case which does time profiling by using steady_clock() from chrono library. To run, the library and test cases should be compiled from the previous step.

```Shell
./test/test_time_multiplication
```

### Build Options
To summarise, the build flags are,
BUILD_TEST          - (ON/OFFF) build unit test
CMAKE_BUILD_TYPE    - (Release/Debug) Build for either release or debug configuration
CMAKE_CXX_STANDARD  - (98/11/14/17) Compiles for the specified language standard

Other CMake provided flags are valid as well.

## Design Choices

### CMake
There are 2 major CMake flags for discussion. First, CMAKE_BUILD_TYPE, and second, BUILD_TEST. 
BUILD_TEST should be on only when the CMAKE_BUILD_TYPE is set to Debug. Although, for time testing, the binaries compiled for release show actual performance.
This is why, CMAKE_BUILD_TYPE and BUILD_TEST are kept independent. Tests can be built whether the build type is release or debug.


## How to use the library

Clone this library using the following command in the directory which holds the top level CMakeLists.txt

`git clone git@github.com:shantanuwadnerkar/matmul.git`


Next, configure the user's top level CMakeLists.txt,

```CMake
# Add the library's CMakeLists.txt to the project
add_subdirectory(matmul)

# User's project executable
add_executable(new_exe new_project/src/tt.cpp)

# Link the library to user's executable
target_link_libraries(new_exe Matrix)
```