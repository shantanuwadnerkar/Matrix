# libmatmul

This is a header-only template library for matrix multiplication and transposition.

NOTE: The Matrix objects should be of arithmetic type, otherwise, the object will display undefined behavior.
NOTE: The Matrix objects during multiplication operation should be of the same type, otherwise there is a chance of narrowing conversion.
NOTE: The Matrix object cannot be empty-initialized.

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
cmake -DCMAKE_INSTALL_PREFIX:PATH=../install ../
cmake --build . --target install -- -j $(nproc)
```

(note to self) Check for other ways of configuring and building from the source and build directory at: https://cliutils.gitlab.io/modern-cmake/chapters/intro/running.html


This will configure the workspace and make the library Matrix.h an interface library. The defualt compiler options are `CMAKE_BUILD_TYPE=Release` and `BUILD_TEST=ON`. To turn off default compilation of unit tests, set this flag `-DBUILD_TEST=OFF` when configuring CMake.

```Shell
cmake -DCMAKE_BUILD_TYPE=Release -DBULD_TEST=ON -DCMAKE_INSTALL_PREFIX:PATH=../install ../
cmake --build . --target install -- -j $(nproc)
make test
```

You can also run `ctest` instead of `make test`. This will run all the test cases and show the performance on the console. Each test executable has several test cases inside them. When this executable is run, additional results can be seen. To run a test executable, go to the build folder and call the executable. For example,

```Shell
cd build
./test/test_square_multiplication
```

There are several other executables inside the `test/` folder.

There is an additional test case which does time profiling by using `steady_clock()` from chrono library. To run, the library and test cases should be compiled from the previous step.

```Shell
./test/test_time_multiplication
```

### Build Options
To summarise, the build flags are,
BUILD_TEST          - (ON/OFFF) build unit test
CMAKE_INSTALL_PREFIX- Prefix path to the installation directory of the header and binary files.
CMAKE_BUILD_TYPE    - (Release/Debug) Build for either release or debug configuration
CMAKE_CXX_STANDARD  - (98/11/14/17) Compiles for the specified language standard

Other CMake provided flags are valid as well.

## Design Choices
### Code-style
The code style is similar to Google style guide for C++, but it doesn't replicate it completely.

### Template
The solution is templatized for arithmetic types. Although the object can be initialized with other data, that is not the intended use. If the user performs any operations, it should fail by a compiler error. This design is by choice.

### Functionality
First, there is possibility of adding more functions, like push_row(), push_col() to update the Matrix.

Second, the application is single threaded right now. It can be more optimized by using multiple threads.

Third, multiplication in matrices of higher dimensions (above 2D) was considered and rejected. Higher dimension matrix multiplication does not make sense.

Fourth, the actual matrix is a 2D vector. It is stored on stack. Another possibility is to store it on the heap.

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

The library is encompassed in the `linalg` namespace.

```C++
#include "Matrix.h"

linalg::Matrix<int> mat1{3, 3, 0}; // Initializes a 3-by-3 matrix with all elements 0.

std::cout << mat1;
std::cout << mat1.size();
```

For more details about usage, check the documentation.
