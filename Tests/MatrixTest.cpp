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
<<<<<<< HEAD
    &MatrixTest::operatorValueTypeCastTest,
    &MatrixTest::operatorAssignmentTest,
    &MatrixTest::operatorEqualsTest,
    &MatrixTest::operatorParenthesesTest,
    &MatrixTest::operatorAddScalarTest,
    &MatrixTest::operatorAddTest,
    &MatrixTest::operatorAddEqualsScalarTest,
    &MatrixTest::operatorUnaryMinusTest,
    &MatrixTest::operatorSubtractScalarTest,
    &MatrixTest::operatorSubtractTest,
    &MatrixTest::operatorSubtractEqualsScalarTest,
    &MatrixTest::operatorMultiplyScalarTest,
    &MatrixTest::operatorMultiplyTest,
    &MatrixTest::operatorMultiplyEqualsScalarTest,
    &MatrixTest::getValueTest,
    &MatrixTest::setValuesTest,
    &MatrixTest::setValuesTest2,
    &MatrixTest::getRowTest,
    &MatrixTest::getColumnTest,
    &MatrixTest::transposeTest,
    &MatrixTest::magnitudeTest,
    &MatrixTest::crossProductTest,
    &MatrixTest::dotProductTest,
    &MatrixTest::toCrossProductEquivalentMatrixTest,
    &MatrixTest::submatrixOperatorAddScalarTest,
    &MatrixTest::submatrixOperatorAddTest,
    &MatrixTest::submatrixOperatorAddEqualsScalarTest,
    &MatrixTest::submatrixOperatorUnaryMinusTest,
    &MatrixTest::submatrixOperatorSubtractScalarTest,
    &MatrixTest::submatrixOperatorSubtractTest,
    &MatrixTest::submatrixOperatorSubtractEqualsScalarTest,
    &MatrixTest::submatrixOperatorMultiplyScalarTest,
    &MatrixTest::submatrixOperatorMultiplyTest,
    &MatrixTest::submatrixOperatorMultiplyEqualsScalarTest
