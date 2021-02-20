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


TEST_SUITE_BEGIN("test_transpose_size");

TEST_CASE("small_matrix1")
{
    using namespace linalg;
    Matrix<int> A{10, 5, 3};
    A = A.transpose();
    Matrix<int> B{5, 10, 3};
    CHECK(isSame(A, B) == 1);
}

TEST_CASE("small_matrix2")
{
    using namespace linalg;
    Matrix<int> A{70, 35, 3};
    A = A.transpose();
    Matrix<int> B{35, 70, 3};
    CHECK(isSame(A, B) == 1);
}

TEST_CASE("small_matrix3")
{
    using namespace linalg;
    Matrix<int> A{1, 1, 3};
    A = A.transpose();
    Matrix<int> B{1, 1, 3};
    CHECK(isSame(A, B) == 1);
}

TEST_CASE("huge_matrix")
{
    using namespace linalg;
    Matrix<int> A{570, 835, 3};
    A = A.transpose();
    Matrix<int> B{835, 570, 3};
    CHECK(isSame(A, B) == 1);
}

TEST_SUITE_END();
