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

#include "doctest.h"
#include "matrix.h"


TEST_SUITE_BEGIN("test_vector_matrix");

TEST_CASE("vector_num1")
{
    using namespace linalg;
    Matrix<int> A{{1, 2, 3, 4, 5, 6, 7, 8, 9}};         // (9, 1)
    A = A.transpose();
    Matrix<int> B{3};                                   // (1, 1)
    Matrix<int> C{{3, 6, 9, 12, 15, 18, 21, 24, 27}};   // (9, 1)
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("vector_num2")
{
    using namespace linalg;
    Matrix<int> A{8};                               // (1, 1)
    Matrix<int> B{{1, 2, 3, 4, 5, 6, 7, 8, 9}};     // (1, 9)
    B = B.transpose();
    Matrix<int> C{{1, 2, 3, 4, 5, 6, 7, 8, 9}};     // (1, 9)
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("square_vector")
{
    using namespace linalg;
    Matrix<int> A{{{1, 2, 3, 13}, {4, 5, 6, 16}, {7, 8, 9, 19}, {10, 11, 12, 20}}}; // (4, 4)
    Matrix<int> B{{1, 2, 3, 4}};                                                    // (1, 4)
    B = B.transpose();                                                              // (4, 1)
    Matrix<int> C{{66, 96, 126, 148}};                                              // (1, 4)
    C = C.transpose();                                                              // (4, 1)
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("vector_square")
{
    using namespace linalg;
    Matrix<int> A{{1, 2, 4}};                           // (1, 3)
    Matrix<int> B{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};   // (3, 3)
    Matrix<int> C{{37, 44, 51}};                        // (1, 3)
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("vector_vector1")
{
    using namespace linalg;
    Matrix<int> A{{1, 2, 3, 4, 5, 6, 7, 8, 9}};             // (9, 1)
    A = A.transpose();
    Matrix<int> B{{1, 2, 3, 4, 5, 6, 7, 8, 9}};             // (1, 9)
    Matrix<int> C{{ {1, 2, 3, 4, 5, 6, 7, 8, 9},
                    {2, 4, 6, 8, 10, 12, 14, 16, 18},
                    {3, 6, 9, 12, 15, 18, 21, 24, 27},
                    {4, 8, 12, 16, 20, 24, 28, 32, 36},
                    {5, 10, 15, 20, 25, 30, 35, 40, 45},
                    {6, 12, 18, 24, 30, 36, 42, 48, 54},
                    {7, 14, 21, 28, 35, 42, 49, 56, 63},
                    {8, 16, 24, 32, 40, 48, 56, 64, 72},
                    {9, 18, 27, 36, 45, 54, 63, 72, 81}}};  // (9, 9)
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("vector_vector2")
{
    using namespace linalg;
    Matrix<int> A{{1, 2, 3, 4, 5, 6, 7, 8, 9}};     // (1, 9)
    Matrix<int> B{{1, 2, 3, 4, 5, 6, 7, 8, 9}};     // (9, 1)
    B = B.transpose();
    Matrix<int> C{285};                             // (1, 1)
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("medium_matrix")
{
    using namespace linalg;
    Matrix<int> A{1, 100, 6};
    Matrix<int> B{100, 1, 2};
    Matrix<int> C{1, 1, 1200};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("huge_matrix")
{
    using namespace linalg;
    Matrix<int> A{1, 1000, 9};
    Matrix<int> B{1000, 1, 7};
    Matrix<int> C{1, 1, 63000};
    CHECK(isSame(C, A * B) == 1);
}

TEST_SUITE_END();