=======
    &MatrixTest::operatorValueTypeCastInternalTest,
    &MatrixTest::operatorValueTypeCastExternalTest,
    &MatrixTest::operatorValueTypeCastConstantTest,
    &MatrixTest::operatorAssignmentInternalTest,
    &MatrixTest::operatorAssignmentExternalTest,
    &MatrixTest::operatorAssignmentConstantTest,
    &MatrixTest::operatorEqualsInternalTest,
    &MatrixTest::operatorEqualsExternalTest,
    &MatrixTest::operatorEqualsConstantTest,
    &MatrixTest::operatorParenthesesInternalTest,
    &MatrixTest::operatorParenthesesExternalTest,
    &MatrixTest::operatorParenthesesConstantTest,
    &MatrixTest::operatorAddScalarInternalTest,
    &MatrixTest::operatorAddScalarExternalTest,
    &MatrixTest::operatorAddScalarConstantTest,
    &MatrixTest::operatorAddInternalTest,
    &MatrixTest::operatorAddExternalTest,
    &MatrixTest::operatorAddConstantTest,
    &MatrixTest::operatorAddEqualsScalarInternalTest,
    &MatrixTest::operatorAddEqualsScalarExternalTest,
    &MatrixTest::operatorUnaryMinusInternalTest,
    &MatrixTest::operatorUnaryMinusExternalTest,
    &MatrixTest::operatorUnaryMinusConstantTest,
    &MatrixTest::operatorSubtractScalarInternalTest,
    &MatrixTest::operatorSubtractScalarExternalTest,
    &MatrixTest::operatorSubtractScalarConstantTest,
    &MatrixTest::operatorSubtractInternalTest,
    &MatrixTest::operatorSubtractExternalTest,
    &MatrixTest::operatorSubtractConstantTest,
    &MatrixTest::operatorSubtractEqualsScalarInternalTest,
    &MatrixTest::operatorSubtractEqualsScalarExternalTest,
    &MatrixTest::operatorMultiplyScalarInternalTest,
    &MatrixTest::operatorMultiplyScalarExternalTest,
    &MatrixTest::operatorMultiplyScalarConstantTest,
    &MatrixTest::operatorMultiplyInternalTest,
    &MatrixTest::operatorMultiplyExternalTest,
    &MatrixTest::operatorMultiplyConstantTest,
    &MatrixTest::operatorMultiplyEqualsScalarInternalTest,
    &MatrixTest::operatorMultiplyEqualsScalarExternalTest,
    &MatrixTest::getValueInternalTest,
    &MatrixTest::getValueExternalTest,
    &MatrixTest::getValueConstantTest,
    &MatrixTest::getValueInternalTest2,
    &MatrixTest::getValueExternalTest2,
    &MatrixTest::setValuesInternalTest,
    &MatrixTest::setValuesExternalTest,
    &MatrixTest::getRowInternalTest,
    &MatrixTest::getRowExternalTest,
    &MatrixTest::getRowConstantTest,
    &MatrixTest::getColumnInternalTest,
    &MatrixTest::getColumnExternalTest,
    &MatrixTest::getColumnConstantTest,
    &MatrixTest::transposeInternalTest,
    &MatrixTest::transposeExternalTest,
    &MatrixTest::transposeConstantTest,
    &MatrixTest::magnitudeInternalTest,
    &MatrixTest::magnitudeExternalTest,
    &MatrixTest::magnitudeConstantTest,
    &MatrixTest::crossProduct3by1InternalTest,
    &MatrixTest::crossProduct3by1ExternalTest,
    &MatrixTest::crossProduct3by1ConstantTest,
    &MatrixTest::dotProductInternalTest,
    &MatrixTest::dotProductExternalTest,
    &MatrixTest::dotProductConstantTest,
    &MatrixTest::toCrossProductEquivalentMatrixInternalTest,
    &MatrixTest::toCrossProductEquivalentMatrixExternalTest,
    &MatrixTest::toCrossProductEquivalentMatrixConstantTest,
    &MatrixTest::submatrixOperatorAddScalarExternalTest,
    &MatrixTest::submatrixOperatorAddScalarConstantTest,
    &MatrixTest::submatrixOperatorAddExternalTest,
    &MatrixTest::submatrixOperatorAddConstantTest,
    &MatrixTest::submatrixOperatorAddEqualsScalarExternalTest,
    &MatrixTest::submatrixOperatorUnaryMinusExternalTest,
    &MatrixTest::submatrixOperatorUnaryMinusConstantTest,
    &MatrixTest::submatrixOperatorSubtractScalarExternalTest,
    &MatrixTest::submatrixOperatorSubtractScalarConstantTest,
    &MatrixTest::submatrixOperatorSubtractExternalTest,
    &MatrixTest::submatrixOperatorSubtractConstantTest,
    &MatrixTest::submatrixOperatorSubtractEqualsScalarExternalTest,
    &MatrixTest::submatrixOperatorMultiplyScalarExternalTest,
    &MatrixTest::submatrixOperatorMultiplyScalarConstantTest,
    &MatrixTest::submatrixOperatorMultiplyExternalTest,
    &MatrixTest::submatrixOperatorMultiplyConstantTest,
    &MatrixTest::submatrixOperatorMultiplyEqualsScalarExternalTest
