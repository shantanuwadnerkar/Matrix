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


#include <doctest/doctest.h>
#include <Matrix/matrix.h>


TEST_SUITE_BEGIN("test_rectangle_matrix");

TEST_CASE("square_rectangle")
{
    using namespace linalg;
    Matrix<int> A{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}; // (3, 3)
    Matrix<int> B{{{1, 2}, {4, 5}, {7, 8}}};          // (3, 2)
    Matrix<int> C{{{30, 36}, {66, 81}, {102, 126}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("rectangle_square")
{
    using namespace linalg;
    Matrix<int> A{{{1, 2, 4} ,{5, 7, 8}}};               // (2, 3)
    Matrix<int> B{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};    // (3, 3)
    Matrix<int> C{{{37, 44, 51}, {89, 109, 129}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("rectangle_rectangle1")
{
    using namespace linalg;
    Matrix<int> A{{{1, 2, 3}, {4, 5, 6}}};   // (2, 3)
    Matrix<int> B{{{1, 2}, {4, 5}, {7, 8}}}; // (3, 2)
    Matrix<int> C{{{30, 36}, {66, 81}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("rectangle_rectangle2")
{
    using namespace linalg;
    Matrix<int> A{{{5, 7}, {2, 4}, {6, 9}}};     // (3, 2)
    Matrix<int> B{{{1, 2, 3, 7}, {4, 5, 6, 8}}}; // (2, 4)
    Matrix<int> C{{{33, 45, 57, 91}, {18, 24, 30, 46}, {42, 57, 72, 114}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("medium_matrix1")
{
    using namespace linalg;
    Matrix<int> A{37, 45, 6};
    Matrix<int> B{45, 73, 2};
    Matrix<int> C{37, 73, 540};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("medium_matrix2")
{
    using namespace linalg;
    Matrix<int> A{59, 28, 7};
    Matrix<int> B{28, 45, 4};
    Matrix<int> C{59, 45, 784};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("huge_matrix")
{
    using namespace linalg;
    Matrix<int> A{186, 489, 9};
    Matrix<int> B{489, 674, 7};
    Matrix<int> C{186, 674, 30807};
    CHECK(isSame(C, A * B) == 1);
}

TEST_SUITE_END();
