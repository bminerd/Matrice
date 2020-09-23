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
/// @file VectorTest.cpp
/// @author Ben Minerd
/// @date 9/23/2020
/// @brief VectorTest class source file.
///

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <Plat4m_Core/Plat4m.h>

#include <Tests/VectorTest.h>
#include <Matrice/Vector.h>

using Matrice::VectorTest;
using Plat4m::UnitTest;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

const UnitTest::TestCallbackFunction VectorTest::myTestCallbackFunctions[] =
{
    &VectorTest::operatorEqualsTest,
    &VectorTest::operatorAddScalarTest,
    &VectorTest::operatorAddTest,
    &VectorTest::operatorAddEqualsScalarTest,
    &VectorTest::operatorUnaryMinusTest,
    &VectorTest::operatorSubtractScalarTest,
    &VectorTest::operatorSubtractTest,
    &VectorTest::operatorSubtractEqualsScalarTest,
    &VectorTest::operatorMultiplyScalarTest,
    &VectorTest::operatorMultiplyTest,
    &VectorTest::operatorMultiplyEqualsScalarTest,
    &VectorTest::submatrixOperatorAddScalarTest,
    &VectorTest::submatrixOperatorAddTest,
    &VectorTest::submatrixOperatorAddEqualsScalarTest,
    &VectorTest::submatrixOperatorUnaryMinusTest,
    &VectorTest::submatrixOperatorSubtractScalarTest,
    &VectorTest::submatrixOperatorSubtractTest,
    &VectorTest::submatrixOperatorSubtractEqualsScalarTest,
    &VectorTest::submatrixOperatorMultiplyScalarTest,
    &VectorTest::submatrixOperatorMultiplyTest,
    &VectorTest::submatrixOperatorMultiplyEqualsScalarTest
};

//------------------------------------------------------------------------------
// Public constructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
VectorTest::VectorTest() :
    UnitTest("VectorTest",
             myTestCallbackFunctions,
             Plat4m::arraySize(myTestCallbackFunctions))
{
}

//------------------------------------------------------------------------------
// Public virtual destructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
VectorTest::~VectorTest()
{
}

//------------------------------------------------------------------------------
// Public static methods
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    const float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector3(values3);

    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true) &
                            UNIT_TEST_CASE_EQUAL(result2, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    Vector<float, 3> result1 = vector1 + 1;
    Vector<float, 3> result2 = vector2 + 1;

    static const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    Vector<float, 3> result1 = vector1 + vector2;
    Vector<float, 3> result2 = vector2 + vector1;

    static const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsScalarTest()
{
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    vector1 += 1;
    Vector<float, 3> result1 = vector1;
    vector2 += 1;
    Vector<float, 3> result2 = vector2;

    static const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorUnaryMinusTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    Vector<float, 3> result1 = - vector1;
    Vector<float, 3> result2 = - vector2;

    static const float expectedValues[3] =
    {
         1.0,
        -2.0,
         3.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    Vector<float, 3> result1 = vector1 - 1;
    Vector<float, 3> result2 = vector1 - 1;

    static const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    Vector<float, 3> result1 = vector1 - vector2;
    Vector<float, 3> result2 = vector2 - vector1;

    static const float expectedValues1[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    static const float expectedValues2[3] =
    {
         2.0,
         0.0,
        -2.0
    };

    Vector<float, 3> expected1(expectedValues1);
    Vector<float, 3> expected2(expectedValues2);
    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsScalarTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    vector1 -= 1;
    Vector<float, 3> result1 = vector1;
    vector2 -= 1;
    Vector<float, 3> result2 = vector2;

    static const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    Vector<float, 3> result1 = vector1 * 2;
    Vector<float, 3> result2 = vector2 * 2;

    static const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    static const float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix1(values3);

    // Test

    Vector<float, 3> result1 = matrix1 * vector1;
    Vector<float, 3> result2 = matrix1 * vector2;

    static const float expectedValues[3] =
    {
        46.0,
        28.0,
        10.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyEqualsScalarTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    // Test

    vector1 *= 2;
    Vector<float, 3> result1 = vector1;
    vector2 *= 2;
    Vector<float, 3> result2 = vector2;

    static const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddScalarTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 + 1;
    Vector<float, 2> result2 = submatrix2 + 1;

    static const float expectedValues[2] =
    {
        6.0,
        9.0
    };

    Vector<float, 2> expected(expectedValues);

    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 + submatrix2;
    Vector<float, 2> result2 = submatrix2 + submatrix1;

    static const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddEqualsScalarTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 += 1;
    submatrix2 += 1;
    Vector<float, 2>    result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Vector<float, 2>    result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

    static const float expectedValues1[2] =
    {
        6.0,
        9.0
    };

    static const float expectedValues2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 6.0, 6.0 },
        { 7.0, 9.0, 9.0 }
    };

    Vector<float, 2>    expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);

    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected2);
    bool compare3 = (result3 == expected1);
    bool compare4 = (result4 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorUnaryMinusTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = -submatrix1;
    Vector<float, 2> result2 = -submatrix2;

    static const float expectedValues[2] =
    {
        -5.0,
        -8.0
    };

    Vector<float, 2> expected(expectedValues);

    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractScalarTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 - 1;
    Vector<float, 2> result2 = submatrix2 - 1;

    static const float expectedValues[2] =
    {
        4.0,
        7.0
    };

    Vector<float, 2> expected(expectedValues);

    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 - submatrix2;
    Vector<float, 2> result2 = submatrix2 - submatrix1;

    static const float expectedValues1[2] =
    {
        0.0,
        6.0
    };

    static const float expectedValues2[2] =
    {
         0.0,
        -6.0
    };

    Vector<float, 2> expected1(expectedValues1);
    Vector<float, 2> expected2(expectedValues2);

    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractEqualsScalarTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 -= 1;
    submatrix2 -= 1;

    Vector<float, 2>    result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Vector<float, 2>    result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

    static const float expectedValues1[2] =
    {
        4.0,
        7.0
    };

    static const float expectedValues2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 4.0, 6.0 },
        { 7.0, 7.0, 9.0 }
    };

    Vector<float, 2>    expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);
    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected2);
    bool compare3 = (result3 == expected1);
    bool compare4 = (result4 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyScalarTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 * 2;
    Vector<float, 2> result2 = submatrix2 * 2;

    static const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyTest()
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

    static const float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix3(values3);

    Vector<float, 3, STORAGE_EXTERNAL> submatrix1(matrix1, 0, 1);
    Vector<float, 3, STORAGE_EXTERNAL> submatrix2(matrix2, 0, 1);

    // Test

    Vector<float, 3> result1 = matrix3 * submatrix1;
    Vector<float, 3> result2 = matrix3 * submatrix2;

    static const float expectedValues1[3] =
    {
        114.0,
         69.0,
         24.0
    };

    Vector<float, 3> expected1(expectedValues1);
    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected1);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyEqualsScalarTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 *= 2;
    submatrix2 *= 2;

    Vector<float, 2>    result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Vector<float, 2>    result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

    static const float expectedValues1[2] =
    {
        10.0,
        16.0
    };

    static const float expectedValues2[3][3] =
    {
        { 1.0,  2.0, 3.0 },
        { 4.0, 10.0, 6.0 },
        { 7.0, 16.0, 9.0 }
    };

    Vector<float, 2>    expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);

    bool compare1 = (result1 == expected1);
    bool compare2 = (result2 == expected2);
    bool compare3 = (result3 == expected1);
    bool compare4 = (result4 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true));
}
