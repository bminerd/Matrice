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
#include <Matrice/Vector.h>

using Matrice::MatrixTest;
using Plat4m::UnitTest;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

const UnitTest::TestCallbackFunction MatrixTest::myTestCallbackFunctions[] =
{
    &MatrixTest::operatorValueTypeCastTestInternal,
    &MatrixTest::operatorValueTypeCastTestExternal,
    &MatrixTest::operatorValueTypeCastTestConstant,
    &MatrixTest::operatorValueTypeCastTest2Internal,
    &MatrixTest::operatorValueTypeCastTest2External,
    &MatrixTest::operatorValueTypeCastTest2Constant,
    &MatrixTest::operatorValueTypeCastTest2InternalRunTime,
    &MatrixTest::operatorValueTypeCastTest2ExternalRunTime,
    &MatrixTest::operatorValueTypeCastTest2ConstantRunTime,
    &MatrixTest::operatorAssignmentTestInternal,
    &MatrixTest::operatorAssignmentTestExternal,
    &MatrixTest::operatorAssignmentTestConstant,
    &MatrixTest::operatorAssignmentTestInternalRunTime,
    &MatrixTest::operatorAssignmentTestExternalRunTime,
    &MatrixTest::operatorAssignmentTestConstantRunTime,
    &MatrixTest::operatorAssignmentTest2Internal,
    &MatrixTest::operatorAssignmentTest2External,
    &MatrixTest::operatorAssignmentTest2Constant,
    &MatrixTest::operatorAssignmentTest2InternalRunTime,
    &MatrixTest::operatorAssignmentTest2ExternalRunTime,
    &MatrixTest::operatorAssignmentTest2ConstantRunTime,
    &MatrixTest::operatorEqualsTestInternal,
    &MatrixTest::operatorEqualsTestExternal,
    &MatrixTest::operatorEqualsTestConstant,
    &MatrixTest::operatorEqualsTestInternalRunTime,
    &MatrixTest::operatorEqualsTestExternalRunTime,
    &MatrixTest::operatorEqualsTestConstantRunTime,
    &MatrixTest::operatorEqualsTest2Internal,
    &MatrixTest::operatorEqualsTest2External,
    &MatrixTest::operatorEqualsTest2Constant,
    &MatrixTest::operatorEqualsTest2InternalRunTime,
    &MatrixTest::operatorEqualsTest2ExternalRunTime,
    &MatrixTest::operatorEqualsTest2ConstantRunTime,
    &MatrixTest::operatorParenthesesTestInternal,
    &MatrixTest::operatorParenthesesTestExternal,
    &MatrixTest::operatorParenthesesTestConstant,
    &MatrixTest::operatorParenthesesTestInternalRunTime,
    &MatrixTest::operatorParenthesesTestExternalRunTime,
    &MatrixTest::operatorParenthesesTestConstantRunTime,
    &MatrixTest::operatorParenthesesTest2Internal,
    &MatrixTest::operatorParenthesesTest2External,
    &MatrixTest::operatorParenthesesTest2InternalRunTime,
    &MatrixTest::operatorParenthesesTest2ExternalRunTime,
    &MatrixTest::operatorAddScalarTestInternal,
    &MatrixTest::operatorAddScalarTestExternal,
    &MatrixTest::operatorAddScalarTestConstant,
    &MatrixTest::operatorAddScalarTestInternalRunTime,
    &MatrixTest::operatorAddScalarTestExternalRunTime,
    &MatrixTest::operatorAddScalarTestConstantRunTime,
    &MatrixTest::operatorAddTestInternal,
    &MatrixTest::operatorAddTestExternal,
    &MatrixTest::operatorAddTestConstant,
    &MatrixTest::operatorAddTestInternalRunTime,
    &MatrixTest::operatorAddTestExternalRunTime,
    &MatrixTest::operatorAddTestConstantRunTime,
    &MatrixTest::operatorAddEqualsScalarTestInternal,
    &MatrixTest::operatorAddEqualsScalarTestExternal,
    &MatrixTest::operatorAddEqualsScalarTestInternalRunTime,
    &MatrixTest::operatorAddEqualsScalarTestExternalRunTime,
    &MatrixTest::operatorAddEqualsTestInternal,
    &MatrixTest::operatorAddEqualsTestExternal,
    &MatrixTest::operatorAddEqualsTestInternalRunTime,
    &MatrixTest::operatorAddEqualsTestExternalRunTime,
    &MatrixTest::operatorUnaryMinusTestInternal,
    &MatrixTest::operatorUnaryMinusTestExternal,
    &MatrixTest::operatorUnaryMinusTestConstant,
    &MatrixTest::operatorUnaryMinusTestInternalRunTime,
    &MatrixTest::operatorUnaryMinusTestExternalRunTime,
    &MatrixTest::operatorUnaryMinusTestConstantRunTime,
    &MatrixTest::operatorSubtractScalarTestInternal,
    &MatrixTest::operatorSubtractScalarTestExternal,
    &MatrixTest::operatorSubtractScalarTestConstant,
    &MatrixTest::operatorSubtractScalarTestInternalRunTime,
    &MatrixTest::operatorSubtractScalarTestExternalRunTime,
    &MatrixTest::operatorSubtractScalarTestConstantRunTime,
    &MatrixTest::operatorSubtractTestInternal,
    &MatrixTest::operatorSubtractTestExternal,
    &MatrixTest::operatorSubtractTestConstant,
    &MatrixTest::operatorSubtractTestInternalRunTime,
    &MatrixTest::operatorSubtractTestExternalRunTime,
    &MatrixTest::operatorSubtractTestConstantRunTime,
    &MatrixTest::operatorSubtractEqualsScalarTestInternal,
    &MatrixTest::operatorSubtractEqualsScalarTestExternal,
    &MatrixTest::operatorSubtractEqualsTestInternal,
    &MatrixTest::operatorSubtractEqualsTestExternal,
    &MatrixTest::operatorMultiplyScalarTestInternal,
    &MatrixTest::operatorSubtractEqualsTestInternalRunTime,
    &MatrixTest::operatorSubtractEqualsTestExternalRunTime,
    &MatrixTest::operatorMultiplyScalarTestInternal,
    &MatrixTest::operatorMultiplyScalarTestExternal,
    &MatrixTest::operatorMultiplyScalarTestConstant,
    &MatrixTest::operatorMultiplyScalarTestInternalRunTime,
    &MatrixTest::operatorMultiplyScalarTestExternalRunTime,
    &MatrixTest::operatorMultiplyScalarTestConstantRunTime,
    &MatrixTest::operatorMultiplyTest4By5InternalTimes5By4,
    &MatrixTest::operatorMultiplyTest4By5ExternalTimes5By4,
    &MatrixTest::operatorMultiplyTest4By5ConstantTimes5By4,
    &MatrixTest::operatorMultiplyTest4By5InternalRunTimeTimes5By4,
    &MatrixTest::operatorMultiplyTest4By5ExternalRunTimeTimes5By4,
    &MatrixTest::operatorMultiplyTest4By5ConstantRunTimeTimes5By4,
    &MatrixTest::operatorMultiplyTest3By3InternalTimes3By3,
    &MatrixTest::operatorMultiplyTest3By3ExternalTimes3By3,
    &MatrixTest::operatorMultiplyTest3By3ConstantTimes3By3,
    &MatrixTest::operatorMultiplyTest3By3InternalRunTimeTimes3By3,
    &MatrixTest::operatorMultiplyTest3By3ExternalRunTimeTimes3By3,
    &MatrixTest::operatorMultiplyTest3By3ConstantRunTimeTimes3By3,
    &MatrixTest::operatorMultiplyTestInternalTimesVector,
    &MatrixTest::operatorMultiplyTestExternalTimesVector,
    &MatrixTest::operatorMultiplyTestConstantTimesVector,
    &MatrixTest::operatorMultiplyTestInternalRunTimeTimesVector,
    &MatrixTest::operatorMultiplyTestExternalRunTimeTimesVector,
    &MatrixTest::operatorMultiplyTestConstantRunTimeTimesVector,
    &MatrixTest::operatorMultiplyEqualsScalarTestInternal,
    &MatrixTest::operatorMultiplyEqualsScalarTestExternal,
    &MatrixTest::operatorMultiplyEqualsScalarTestInternalRunTime,
    &MatrixTest::operatorMultiplyEqualsScalarTestExternalRunTime,
    &MatrixTest::getValueTestInternal,
    &MatrixTest::getValueTestExternal,
    &MatrixTest::getValueTestConstant,
    &MatrixTest::getValueTestInternalRunTime,
    &MatrixTest::getValueTestExternalRunTime,
    &MatrixTest::getValueTestConstantRunTime,
    &MatrixTest::getValueTest2Internal,
    &MatrixTest::getValueTest2External,
    &MatrixTest::getValueTest2InternalRunTime,
    &MatrixTest::getValueTest2ExternalRunTime,
    &MatrixTest::setValueTestInternal,
    &MatrixTest::setValueTestExternal,
    &MatrixTest::setValueTestInternalRunTime,
    &MatrixTest::setValueTestExternalRunTime,
    &MatrixTest::setValuesTestInternal,
    &MatrixTest::setValuesTestExternal,
    &MatrixTest::setValuesTestInternalRunTime,
    &MatrixTest::setValuesTestExternalRunTime,
    &MatrixTest::getRowTestInternal,
    &MatrixTest::getRowTestExternal,
    &MatrixTest::getRowTestConstant,
    &MatrixTest::getRowTestInternalRunTime,
    &MatrixTest::getRowTestExternalRunTime,
    &MatrixTest::getRowTestConstantRunTime,
    &MatrixTest::getColumnTestInternal,
    &MatrixTest::getColumnTestExternal,
    &MatrixTest::getColumnTestConstant,
    &MatrixTest::getColumnTestInternalRunTime,
    &MatrixTest::getColumnTestExternalRunTime,
    &MatrixTest::getColumnTestConstantRunTime,
    &MatrixTest::transposeTestInternal,
    &MatrixTest::transposeTestExternal,
    &MatrixTest::transposeTestConstant,
    &MatrixTest::transposeTestInternalRunTime,
    &MatrixTest::transposeTestExternalRunTime,
    &MatrixTest::transposeTestConstantRunTime,
    &MatrixTest::magnitudeTestInternal,
    &MatrixTest::magnitudeTestExternal,
    &MatrixTest::magnitudeTestConstant,
    &MatrixTest::magnitudeTestInternalRunTime,
    &MatrixTest::magnitudeTestExternalRunTime,
    &MatrixTest::magnitudeTestConstantRunTime,
    &MatrixTest::crossProductTest3by1Internal,
    &MatrixTest::crossProductTest3by1External,
    &MatrixTest::crossProductTest3by1Constant,
    &MatrixTest::dotProductTestInternal,
    &MatrixTest::dotProductTestExternal,
    &MatrixTest::dotProductTestConstant,
    &MatrixTest::toCrossProductEquivalentMatrixTestInternal,
    &MatrixTest::toCrossProductEquivalentMatrixTestExternal,
    &MatrixTest::toCrossProductEquivalentMatrixTestConstant,
    &MatrixTest::printTestInternal,
    &MatrixTest::printTestExternal,
    &MatrixTest::printTestConstant,
    &MatrixTest::printTestInternalRunTime,
    &MatrixTest::printTestExternalRunTime,
    &MatrixTest::printTestConstantRunTime,
    &MatrixTest::submatrixOperatorAddScalarTestExternal,
    &MatrixTest::submatrixOperatorAddScalarTestConstant,
    &MatrixTest::submatrixOperatorAddScalarTestExternalRunTime,
    &MatrixTest::submatrixOperatorAddScalarTestConstantRunTime,
    &MatrixTest::submatrixOperatorAddTestExternal,
    &MatrixTest::submatrixOperatorAddTestConstant,
    &MatrixTest::submatrixOperatorAddTestExternalRunTime,
    &MatrixTest::submatrixOperatorAddTestConstantRunTime,
    &MatrixTest::submatrixOperatorAddEqualsScalarTestExternal,
    &MatrixTest::submatrixOperatorAddEqualsScalarTestExternalRunTime,
    &MatrixTest::submatrixOperatorAddEqualsTestExternal,
    &MatrixTest::submatrixOperatorAddEqualsTestExternalRunTime,
    &MatrixTest::submatrixOperatorUnaryMinusTestExternal,
    &MatrixTest::submatrixOperatorUnaryMinusTestConstant,
    &MatrixTest::submatrixOperatorUnaryMinusTestExternalRunTime,
    &MatrixTest::submatrixOperatorUnaryMinusTestConstantRunTime,
    &MatrixTest::submatrixOperatorSubtractScalarTestExternal,
    &MatrixTest::submatrixOperatorSubtractScalarTestConstant,
    &MatrixTest::submatrixOperatorSubtractScalarTestExternalRunTime,
    &MatrixTest::submatrixOperatorSubtractScalarTestConstantRunTime,
    &MatrixTest::submatrixOperatorSubtractTestExternal,
    &MatrixTest::submatrixOperatorSubtractTestConstant,
    &MatrixTest::submatrixOperatorSubtractTestExternalRunTime,
    &MatrixTest::submatrixOperatorSubtractTestConstantRunTime,
    &MatrixTest::submatrixOperatorSubtractEqualsScalarTestExternal,
    &MatrixTest::submatrixOperatorSubtractEqualsScalarTestExternalRunTime,
    &MatrixTest::submatrixOperatorSubtractEqualsTestExternal,
    &MatrixTest::submatrixOperatorSubtractEqualsTestExternalRunTime,
    &MatrixTest::submatrixOperatorMultiplyScalarTestExternal,
    &MatrixTest::submatrixOperatorMultiplyScalarTestConstant,
    &MatrixTest::submatrixOperatorMultiplyScalarTestExternalRunTime,
    &MatrixTest::submatrixOperatorMultiplyScalarTestConstantRunTime,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ExternalTimes2By2,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ConstantTimes2By2,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ExternalRunTimeTimes2By2,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ConstantRunTimeTimes2By2,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ExternalTimesVector,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ConstantTimesVector,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ExternalRunTimeTimesVector,
    &MatrixTest::submatrixOperatorMultiplyTest2By2ConstantRunTimeTimesVector,
    &MatrixTest::submatrixOperatorMultiplyTestEqualsScalarExternal,
    &MatrixTest::submatrixOperatorMultiplyTestEqualsScalarExternalRunTime,
    &MatrixTest::submatrixGetValueTestExternal,
    &MatrixTest::submatrixGetValueTestConstant,
    &MatrixTest::submatrixGetValueTestExternalRunTime,
    &MatrixTest::submatrixGetValueTestConstantRunTime,
    &MatrixTest::submatrixSetValueTestExternal,
    &MatrixTest::submatrixSetValueTestExternalRunTime,
    &MatrixTest::submatrixTransposeTestExternal,
    &MatrixTest::submatrixTransposeTestConstant,
    &MatrixTest::submatrixTransposeTestExternalRunTime,
    &MatrixTest::submatrixTransposeTestConstantRunTime,
    &MatrixTest::submatrixPrintTestExternal,
    &MatrixTest::submatrixPrintTestConstant,
    &MatrixTest::submatrixPrintTestExternalRunTime,
    &MatrixTest::submatrixPrintTestConstantRunTime,
    &MatrixTest::nestedSubmatrixOperatorEqualsTestExternal,
    &MatrixTest::nestedSubmatrixOperatorEqualsTestExternalRunTime
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
bool MatrixTest::operatorValueTypeCastTestInternal()
{
    // Setup / Operation

    const float values[1][1] =
    {
        { 1.0 }
    };

    const Matrix<float, 1, 1> matrix(values);

    // Test

    const float result = matrix;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTestExternal()
{
    // Setup / Operation

    float values[1][1] =
    {
        { 1.0 }
    };

    const Matrix<float, 1, 1, STORAGE_EXTERNAL> matrix(values);

    // Test

    const float result = matrix;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTestConstant()
{
    // Setup / Operation

    const float values[1][1] =
    {
        { 1.0 }
    };

    const Matrix<float, 1, 1, STORAGE_CONSTANT> matrix(values);

    // Test

    const float result = matrix;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTest2Internal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    const Matrix<double, 3, 3> result1 = static_cast<Matrix<double, 3, 3>>(
                                                                        matrix);

    const Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> result2 =
        static_cast<Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME>>(
                                                                        matrix);

    const double expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<double, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTest2External()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<double, 3, 3> result1 = static_cast<Matrix<double, 3, 3>>(
                                                                        matrix);

    const Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> result2 =
        static_cast<Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME>>(
                                                                        matrix);


    const double expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<double, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTest2Constant()
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

    const Matrix<double, 3, 3> result1 = static_cast<Matrix<double, 3, 3>>(
                                                                        matrix);

    const Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> result2 =
        static_cast<Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME>>(
                                                                        matrix);


    const double expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<double, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTest2InternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    const Matrix<double, 3, 3> result1 = static_cast<Matrix<double, 3, 3>>(
                                                                        matrix);

    const Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> result2 =
        static_cast<Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME>>(
                                                                        matrix);

    const double expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<double, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTest2ExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    const Matrix<double, 3, 3> result1 = static_cast<Matrix<double, 3, 3>>(
                                                                        matrix);

    const Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> result2 =
        static_cast<Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME>>(
                                                                        matrix);

    const double expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<double, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorValueTypeCastTest2ConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Test

    const Matrix<double, 3, 3> result1 = static_cast<Matrix<double, 3, 3>>(
                                                                        matrix);

    const Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> result2 =
        static_cast<Matrix<double, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME>>(
                                                                        matrix);

    const double expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<double, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTestInternal()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(
                                                                       3,
                                                                       3,
                                                                       values4);

    float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix5(3, 3, values5);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(3, 3, values6);

    // Test

    Matrix<float, 3, 3> result1;
    result1 = matrix1;

    Matrix<float, 3, 3> result2;
    result2 = matrix2;

    Matrix<float, 3, 3> result3;
    result3 = matrix3;

    Matrix<float, 3, 3> result4;
    result4 = matrix4;

    Matrix<float, 3, 3> result5;
    result5 = matrix5;

    Matrix<float, 3, 3> result6;
    result6 = matrix6;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTestExternal()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(
                                                                       3,
                                                                       3,
                                                                       values4);

    float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix5(3, 3, values5);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(3, 3, values6);

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

    float resultValues4[3][3];
    Matrix<float, 3, 3, STORAGE_EXTERNAL> result4(resultValues4);
    result4 = matrix4;

    float resultValues5[3][3];
    Matrix<float, 3, 3, STORAGE_EXTERNAL> result5(resultValues5);
    result5 = matrix5;

    float resultValues6[3][3];
    Matrix<float, 3, 3, STORAGE_EXTERNAL> result6(resultValues6);
    result6 = matrix6;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTestConstant()
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

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix2(3, 3, values2);

    // Test

    const float resultValues1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3, STORAGE_CONSTANT> result1(resultValues1);
    result1 = matrix1;

    const float resultValues2[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3> result2(resultValues2);
    result2 = matrix2;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}


//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTestInternalRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(
                                                                       3,
                                                                       3,
                                                                       values4);

    float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix5(3, 3, values5);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(3, 3, values6);

    // Test

    Matrix<float, 3, 3> result1;
    result1 = matrix1;

    Matrix<float, 3, 3> result2;
    result2 = matrix2;

    Matrix<float, 3, 3> result3;
    result3 = matrix3;

    Matrix<float, 3, 3> result4;
    result4 = matrix4;

    Matrix<float, 3, 3> result5;
    result5 = matrix5;

    Matrix<float, 3, 3> result6;
    result6 = matrix6;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTestExternalRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(
                                                                       3,
                                                                       3,
                                                                       values4);

    float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix5(3, 3, values5);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(3, 3, values6); 

    // Test

    float resultValues1[3][3];
    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> result1(3, 3, resultValues1);
    result1 = matrix1;

    float resultValues2[3][3];
    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> result2(3, 3, resultValues2);
    result2 = matrix2;

    float resultValues3[3][3];
    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> result3(3, 3, resultValues3);
    result3 = matrix3;

    float resultValues4[3][3];
    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> result4(3, 3, resultValues4);
    result4 = matrix4;

    float resultValues5[3][3];
    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> result5(3, 3, resultValues5);
    result5 = matrix5;

    float resultValues6[3][3];
    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> result6(3, 3, resultValues6);
    result6 = matrix6;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTestConstantRunTime()
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

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix2(3, 3, values2);

    // Test

    const float resultValues1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_CONSTANT> result1(3, 3, resultValues1);
    result1 = matrix1;

    const float resultValues2[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_CONSTANT> result2(3, 3, resultValues2);
    result2 = matrix2;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTest2Internal()
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

    const Matrix<float, 3, 3> result = matrix;

    const Matrix<float, 3, 3> expected(values);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTest2External()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix = values2;

    const Matrix<float, 3, 3> result = matrix;

    const Matrix<float, 3, 3> expected(values2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTest2Constant()
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

    const Matrix<float, 3, 3> result = matrix;

    const Matrix<float, 3, 3> expected(values2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTest2InternalRunTime()
{
    // Setup / Operation

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3, 3);

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix = values;

    const Matrix<float, 3, 3> result = matrix;

    const Matrix<float, 3, 3> expected(values);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTest2ExternalRunTime()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix = values2;

    const Matrix<float, 3, 3> result = matrix;

    const Matrix<float, 3, 3> expected(values2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAssignmentTest2ConstantRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_CONSTANT> matrix(3, 3, values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix = values2;

    const Matrix<float, 3, 3> result = matrix;

    const Matrix<float, 3, 3> expected(values2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix1(
                                                                       3,
                                                                       3,
                                                                       values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTest2Internal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTest2External()
{
    // Setup / Operation

    // Items to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTest2Constant()
{
    // Setup / Operation

    // Items to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTest2InternalRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Items to test

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix1(
                                                                       3,
                                                                       3,
                                                                       values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTest2ExternalRunTime()
{
    // Setup / Operation

    // Items to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorEqualsTest2ConstantRunTime()
{
    // Setup / Operation

    // Items to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0,  3.0 },
        { 4.0, 5.0,  6.0 },
        { 7.0, 8.0, 10.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix2) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix3) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix4) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix5) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix6) &
                            UNIT_TEST_CASE_NOT_EQUAL(matrix1, matrix7));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTestInternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTestExternal()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTestConstant()
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

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTest2Internal()
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

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTest2External()
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

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTest2InternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3,
                                                                   3,
                                                                   values);

    // Test

    matrix(1, 2) = 10.0;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorParenthesesTest2ExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    matrix(1, 2) = 10.0;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarTestInternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarTestExternal()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}


//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarTestConstant()
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

    const Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    const Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    const Matrix<float, 3, 3> result = matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}


//------------------------------------------------------------------------------
bool MatrixTest::operatorAddScalarTestConstantRunTime()
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

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> result =
                                                                     matrix + 1;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 + matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 + matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 + matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 + matrix7;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 + matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 + matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 + matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 + matrix7;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);
    
    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 + matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 + matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 + matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 + matrix7;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix1(
                                                                       3,
                                                                       3,
                                                                       values1);

    // Items to test against

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

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 + matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 + matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 + matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 + matrix7;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 + matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 + matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 + matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 + matrix7;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                DIMENSIONS_RUN_TIME,
                DIMENSIONS_RUN_TIME,
                STORAGE_CONSTANT> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 + matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 + matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 + matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 + matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 + matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 + matrix7;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsScalarTestInternal()
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
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsScalarTestExternal()
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
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3,
                                                                   3,
                                                                   values);

    // Test

    matrix += 1;
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    matrix += 1;
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 2.0, 3.0,  4.0 },
        { 5.0, 6.0,  7.0 },
        { 8.0, 9.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

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

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(3,
                                                                    3,
                                                                    values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix6(3, 3, values6);
    
    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 += matrix2;
    const Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

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

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(3,
                                                                    3,
                                                                    values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix6(3, 3, values6);
    
    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 += matrix2;
    const Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

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

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(3,
                                                                    3,
                                                                    values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 += matrix2;
    const Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 += matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorAddEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

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

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(3,
                                                                    3,
                                                                    values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix6(3, 3, values6);
    
    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 += matrix2;
    const Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 += matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 },
        { 10.0, 10.0, 10.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusTestInternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = -matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusTestExternal()
{
    // Setup / Operation

    float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = -matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusTestConstant()
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

    const Matrix<float, 3, 3> result = -matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    const Matrix<float, 3, 3> result = -matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    const Matrix<float, 3, 3> result = -matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorUnaryMinusTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { -1.0, -2.0, -3.0 },
        { -4.0, -5.0, -6.0 },
        { -7.0, -8.0, -9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Test

    const Matrix<float, 3, 3> result = -matrix;

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarTestInternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarTestExternal()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarTestConstant()
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

    const Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    const Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    const Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Test

    const Matrix<float, 3, 3> result = matrix - 1;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 - matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 - matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 - matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 - matrix7;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 - matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 - matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 - matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 - matrix7;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 - matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 - matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 - matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 - matrix7;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix1(
                                                                       3,
                                                                       3,
                                                                       values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 - matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 - matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 - matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 - matrix7;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 - matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 - matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 - matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 - matrix7;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix7(values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 - matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 - matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 - matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 - matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 - matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 - matrix7;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsScalarTestInternal()
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
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsScalarTestExternal()
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
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3,
                                                                   3,
                                                                   values);

    // Test

    matrix -= 1;
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    matrix -= 1;
    const Matrix<float, 3, 3> result = matrix;

    const float expectedValues[3][3] =
    {
        { 0.0, 1.0, 2.0 },
        { 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 -= matrix2;
    const Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 -= matrix2;
    const Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix1(3,
                                                                    3,
                                                                    values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 -= matrix2;
    const Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    matrix1 -= matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorSubtractEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    matrix1 -= matrix2;
    Matrix<float, 3, 3> result1 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix3;
    const Matrix<float, 3, 3> result2 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix4;
    const Matrix<float, 3, 3> result3 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix5;
    const Matrix<float, 3, 3> result4 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix6;
    const Matrix<float, 3, 3> result5 = matrix1;

    matrix1 = Matrix<float, 3, 3>(initialValues);

    matrix1 -= matrix7;
    const Matrix<float, 3, 3> result6 = matrix1;

    const float expectedValues[3][3] =
    {
        { -8.0, -6.0, -4.0 },
        { -2.0,  0.0,  2.0 },
        {  4.0,  6.0,  8.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarTestInternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarTestExternal()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarTestConstant()
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

    const Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    const Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    const Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Test

    const Matrix<float, 3, 3> result = matrix * 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest4By5InternalTimes5By4()
{
    // Setup / Operation

    // Item to test

    const float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    const Matrix<float, 4, 5> matrix1(values1);

    // Items to test against

    const float values2[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4> matrix2(values2);

    float values3[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_CONSTANT> matrix4(values4);

    const float values5[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       5,
                                                                       4,
                                                                       values5);

    float values6[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(5, 4, values6);

    const float values7[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(5, 4, values7);

    // Test

    const Matrix<float, 4, 4> result1 = matrix1 * matrix2;
    const Matrix<float, 4, 4> result2 = matrix1 * matrix3;
    const Matrix<float, 4, 4> result3 = matrix1 * matrix4;
    const Matrix<float, 4, 4> result4 = matrix1 * matrix5;
    const Matrix<float, 4, 4> result5 = matrix1 * matrix6;
    const Matrix<float, 4, 4> result6 = matrix1 * matrix7;

    const float expectedValues[4][4] =
    {
        {  140.0, 125.0, 110.0,  95.0 },
        {  440.0, 400.0, 360.0, 320.0 },
        {  740.0, 675.0, 610.0, 545.0 },
        { 1040.0, 950.0, 860.0, 770.0 }
    };

    const Matrix<float, 4, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest4By5ExternalTimes5By4()
{
    // Setup / Operation

    // Item to test

    float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    const Matrix<float, 4, 5, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4> matrix2(values2);

    float values3[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_CONSTANT> matrix4(values4);

    const float values5[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       5,
                                                                       4,
                                                                       values5);

    float values6[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(5, 4, values6);

    const float values7[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(5, 4, values7);

    // Test

    const Matrix<float, 4, 4> result1 = matrix1 * matrix2;
    const Matrix<float, 4, 4> result2 = matrix1 * matrix3;
    const Matrix<float, 4, 4> result3 = matrix1 * matrix4;
    const Matrix<float, 4, 4> result4 = matrix1 * matrix5;
    const Matrix<float, 4, 4> result5 = matrix1 * matrix6;
    const Matrix<float, 4, 4> result6 = matrix1 * matrix7;

    const float expectedValues[4][4] =
    {
        {  140.0, 125.0, 110.0,  95.0 },
        {  440.0, 400.0, 360.0, 320.0 },
        {  740.0, 675.0, 610.0, 545.0 },
        { 1040.0, 950.0, 860.0, 770.0 }
    };

    const Matrix<float, 4, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest4By5ConstantTimes5By4()
{
    // Setup / Operation

    // Item to test

    const float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    const Matrix<float, 4, 5, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4> matrix2(values2);

    float values3[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_CONSTANT> matrix4(values4);

    const float values5[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       5,
                                                                       4,
                                                                       values5);

    float values6[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(5, 4, values6);

    const float values7[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(5, 4, values7);

    // Test

    const Matrix<float, 4, 4> result1 = matrix1 * matrix2;
    const Matrix<float, 4, 4> result2 = matrix1 * matrix3;
    const Matrix<float, 4, 4> result3 = matrix1 * matrix4;
    const Matrix<float, 4, 4> result4 = matrix1 * matrix5;
    const Matrix<float, 4, 4> result5 = matrix1 * matrix6;
    const Matrix<float, 4, 4> result6 = matrix1 * matrix7;

    const float expectedValues[4][4] =
    {
        {  140.0, 125.0, 110.0,  95.0 },
        {  440.0, 400.0, 360.0, 320.0 },
        {  740.0, 675.0, 610.0, 545.0 },
        { 1040.0, 950.0, 860.0, 770.0 }
    };

    const Matrix<float, 4, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest4By5InternalRunTimeTimes5By4()
{
    // Setup / Operation

    // Item to test

    const float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME> matrix1(4, 5, values1);

    // Items to test against

    const float values2[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4> matrix2(values2);

    float values3[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_CONSTANT> matrix4(values4);

    const float values5[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME> matrix5(5, 4, values5);

    float values6[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(5, 4, values6);

    const float values7[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(5, 4, values7);

    // Test

    const Matrix<float, 4, 4> result1 = matrix1 * matrix2;
    const Matrix<float, 4, 4> result2 = matrix1 * matrix3;
    const Matrix<float, 4, 4> result3 = matrix1 * matrix4;
    const Matrix<float, 4, 4> result4 = matrix1 * matrix5;
    const Matrix<float, 4, 4> result5 = matrix1 * matrix6;
    const Matrix<float, 4, 4> result6 = matrix1 * matrix7;

    const float expectedValues[4][4] =
    {
        {  140.0, 125.0, 110.0,  95.0 },
        {  440.0, 400.0, 360.0, 320.0 },
        {  740.0, 675.0, 610.0, 545.0 },
        { 1040.0, 950.0, 860.0, 770.0 }
    };

    const Matrix<float, 4, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest4By5ExternalRunTimeTimes5By4()
{
    // Setup / Operation

    // Item to test

    float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix1(4, 5, values1);

    // Items to test against

    const float values2[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4> matrix2(values2);

    float values3[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_CONSTANT> matrix4(values4);

    const float values5[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       5,
                                                                       4,
                                                                       values5);

    float values6[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(5, 4, values6);

    const float values7[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(5, 4, values7);

    // Test

    const Matrix<float, 4, 4> result1 = matrix1 * matrix2;
    const Matrix<float, 4, 4> result2 = matrix1 * matrix3;
    const Matrix<float, 4, 4> result3 = matrix1 * matrix4;
    const Matrix<float, 4, 4> result4 = matrix1 * matrix5;
    const Matrix<float, 4, 4> result5 = matrix1 * matrix6;
    const Matrix<float, 4, 4> result6 = matrix1 * matrix7;

    const float expectedValues[4][4] =
    {
        {  140.0, 125.0, 110.0,  95.0 },
        {  440.0, 400.0, 360.0, 320.0 },
        {  740.0, 675.0, 610.0, 545.0 },
        { 1040.0, 950.0, 860.0, 770.0 }
    };

    const Matrix<float, 4, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest4By5ConstantRunTimeTimes5By4()
{
    // Setup / Operation

    // Item to test

    const float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix1(4, 5, values1);

    // Items to test against

    const float values2[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4> matrix2(values2);

    float values3[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, 5, 4, STORAGE_CONSTANT> matrix4(values4);

    const float values5[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       5,
                                                                       4,
                                                                       values5);

    float values6[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(5, 4, values6);

    const float values7[5][4] =
    {
        { 20.0, 19.0, 18.0, 17.0 },
        { 16.0, 15.0, 14.0, 13.0 },
        { 12.0, 11.0, 10.0,  9.0 },
        {  8.0,  7.0,  6.0,  5.0 },
        {  4.0,  3.0,  2.0,  1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(5, 4, values7);

    // Test

    const Matrix<float, 4, 4> result1 = matrix1 * matrix2;
    const Matrix<float, 4, 4> result2 = matrix1 * matrix3;
    const Matrix<float, 4, 4> result3 = matrix1 * matrix4;
    const Matrix<float, 4, 4> result4 = matrix1 * matrix5;
    const Matrix<float, 4, 4> result5 = matrix1 * matrix6;
    const Matrix<float, 4, 4> result6 = matrix1 * matrix7;

    const float expectedValues[4][4] =
    {
        {  140.0, 125.0, 110.0,  95.0 },
        {  440.0, 400.0, 360.0, 320.0 },
        {  740.0, 675.0, 610.0, 545.0 },
        { 1040.0, 950.0, 860.0, 770.0 }
    };

    const Matrix<float, 4, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest3By3InternalTimes3By3()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 * matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 * matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 * matrix7;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest3By3ExternalTimes3By3()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 * matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 * matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 * matrix7;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest3By3ConstantTimes3By3()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 * matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 * matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 * matrix7;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest3By3InternalRunTimeTimes3By3()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix1(
                                                                       3,
                                                                       3,
                                                                       values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 * matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 * matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 * matrix7;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest3By3ExternalRunTimeTimes3By3()
{
    // Setup / Operation

    // Item to test

    float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 * matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 * matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 * matrix7;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTest3By3ConstantRunTimeTimes3By3()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix1(3, 3, values1);

    // Items to test against

    const float values2[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3> matrix2(values2);

    float values3[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       3,
                                                                       3,
                                                                       values5);

    float values6[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(3, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(3, 3, values7);

    // Test

    const Matrix<float, 3, 3> result1 = matrix1 * matrix2;
    const Matrix<float, 3, 3> result2 = matrix1 * matrix3;
    const Matrix<float, 3, 3> result3 = matrix1 * matrix4;
    const Matrix<float, 3, 3> result4 = matrix1 * matrix5;
    const Matrix<float, 3, 3> result5 = matrix1 * matrix6;
    const Matrix<float, 3, 3> result6 = matrix1 * matrix7;

    const float expectedValues[3][3] =
    {
        {  30.0,  24.0, 18.0 },
        {  84.0,  69.0, 54.0 },
        { 138.0, 114.0, 90.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTestInternalTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Items to test against

    const float values1[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3,
                                                                       values5);

    const float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    const Vector<float, 3> result1 = matrix * vector1;
    const Vector<float, 3> result2 = matrix * vector2;
    const Vector<float, 3> result3 = matrix * vector3;
    const Vector<float, 3> result4 = matrix * vector4;
    const Vector<float, 3> result5 = matrix * vector5;
    const Vector<float, 3> result6 = matrix * vector6;

    const float expectedValues[3] =
    {
        10.0,
        28.0,
        46.0
    };

    const Vector<float, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTestExternalTimesVector()
{
    // Setup / Operation

    // Item to test

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Items to test against

    const float values1[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3,
                                                                       values5);

    const float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    const Vector<float, 3> result1 = matrix * vector1;
    const Vector<float, 3> result2 = matrix * vector2;
    const Vector<float, 3> result3 = matrix * vector3;
    const Vector<float, 3> result4 = matrix * vector4;
    const Vector<float, 3> result5 = matrix * vector5;
    const Vector<float, 3> result6 = matrix * vector6;

    const float expectedValues[3] =
    {
        10.0,
        28.0,
        46.0
    };

    const Vector<float, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTestConstantTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    // Items to test against

    const float values1[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3,
                                                                       values5);

    const float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    const Vector<float, 3> result1 = matrix * vector1;
    const Vector<float, 3> result2 = matrix * vector2;
    const Vector<float, 3> result3 = matrix * vector3;
    const Vector<float, 3> result4 = matrix * vector4;
    const Vector<float, 3> result5 = matrix * vector5;
    const Vector<float, 3> result6 = matrix * vector6;

    const float expectedValues[3] =
    {
        10.0,
        28.0,
        46.0
    };

    const Vector<float, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTestInternalRunTimeTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Items to test against

    const float values1[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3,
                                                                       values5);

    const float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    const Vector<float, 3> result1 = matrix * vector1;
    const Vector<float, 3> result2 = matrix * vector2;
    const Vector<float, 3> result3 = matrix * vector3;
    const Vector<float, 3> result4 = matrix * vector4;
    const Vector<float, 3> result5 = matrix * vector5;
    const Vector<float, 3> result6 = matrix * vector6;

    const float expectedValues[3] =
    {
        10.0,
        28.0,
        46.0
    };

    const Vector<float, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTestExternalRunTimeTimesVector()
{
    // Setup / Operation

    // Item to test

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Items to test against

    const float values1[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3,
                                                                       values5);

    const float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    const Vector<float, 3> result1 = matrix * vector1;
    const Vector<float, 3> result2 = matrix * vector2;
    const Vector<float, 3> result3 = matrix * vector3;
    const Vector<float, 3> result4 = matrix * vector4;
    const Vector<float, 3> result5 = matrix * vector5;
    const Vector<float, 3> result6 = matrix * vector6;

    const float expectedValues[3] =
    {
        10.0,
        28.0,
        46.0
    };

    const Vector<float, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyTestConstantRunTimeTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Items to test against

    const float values1[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector1(values1);

    float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_EXTERNAL> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3,
                                                                       values5);

    const float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    const Vector<float, 3> result1 = matrix * vector1;
    const Vector<float, 3> result2 = matrix * vector2;
    const Vector<float, 3> result3 = matrix * vector3;
    const Vector<float, 3> result4 = matrix * vector4;
    const Vector<float, 3> result5 = matrix * vector5;
    const Vector<float, 3> result6 = matrix * vector6;

    const float expectedValues[3] =
    {
        10.0,
        28.0,
        46.0
    };

    const Vector<float, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyEqualsScalarTestInternal()
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

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyEqualsScalarTestExternal()
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

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyEqualsScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3,
                                                                   3,
                                                                   values);

    // Test

    matrix *= 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::operatorMultiplyEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    matrix *= 2;

    const float expectedValues[3][3] =
    {
        {  2.0,  4.0,  6.0 },
        {  8.0, 10.0, 12.0 },
        { 14.0, 16.0, 18.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTestInternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTestExternal()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTestConstant()
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

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 6.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTest2Internal()
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

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTest2External()
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

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTest2InternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3,
                                                                   3,
                                                                   values);

    // Test

    matrix.getValue(1, 2) = 10.0f;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::getValueTest2ExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    matrix.getValue(1, 2) = 10.0f;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValueTestInternal()
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

    matrix.setValue(1, 2, 10.0f);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValueTestExternal()
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

    matrix.setValue(1, 2, 10.0f);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValueTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3,
                                                                   3,
                                                                   values);

    // Test

    matrix.setValue(1, 2, 10.0f);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValueTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    matrix.setValue(1, 2, 10.0f);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.getValue(1, 2), 10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValuesTestInternal()
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

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValuesTestExternal()
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

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValuesTestInternalRunTime()
{
    // Setup / Operation

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(3, 3);

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix.setValues(values);

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::setValuesTestExternalRunTime()
{
    // Setup / Operation

    float values1[3][3] =
    {
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, 0.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix(3, 3, values1);

    const float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Test

    matrix.setValues(values2);

    const float expectedValues[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowTestInternal()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, 3, 4> matrix(values);

    // Test

    const Matrix<float, 1, 4, STORAGE_CONSTANT> result1 = matrix.getRow(1);
    const Matrix<float, 1, 4, STORAGE_CONSTANT> result2 = matrix.row(1);

    const float expectedValues[1][4] =
    {
        { 4.0, 5.0, 6.0, -1.0 }
    };

    const Matrix<float, 1, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowTestExternal()
{
    // Setup / Operation

    float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, 3, 4, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<float, 1, 4, STORAGE_CONSTANT> result1 = matrix.getRow(1);
    const Matrix<float, 1, 4, STORAGE_CONSTANT> result2 = matrix.row(1);

    const float expectedValues[1][4] =
    {
        { 4.0, 5.0, 6.0, -1.0 }
    };

    const Matrix<float, 1, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowTestConstant()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, 3, 4, STORAGE_CONSTANT> matrix(values);

    // Test

    const Matrix<float, 1, 4, STORAGE_CONSTANT> result1 = matrix.getRow(1);
    const Matrix<float, 1, 4, STORAGE_CONSTANT> result2 = matrix.row(1);

    const float expectedValues[1][4] =
    {
        { 4.0, 5.0, 6.0, -1.0 }
    };

    const Matrix<float, 1, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        4,
                                                                        values);

    // Test

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> result1 = matrix.getRow(1);
    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> result2 = matrix.row(1);

    const float expectedValues[1][4] =
    {
        { 4.0, 5.0, 6.0, -1.0 }
    };

    const Matrix<float, 1, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowTestExternalRunTime()
{
    // Setup / Operation

    float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 4, values);

    // Test

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> result1 = matrix.getRow(1);
    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> result2 = matrix.row(1);

    const float expectedValues[1][4] =
    {
        { 4.0, 5.0, 6.0, -1.0 }
    };

    const Matrix<float, 1, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getRowTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 4, values);

    // Test

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> result1 = matrix.getRow(1);
    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> result2 = matrix.row(1);

    const float expectedValues[1][4] =
    {
        { 4.0, 5.0, 6.0, -1.0 }
    };

    const Matrix<float, 1, 4> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnTestInternal()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, 3, 4> matrix(values);

    // Test

    const Matrix<float, 3, 1, STORAGE_CONSTANT> result1 = matrix.getColumn(1);
    const Matrix<float, 3, 1, STORAGE_CONSTANT> result2 = matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnTestExternal()
{
    // Setup / Operation

    float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, 3, 4, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<float, 3, 1, STORAGE_CONSTANT> result1 = matrix.getColumn(1);
    const Matrix<float, 3, 1, STORAGE_CONSTANT> result2 = matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnTestConstant()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, 3, 4, STORAGE_CONSTANT> matrix(values);

    // Test

    const Matrix<float, 3, 1, STORAGE_CONSTANT> result1 = matrix.getColumn(1);
    const Matrix<float, 3, 1, STORAGE_CONSTANT> result2 = matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        4,
                                                                        values);

    // Test

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> result1 =
                                                            matrix.getColumn(1);
    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> result2 =
                                                                  matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnTestExternalRunTime()
{
    // Setup / Operation

    float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 4, values);

    // Test

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> result1 =
                                                            matrix.getColumn(1);
    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> result2 =
                                                                  matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::getColumnTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][4] =
    {
        { 1.0, 2.0, 3.0, -1.0 },
        { 4.0, 5.0, 6.0, -1.0 },
        { 7.0, 8.0, 9.0, -1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 4, values);

    // Test

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> result1 =
                                                            matrix.getColumn(1);
    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> result2 =
                                                                  matrix.col(1);

    const float expectedValues[3][1] =
    {
        { 2.0 },
        { 5.0 },
        { 8.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::transposeTestInternal()
{
    // Setup / Operation

    const float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    const Matrix<float, 2, 3> matrix(values);

    // Test

    const Matrix<float, 3, 2> result1 = matrix.transpose();
    const Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    const Matrix<float, 3, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::transposeTestExternal()
{
    // Setup / Operation

    float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    const Matrix<float, 2, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const Matrix<float, 3, 2> result1 = matrix.transpose();
    const Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    const Matrix<float, 3, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}


//------------------------------------------------------------------------------
bool MatrixTest::transposeTestConstant()
{
    // Setup / Operation

    const float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    const Matrix<float, 2, 3, STORAGE_CONSTANT> matrix(values);

    // Test

    const Matrix<float, 3, 2> result1 = matrix.transpose();
    const Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    const Matrix<float, 3, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::transposeTestInternalRunTime()
{
    // Setup / Operation

    const float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        2,
                                                                        3,
                                                                        values);

    // Test

    const Matrix<float, 3, 2> result1 = matrix.transpose();
    const Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    const Matrix<float, 3, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::transposeTestExternalRunTime()
{
    // Setup / Operation

    float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(2, 3, values);

    // Test

    const Matrix<float, 3, 2> result1 = matrix.transpose();
    const Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    const Matrix<float, 3, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}


//------------------------------------------------------------------------------
bool MatrixTest::transposeTestConstantRunTime()
{
    // Setup / Operation

    const float values[2][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(2, 3, values);

    // Test

    const Matrix<float, 3, 2> result1 = matrix.transpose();
    const Matrix<float, 3, 2> result2 = matrix.T();

    const float expectedValues[3][2] =
    {
        { 1.0, 4.0 },
        { 2.0, 5.0 },
        { 3.0, 6.0 }
    };

    const Matrix<float, 3, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeTestInternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    // Test

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.magnitude(), expected) &
                            UNIT_TEST_CASE_EQUAL(matrix.norm(),      expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeTestExternal()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    // Test

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.magnitude(), expected) &
                            UNIT_TEST_CASE_EQUAL(matrix.norm(),      expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeTestConstant()
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

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.magnitude(), expected) &
                            UNIT_TEST_CASE_EQUAL(matrix.norm(),      expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeTestInternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    // Test

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.magnitude(), expected) &
                            UNIT_TEST_CASE_EQUAL(matrix.norm(),      expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeTestExternalRunTime()
{
    // Setup / Operation

    float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    // Test

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.magnitude(), expected) &
                            UNIT_TEST_CASE_EQUAL( matrix.norm(),     expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::magnitudeTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    // Test

    const float expected =
                      sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7 + 8*8 + 9*9);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix.magnitude(), expected) &
                            UNIT_TEST_CASE_EQUAL(matrix.norm(),      expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::crossProductTest3by1Internal()
{
    // Setup

    // Item to test

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1> matrix1(values1);

    // Items to test against

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1> matrix5(3, values5);

    float values6[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL> matrix6(
                                                                       3,
                                                                       values6);

    const float values7[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> matrix7(
                                                                       3,
                                                                       values7);

    // Test

    const Matrix<float, 3, 1> result1 = matrix1.cross(matrix2);
    const Matrix<float, 3, 1> result2 = matrix1.cross(matrix3);
    const Matrix<float, 3, 1> result3 = matrix1.cross(matrix4);
    const Matrix<float, 3, 1> result4 = matrix1.cross(matrix5);
    const Matrix<float, 3, 1> result5 = matrix1.cross(matrix6);
    const Matrix<float, 3, 1> result6 = matrix1.cross(matrix7);

    const float expectedValues[3][1] =
    {
        { -3.0 },
        {  6.0 },
        { -3.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::crossProductTest3by1External()
{
    // Setup

    // Item to test

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1> matrix5(3, values5);

    float values6[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL> matrix6(
                                                                       3,
                                                                       values6);

    const float values7[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> matrix7(
                                                                       3,
                                                                       values7);

    // Test

    const Matrix<float, 3, 1> result1 = matrix1.cross(matrix2);
    const Matrix<float, 3, 1> result2 = matrix1.cross(matrix3);
    const Matrix<float, 3, 1> result3 = matrix1.cross(matrix4);
    const Matrix<float, 3, 1> result4 = matrix1.cross(matrix5);
    const Matrix<float, 3, 1> result5 = matrix1.cross(matrix6);
    const Matrix<float, 3, 1> result6 = matrix1.cross(matrix7);

    const float expectedValues[3][1] =
    {
        { -3.0 },
        {  6.0 },
        { -3.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::crossProductTest3by1Constant()
{
    // Setup

    // Item to test

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1> matrix5(3, values5);

    float values6[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL> matrix6(
                                                                       3,
                                                                       values6);

    const float values7[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> matrix7(
                                                                       3,
                                                                       values7);

    // Test

    const Matrix<float, 3, 1> result1 = matrix1.cross(matrix2);
    const Matrix<float, 3, 1> result2 = matrix1.cross(matrix3);
    const Matrix<float, 3, 1> result3 = matrix1.cross(matrix4);
    const Matrix<float, 3, 1> result4 = matrix1.cross(matrix5);
    const Matrix<float, 3, 1> result5 = matrix1.cross(matrix6);
    const Matrix<float, 3, 1> result6 = matrix1.cross(matrix7);

    const float expectedValues[3][1] =
    {
        { -3.0 },
        {  6.0 },
        { -3.0 }
    };

    const Matrix<float, 3, 1> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::dotProductTestInternal()
{
    // Setup

    // Item to test

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1> matrix1(values1);

    // Items to test against

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1> matrix5(3, values5);

    float values6[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL> matrix6(
                                                                       3,
                                                                       values6);

    const float values7[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> matrix7(
                                                                       3,
                                                                       values7);

    // Test

    return UNIT_TEST_REPORT(
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix2), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix3), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix4), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix5), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix6), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix7), 32.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::dotProductTestExternal()
{
    // Setup

    // Item to test

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    // Items to test against

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1> matrix5(3, values5);

    float values6[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL> matrix6(
                                                                       3,
                                                                       values6);

    const float values7[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> matrix7(
                                                                       3,
                                                                       values7);

    // Test

    return UNIT_TEST_REPORT(
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix2), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix3), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix4), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix5), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix6), 32.0f) &
                       UNIT_TEST_CASE_EQUAL_FLOAT(matrix1.dot(matrix7), 32.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::dotProductTestConstant()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix1(values1);

    // Items to test against

    const float values2[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1> matrix2(values2);

    float values3[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix4(values4);

    const float values5[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1> matrix5(3, values5);

    float values6[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL> matrix6(
                                                                       3,
                                                                       values6);

    const float values7[3][1] =
    {
        { 4.0 },
        { 5.0 },
        { 6.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT> matrix7(
                                                                       3,
                                                                       values7);

    // Test

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(matrix1.dot(matrix2), 32.0f) &
                            UNIT_TEST_CASE_EQUAL(matrix1.dot(matrix3), 32.0f) &
                            UNIT_TEST_CASE_EQUAL(matrix1.dot(matrix4), 32.0f) &
                            UNIT_TEST_CASE_EQUAL(matrix1.dot(matrix5), 32.0f) &
                            UNIT_TEST_CASE_EQUAL(matrix1.dot(matrix6), 32.0f) &
                            UNIT_TEST_CASE_EQUAL(matrix1.dot(matrix7), 32.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::toCrossProductEquivalentMatrixTestInternal()
{
    // Setup

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1> matrix1(values1);

    // Test

    const Matrix<float, 3, 3> result1 =
                                       matrix1.toCrossProductEquivalentMatrix();
    const Matrix<float, 3, 3> result2 = matrix1.skew();

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::toCrossProductEquivalentMatrixTestExternal()
{
    // Setup

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    const Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    // Test

    const Matrix<float, 3, 3> result1 =
                                       matrix1.toCrossProductEquivalentMatrix();
    const Matrix<float, 3, 3> result2 = matrix1.skew();

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::toCrossProductEquivalentMatrixTestConstant()
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

    const Matrix<float, 3, 3> result1 =
                                       matrix1.toCrossProductEquivalentMatrix();
    const Matrix<float, 3, 3> result2 = matrix1.skew();

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::printTestInternal()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    Matrice::print("\n");
    matrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::printTestExternal()
{
    // Setup

    float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix(values);

    Matrice::print("\n");
    matrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::printTestConstant()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix(values);

    Matrice::print("\n");
    matrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::printTestInternalRunTime()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix(
                                                                        3,
                                                                        3,
                                                                        values);

    Matrice::print("\n");
    matrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::printTestExternalRunTime()
{
    // Setup

    float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix(3, 3, values);

    Matrice::print("\n");
    matrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::printTestConstantRunTime()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix(3, 3, values);

    Matrice::print("\n");
    matrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddScalarTestExternal()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix3(3,
                                                                    3,
                                                                    values3);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix3(matrix3, 1, 1);

    float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix4(3, 3, values4);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix4(matrix4, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + 1;
    const Matrix<float, 2, 2> result2 = submatrix2 + 1;
    const Matrix<float, 2, 2> result3 = submatrix3 + 1;
    const Matrix<float, 2, 2> result4 = submatrix4 + 1;

    const float expectedValues[2][2] =
    {
        { 6.0,  7.0 },
        { 9.0, 10.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddScalarTestConstant()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix3(matrix3, 1, 1);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(
                                                                       3,
                                                                       3,
                                                                       values4);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix4(matrix4, 1, 1);

    float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix5(3, 3, values5);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix5(matrix5, 1, 1);

    float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(3, 3, values6);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix6(matrix6, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + 1;
    const Matrix<float, 2, 2> result2 = submatrix2 + 1;
    const Matrix<float, 2, 2> result3 = submatrix3 + 1;
    const Matrix<float, 2, 2> result4 = submatrix4 + 1;
    const Matrix<float, 2, 2> result5 = submatrix5 + 1;
    const Matrix<float, 2, 2> result6 = submatrix6 + 1;

    const float expectedValues[2][2] =
    {
        { 6.0,  7.0 },
        { 9.0, 10.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix1(2, 2, matrix1, 1, 1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix2(2, 2, matrix2, 1, 1);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix3(3,
                                                                    3,
                                                                    values3);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix3(2, 2, matrix3, 1, 1);

    float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix4(3, 3, values4);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix4(2, 2, matrix4, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + 1;
    const Matrix<float, 2, 2> result2 = submatrix2 + 1;
    const Matrix<float, 2, 2> result3 = submatrix3 + 1;
    const Matrix<float, 2, 2> result4 = submatrix4 + 1;

    const float expectedValues[2][2] =
    {
        { 6.0,  7.0 },
        { 9.0, 10.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix1(2, 2, matrix1, 1, 1);

    float values2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix2(values2);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix2(2, 2, matrix2, 1, 1);

    const float values3[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3, STORAGE_CONSTANT> matrix3(values3);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix3(2, 2, matrix3, 1, 1);

    const float values4[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(
                                                                       3,
                                                                       3,
                                                                       values4);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix4(2, 2, matrix4, 1, 1);

    float values5[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix5(3, 3, values5);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix5(matrix5, 1, 1);

    const float values6[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(3, 3, values6);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix6(2, 2, matrix6, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + 1;
    const Matrix<float, 2, 2> result2 = submatrix2 + 1;
    const Matrix<float, 2, 2> result3 = submatrix3 + 1;
    const Matrix<float, 2, 2> result4 = submatrix4 + 1;
    const Matrix<float, 2, 2> result5 = submatrix5 + 1;
    const Matrix<float, 2, 2> result6 = submatrix6 + 1;

    const float expectedValues[2][2] =
    {
        { 6.0,  7.0 },
        { 9.0, 10.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix9(values9);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix3(matrix9, 1, 1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix4(2, 2, matrix10, 1, 1);

    const float values11[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix11(values11);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, 2, matrix11, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 + matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 + matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 + matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 + submatrix2;
    const Matrix<float, 2, 2> result6 = submatrix1 + submatrix3;
    const Matrix<float, 2, 2> result7 = submatrix1 + submatrix4;
    const Matrix<float, 2, 2> result8 = submatrix1 + submatrix5;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected) &
                            UNIT_TEST_CASE_EQUAL(result8, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix9(values9);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix3(matrix9, 1, 1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix4(2, 2, matrix10, 1, 1);

    const float values11[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix11(values11);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, 2, matrix11, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 + matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 + matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 + matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 + submatrix2;
    const Matrix<float, 2, 2> result6 = submatrix1 + submatrix3;
    const Matrix<float, 2, 2> result7 = submatrix1 + submatrix4;
    const Matrix<float, 2, 2> result8 = submatrix1 + submatrix5;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected) &
                            UNIT_TEST_CASE_EQUAL(result8, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddTestExternalRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix9(values9);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix3(matrix9, 1, 1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix4(2, 2, matrix10, 1, 1);

    const float values11[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix11(values11);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, 2, matrix11, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 + matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 + matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 + matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 + submatrix2;
    const Matrix<float, 2, 2> result6 = submatrix1 + submatrix3;
    const Matrix<float, 2, 2> result7 = submatrix1 + submatrix4;
    const Matrix<float, 2, 2> result8 = submatrix1 + submatrix5;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected) &
                            UNIT_TEST_CASE_EQUAL(result8, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddTestConstantRunTime()
{
    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 6.0 },
        { 8.0, 9.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix9(values9);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix3(matrix9, 1, 1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix4(2, 2, matrix10, 1, 1);

    const float values11[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix11(values11);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, 2, matrix11, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 + matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 + matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 + matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 + matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 + submatrix2;
    const Matrix<float, 2, 2> result6 = submatrix1 + submatrix3;
    const Matrix<float, 2, 2> result7 = submatrix1 + submatrix4;
    const Matrix<float, 2, 2> result8 = submatrix1 + submatrix5;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected) &
                            UNIT_TEST_CASE_EQUAL(result8, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddEqualsScalarTestExternal()
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

    submatrix += 1;

    const Matrix<float, 2, 2> result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

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

    const Matrix<float, 2, 2> expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected1) &
                            UNIT_TEST_CASE_EQUAL(result2, expected2));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    submatrix += 1;

    const Matrix<float, 2, 2> result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

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

    const Matrix<float, 2, 2> expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected1) &
                            UNIT_TEST_CASE_EQUAL(result2, expected2));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix5(values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix7(values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    submatrix1 += matrix2;
    const Matrix<float, 2, 2> result1 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix3;
    const Matrix<float, 2, 2> result2 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix4;
    const Matrix<float, 2, 2> result3 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix5;
    const Matrix<float, 2, 2> result4 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix6;
    const Matrix<float, 2, 2> result5 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix7;
    const Matrix<float, 2, 2> result6 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += submatrix2;
    const Matrix<float, 2, 2> result7 = submatrix1;

    const float expectedValues[2][2] =
    {
        { 10.0, 10.0 },
        { 10.0, 10.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorAddEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix1(2, 2, matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix5(values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix7(values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    submatrix1 += matrix2;
    const Matrix<float, 2, 2> result1 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix3;
    const Matrix<float, 2, 2> result2 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix4;
    const Matrix<float, 2, 2> result3 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix5;
    const Matrix<float, 2, 2> result4 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix6;
    const Matrix<float, 2, 2> result5 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += matrix7;
    const Matrix<float, 2, 2> result6 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 += submatrix2;
    const Matrix<float, 2, 2> result7 = submatrix1;

    const float expectedValues[2][2] =
    {
        { 10.0, 10.0 },
        { 10.0, 10.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorUnaryMinusTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = -submatrix;

    const float expectedValues[2][2] =
    {
        { -5.0, -6.0 },
        { -8.0, -9.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorUnaryMinusTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = -submatrix;

    const float expectedValues[2][2] =
    {
        { -5.0, -6.0 },
        { -8.0, -9.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorUnaryMinusTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = -submatrix;

    const float expectedValues[2][2] =
    {
        { -5.0, -6.0 },
        { -8.0, -9.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorUnaryMinusTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, 2, matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = -submatrix;

    const float expectedValues[2][2] =
    {
        { -5.0, -6.0 },
        { -8.0, -9.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractScalarTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix - 1;

    const float expectedValues[2][2] =
    {
        { 4.0, 5.0 },
        { 7.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractScalarTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix - 1;

    const float expectedValues[2][2] =
    {
        { 4.0, 5.0 },
        { 7.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix - 1;

    const float expectedValues[2][2] =
    {
        { 4.0, 5.0 },
        { 7.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, 2, matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix - 1;

    const float expectedValues[2][2] =
    {
        { 4.0, 5.0 },
        { 7.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 - matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 - matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 - matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 - matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 - matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 - matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 - submatrix2;

    const float expectedValues[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 - matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 - matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 - matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 - matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 - matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 - matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 - submatrix2;

    const float expectedValues[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix1(2, 2, matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 - matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 - matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 - matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 - matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 - matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 - matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 - submatrix2;

    const float expectedValues[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix1(2, 2, matrix1, 1, 1);
    
    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 - matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 - matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 - matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 - matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 - matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 - matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 - submatrix2;

    const float expectedValues[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractEqualsScalarTestExternal()
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

    submatrix -= 1;

    const Matrix<float, 2, 2> result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

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

    const Matrix<float, 2, 2> expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected1) &
                            UNIT_TEST_CASE_EQUAL(result2, expected2));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    submatrix -= 1;

    const Matrix<float, 2, 2> result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

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

    const Matrix<float, 2, 2> expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected1) &
                            UNIT_TEST_CASE_EQUAL(result2, expected2));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);
    
    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    submatrix1 -= matrix2;
    const Matrix<float, 2, 2> result1 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix3;
    const Matrix<float, 2, 2> result2 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix4;
    const Matrix<float, 2, 2> result3 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix5;
    const Matrix<float, 2, 2> result4 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix6;
    const Matrix<float, 2, 2> result5 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix7;
    const Matrix<float, 2, 2> result6 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= submatrix2;
    const Matrix<float, 2, 2> result7 = submatrix1;

    const float expectedValues[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorSubtractEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix1(2, 2, matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);
    
    const float values5[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix5(
                                                                       2,
                                                                       2,
                                                                       values5);

    float values6[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> matrix6(2, 2, values6);

    const float values7[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix7(2, 2, values7);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    submatrix1 -= matrix2;
    const Matrix<float, 2, 2> result1 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix3;
    const Matrix<float, 2, 2> result2 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix4;
    const Matrix<float, 2, 2> result3 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix5;
    const Matrix<float, 2, 2> result4 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix6;
    const Matrix<float, 2, 2> result5 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= matrix7;
    const Matrix<float, 2, 2> result6 = submatrix1;

    matrix1 = Matrix<float, 3, 3>(values1);

    submatrix1 -= submatrix2;
    const Matrix<float, 2, 2> result7 = submatrix1;

    const float expectedValues[2][2] =
    {
        { 0.0, 2.0 },
        { 6.0, 8.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyScalarTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix * 2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyScalarTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix * 2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix * 2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, 2, matrix, 1, 1);

    // Test

    const Matrix<float, 2, 2> result = submatrix * 2;

    const float expectedValues[2][2] =
    {
        { 10.0, 12.0 },
        { 16.0, 18.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ExternalTimes2By2()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix5(values5);

    float values6[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix7(values7);

    const float values8[3][3] =
    {
        { 1.0, 1.0, 1.0 },
        { 1.0, 4.0, 3.0 },
        { 1.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 * matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 * matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 * matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 * matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 * matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 * matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 * submatrix2;

    const float expectedValues[2][2] =
    {
        { 32.0, 21.0 },
        { 50.0, 33.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ConstantTimes2By2()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix5(values5);

    float values6[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix7(values7);

    const float values8[3][3] =
    {
        { 1.0, 1.0, 1.0 },
        { 1.0, 4.0, 3.0 },
        { 1.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 * matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 * matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 * matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 * matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 * matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 * matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 * submatrix2;

    const float expectedValues[2][2] =
    {
        { 32.0, 21.0 },
        { 50.0, 33.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ExternalRunTimeTimes2By2()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix1(2, 2, matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix5(values5);

    float values6[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix7(values7);

    const float values8[3][3] =
    {
        { 1.0, 1.0, 1.0 },
        { 1.0, 4.0, 3.0 },
        { 1.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 * matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 * matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 * matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 * matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 * matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 * matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 * submatrix2;

    const float expectedValues[2][2] =
    {
        { 32.0, 21.0 },
        { 50.0, 33.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ConstantRunTimeTimes2By2()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix1(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix1(2, 2, matrix1, 1, 1);

    // Items to test against

    const float values2[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix2(values2);

    float values3[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix3(values3);

    const float values4[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix4(values4);

    const float values5[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2> matrix5(values5);

    float values6[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> matrix6(values6);

    const float values7[2][2] =
    {
        { 4.0, 3.0 },
        { 2.0, 1.0 }
    };

    const Matrix<float, 2, 2, STORAGE_CONSTANT> matrix7(values7);

    const float values8[3][3] =
    {
        { 1.0, 1.0, 1.0 },
        { 1.0, 4.0, 3.0 },
        { 1.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix2(matrix8, 1, 1);

    // Test

    const Matrix<float, 2, 2> result1 = submatrix1 * matrix2;
    const Matrix<float, 2, 2> result2 = submatrix1 * matrix3;
    const Matrix<float, 2, 2> result3 = submatrix1 * matrix4;
    const Matrix<float, 2, 2> result4 = submatrix1 * matrix5;
    const Matrix<float, 2, 2> result5 = submatrix1 * matrix6;
    const Matrix<float, 2, 2> result6 = submatrix1 * matrix7;
    const Matrix<float, 2, 2> result7 = submatrix1 * submatrix2;

    const float expectedValues[2][2] =
    {
        { 32.0, 21.0 },
        { 50.0, 33.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected) &
                            UNIT_TEST_CASE_EQUAL(result3, expected) &
                            UNIT_TEST_CASE_EQUAL(result4, expected) &
                            UNIT_TEST_CASE_EQUAL(result5, expected) &
                            UNIT_TEST_CASE_EQUAL(result6, expected) &
                            UNIT_TEST_CASE_EQUAL(result7, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ExternalTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Items to test against

    const float values2[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2> vector1(values2);

    float values3[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_EXTERNAL> vector2(values3);

    const float values4[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values4);

    const float values5[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values5);

    float values6[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2,
                                                                       values6);

    const float values7[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values7);

    const float values8[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector7(values8);

    const Vector<float, 2, STORAGE_EXTERNAL> subvector1(vector7, 1);

    const float values9[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector8(values9);

    const Vector<float, 2, STORAGE_CONSTANT> subvector2(vector8, 1);

    const float values10[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector9(values10);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> subvector3(
                                                                        2,
                                                                        vector9,
                                                                        1);

    const float values11[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector10(values11);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> subvector4(
                                                                       2,
                                                                       vector10,
                                                                       1);

    // Test

    const Vector<float, 2> result1 = submatrix * vector1;
    const Vector<float, 2> result2 = submatrix * vector2;
    const Vector<float, 2> result3 = submatrix * vector3;
    const Vector<float, 2> result4 = submatrix * vector4;
    const Vector<float, 2> result5 = submatrix * vector5;
    const Vector<float, 2> result6 = submatrix * vector6;
    const Vector<float, 2> result7 = submatrix * subvector1;
    const Vector<float, 2> result8 = submatrix * subvector2;
    const Vector<float, 2> result9 = submatrix * subvector3;
    const Vector<float, 2> result10 = submatrix * subvector4;

    const float expectedValues[2] =
    {
        16.0,
        25.0
    };

    const Vector<float, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1,  expected) &
                            UNIT_TEST_CASE_EQUAL(result2,  expected) &
                            UNIT_TEST_CASE_EQUAL(result3,  expected) &
                            UNIT_TEST_CASE_EQUAL(result4,  expected) &
                            UNIT_TEST_CASE_EQUAL(result5,  expected) &
                            UNIT_TEST_CASE_EQUAL(result6,  expected) &
                            UNIT_TEST_CASE_EQUAL(result7,  expected) &
                            UNIT_TEST_CASE_EQUAL(result8,  expected) &
                            UNIT_TEST_CASE_EQUAL(result9,  expected) &
                            UNIT_TEST_CASE_EQUAL(result10, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ConstantTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values1);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Items to test against

    const float values2[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2> vector1(values2);

    float values3[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_EXTERNAL> vector2(values3);

    const float values4[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values4);

    const float values5[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values5);

    float values6[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values6);

    const float values7[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values7);

    const float values8[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector7(values8);

    const Vector<float, 2, STORAGE_EXTERNAL> subvector1(vector7, 1);

    const float values9[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector8(values9);

    const Vector<float, 2, STORAGE_CONSTANT> subvector2(vector8, 1);

    const float values10[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector9(values10);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> subvector3(
                                                                        2,
                                                                        vector9,
                                                                        1);

    const float values11[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector10(values11);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> subvector4(
                                                                       2,
                                                                       vector10,
                                                                       1);

    // Test

    const Vector<float, 2> result1 = submatrix * vector1;
    const Vector<float, 2> result2 = submatrix * vector2;
    const Vector<float, 2> result3 = submatrix * vector3;
    const Vector<float, 2> result4 = submatrix * vector4;
    const Vector<float, 2> result5 = submatrix * vector5;
    const Vector<float, 2> result6 = submatrix * vector6;
    const Vector<float, 2> result7 = submatrix * subvector1;
    const Vector<float, 2> result8 = submatrix * subvector2;
    const Vector<float, 2> result9 = submatrix * subvector3;
    const Vector<float, 2> result10 = submatrix * subvector4;

    const float expectedValues[2] =
    {
        16.0,
        25.0
    };

    const Vector<float, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1,  expected) &
                            UNIT_TEST_CASE_EQUAL(result2,  expected) &
                            UNIT_TEST_CASE_EQUAL(result3,  expected) &
                            UNIT_TEST_CASE_EQUAL(result4,  expected) &
                            UNIT_TEST_CASE_EQUAL(result5,  expected) &
                            UNIT_TEST_CASE_EQUAL(result6,  expected) &
                            UNIT_TEST_CASE_EQUAL(result7,  expected) &
                            UNIT_TEST_CASE_EQUAL(result8,  expected) &
                            UNIT_TEST_CASE_EQUAL(result9,  expected) &
                            UNIT_TEST_CASE_EQUAL(result10, expected));
}
//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ExternalRunTimeTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Items to test against

    const float values2[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2> vector1(values2);

    float values3[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_EXTERNAL> vector2(values3);

    const float values4[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values4);

    const float values5[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values5);

    float values6[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2,
                                                                       values6);

    const float values7[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values7);

    const float values8[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector7(values8);

    const Vector<float, 2, STORAGE_EXTERNAL> subvector1(vector7, 1);

    const float values9[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector8(values9);

    const Vector<float, 2, STORAGE_CONSTANT> subvector2(vector8, 1);

    const float values10[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector9(values10);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> subvector3(
                                                                        2,
                                                                        vector9,
                                                                        1);

    const float values11[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector10(values11);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> subvector4(
                                                                       2,
                                                                       vector10,
                                                                       1);

    // Test

    const Vector<float, 2> result1 = submatrix * vector1;
    const Vector<float, 2> result2 = submatrix * vector2;
    const Vector<float, 2> result3 = submatrix * vector3;
    const Vector<float, 2> result4 = submatrix * vector4;
    const Vector<float, 2> result5 = submatrix * vector5;
    const Vector<float, 2> result6 = submatrix * vector6;
    const Vector<float, 2> result7 = submatrix * subvector1;
    const Vector<float, 2> result8 = submatrix * subvector2;
    const Vector<float, 2> result9 = submatrix * subvector3;
    const Vector<float, 2> result10 = submatrix * subvector4;

    const float expectedValues[2] =
    {
        16.0,
        25.0
    };

    const Vector<float, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1,  expected) &
                            UNIT_TEST_CASE_EQUAL(result2,  expected) &
                            UNIT_TEST_CASE_EQUAL(result3,  expected) &
                            UNIT_TEST_CASE_EQUAL(result4,  expected) &
                            UNIT_TEST_CASE_EQUAL(result5,  expected) &
                            UNIT_TEST_CASE_EQUAL(result6,  expected) &
                            UNIT_TEST_CASE_EQUAL(result7,  expected) &
                            UNIT_TEST_CASE_EQUAL(result8,  expected) &
                            UNIT_TEST_CASE_EQUAL(result9,  expected) &
                            UNIT_TEST_CASE_EQUAL(result10, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTest2By2ConstantRunTimeTimesVector()
{
    // Setup / Operation

    // Item to test

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values1);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, 2, matrix, 1, 1);

    // Items to test against

    const float values2[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2> vector1(values2);

    float values3[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_EXTERNAL> vector2(values3);

    const float values4[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values4);

    const float values5[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values5);

    float values6[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2,
                                                                       values6);

    const float values7[2] =
    {
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values7);

    const float values8[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector7(values8);

    const Vector<float, 2, STORAGE_EXTERNAL> subvector1(vector7, 1);

    const float values9[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector8(values9);

    const Vector<float, 2, STORAGE_CONSTANT> subvector2(vector8, 1);

    const float values10[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector9(values10);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> subvector3(
                                                                        2,
                                                                        vector9,
                                                                        1);

    const float values11[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector10(values11);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> subvector4(
                                                                       2,
                                                                       vector10,
                                                                       1);

    // Test

    const Vector<float, 2> result1 = submatrix * vector1;
    const Vector<float, 2> result2 = submatrix * vector2;
    const Vector<float, 2> result3 = submatrix * vector3;
    const Vector<float, 2> result4 = submatrix * vector4;
    const Vector<float, 2> result5 = submatrix * vector5;
    const Vector<float, 2> result6 = submatrix * vector6;
    const Vector<float, 2> result7 = submatrix * subvector1;
    const Vector<float, 2> result8 = submatrix * subvector2;
    const Vector<float, 2> result9 = submatrix * subvector3;
    const Vector<float, 2> result10 = submatrix * subvector4;

    const float expectedValues[2] =
    {
        16.0,
        25.0
    };

    const Vector<float, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1,  expected) &
                            UNIT_TEST_CASE_EQUAL(result2,  expected) &
                            UNIT_TEST_CASE_EQUAL(result3,  expected) &
                            UNIT_TEST_CASE_EQUAL(result4,  expected) &
                            UNIT_TEST_CASE_EQUAL(result5,  expected) &
                            UNIT_TEST_CASE_EQUAL(result6,  expected) &
                            UNIT_TEST_CASE_EQUAL(result7,  expected) &
                            UNIT_TEST_CASE_EQUAL(result8,  expected) &
                            UNIT_TEST_CASE_EQUAL(result9,  expected) &
                            UNIT_TEST_CASE_EQUAL(result10, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTestEqualsScalarExternal()
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

    submatrix *= 2;

    const Matrix<float, 2, 2> result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

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

    const Matrix<float, 2, 2> expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected1) &
                            UNIT_TEST_CASE_EQUAL(result2, expected2));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixOperatorMultiplyTestEqualsScalarExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    submatrix *= 2;

    const Matrix<float, 2, 2> result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

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

    const Matrix<float, 2, 2> expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected1) &
                            UNIT_TEST_CASE_EQUAL(result2, expected2));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixGetValueTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    return UNIT_TEST_REPORT(
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 0), 5.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 1), 6.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 0), 8.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 1), 9.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixGetValueTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    return UNIT_TEST_REPORT(
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 0), 5.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 1), 6.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 0), 8.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 1), 9.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixGetValueTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    return UNIT_TEST_REPORT(
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 0), 5.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 1), 6.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 0), 8.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 1), 9.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixGetValueTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, 2, matrix, 1, 1);

    // Test

    return UNIT_TEST_REPORT(
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 0), 5.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(0, 1), 6.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 0), 8.0f) &
                          UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 1), 9.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixSetValueTestExternal()
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

    submatrix.setValue(1, 0, 10.0f);

    return UNIT_TEST_REPORT(
                         UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 0), 10.0f) &
                         UNIT_TEST_CASE_EQUAL(matrix.getValue(2, 1),    10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixSetValueTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    // Test

    submatrix.setValue(1, 0, 10.0f);

    return UNIT_TEST_REPORT(
                         UNIT_TEST_CASE_EQUAL(submatrix.getValue(1, 0), 10.0f) &
                         UNIT_TEST_CASE_EQUAL(matrix.getValue(2, 1),    10.0f));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixTransposeTestExternal()
{
    // Setup / Operation

    const float values[3][6] =
    {
        { 0.0, 0.0, 0.0, 1.0, 2.0, 3.0 },
        { 0.0, 0.0, 0.0, 4.0, 5.0, 6.0 },
        { 0.0, 0.0, 0.0, 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 6> matrix(values);

    const Matrix<float, 3, 3, STORAGE_EXTERNAL> submatrix(matrix, 0, 3);

    // Test

    const Matrix<float, 3, 3> result1 = submatrix.transpose();
    const Matrix<float, 3, 3> result2 = submatrix.T();

    const float expectedValues[3][3] =
    {
        { 1.0, 4.0, 7.0 },
        { 2.0, 5.0, 8.0 },
        { 3.0, 6.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixTransposeTestConstant()
{
    // Setup / Operation

    const float values[3][6] =
    {
        { 0.0, 0.0, 0.0, 1.0, 2.0, 3.0 },
        { 0.0, 0.0, 0.0, 4.0, 5.0, 6.0 },
        { 0.0, 0.0, 0.0, 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 6> matrix(values);
    const Matrix<float, 3, 3, STORAGE_CONSTANT> submatrix(matrix, 0, 3);

    // Test

    const Matrix<float, 3, 3> result1 = submatrix.transpose();
    const Matrix<float, 3, 3> result2 = submatrix.T();

    const float expectedValues[3][3] =
    {
        { 1.0, 4.0, 7.0 },
        { 2.0, 5.0, 8.0 },
        { 3.0, 6.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixTransposeTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][6] =
    {
        { 0.0, 0.0, 0.0, 1.0, 2.0, 3.0 },
        { 0.0, 0.0, 0.0, 4.0, 5.0, 6.0 },
        { 0.0, 0.0, 0.0, 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 6> matrix(values);
    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(3, 3, matrix, 0, 3);

    // Test

    const float expectedValues[3][3] =
    {
        { 1.0, 4.0, 7.0 },
        { 2.0, 5.0, 8.0 },
        { 3.0, 6.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(
                         UNIT_TEST_CASE_EQUAL(submatrix.transpose(), expected) &
                         UNIT_TEST_CASE_EQUAL(submatrix.T(),         expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixTransposeTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][6] =
    {
        { 0.0, 0.0, 0.0, 1.0, 2.0, 3.0 },
        { 0.0, 0.0, 0.0, 4.0, 5.0, 6.0 },
        { 0.0, 0.0, 0.0, 7.0, 8.0, 9.0 }
    };

    const Matrix<float, 3, 6> matrix(values);
    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(3, 3, matrix, 0, 3);

    // Test

    const float expectedValues[3][3] =
    {
        { 1.0, 4.0, 7.0 },
        { 2.0, 5.0, 8.0 },
        { 3.0, 6.0, 9.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    return UNIT_TEST_REPORT(
                         UNIT_TEST_CASE_EQUAL(submatrix.transpose(), expected) &
                         UNIT_TEST_CASE_EQUAL(submatrix.T(),         expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixPrintTestExternal()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixPrintTestConstant()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float, 2, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixPrintTestExternalRunTime()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(2, 2, matrix, 1, 1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::submatrixPrintTestConstantRunTime()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    const Matrix<float, 3, 3> matrix(values);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, 2, matrix, 1, 1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool MatrixTest::nestedSubmatrixOperatorEqualsTestExternal()
{
    // Setup / Operation

    const float values[5][5] =
    {
        { 1.0, 2.0, 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0, 9.0, 8.0 },
        { 7.0, 6.0, 5.0, 4.0, 3.0 },
        { 2.0, 1.0, 2.0, 3.0, 4.0 },
        { 5.0, 6.0, 7.0, 8.0, 9.0 }
    };

    Matrix<float, 5, 5> matrix(values);

    Matrix<float, 4, 4, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    const Matrix<float, 2, 2, STORAGE_EXTERNAL> nestedSubmatrix(submatrix,
                                                                1,
                                                                1);

    // Test

    const float expectedValues[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 3.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(nestedSubmatrix, expected));
}

//------------------------------------------------------------------------------
bool MatrixTest::nestedSubmatrixOperatorEqualsTestExternalRunTime()
{
    // Setup / Operation

    const float values[5][5] =
    {
        { 1.0, 2.0, 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0, 9.0, 8.0 },
        { 7.0, 6.0, 5.0, 4.0, 3.0 },
        { 2.0, 1.0, 2.0, 3.0, 4.0 },
        { 5.0, 6.0, 7.0, 8.0, 9.0 }
    };

    Matrix<float, 5, 5> matrix(values);

    Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_EXTERNAL> submatrix(4, 4, matrix, 1, 1);

    const Matrix<float,
                DIMENSIONS_RUN_TIME,
                DIMENSIONS_RUN_TIME,
                STORAGE_EXTERNAL> nestedSubmatrix(2, 2, submatrix, 1, 1);

    // Test
    
    const float expectedValues[2][2] =
    {
        { 5.0, 4.0 },
        { 2.0, 3.0 }
    };

    const Matrix<float, 2, 2> expected(expectedValues);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(nestedSubmatrix, expected));
}
