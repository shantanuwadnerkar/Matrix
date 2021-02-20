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
#include <vector>

#include "matrix.h"


int main()
{
    // test using lvalue and rvalue

    // linalg::Matrix A;
    // linalg::Matrix B;
    // std::cout << A * B;

    // linalg::Matrix<double> mat1{{{1.5, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}}};
    // linalg::Matrix<double> mat2{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    // linalg::Matrix mat3{{{1, 2, 3}, {4, 5, 6}}};
    // linalg::Matrix mat4{100, 100, 3};
    // std::cout << mat4.size().first << ' ' << mat4.size().second << '\n';

    linalg::Matrix<int> mat1{3, 3, 1};
    linalg::Matrix<int> mat2{5, 5, 3};

    // std::cout << mat1;
    // std::cout << mat2;
    std::cout << mat1 * mat2;

    using namespace linalg;
    Matrix<int> A{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    Matrix<int> B{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    B.transpose();
    // std::vector<int> C_{285};
    // Matrix C{{285}};
    Matrix<int> C{1, 1, 285};
    std::cout << C.size();    

    return 0;
}