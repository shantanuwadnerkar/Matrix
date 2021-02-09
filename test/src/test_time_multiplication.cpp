/*
 * This file is part of Matrix.
 *
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <chrono>
#include <thread>

#include "matrix.h"


int main()
{
    double iterations;
    const int NUM_ITER{10};

    std::cout << "This file creates 3 Matrix objects, and stores ";
    std::cout << "the multiplication in the third object. This operation is done 10 times, ";
    std::cout << "measured, and averaged to give the run-time.";

    for (int iter=0; iter<NUM_ITER; iter++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        linalg::Matrix<int> A{3, 3, 3};
        linalg::Matrix<int> B{3, 3, 5};
        linalg::Matrix<int> C{A * B};
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        iterations += duration.count();
    }
    std::cout << "3-by-3 integer matrix multiplication\n";
    std::cout << "\tAverage of 10: " << iterations / NUM_ITER / 1000.0 << " ms" << '\n';

    for (int iter=0; iter<NUM_ITER; iter++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        linalg::Matrix<int> A{100, 100, 3};
        linalg::Matrix<int> B{100, 100, 5};
        linalg::Matrix<int> C{A * B};
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        iterations += duration.count();
    }
    std::cout << "100-by-100 integer matrix multiplication\n";
    std::cout << "\tAverage of 10: " << iterations / NUM_ITER / 1000.0 << " ms" << '\n';

    for (int iter=0; iter<NUM_ITER; iter++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        linalg::Matrix<double> A{100, 100, 3.5};
        linalg::Matrix<double> B{100, 100, 5.9};
        linalg::Matrix<double> C{A * B};
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        iterations += duration.count();
    }
    std::cout << "100-by-100 double matrix multiplication\n";
    std::cout << "\tAverage of 10: " << iterations / NUM_ITER / 1000.0 << " ms" << '\n';
    return 0;
}
