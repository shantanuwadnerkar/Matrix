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


#include "doctest.h"
#include "matrix.h"


TEST_SUITE_BEGIN("test_square_matrix");

TEST_CASE("small_zeros_matrix")
{
    using namespace linalg;
    Matrix<int> A{5, 5, 0};
    Matrix<int> B{5, 5, 0};
    Matrix<int> C{5, 5, 0};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("small_ones_matrix")
{
    using namespace linalg;
    Matrix<int> A{5, 5, 1};
    Matrix<int> B{5, 5, 1};
    Matrix<int> C{5, 5, 5};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("small_matrix1")
{
    using namespace linalg;
    Matrix<int> A{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix<int> B{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix<int> C{{{30, 36, 42}, {66, 81, 96}, {102, 126, 150}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("small_matrix2")
{
    using namespace linalg;
    Matrix<int> A{{{1, 2, 3, 3}, {4, 5, 6, 6}, {7, 8, 9, 9}, {1, 2, 3, 4}}};                        // (4, 4)
    Matrix<int> B{{{4, 3, 2, 1}, {9, 9, 8, 7}, {6, 6, 5, 4}, {3, 3, 2, 1}}};                        // (4, 4)
    Matrix<int> C{{{49, 48, 39, 30}, {115, 111, 90, 69}, {181, 174, 141, 108}, {52, 51, 41, 31}}};  // (4, 4)
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("small_matrix3")
{
    using namespace linalg;
    Matrix<int> A{5, 5, 5};
    Matrix<int> B{5, 5, 5};
    Matrix<int> C{5, 5, 125};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("small_matrix4")
{
    using namespace linalg;
    Matrix<int> A{10, 10, 5};
    Matrix<int> B{10, 10, 5};
    Matrix<int> C{10, 10, 250};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("small_matrix5")
{
    using namespace linalg;
    Matrix<int> A{10, 10, 3};
    Matrix<int> B{10, 10, 7};
    Matrix<int> C{10, 10, 210};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("medium_ones_matrix")
{
    using namespace linalg;
    Matrix<int> A{100, 100, 1};
    Matrix<int> B{100, 100, 1};
    Matrix<int> C{100, 100, 100};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("medium_matrix")
{
    using namespace linalg;
    Matrix<int> A{100, 100, 6};
    Matrix<int> B{100, 100, 2};
    Matrix<int> C{100, 100, 1200};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("huge_ones_matrix")
{
    using namespace linalg;
    Matrix<int> A{1000, 1000, 1};
    Matrix<int> B{1000, 1000, 1};
    Matrix<int> C{1000, 1000, 1000};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("huge_matrix")
{
    using namespace linalg;
    Matrix<int> A{1000, 1000, 9};
    Matrix<int> B{1000, 1000, 7};
    Matrix<int> C{1000, 1000, 63000};
    CHECK(isSame(C, A * B) == 1);
}

// TEST_CASE("vhuge_matrix1")
// {
//     using namespace linalg;
//     Matrix<int> A{10000, 10000, 14};
//     Matrix<int> B{10000, 10000, 27};
//     Matrix<int> C{10000, 10000, 3780000};
//     CHECK(isSame(C, A * B) == 1);
// }

// TEST_CASE("vhuge_matrix2")
// {
//     using namespace linalg;
//     Matrix<int> A{100000, 100000, 1};
//     Matrix<int> B{100000, 100000, 1};
//     Matrix<int> C{100000, 100000, 100000};
//     CHECK(isSame(C, A * B) == 1);
// }

TEST_SUITE_END();
