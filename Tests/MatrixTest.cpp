//------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2020 Benjamin Minerd
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//------------------------------------------------------------------------------

///
/// @file MatrixTest.cpp
/// @author Ben Minerd
/// @date 5/1/2020
/// @brief MatrixTest class source file.
///

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <string.h>

#include <Plat4m_Core/Plat4m.h>

#include <Tests/MatrixTest.h>
#include <Matrice/Matrix.h>
#include <Matrice/Map.h>

using Matrice::MatrixTest;
using Plat4m::UnitTest;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

const UnitTest::TestCallbackFunction MatrixTest::myTestCallbackFunctions[] =
{
    &MatrixTest::test1
};

//------------------------------------------------------------------------------
// Public constructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
MatrixTest::MatrixTest() :
    UnitTest("MatrixTest",
             myTestCallbackFunctions,
             Plat4m::arraySize(myTestCallbackFunctions))
{
}

//------------------------------------------------------------------------------
// Public virtual destructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
MatrixTest::~MatrixTest()
{
}

//------------------------------------------------------------------------------
// Public static methods
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
bool MatrixTest::test1()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    // Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);
    Map< Matrix<float, 3, 3> > matrix2(values2);

    Matrix<float, 3, 3> result1;
    Matrix<float, 3, 3> result2;
    Matrix<float, 3, 3> result3;
    Matrix<float, 3, 3> result4;
    Matrix<float, 3, 3> result5;
    Matrix<float, 3, 3> result6;
    Matrix<float, 3, 3> result7;
    Matrix<float, 3, 3> result8;
    Matrix<float, 3, 3> result9;
    Matrix<float, 3, 3> result10;
    Matrix<float, 3, 3> result11;
    Matrix<float, 3, 3> result12;

    // Test

    Matrix<float, 3, 3> result1 = matrix1 + 1;

    Matrix<float, 3, 3> result2 = matrix2 + 1;

    Matrix<float, 3, 3> result3 = matrix1 - 1;

    Matrix<float, 3, 3> result4 = matrix2 - 1;

    Matrix<float, 3, 3> result5 = matrix1 * 2;

    Matrix<float, 3, 3> result6 = matrix2 * 2;

    Matrix<float, 3, 3> result7 = matrix1 + matrix2;

    Matrix<float, 3, 3> result8 = matrix2 + matrix1;

    Matrix<float, 3, 3> result9 = matrix1 - matrix2;

    Matrix<float, 3, 3> result10 = matrix2 - matrix1;

    Matrix<float, 3, 3> result11 = matrix1 * matrix2;

    Matrix<float, 3, 3> result12 = matrix2 * matrix1;

    return UNIT_TEST_REPORT(false);
}
