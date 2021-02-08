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


TEST_SUITE_BEGIN("test");

TEST_CASE("test_func")
{
    using namespace linalg;
    Matrix A{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix B{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix C{{{30, 36, 42}, {66, 81, 96}, {102, 126, 150}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("new_test")
{
    using namespace linalg;
    Matrix A{2, 3, 3};
    Matrix B{3, 2, 3};
    Matrix C{{{27, 27}, {27, 27}}};
    CHECK(isSame(C, A * B) == 1);
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("vector operations");

TEST_CASE("row")
{
    using namespace linalg;
    Matrix A{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    Matrix B{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::cout << B.size();
    B = B.transpose();
    std::cout << B.size();
    std::vector<int> C_{285};
    Matrix C{C_};
    // std::cout << C.size().first << C.size().second;
    CHECK(isSame(C, A * B) == 1);
}

TEST_SUITE_END();
