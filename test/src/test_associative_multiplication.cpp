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


TEST_SUITE_BEGIN("test_associative_multiplication");

TEST_CASE("small_ones_matrix")
{
    using namespace linalg;
    Matrix<int> A{5, 5, 1};
    Matrix<int> B{5, 5, 1};
    Matrix<int> C{5, 5, 1};
    Matrix<int> D{5, 5, 25};
    CHECK(isSame(D, A * B * C) == 1);
}

TEST_CASE("small_matrix")
{
    using namespace linalg;
    Matrix<int> A{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix<int> B{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix<int> C{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix<int> D{{{468, 576, 684}, {1062, 1305, 1548}, {1656, 2034, 2412}}};
    CHECK(isSame(D, A * B * C) == 1);
}

TEST_CASE("medium_matrix")
{
    using namespace linalg;
    Matrix<int> A{100, 100, 6};
    Matrix<int> B{100, 100, 2};
    Matrix<int> C{100, 100, 8};
    Matrix<int> D{100, 100, 960000};
    CHECK(isSame(D, A * B * C) == 1);
}

TEST_CASE("huge_matrix")
{
    using namespace linalg;
    Matrix<int> A{1000, 1000, 9};
    Matrix<int> B{1000, 1000, 7};
    Matrix<int> C{1000, 1000, 1};
    Matrix<int> D{1000, 1000, 63000000};
    CHECK(isSame(D, A * B * C) == 1);
}

TEST_SUITE_END();