>>>>>>> 17: Added acceptance tests for Matrix and Vector to better cover interactions between objects with different storage options.
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
bool MatrixTest::operatorValueTypeCastInternalTest()
{
    // Setup / Operation

    const float values[1][1] =
    {
        { 1.0 }
    };

    Matrix<float, 1, 1> matrix(values);

    // Test
    
    float result = matrix;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastExternalTest()
{
    // Setup / Operation

    float values[1][1] =
    {
        { 1.0 }
    };

    Matrix<float, 1, 1, STORAGE_EXTERNAL> matrix(values);

    // Test
    
    float result = matrix;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastConstantTest()
{
    // Setup / Operation

    const float values[1][1] =
    {
        { 1.0 }
    };

    const Matrix<float, 1, 1, STORAGE_CONSTANT> matrix(values);

    // Test
    
    float result = matrix;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentInternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    // Test

    Matrix<float, 3, 3> result1;
    result1 = matrix1;

    Matrix<float, 3, 3> result2;
    result2 = matrix2;

    Matrix<float, 3, 3> result3;
    result3 = matrix3;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    // Test

    float resultValues1[3][3];
    Matrix<float, 3, 3, STORAGE_EXTERNAL> result1(resultValues1);
    result1 = matrix1;

    float resultValues2[3][3];
    Matrix<float, 3, 3, STORAGE_EXTERNAL> result2(resultValues2);
    result2 = matrix2;

    float resultValues3[3][3];
    Matrix<float, 3, 3, STORAGE_EXTERNAL> result3(resultValues3);
    result3 = matrix3;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentConstantTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    const float resultValues[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3, STORAGE_CONSTANT> result(resultValues);
    result = matrix;

    Matrix<float, 3, 3> expected(values);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentInternalTest2()
{
    // Setup / Operation

    Matrix<float, 3, 3> matrix;

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix = values;
    Matrix<float, 3, 3> result = matrix;

    Matrix<float, 3, 3> expected(values);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentConstantTest2()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix = values2;
    Matrix<float, 3, 3> result = matrix;

    Matrix<float, 3, 3> expected(values2);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsInternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    Matrix<float, 3, 3> matrix3(values3);

    float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix4(values4);

    float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix5(values5);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix6(values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    bool result1 = matrix1 == matrix2;
    bool result2 = matrix1 == matrix3;
    bool result3 = matrix1 == matrix4;
    bool result4 = matrix1 == matrix5;
    bool result5 = matrix1 == matrix6;
    bool result6 = matrix1 == matrix7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true)  &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, true)  &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, true)  &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsExternalTest()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    Matrix<float, 3, 3> matrix3(values3);

    float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix4(values4);

    float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix5(values5);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix6(values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    bool result1 = matrix1 == matrix2;
    bool result2 = matrix1 == matrix3;
    bool result3 = matrix1 == matrix4;
    bool result4 = matrix1 == matrix5;
    bool result5 = matrix1 == matrix6;
    bool result6 = matrix1 == matrix7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true)  &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, true)  &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, true)  &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    Matrix<float, 3, 3> matrix3(values3);

    float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix4(values4);

    float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix5(values5);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix6(values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    bool result1 = matrix1 == matrix2;
    bool result2 = matrix1 == matrix3;
    bool result3 = matrix1 == matrix4;
    bool result4 = matrix1 == matrix5;
    bool result5 = matrix1 == matrix6;
    bool result6 = matrix1 == matrix7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true)  &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, true)  &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, true)  &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    float result = matrix(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    float result = matrix(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    float result = matrix(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesInternalTest2()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    matrix(1, 2) = 10.0;
    float result = matrix(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesExternalTest2()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

        matrix(1, 2) = 10.0;
    float result = matrix(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
<<<<<<< HEAD
bool MatrixTest::setValuesTest2()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static const float values1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3> matrix1;

    float values2[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    // Test

    matrix1.setValues(1.0f);
    matrix2.setValues(1.0f);
    Matrix<float, 3, 3> result1 = matrix1;
    Matrix<float, 3, 3> result2 = matrix2;

    static const float expectedValues[3][3] =
    {
        { 1.0, 1.0, 1.0 },
        { 1.0, 1.0, 1.0 },
        { 1.0, 1.0, 1.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    bool compare1 = (result1 == expected);
    bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowTest()
=======
bool MatrixTest::operatorAddScalarExternalTest()
>>>>>>> 17: Added acceptance tests for Matrix and Vector to better cover interactions between objects with different storage options.
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}


//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddInternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);
    
    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    Matrix<float, 3, 3> result3 = matrix1 + matrix4;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddExternalTest()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);
    
    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    Matrix<float, 3, 3> result3 = matrix1 + matrix4;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);
    
    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    Matrix<float, 3, 3> result3 = matrix1 + matrix4;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsScalarInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    matrix += 1;
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsScalarExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    matrix += 1;
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    Matrix<float, 3, 3> result = - matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    Matrix<float, 3, 3> result = - matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    Matrix<float, 3, 3> result = - matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractInternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    Matrix<float, 3, 3> result3 = matrix1 - matrix4;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractExternalTest()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    Matrix<float, 3, 3> result3 = matrix1 - matrix4;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    Matrix<float, 3, 3> result3 = matrix1 - matrix4;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsScalarInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    matrix -= 1;
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsScalarExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    matrix -= 1;
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyInternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyExternalTest()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyEqualsScalarInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    matrix *= 2;
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyEqualsScalarExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    matrix *= 2;
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    float result = matrix.getValue(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    float result = matrix.getValue(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    float result = matrix.getValue(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueInternalTest2()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    matrix.getValue(1, 2) = 10.0f;
    float result = matrix.getValue(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueExternalTest2()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    matrix.getValue(1, 2) = 10.0f;
    float result = matrix.getValue(1, 2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValuesInternalTest()
{
    // Setup / Operation

    Matrix<float, 3, 3> matrix;

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix.setValues(values);
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValuesExternalTest()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3> matrix(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix.setValues(values2);
    Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    Matrix<float, 1, 3> result1 = matrix.getRow(1);
    Matrix<float, 1, 3> result2 = matrix.row(1);

    const float expectedValues[1][3] =
    {
        { 4.0, 5.0, 6.0 }
    };

    Matrix<float, 1, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    Matrix<float, 1, 3> result1 = matrix.getRow(1);
    Matrix<float, 1, 3> result2 = matrix.row(1);

    const float expectedValues[1][3] =
    {
        { 4.0, 5.0, 6.0 }
    };

    Matrix<float, 1, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    Matrix<float, 1, 3> result1 = matrix.getRow(1);
    Matrix<float, 1, 3> result2 = matrix.row(1);

    const float expectedValues[1][3] =
    {
        { 4.0, 5.0, 6.0 }
    };

    Matrix<float, 1, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    Matrix<float, 3, 1> result1 = matrix.getColumn(1);
    Matrix<float, 3, 1> result2 = matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    Matrix<float, 3, 1> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnExternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    Matrix<float, 3, 1> result1 = matrix.getColumn(1);
    Matrix<float, 3, 1> result2 = matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    Matrix<float, 3, 1> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    Matrix<float, 3, 1> result1 = matrix.getColumn(1);
    Matrix<float, 3, 1> result2 = matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    Matrix<float, 3, 1> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::transposeInternalTest()
{
    // Setup / Operation

    const float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    Matrix<float, 2, 3> matrix(values);

    // Test

    Matrix<float, 3, 2> result1 = matrix.transpose();
    Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    Matrix<float, 3, 2> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::transposeExternalTest()
{
    // Setup / Operation

    float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    Matrix<float, 2, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    Matrix<float, 3, 2> result1 = matrix.transpose();
    Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    Matrix<float, 3, 2> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}


//------------------------------------------------------------------------------
bool MatrixTest::transposeConstantTest()
{
    // Setup / Operation

    const float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    const Matrix<float, 2, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    Matrix<float, 3, 2> result1 = matrix.transpose();
    Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    Matrix<float, 3, 2> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeInternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    // Test

    const float result1 = matrix.magnitude();
    const float result2 = matrix.norm();

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeExternalTest()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const float result1 = matrix.magnitude();
    const float result2 = matrix.norm();

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    const float result1 = matrix.magnitude();
    const float result2 = matrix.norm();

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::crossProduct3by1InternalTest()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1> matrix1(values1);

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 1> result1 = matrix1.cross(matrix2);
    Matrix<float, 3, 1> result2 = matrix1.cross(matrix3);
    Matrix<float, 3, 1> result3 = matrix1.cross(matrix4);

    float expectedValues[3][1] =
    {
        { -3.0 },
        {  6.0 },
        { -3.0 }
    };

    Matrix<float, 3, 1> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::crossProduct3by1ExternalTest()
{
    // Setup

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 1> result1 = matrix1.cross(matrix2);
    Matrix<float, 3, 1> result2 = matrix1.cross(matrix3);
    Matrix<float, 3, 1> result3 = matrix1.cross(matrix4);

    float expectedValues[3][1] =
    {
        { -3.0 },
        {  6.0 },
        { -3.0 }
    };

    Matrix<float, 3, 1> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::crossProduct3by1ConstantTest()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1, STORAGE_CONSTANT> matrix1(values1);

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    // Test

    Matrix<float, 3, 1> result1 = matrix1.cross(matrix2);
    Matrix<float, 3, 1> result2 = matrix1.cross(matrix3);
    Matrix<float, 3, 1> result3 = matrix1.cross(matrix4);

    float expectedValues[3][1] =
    {
        { -3.0 },
        {  6.0 },
        { -3.0 }
    };

    Matrix<float, 3, 1> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::dotProductInternalTest()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1> matrix1(values1);

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    // Test

    float result1 = matrix1.dot(matrix2);
    float result2 = matrix1.dot(matrix3);
    float result3 = matrix1.dot(matrix4);

    float expected = 32.0f;

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::dotProductExternalTest()
{
    // Setup

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    // Test

    float result1 = matrix1.dot(matrix2);
    float result2 = matrix1.dot(matrix3);
    float result3 = matrix1.dot(matrix4);

    float expected = 32.0f;

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::dotProductConstantTest()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1, STORAGE_CONSTANT> matrix1(values1);

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    // Test

    float result1 = matrix1.dot(matrix2);
    float result2 = matrix1.dot(matrix3);
    float result3 = matrix1.dot(matrix4);

    float expected = 32.0f;

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::toCrossProductEquivalentMatrixInternalTest()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1> matrix1(values1);

    // Test

    Matrix<float, 3, 3> result1 = matrix1.toCrossProductEquivalentMatrix();
    Matrix<float, 3, 3> result2 = matrix1.skew();

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::toCrossProductEquivalentMatrixExternalTest()
{
    // Setup

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    // Test

    Matrix<float, 3, 3> result1 = matrix1.toCrossProductEquivalentMatrix();
    Matrix<float, 3, 3> result2 = matrix1.skew();

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::toCrossProductEquivalentMatrixConstantTest()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix1(values1);

    // Test

    Matrix<float, 3, 3> result1 = matrix1.toCrossProductEquivalentMatrix();
    Matrix<float, 3, 3> result2 = matrix1.skew();

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddScalarExternalTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    Matrix<float, 2, 2> result = submatrix + 1;

    const float expectedValues[2][2] =
    {
        { 6.0,  7.0 },
        { 9.0, 10.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddScalarConstantTest()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    Matrix<float, 2, 2> result = submatrix + 1;

    const float expectedValues[2][2] =
    {
        { 6.0,  7.0 },
        { 9.0, 10.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result = submatrix1 + submatrix2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values2);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result = submatrix1 + submatrix2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddEqualsScalarExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 += 1;
    submatrix2 += 1;
    Matrix<float, 2, 2> result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Matrix<float, 2, 2> result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

    const float expectedValues1[2][2] =
    {
        { 6.0,  7.0 },
        { 9.0, 10.0 }
    };

    const float expectedValues2[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 6.0,  7.0 },
        { 7.0, 9.0, 10.0 }
    };

    Matrix<float, 2, 2> expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);
    const bool compare3 = (result3 == expected1);
    const bool compare4 = (result4 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorUnaryMinusExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = -submatrix1;
    Matrix<float, 2, 2> result2 = -submatrix2;

    const float expectedValues[2][2] =
    {
        { -5.0, -6.0 },
        { -8.0, -9.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorUnaryMinusConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = -submatrix1;
    Matrix<float, 2, 2> result2 = -submatrix2;

    const float expectedValues[2][2] =
    {
        { -5.0, -6.0 },
        { -8.0, -9.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractScalarExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = submatrix1 - 1;
    Matrix<float, 2, 2> result2 = submatrix2 - 1;

    const float expectedValues[2][2] =
    {
        { 4.0, 5.0 },
        { 7.0, 8.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractScalarConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = submatrix1 - 1;
    Matrix<float, 2, 2> result2 = submatrix2 - 1;

    const float expectedValues[2][2] =
    {
        { 4.0, 5.0 },
        { 7.0, 8.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = submatrix1 - submatrix2;
    Matrix<float, 2, 2> result2 = submatrix2 - submatrix1;

    const float expectedValues1[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const float expectedValues2[2][2] =
    {
        {  0.0, -2.0 },
        { -6.0, -8.0 }
    };

    Matrix<float, 2, 2> expected1(expectedValues1);
    Matrix<float, 2, 2> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = submatrix1 - submatrix2;
    Matrix<float, 2, 2> result2 = submatrix2 - submatrix1;

    const float expectedValues1[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const float expectedValues2[2][2] =
    {
        {  0.0, -2.0 },
        { -6.0, -8.0 }
    };

    Matrix<float, 2, 2> expected1(expectedValues1);
    Matrix<float, 2, 2> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}


//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractEqualsScalarExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 -= 1;
    submatrix2 -= 1;

    Matrix<float, 2, 2> result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Matrix<float, 2, 2> result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

    const float expectedValues1[2][2] =
    {
        { 4.0, 5.0 },
        { 7.0, 8.0 }
    };

    const float expectedValues2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 4.0, 5.0 },
        { 7.0, 7.0, 8.0 }
    };

    Matrix<float, 2, 2> expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);
    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);
    const bool compare3 = (result3 == expected1);
    const bool compare4 = (result4 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyScalarExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = submatrix1 * 2;
    Matrix<float, 2, 2> result2 = submatrix2 * 2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyScalarConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result1 = submatrix1 * 2;
    Matrix<float, 2, 2> result2 = submatrix2 * 2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result = submatrix1 * submatrix2;

    const float expectedValues[2][2] =
    {
        { 37.0,  26.0 },
        { 58.0,  41.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyConstantTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Matrix<float, 2, 2> result = submatrix1 * submatrix2;

    const float expectedValues[2][2] =
    {
        { 37.0,  26.0 },
        { 58.0,  41.0 }
    };

    Matrix<float, 2, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyEqualsScalarExternalTest()
{
    // Setup / Operation

    const float values1[3][3] =
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

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 *= 2;
    submatrix2 *= 2;

    Matrix<float, 2, 2> result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Matrix<float, 2, 2> result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

    const float expectedValues1[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const float expectedValues2[3][3] =
    {
        { 1.0,  2.0,  3.0 },
        { 4.0, 10.0, 12.0 },
        { 7.0, 16.0, 18.0 }
    };

    Matrix<float, 2, 2> expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);
    const bool compare3 = (result3 == expected1);
    const bool compare4 = (result4 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true));
}
