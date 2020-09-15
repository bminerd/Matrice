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

using Matrice::MatrixTest;
using Plat4m::UnitTest;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

const UnitTest::TestCallbackFunction MatrixTest::myTestCallbackFunctions[] =
{
    &MatrixTest::operatorUnaryPlusTest,
    &MatrixTest::operatorAddScalarTest,
    &MatrixTest::operatorAddTest,
    &MatrixTest::operatorAddEqualsScalarTest,
    &MatrixTest::operatorUnaryMinusTest,
    &MatrixTest::operatorSubtractScalarTest,
    &MatrixTest::operatorSubtractTest,
    &MatrixTest::operatorSubtractEqualsScalarTest,
    &MatrixTest::operatorMultiplyScalarTest,
    &MatrixTest::operatorMultiplyTest,
    &MatrixTest::operatorMultiplyEqualsScalarTest
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
bool MatrixTest::operatorEqualsTest()
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    Matrix<float, 3, 3> matrix3(values3);

    // Test

    bool result1 = matrix1 == matrix2;
    bool result2 = matrix1 == matrix3;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true) &
                            UNIT_TEST_CASE_EQUAL(result2, false));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryPlusTest()
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = + matrix1;
    Matrix<float, 3, 3> result2 = + matrix2;

    static const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarTest()
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 + 1;
    Matrix<float, 3, 3> result2 = matrix2 + 1;

    static const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddTest()
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

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    Matrix<float, 3, 3> result2 = matrix2 + matrix1;

    static const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsScalarTest()
{
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    matrix1 += 1;
    Matrix<float, 3, 3> result1 = matrix1;
    matrix2 += 1;
    Matrix<float, 3, 3> result2 = matrix2;

    static const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    float values2[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = - matrix1;
    Matrix<float, 3, 3> result2 = - matrix2;

    static const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarTest()
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 - 1;
    Matrix<float, 3, 3> result2 = matrix2 - 1;

    static const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractTest()
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

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    Matrix<float, 3, 3> result2 = matrix2 - matrix1;

    static const float expectedValues1[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    static const float expectedValues2[3][3] =
    {
        {  8.0,  6.0,  4.0 },
        {  2.0,  0.0, -2.0 },
        { -4.0, -6.0, -8.0 }
    };

    Matrix<float, 3, 3> expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);
    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsScalarTest()
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    matrix1 -= 1;
    Matrix<float, 3, 3> result1 = matrix1;
    matrix2 -= 1;
    Matrix<float, 3, 3> result2 = matrix2;

    static const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarTest()
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 * 2;
    Matrix<float, 3, 3> result2 = matrix2 * 2;

    static const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest()
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

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    Matrix<float, 3, 3> result2 = matrix2 * matrix1;

    static const float expectedValues1[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    static const float expectedValues2[3][3] =
    {
        { 90.0, 114.0, 138.0 },
        { 54.0,  69.0,  84.0 },
        { 18.0,  24.0,  30.0 }
    };

    Matrix<float, 3, 3> expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);
    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyEqualsScalarTest()
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    matrix1 *= 2;
    Matrix<float, 3, 3> result1 = matrix1;
    matrix2 *= 2;
    Matrix<float, 3, 3> result2 = matrix2;

    static const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}