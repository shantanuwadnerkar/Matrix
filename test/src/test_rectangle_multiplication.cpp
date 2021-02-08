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


TEST_SUITE_BEGIN("test_rectangle_matrix");

TEST_CASE("square_rectangle")
{
    using namespace linalg;
    Matrix A{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}; // (3, 3)
    Matrix B{{{1, 2}, {4, 5}, {7, 8}}};          // (3, 2)
    Matrix C{{{30, 36}, {66, 81}, {102, 126}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("rectangle_square")
{
    using namespace linalg;
    Matrix B{{{1, 2, 4} ,{5, 7, 8}}};               // (2, 3)
    Matrix A{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};    // (3, 3)
    Matrix C{{{37, 44, 51}, {89, 109, 129}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("rectangle_rectangle1")
{
    using namespace linalg;
    Matrix A{{{1, 2, 3}, {4, 5, 6}}};   // (2, 3)
    Matrix B{{{1, 2}, {4, 5}, {7, 8}}}; // (3, 2)
    Matrix C{{{30, 36}, {66, 81}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("rectangle_rectangle2")
{
    using namespace linalg;
    Matrix A{{{5, 7}, {2, 4}, {6, 9}}};     // (3, 2)
    Matrix B{{{1, 2, 3, 7}, {4, 5, 6, 8}}}; // (2, 4)
    Matrix C{{{33, 45, 57, 91}, {18, 24, 30, 46}, {42, 57, 72, 114}}};
    CHECK(isSame(C, A * B) == 1);
}



// TEST_CASE("small_matrix2")
// {
//     using namespace linalg;
//     Matrix A{{{1, 2, 3, 3}, {4, 5, 6, 6}, {7, 8, 9, 9}, {1, 2, 3, 4}}};
//     Matrix B{{{4, 3, 2, 1}, {9, 9, 8, 7}, {6, 6, 5, 4}, {3, 3, 2, 1}}};
//     Matrix C{{{49, 48, 39, 30}, {115, 111, 90, 69}, {181, 174, 141, 108}, {52, 51, 41, 31}}};
//     CHECK(isSame(C, A * B) == 1);
// }

// TEST_CASE("small_matrix3")
// {
//     using namespace linalg;
//     Matrix A{5, 5, 5};
//     Matrix B{5, 5, 5};
//     Matrix C{5, 5, 125};
//     CHECK(isSame(C, A * B) == 1);
// }

// TEST_CASE("small_matrix4")
// {
//     using namespace linalg;
//     Matrix A{10, 10, 5};
//     Matrix B{10, 10, 5};
//     Matrix C{10, 10, 250};
//     CHECK(isSame(C, A * B) == 1);
// }

// TEST_CASE("small_matrix5")
// {
//     using namespace linalg;
//     Matrix A{10, 10, 3};
//     Matrix B{10, 10, 7};
//     Matrix C{10, 10, 210};
//     CHECK(isSame(C, A * B) == 1);
// }

// TEST_CASE("medium_ones_matrix")
// {
//     using namespace linalg;
//     Matrix A{100, 100, 1};
//     Matrix B{100, 100, 1};
//     Matrix C{100, 100, 100};
//     CHECK(isSame(C, A * B) == 1);
// }

TEST_CASE("medium_matrix")
{
    using namespace linalg;
    Matrix A{100, 100, 6};
    Matrix B{100, 100, 2};
    Matrix C{100, 100, 1200};
    CHECK(isSame(C, A * B) == 1);
}

// TEST_CASE("huge_ones_matrix")
// {
//     using namespace linalg;
//     Matrix A{1000, 1000, 1};
//     Matrix B{1000, 1000, 1};
//     Matrix C{1000, 1000, 1000};
//     CHECK(isSame(C, A * B) == 1);
// }

// TEST_CASE("huge_matrix")
// {
//     using namespace linalg;
//     Matrix A{1000, 1000, 9};
//     Matrix B{1000, 1000, 7};
//     Matrix C{1000, 1000, 63000};
//     CHECK(isSame(C, A * B) == 1);
// }

// // TEST_CASE("vhuge_matrix1")
// // {
// //     using namespace linalg;
// //     Matrix A{10000, 10000, 14};
// //     Matrix B{10000, 10000, 27};
// //     Matrix C{10000, 10000, 3780000};
// //     CHECK(isSame(C, A * B) == 1);
// // }

// // TEST_CASE("vhuge_matrix2")
// // {
// //     using namespace linalg;
// //     Matrix A{100000, 100000, 1};
// //     Matrix B{100000, 100000, 1};
// //     Matrix C{100000, 100000, 100000};
// //     CHECK(isSame(C, A * B) == 1);
// // }

TEST_SUITE_END();
