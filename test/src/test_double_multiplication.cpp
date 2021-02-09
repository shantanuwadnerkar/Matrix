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

TEST_CASE("long_long_int")
{
    using namespace linalg;
    Matrix<long long int> A{5, 7, 1};
    Matrix<long long int> B{7, 3, 1};
    Matrix<long long int> C{5, 3, 7};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("float")
{
    using namespace linalg;
    Matrix<float> A{5, 7, 1.5};
    Matrix<float> B{7, 3, 1.5};
    Matrix<float> C{5, 3, 15.75};
    CHECK(isSame(C, A * B) == 1);
}

TEST_CASE("double")
{
    using namespace linalg;
    Matrix<double> A{5, 7, 1.5};
    Matrix<double> B{7, 3, 1.5};
    Matrix<double> C{5, 3, 15.75};
    CHECK(isSame(C, A * B) == 1);
}

TEST_SUITE_END();
