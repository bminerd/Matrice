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
#include <Matrice/Matrix.h>

using Matrice::VectorTest;
using Plat4m::UnitTest;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

const UnitTest::TestCallbackFunction VectorTest::myTestCallbackFunctions[] =
{
    &VectorTest::operatorValueTypeCastTestInternal,
    &VectorTest::operatorValueTypeCastTestExternal,
    &VectorTest::operatorValueTypeCastTestConstant,
    &VectorTest::operatorValueTypeCastTest2Internal,
    &VectorTest::operatorValueTypeCastTest2External,
    &VectorTest::operatorValueTypeCastTest2Constant,
    &VectorTest::operatorValueTypeCastTest2InternalRunTime,
    &VectorTest::operatorValueTypeCastTest2ExternalRunTime,
    &VectorTest::operatorValueTypeCastTest2ConstantRunTime,
    &VectorTest::operatorAssignmentTestInternal,
    &VectorTest::operatorAssignmentTestExternal,
    &VectorTest::operatorAssignmentTestConstant,
    &VectorTest::operatorAssignmentTestInternalRunTime,
    &VectorTest::operatorAssignmentTestExternalRunTime,
    &VectorTest::operatorAssignmentTestConstantRunTime,
    &VectorTest::operatorAssignmentTest2Internal,
    &VectorTest::operatorAssignmentTest2External,
    &VectorTest::operatorAssignmentTest2Constant,
    &VectorTest::operatorAssignmentTest2InternalRunTime,
    &VectorTest::operatorAssignmentTest2ExternalRunTime,
    &VectorTest::operatorAssignmentTest2ConstantRunTime,
    &VectorTest::operatorEqualsTestInternal,
    &VectorTest::operatorEqualsTestExternal,
    &VectorTest::operatorEqualsTestConstant,
    &VectorTest::operatorEqualsTestInternalRunTime,
    &VectorTest::operatorEqualsTestExternalRunTime,
    &VectorTest::operatorEqualsTestConstantRunTime,
    &VectorTest::operatorEqualsTest2Internal,
    &VectorTest::operatorEqualsTest2External,
    &VectorTest::operatorEqualsTest2Constant,
    &VectorTest::operatorEqualsTest2InternalRunTime,
    &VectorTest::operatorEqualsTest2ExternalRunTime,
    &VectorTest::operatorEqualsTest2ConstantRunTime,
    &VectorTest::operatorParenthesesTestInternal,
    &VectorTest::operatorParenthesesTestExternal,
    &VectorTest::operatorParenthesesTestConstant,
    &VectorTest::operatorParenthesesTestInternalRunTime,
    &VectorTest::operatorParenthesesTestExternalRunTime,
    &VectorTest::operatorParenthesesTestConstantRunTime,
    &VectorTest::operatorParenthesesTest2Internal,
    &VectorTest::operatorParenthesesTest2External,
    &VectorTest::operatorParenthesesTest2InternalRunTime,
    &VectorTest::operatorParenthesesTest2ExternalRunTime,
    &VectorTest::operatorAddScalarTestInternal,
    &VectorTest::operatorAddScalarTestExternal,
    &VectorTest::operatorAddScalarTestConstant,
    &VectorTest::operatorAddScalarTestInternalRunTime,
    &VectorTest::operatorAddScalarTestExternalRunTime,
    &VectorTest::operatorAddScalarTestConstantRunTime,
    &VectorTest::operatorAddTestInternal,
    &VectorTest::operatorAddTestExternal,
    &VectorTest::operatorAddTestConstant,
    &VectorTest::operatorAddTestInternalRunTime,
    &VectorTest::operatorAddTestExternalRunTime,
    &VectorTest::operatorAddTestConstantRunTime,
    &VectorTest::operatorAddEqualsScalarTestInternal,
    &VectorTest::operatorAddEqualsScalarTestExternal,
    &VectorTest::operatorAddEqualsScalarTestInternalRunTime,
    &VectorTest::operatorAddEqualsScalarTestExternalRunTime,
    &VectorTest::operatorAddEqualsTestInternal,
    &VectorTest::operatorAddEqualsTestExternal,
    &VectorTest::operatorAddEqualsTestInternalRunTime,
    &VectorTest::operatorAddEqualsTestExternalRunTime,
    &VectorTest::operatorUnaryMinusTestInternal,
    &VectorTest::operatorUnaryMinusTestExternal,
    &VectorTest::operatorUnaryMinusTestConstant,
    &VectorTest::operatorUnaryMinusTestInternalRunTime,
    &VectorTest::operatorUnaryMinusTestExternalRunTime,
    &VectorTest::operatorUnaryMinusTestConstantRunTime,
    &VectorTest::operatorSubtractScalarTestInternal,
    &VectorTest::operatorSubtractScalarTestExternal,
    &VectorTest::operatorSubtractScalarTestConstant,
    &VectorTest::operatorSubtractScalarTestInternalRunTime,
    &VectorTest::operatorSubtractScalarTestExternalRunTime,
    &VectorTest::operatorSubtractScalarTestConstantRunTime,
    &VectorTest::operatorSubtractTestInternal,
    &VectorTest::operatorSubtractTestExternal,
    &VectorTest::operatorSubtractTestConstant,
    &VectorTest::operatorSubtractTestInternalRunTime,
    &VectorTest::operatorSubtractTestExternalRunTime,
    &VectorTest::operatorSubtractTestConstantRunTime,
    &VectorTest::operatorSubtractEqualsTestScalarInternal,
    &VectorTest::operatorSubtractEqualsTestScalarExternal,
    &VectorTest::operatorSubtractEqualsTestScalarInternalRunTime,
    &VectorTest::operatorSubtractEqualsTestScalarExternalRunTime,
    &VectorTest::operatorSubtractEqualsTestInternal,
    &VectorTest::operatorSubtractEqualsTestExternal,
    &VectorTest::operatorSubtractEqualsTestInternalRunTime,
    &VectorTest::operatorSubtractEqualsTestExternalRunTime,
    &VectorTest::operatorMultiplyScalarTestInternal,
    &VectorTest::operatorMultiplyScalarTestExternal,
    &VectorTest::operatorMultiplyScalarTestConstant,
    &VectorTest::operatorMultiplyScalarTestInternalRunTime,
    &VectorTest::operatorMultiplyScalarTestExternalRunTime,
    &VectorTest::operatorMultiplyScalarTestConstantRunTime,
    &VectorTest::operatorMultiplyTestInternal,
    &VectorTest::operatorMultiplyTestExternal,
    &VectorTest::operatorMultiplyTestConstant,
    &VectorTest::operatorMultiplyTestInternalRunTime,
    &VectorTest::operatorMultiplyTestExternalRunTime,
    &VectorTest::operatorMultiplyTestConstantRunTime,
    &VectorTest::operatorMultiplyEqualsTestScalarInternal,
    &VectorTest::operatorMultiplyEqualsTestScalarExternal,
    &VectorTest::operatorMultiplyEqualsTestScalarInternalRunTime,
    &VectorTest::operatorMultiplyEqualsTestScalarExternalRunTime,
    &VectorTest::getValueTestInternal,
    &VectorTest::getValueTestExternal,
    &VectorTest::getValueTestConstant,
    &VectorTest::getValueTestInternalRunTime,
    &VectorTest::getValueTestExternalRunTime,
    &VectorTest::getValueTestConstantRunTime,
    &VectorTest::getValueTest2Internal,
    &VectorTest::getValueTest2External,
    &VectorTest::getValueTest2InternalRunTime,
    &VectorTest::getValueTest2ExternalRunTime,
    &VectorTest::setValueTestInternal,
    &VectorTest::setValueTestExternal,
    &VectorTest::setValueTestInternalRunTime,
    &VectorTest::setValueTestExternalRunTime,
    &VectorTest::setValuesTestInternal,
    &VectorTest::setValuesTestExternal,
    &VectorTest::setValuesTestInternalRunTime,
    &VectorTest::setValuesTestExternalRunTime,
    &VectorTest::transposeTestInternal,
    &VectorTest::transposeTestExternal,
    &VectorTest::transposeTestConstant,
    &VectorTest::transposeTestInternalRunTime,
    &VectorTest::transposeTestExternalRunTime,
    &VectorTest::transposeTestConstantRunTime,
    &VectorTest::magnitudeTestInternal,
    &VectorTest::magnitudeTestExternal,
    &VectorTest::magnitudeTestConstant,
    &VectorTest::magnitudeTestInternalRunTime,
    &VectorTest::magnitudeTestExternalRunTime,
    &VectorTest::magnitudeTestConstantRunTime,
    &VectorTest::crossProductTestInternal,
    &VectorTest::crossProductTestExternal,
    &VectorTest::crossProductTestConstant,
    &VectorTest::dotProductTestInternal,
    &VectorTest::dotProductTestExternal,
    &VectorTest::dotProductTestConstant,
    &VectorTest::toCrossProductEquivalentMatrixTestInternal,
    &VectorTest::toCrossProductEquivalentMatrixTestExternal,
    &VectorTest::toCrossProductEquivalentMatrixTestConstant,
    &VectorTest::printTestInternal,
    &VectorTest::printTestExternal,
    &VectorTest::printTestConstant,
    &VectorTest::printTestInternalRunTime,
    &VectorTest::printTestExternalRunTime,
    &VectorTest::printTestConstantRunTime,
    &VectorTest::submatrixOperatorAddScalarTestExternal,
    &VectorTest::submatrixOperatorAddScalarTestConstant,
    &VectorTest::submatrixOperatorAddScalarTestExternalRunTime,
    &VectorTest::submatrixOperatorAddScalarTestConstantRunTime,
    &VectorTest::submatrixOperatorAddTestExternal,
    &VectorTest::submatrixOperatorAddTestConstant,
    &VectorTest::submatrixOperatorAddTestExternalRunTime,
    &VectorTest::submatrixOperatorAddTestConstantRunTime,
    &VectorTest::submatrixOperatorAddEqualsScalarTestExternal,
    &VectorTest::submatrixOperatorAddEqualsScalarTestExternalRunTime,
    &VectorTest::submatrixOperatorAddEqualsTestExternal,
    &VectorTest::submatrixOperatorAddEqualsTestExternalRunTime,
    &VectorTest::submatrixOperatorUnaryMinusTestExternal,
    &VectorTest::submatrixOperatorUnaryMinusTestConstant,
    &VectorTest::submatrixOperatorUnaryMinusTestExternalRunTime,
    &VectorTest::submatrixOperatorUnaryMinusTestConstantRunTime,
    &VectorTest::submatrixOperatorSubtractScalarTestExternal,
    &VectorTest::submatrixOperatorSubtractScalarTestConstant,
    &VectorTest::submatrixOperatorSubtractScalarTestExternalRunTime,
    &VectorTest::submatrixOperatorSubtractScalarTestConstantRunTime,
    &VectorTest::submatrixOperatorSubtractTestExternal,
    &VectorTest::submatrixOperatorSubtractTestConstant,
    &VectorTest::submatrixOperatorSubtractTestExternalRunTime,
    &VectorTest::submatrixOperatorSubtractTestConstantRunTime,
    &VectorTest::submatrixOperatorSubtractEqualsScalarTestExternal,
    &VectorTest::submatrixOperatorSubtractEqualsScalarTestExternalRunTime,
    &VectorTest::submatrixOperatorSubtractEqualsTestExternal,
    &VectorTest::submatrixOperatorSubtractEqualsTestExternalRunTime,
    &VectorTest::submatrixOperatorMultiplyScalarTestExternal,
    &VectorTest::submatrixOperatorMultiplyScalarTestConstant,
    &VectorTest::submatrixOperatorMultiplyScalarTestExternalRunTime,
    &VectorTest::submatrixOperatorMultiplyScalarTestConstantRunTime,
    &VectorTest::submatrixOperatorMultiplyTestExternal,
    &VectorTest::submatrixOperatorMultiplyTestConstant,
    &VectorTest::submatrixOperatorMultiplyTestExternalRunTime,
    &VectorTest::submatrixOperatorMultiplyTestConstantRunTime,
    &VectorTest::submatrixOperatorMultiplyEqualsTestScalarExternal,
    &VectorTest::submatrixOperatorMultiplyEqualsTestScalarExternalRunTime,
    &VectorTest::submatrixGetValueTestExternal,
    &VectorTest::submatrixGetValueTestConstant,
    &VectorTest::submatrixGetValueTestExternalRunTime,
    &VectorTest::submatrixGetValueTestConstantRunTime,
    &VectorTest::submatrixSetValueTestExternal,
    &VectorTest::submatrixSetValueTestExternalRunTime,
    &VectorTest::submatrixTransposeTestExternal,
    &VectorTest::submatrixTransposeTestConstant,
    &VectorTest::submatrixTransposeTestExternalRunTime,
    &VectorTest::submatrixTransposeTestConstantRunTime,
    &VectorTest::submatrixPrintTestExternal,
    &VectorTest::submatrixPrintTestConstant,
    &VectorTest::submatrixPrintTestExternalRunTime,
    &VectorTest::submatrixPrintTestConstantRunTime,
    &VectorTest::nestedSubmatrixOperatorEqualsTestExternal,
    &VectorTest::nestedSubmatrixOperatorEqualsTestConstant,
    &VectorTest::nestedSubmatrixOperatorEqualsTestExternalRunTime,
    &VectorTest::nestedSubmatrixOperatorEqualsTestConstantRunTime,
    &VectorTest::subvectorOperatorEqualsTestExternal,
    &VectorTest::subvectorOperatorEqualsTestConstant,
    &VectorTest::subvectorOperatorEqualsTestExternalRunTime,
    &VectorTest::subvectorOperatorEqualsTestConstantRunTime
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
bool VectorTest::operatorValueTypeCastTestInternal()
{
    // Setup / Operation

    const float values[1] =
    {
        1.0
    };

    Vector<float, 1> vector(values);

    // Test
    
    const float result = vector;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTestExternal()
{
    // Setup / Operation

    float values[1] =
    {
        1.0
    };

    Vector<float, 1, STORAGE_EXTERNAL> vector(values);

    // Test
    
    float result = vector;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTestConstant()
{
    // Setup / Operation

    const float values[1] =
    {
        1.0
    };

    const Vector<float, 1, STORAGE_CONSTANT> vector(values);

    // Test
    
    float result = vector;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTest2Internal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test
    
    const Vector<double, 3> result1 = static_cast<Vector<double, 3>>(vector);

    double resultValues[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<double, 3, STORAGE_EXTERNAL> result2(resultValues);
    result2 = static_cast<Vector<double, 3>>(vector);

    const double expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<double, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTest2External()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test
    
    const Vector<double, 3> result1 = static_cast<Vector<double, 3>>(vector);

    double resultValues[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<double, 3, STORAGE_EXTERNAL> result2(resultValues);
    result2 = static_cast<Vector<double, 3>>(vector);

    const double expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<double, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTest2Constant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test
    
    const Vector<double, 3> result1 = static_cast<Vector<double, 3>>(vector);

    double resultValues[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<double, 3, STORAGE_EXTERNAL> result2(resultValues);
    result2 = static_cast<Vector<double, 3>>(vector);

    const double expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<double, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTest2InternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test
    
    const Vector<double, 3> result1 = static_cast<Vector<double, 3>>(vector);

    double resultValues[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<double, 3, STORAGE_EXTERNAL> result2(resultValues);
    result2 = static_cast<Vector<double, 3>>(vector);

    const double expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<double, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTest2ExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test
    
    const Vector<double, 3> result1 = static_cast<Vector<double, 3>>(vector);

    double resultValues[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<double, 3, STORAGE_EXTERNAL> result2(resultValues);
    result2 = static_cast<Vector<double, 3>>(vector);

    const double expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<double, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastTest2ConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3, values);

    // Test
    
    Vector<double, 3> result1 = static_cast<Vector<double, 3>>(vector);

    double resultValues[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<double, 3, STORAGE_EXTERNAL> result2(resultValues);
    result2 = static_cast<Vector<double, 3>>(vector);

    const double expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<double, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3, values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    Vector<float, 3> result1;
    result1 = vector1;

    Vector<float, 3> result2;
    result2 = vector2;

    Vector<float, 3> result3;
    result3 = vector3;

    Vector<float, 3> result4;
    result4 = vector4;

    Vector<float, 3> result5;
    result5 = vector5;

    Vector<float, 3> result6;
    result6 = vector6;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTestExternal()
{
    // Setup / Operation

    // Items to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3, values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    Vector<float, 3> result1;
    result1 = vector1;

    Vector<float, 3> result2;
    result2 = vector2;

    Vector<float, 3> result3;
    result3 = vector3;

    Vector<float, 3> result4;
    result4 = vector4;

    Vector<float, 3> result5;
    result5 = vector5;

    Vector<float, 3> result6;
    result6 = vector6;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTestConstant()
{
    // Setup / Operation

    // Items to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3, values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    Vector<float, 3> result1;
    result1 = vector1;

    Vector<float, 3> result2;
    result2 = vector2;

    Vector<float, 3> result3;
    result3 = vector3;

    Vector<float, 3> result4;
    result4 = vector4;

    Vector<float, 3> result5;
    result5 = vector5;

    Vector<float, 3> result6;
    result6 = vector6;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3, values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    Vector<float, 3> result1;
    result1 = vector1;

    Vector<float, 3> result2;
    result2 = vector2;

    Vector<float, 3> result3;
    result3 = vector3;

    Vector<float, 3> result4;
    result4 = vector4;

    Vector<float, 3> result5;
    result5 = vector5;

    Vector<float, 3> result6;
    result6 = vector6;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTestExternalRunTime()
{
    // Setup / Operation

    // Items to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3, values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    Vector<float, 3> result1;
    result1 = vector1;

    Vector<float, 3> result2;
    result2 = vector2;

    Vector<float, 3> result3;
    result3 = vector3;

    Vector<float, 3> result4;
    result4 = vector4;

    Vector<float, 3> result5;
    result5 = vector5;

    Vector<float, 3> result6;
    result6 = vector6;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTestConstantRunTime()
{
    // Setup / Operation

    // Items to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(3, values4);

    float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(3, values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(3,
                                                                       values6);

    // Test

    Vector<float, 3> result1;
    result1 = vector1;

    Vector<float, 3> result2;
    result2 = vector2;

    Vector<float, 3> result3;
    result3 = vector3;

    Vector<float, 3> result4;
    result4 = vector4;

    Vector<float, 3> result5;
    result5 = vector5;

    Vector<float, 3> result6;
    result6 = vector6;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTest2Internal()
{
    // Setup / Operation

    Vector<float, 3> vector;

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector = values;
    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTest2External()
{
    // Setup / Operation

    float values1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values1);

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector = values2;
    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTest2Constant()
{
    // Setup / Operation

    const float values1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_CONSTANT> vector(values1);

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };


    // Test

    vector = values;
    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTest2InternalRunTime()
{
    // Setup / Operation

    Vector<float, DIMENSIONS_RUN_TIME> vector(3);

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector = values;
    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTest2ExternalRunTime()
{
    // Setup / Operation

    float values1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values1);

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector = values2;
    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentTest2ConstantRunTime()
{
    // Setup / Operation

    const float values1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3, values1);

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };


    // Test

    vector = values;
    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true) &
                            UNIT_TEST_CASE_EQUAL(result2, true) &
                            UNIT_TEST_CASE_EQUAL(result3, true) &
                            UNIT_TEST_CASE_EQUAL(result4, true) &
                            UNIT_TEST_CASE_EQUAL(result5, true) &
                            UNIT_TEST_CASE_EQUAL(result6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true) &
                            UNIT_TEST_CASE_EQUAL(result2, true) &
                            UNIT_TEST_CASE_EQUAL(result3, true) &
                            UNIT_TEST_CASE_EQUAL(result4, true) &
                            UNIT_TEST_CASE_EQUAL(result5, true) &
                            UNIT_TEST_CASE_EQUAL(result6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true) &
                            UNIT_TEST_CASE_EQUAL(result2, true) &
                            UNIT_TEST_CASE_EQUAL(result3, true) &
                            UNIT_TEST_CASE_EQUAL(result4, true) &
                            UNIT_TEST_CASE_EQUAL(result5, true) &
                            UNIT_TEST_CASE_EQUAL(result6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true) &
                            UNIT_TEST_CASE_EQUAL(result2, true) &
                            UNIT_TEST_CASE_EQUAL(result3, true) &
                            UNIT_TEST_CASE_EQUAL(result4, true) &
                            UNIT_TEST_CASE_EQUAL(result5, true) &
                            UNIT_TEST_CASE_EQUAL(result6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true) &
                            UNIT_TEST_CASE_EQUAL(result2, true) &
                            UNIT_TEST_CASE_EQUAL(result3, true) &
                            UNIT_TEST_CASE_EQUAL(result4, true) &
                            UNIT_TEST_CASE_EQUAL(result5, true) &
                            UNIT_TEST_CASE_EQUAL(result6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true)  &
                            UNIT_TEST_CASE_EQUAL(result2, true) &
                            UNIT_TEST_CASE_EQUAL(result3, true)  &
                            UNIT_TEST_CASE_EQUAL(result4, true) &
                            UNIT_TEST_CASE_EQUAL(result5, true)  &
                            UNIT_TEST_CASE_EQUAL(result6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTest2Internal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, false) &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, false) &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, false) &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTest2External()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, false) &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, false) &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, false) &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTest2Constant()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, false) &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, false) &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, false) &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTest2InternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, false) &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, false) &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, false) &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTest2ExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, false) &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, false) &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, false) &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsTest2ConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);


    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, false) &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, false) &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, false) &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3,
                                                                      values);

    // Test

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTest2Internal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    vector(2) = 4.0;

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTest2External()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    vector(2) = 4.0;

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTest2InternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    vector(2) = 4.0;

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesTest2ExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    vector(2) = 4.0;

    const float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    Vector<float, 3> result = vector + 1;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    Vector<float, 3> result = vector + 1;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    Vector<float, 3> result = vector + 1;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    Vector<float, 3> result = vector + 1;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    Vector<float, 3> result = vector + 1;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3,
                                                                      values);

    // Test

    Vector<float, 3> result = vector + 1;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 + vector2;
    const Vector<float, 3> result2 = vector1 + vector3;
    const Vector<float, 3> result3 = vector1 + vector4;
    const Vector<float, 3> result4 = vector1 + vector5;
    const Vector<float, 3> result5 = vector1 + vector6;
    const Vector<float, 3> result6 = vector1 + vector7;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 + vector2;
    const Vector<float, 3> result2 = vector1 + vector3;
    const Vector<float, 3> result3 = vector1 + vector4;
    const Vector<float, 3> result4 = vector1 + vector5;
    const Vector<float, 3> result5 = vector1 + vector6;
    const Vector<float, 3> result6 = vector1 + vector7;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 + vector2;
    const Vector<float, 3> result2 = vector1 + vector3;
    const Vector<float, 3> result3 = vector1 + vector4;
    const Vector<float, 3> result4 = vector1 + vector5;
    const Vector<float, 3> result5 = vector1 + vector6;
    const Vector<float, 3> result6 = vector1 + vector7;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector1(3, values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 + vector2;
    const Vector<float, 3> result2 = vector1 + vector3;
    const Vector<float, 3> result3 = vector1 + vector4;
    const Vector<float, 3> result4 = vector1 + vector5;
    const Vector<float, 3> result5 = vector1 + vector6;
    const Vector<float, 3> result6 = vector1 + vector7;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector1(3, values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 + vector2;
    const Vector<float, 3> result2 = vector1 + vector3;
    const Vector<float, 3> result3 = vector1 + vector4;
    const Vector<float, 3> result4 = vector1 + vector5;
    const Vector<float, 3> result5 = vector1 + vector6;
    const Vector<float, 3> result6 = vector1 + vector7;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector1(3, values1);

    // Items to test against

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 + vector2;
    const Vector<float, 3> result2 = vector1 + vector3;
    const Vector<float, 3> result3 = vector1 + vector4;
    const Vector<float, 3> result4 = vector1 + vector5;
    const Vector<float, 3> result5 = vector1 + vector6;
    const Vector<float, 3> result6 = vector1 + vector7;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsScalarTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    vector += 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsScalarTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    vector += 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    vector += 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    vector += 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 += vector2;
    const Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector3;
    const Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector4;
    const Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector5;
    const Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector6;
    const Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector7;
    const Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        4.0,
        4.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 += vector2;
    const Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector3;
    const Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector4;
    const Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector5;
    const Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector6;
    const Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector7;
    const Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        4.0,
        4.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 += vector2;
    const Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector3;
    const Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector4;
    const Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector5;
    const Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector6;
    const Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += vector7;
    const Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        4.0,
        4.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 += vector2;
    const Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector3;
    const Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector4;
    const Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector5;
    const Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector6;
    const Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += vector7;
    const Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        4.0,
        4.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorUnaryMinusTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const Vector<float, 3> result = - vector;

    const float expectedValues[3] =
    {
         1.0,
        -2.0,
         3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorUnaryMinusTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const Vector<float, 3> result = - vector;

    const float expectedValues[3] =
    {
         1.0,
        -2.0,
         3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorUnaryMinusTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const Vector<float, 3> result = - vector;

    const float expectedValues[3] =
    {
         1.0,
        -2.0,
         3.0
    };

    Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorUnaryMinusTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const Vector<float, 3> result = - vector;

    const float expectedValues[3] =
    {
         1.0,
        -2.0,
         3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorUnaryMinusTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const Vector<float, 3> result = - vector;

    const float expectedValues[3] =
    {
         1.0,
        -2.0,
         3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorUnaryMinusTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        -1.0,
         2.0,
        -3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const Vector<float, 3> result = - vector;

    const float expectedValues[3] =
    {
         1.0,
        -2.0,
         3.0
    };

    Vector<float, 3> expected(expectedValues);
    
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    const Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    const Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3,
                                                                      values);

    // Test

    const Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 - vector2;
    const Vector<float, 3> result2 = vector1 - vector3;
    const Vector<float, 3> result3 = vector1 - vector4;
    const Vector<float, 3> result4 = vector1 - vector5;
    const Vector<float, 3> result5 = vector1 - vector6;
    const Vector<float, 3> result6 = vector1 - vector7;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 - vector2;
    const Vector<float, 3> result2 = vector1 - vector3;
    const Vector<float, 3> result3 = vector1 - vector4;
    const Vector<float, 3> result4 = vector1 - vector5;
    const Vector<float, 3> result5 = vector1 - vector6;
    const Vector<float, 3> result6 = vector1 - vector7;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 - vector2;
    const Vector<float, 3> result2 = vector1 - vector3;
    const Vector<float, 3> result3 = vector1 - vector4;
    const Vector<float, 3> result4 = vector1 - vector5;
    const Vector<float, 3> result5 = vector1 - vector6;
    const Vector<float, 3> result6 = vector1 - vector7;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 - vector2;
    const Vector<float, 3> result2 = vector1 - vector3;
    const Vector<float, 3> result3 = vector1 - vector4;
    const Vector<float, 3> result4 = vector1 - vector5;
    const Vector<float, 3> result5 = vector1 - vector6;
    const Vector<float, 3> result6 = vector1 - vector7;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 - vector2;
    const Vector<float, 3> result2 = vector1 - vector3;
    const Vector<float, 3> result3 = vector1 - vector4;
    const Vector<float, 3> result4 = vector1 - vector5;
    const Vector<float, 3> result5 = vector1 - vector6;
    const Vector<float, 3> result6 = vector1 - vector7;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1 - vector2;
    const Vector<float, 3> result2 = vector1 - vector3;
    const Vector<float, 3> result3 = vector1 - vector4;
    const Vector<float, 3> result4 = vector1 - vector5;
    const Vector<float, 3> result5 = vector1 - vector6;
    const Vector<float, 3> result6 = vector1 - vector7;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestScalarInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    vector -= 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestScalarExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    vector -= 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestScalarInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    vector -= 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestScalarExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    vector -= 1;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 -= vector2;
    const Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector3;
    const Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector4;
    const Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector5;
    const Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector6;
    const Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector7;
    const Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 -= vector2;
    Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector3;
    Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector4;
    Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector5;
    Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector6;
    Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector7;
    Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector1(3, values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 -= vector2;
    const Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector3;
    const Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector4;
    const Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector5;
    const Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector6;
    const Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= vector7;
    const Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float initialValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector1(3, values1);

    // Items to test against

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);
    
    const float values7[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    vector1 -= vector2;
    Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector3;
    Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector4;
    Vector<float, 3> result3 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector5;
    Vector<float, 3> result4 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector6;
    Vector<float, 3> result5 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= vector7;
    Vector<float, 3> result6 = vector1;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    const Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    const Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    // Test

    const Matrix<float, 3, 3> result1 =  vector * matrix1;
    const Matrix<float, 3, 3> result2 =  vector * matrix2;
    const Matrix<float, 3, 3> result3 =  vector * matrix3;
    const Matrix<float, 3, 3> result4 =  vector * matrix4;
    const Matrix<float, 3, 3> result5 =  vector * matrix5;
    const Matrix<float, 3, 3> result6 =  vector * matrix6;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyTestExternal()
{
    // Setup / Operation

    // Item to test

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    // Test

    const Matrix<float, 3, 3> result1 =  vector * matrix1;
    const Matrix<float, 3, 3> result2 =  vector * matrix2;
    const Matrix<float, 3, 3> result3 =  vector * matrix3;
    const Matrix<float, 3, 3> result4 =  vector * matrix4;
    const Matrix<float, 3, 3> result5 =  vector * matrix5;
    const Matrix<float, 3, 3> result6 =  vector * matrix6;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    // Test

    const Matrix<float, 3, 3> result1 =  vector * matrix1;
    const Matrix<float, 3, 3> result2 =  vector * matrix2;
    const Matrix<float, 3, 3> result3 =  vector * matrix3;
    const Matrix<float, 3, 3> result4 =  vector * matrix4;
    const Matrix<float, 3, 3> result5 =  vector * matrix5;
    const Matrix<float, 3, 3> result6 =  vector * matrix6;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyTestInternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    // Test

    const Matrix<float, 3, 3> result1 =  vector * matrix1;
    const Matrix<float, 3, 3> result2 =  vector * matrix2;
    const Matrix<float, 3, 3> result3 =  vector * matrix3;
    const Matrix<float, 3, 3> result4 =  vector * matrix4;
    const Matrix<float, 3, 3> result5 =  vector * matrix5;
    const Matrix<float, 3, 3> result6 =  vector * matrix6;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    // Test

    const Matrix<float, 3, 3> result1 =  vector * matrix1;
    const Matrix<float, 3, 3> result2 =  vector * matrix2;
    const Matrix<float, 3, 3> result3 =  vector * matrix3;
    const Matrix<float, 3, 3> result4 =  vector * matrix4;
    const Matrix<float, 3, 3> result5 =  vector * matrix5;
    const Matrix<float, 3, 3> result6 =  vector * matrix6;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3,
                                                                      values);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    // Test

    const Matrix<float, 3, 3> result1 =  vector * matrix1;
    const Matrix<float, 3, 3> result2 =  vector * matrix2;
    const Matrix<float, 3, 3> result3 =  vector * matrix3;
    const Matrix<float, 3, 3> result4 =  vector * matrix4;
    const Matrix<float, 3, 3> result5 =  vector * matrix5;
    const Matrix<float, 3, 3> result6 =  vector * matrix6;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyEqualsTestScalarInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    vector *= 2;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyEqualsTestScalarExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    vector *= 2;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyEqualsTestScalarInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    vector *= 2;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyEqualsTestScalarExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    vector *= 2;

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3,
                                                                      values);

    // Test

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTest2Internal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    vector.getValue(2) = 4.0;

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTest2External()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    vector.getValue(2) = 4.0;

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTest2InternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    vector.getValue(2) = 4.0;

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueTest2ExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    vector.getValue(2) = 4.0;

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::setValueTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    vector.setValue(2, 10.0f);

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::setValueTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    vector.setValue(2, 10.0f);

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::setValueTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    vector.setValue(2, 10.0f);

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::setValueTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    vector.setValue(2, 10.0f);

    const float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::setValuesTestInternal()
{
    // Setup / Operation

    Vector<float, 3> vector;

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector.setValues(values);

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::setValuesTestExternal()
{
    // Setup / Operation

    float values1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector.setValues(values2);

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::setValuesTestInternalRunTime()
{
    // Setup / Operation

    Vector<float, DIMENSIONS_RUN_TIME> vector(3);

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector.setValues(values);

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::setValuesTestExternalRunTime()
{
    // Setup / Operation

    float values1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values1);

    float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    // Test

    vector.setValues(values2);

    const Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3> expected(expectedValues);
    
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const Matrix<float, 1, 3> result1 = vector.transpose();
    const Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const Matrix<float, 1, 3> result1 = vector.transpose();
    const Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const Matrix<float, 1, 3> result1 = vector.transpose();
    const Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    const Matrix<float, 1, 3> result1 = vector.transpose();
    const Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    const Matrix<float, 1, 3> result1 = vector.transpose();
    const Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3,
                                                                      values);

    // Test

    const Matrix<float, 1, 3> result1 = vector.transpose();
    const Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::magnitudeTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    // Test

    const float result1 = vector.magnitude();
    const float result2 = vector.norm();

    const float expected = sqrt(1*1 + 2*2 + 3*3);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool VectorTest::magnitudeTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    // Test

    const float result1 = vector.magnitude();
    const float result2 = vector.norm();

    const float expected = sqrt(1*1 + 2*2 + 3*3);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool VectorTest::magnitudeTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    // Test

    const float result1 = vector.magnitude();
    const float result2 = vector.norm();

    const float expected = sqrt(1*1 + 2*2 + 3*3);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool VectorTest::magnitudeTestInternalRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    // Test

    const float result1 = vector.magnitude();
    const float result2 = vector.norm();

    const float expected = sqrt(1*1 + 2*2 + 3*3);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool VectorTest::magnitudeTestExternalRunTime()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    // Test

    const float result1 = vector.magnitude();
    const float result2 = vector.norm();

    const float expected = sqrt(1*1 + 2*2 + 3*3);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool VectorTest::magnitudeTestConstantRunTime()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3,
                                                                      values);

    // Test

    const float result1 = vector.magnitude();
    const float result2 = vector.norm();

    const float expected = sqrt(1*1 + 2*2 + 3*3);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, expected) &
                            UNIT_TEST_CASE_EQUAL(result2, expected));
}

//------------------------------------------------------------------------------
bool VectorTest::crossProductTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1.cross(vector2);
    const Vector<float, 3> result2 = vector1.cross(vector3);
    const Vector<float, 3> result3 = vector1.cross(vector4);
    const Vector<float, 3> result4 = vector1.cross(vector5);
    const Vector<float, 3> result5 = vector1.cross(vector6);
    const Vector<float, 3> result6 = vector1.cross(vector7);

    const float expectedValues[3] =
    {
        -3.0,
         6.0,
        -3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::crossProductTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1.cross(vector2);
    const Vector<float, 3> result2 = vector1.cross(vector3);
    const Vector<float, 3> result3 = vector1.cross(vector4);
    const Vector<float, 3> result4 = vector1.cross(vector5);
    const Vector<float, 3> result5 = vector1.cross(vector6);
    const Vector<float, 3> result6 = vector1.cross(vector7);

    const float expectedValues[3] =
    {
        -3.0,
         6.0,
        -3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::crossProductTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const Vector<float, 3> result1 = vector1.cross(vector2);
    const Vector<float, 3> result2 = vector1.cross(vector3);
    const Vector<float, 3> result3 = vector1.cross(vector4);
    const Vector<float, 3> result4 = vector1.cross(vector5);
    const Vector<float, 3> result5 = vector1.cross(vector6);
    const Vector<float, 3> result6 = vector1.cross(vector7);

    const float expectedValues[3] =
    {
        -3.0,
         6.0,
        -3.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true));
}

//------------------------------------------------------------------------------
bool VectorTest::dotProductTestInternal()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const float result1 = vector1.dot(vector2);
    const float result2 = vector1.dot(vector3);
    const float result3 = vector1.dot(vector4);
    const float result4 = vector1.dot(vector5);
    const float result5 = vector1.dot(vector6);
    const float result6 = vector1.dot(vector7);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result3, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result4, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result5, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result6, 32.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::dotProductTestExternal()
{
    // Setup / Operation

    // Item to test

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const float result1 = vector1.dot(vector2);
    const float result2 = vector1.dot(vector3);
    const float result3 = vector1.dot(vector4);
    const float result4 = vector1.dot(vector5);
    const float result5 = vector1.dot(vector6);
    const float result6 = vector1.dot(vector7);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result3, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result4, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result5, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result6, 32.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::dotProductTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    // Items to test against

    const float values2[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3> vector2(values2);

    float values3[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector3(values3);

    const float values4[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    const float values5[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector5(3, values5);

    float values6[3] =
    {
        4.0,
        5.0,
        6.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector6(3, values6);

    const float values7[3] =
    {
        4.0,
        5.0,
        6.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector7(3,
                                                                       values7);

    // Test

    const float result1 = vector1.dot(vector2);
    const float result2 = vector1.dot(vector3);
    const float result3 = vector1.dot(vector4);
    const float result4 = vector1.dot(vector5);
    const float result5 = vector1.dot(vector6);
    const float result6 = vector1.dot(vector7);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result3, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result4, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result5, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result6, 32.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::toCrossProductEquivalentMatrixTestInternal()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    const Matrix<float, 3, 3> result1 = vector.toCrossProductEquivalentMatrix();
    const Matrix<float, 3, 3> result2 = vector.skew();

    // Test

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::toCrossProductEquivalentMatrixTestExternal()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    const Matrix<float, 3, 3> result1 = vector.toCrossProductEquivalentMatrix();
    const Matrix<float, 3, 3> result2 = vector.skew();

    // Test

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::toCrossProductEquivalentMatrixTestConstant()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    const Matrix<float, 3, 3> result1 = vector.toCrossProductEquivalentMatrix();
    const Matrix<float, 3, 3> result2 = vector.skew();

    // Test

    const float expectedValues[3][3] =
    {
        {  0.0, -3.0,  2.0 },
        {  3.0,  0.0, -1.0 },
        { -2.0,  1.0,  0.0 }
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::printTestInternal()
{
    // Setup

    const float values[3] =
    {
        0.00001,
            0.1,
        10000.0
    };

    Vector<float, 3> vector(values);

    Matrice::print("\n");
    vector.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::printTestExternal()
{
    // Setup

    float values[3] =
    {
        0.00001,
            0.1,
        10000.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    Matrice::print("\n");
    vector.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::printTestConstant()
{
    // Setup

    const float values[3] =
    {
        0.00001,
            0.1,
        10000.0
    };

    Vector<float, 3, STORAGE_CONSTANT> vector(values);

    Matrice::print("\n");
    vector.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::printTestInternalRunTime()
{
    // Setup

    const float values[3] =
    {
        0.00001,
            0.1,
        10000.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector(3, values);

    Matrice::print("\n");
    vector.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::printTestExternalRunTime()
{
    // Setup

    float values[3] =
    {
        0.00001,
            0.1,
        10000.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector(3, values);

    Matrice::print("\n");
    vector.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::printTestConstantRunTime()
{
    // Setup

    const float values[3] =
    {
        0.00001,
            0.1,
        10000.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector(3, values);

    Matrice::print("\n");
    vector.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddScalarTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    const Vector<float, 2> result = submatrix + 1;

    const float expectedValues[2] =
    {
        6.0,
        9.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddScalarTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    const Vector<float, 2> result = submatrix + 1;

    const float expectedValues[2] =
    {
        6.0,
        9.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    const Vector<float, 2> result = submatrix + 1;

    const float expectedValues[2] =
    {
        6.0,
        9.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, matrix, 1, 1);

    // Test

    const Vector<float, 2> result = submatrix + 1;

    const float expectedValues[2] =
    {
        6.0,
        9.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix, 1, 1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix4(values8);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 + vector1;
    const Vector<float, 2> result2 = submatrix1 + vector2;
    const Vector<float, 2> result3 = submatrix1 + vector3;
    const Vector<float, 2> result4 = submatrix1 + vector4;
    const Vector<float, 2> result5 = submatrix1 + vector5;
    const Vector<float, 2> result6 = submatrix1 + vector6;
    const Vector<float, 2> result7 = submatrix1 + submatrix2;
    const Vector<float, 2> result8 = submatrix1 + submatrix3;
    const Vector<float, 2> result9 = submatrix1 + submatrix4;
    const Vector<float, 2> result10 = submatrix1 + submatrix5;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix, 1, 1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix4(values8);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 + vector1;
    const Vector<float, 2> result2 = submatrix1 + vector2;
    const Vector<float, 2> result3 = submatrix1 + vector3;
    const Vector<float, 2> result4 = submatrix1 + vector4;
    const Vector<float, 2> result5 = submatrix1 + vector5;
    const Vector<float, 2> result6 = submatrix1 + vector6;
    const Vector<float, 2> result7 = submatrix1 + submatrix2;
    const Vector<float, 2> result8 = submatrix1 + submatrix3;
    const Vector<float, 2> result9 = submatrix1 + submatrix4;
    const Vector<float, 2> result10 = submatrix1 + submatrix5;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix1(2,
                                                                    matrix,
                                                                    1,
                                                                    1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix4(values8);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 + vector1;
    const Vector<float, 2> result2 = submatrix1 + vector2;
    const Vector<float, 2> result3 = submatrix1 + vector3;
    const Vector<float, 2> result4 = submatrix1 + vector4;
    const Vector<float, 2> result5 = submatrix1 + vector5;
    const Vector<float, 2> result6 = submatrix1 + vector6;
    const Vector<float, 2> result7 = submatrix1 + submatrix2;
    const Vector<float, 2> result8 = submatrix1 + submatrix3;
    const Vector<float, 2> result9 = submatrix1 + submatrix4;
    const Vector<float, 2> result10 = submatrix1 + submatrix5;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix1(2, matrix, 1, 1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix4(values8);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 + vector1;
    const Vector<float, 2> result2 = submatrix1 + vector2;
    const Vector<float, 2> result3 = submatrix1 + vector3;
    const Vector<float, 2> result4 = submatrix1 + vector4;
    const Vector<float, 2> result5 = submatrix1 + vector5;
    const Vector<float, 2> result6 = submatrix1 + vector6;
    const Vector<float, 2> result7 = submatrix1 + submatrix2;
    const Vector<float, 2> result8 = submatrix1 + submatrix3;
    const Vector<float, 2> result9 = submatrix1 + submatrix4;
    const Vector<float, 2> result10 = submatrix1 + submatrix5;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddEqualsScalarTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    submatrix += 1;

    const Vector<float, 2>    result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

    const float expectedValues1[2] =
    {
        6.0,
        9.0
    };

    const float expectedValues2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 6.0, 6.0 },
        { 7.0, 9.0, 9.0 }
    };

    const Vector<float, 2>    expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    submatrix += 1;

    const Vector<float, 2>    result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

    const float expectedValues1[2] =
    {
        6.0,
        9.0
    };

    const float expectedValues2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 6.0, 6.0 },
        { 7.0, 9.0, 9.0 }
    };

    const Vector<float, 2>    expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix, 1, 1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    submatrix1 += vector1;
    const Vector<float, 2> result1 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector2;
    const Vector<float, 2> result2 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector3;
    const Vector<float, 2> result3 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector4;
    const Vector<float, 2> result4 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector5;
    const Vector<float, 2> result5 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector6;
    const Vector<float, 2> result6 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix2;
    const Vector<float, 2> result7 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix3;
    const Vector<float, 2> result8 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix4;
    const Vector<float, 2> result9 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix5;
    const Vector<float, 2> result10 = submatrix1;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = result1 == expected;
    const bool compare2 = result2 == expected;
    const bool compare3 = result3 == expected;
    const bool compare4 = result4 == expected;
    const bool compare5 = result5 == expected;
    const bool compare6 = result6 == expected;
    const bool compare7 = result7 == expected;
    const bool compare8 = result8 == expected;
    const bool compare9 = result9 == expected;
    const bool compare10 = result10 == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix1(2,
                                                                    matrix,
                                                                    1,
                                                                    1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        8.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        8.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        8.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    submatrix1 += vector1;
    const Vector<float, 2> result1 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector2;
    const Vector<float, 2> result2 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector3;
    const Vector<float, 2> result3 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector4;
    const Vector<float, 2> result4 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector5;
    const Vector<float, 2> result5 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += vector6;
    const Vector<float, 2> result6 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix2;
    const Vector<float, 2> result7 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix3;
    const Vector<float, 2> result8 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix4;
    const Vector<float, 2> result9 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 += submatrix5;
    const Vector<float, 2> result10 = submatrix1;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = result1 == expected;
    const bool compare2 = result2 == expected;
    const bool compare3 = result3 == expected;
    const bool compare4 = result4 == expected;
    const bool compare5 = result5 == expected;
    const bool compare6 = result6 == expected;
    const bool compare7 = result7 == expected;
    const bool compare8 = result8 == expected;
    const bool compare9 = result9 == expected;
    const bool compare10 = result10 == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorUnaryMinusTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    const Vector<float, 2> result = -submatrix;

    const float expectedValues[2] =
    {
        -5.0,
        -8.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorUnaryMinusTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    const Vector<float, 2> result = -submatrix;

    const float expectedValues[2] =
    {
        -5.0,
        -8.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorUnaryMinusTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    const Vector<float, 2> result = -submatrix;

    const float expectedValues[2] =
    {
        -5.0,
        -8.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorUnaryMinusTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(2, matrix, 1, 1);

    // Test

    const Vector<float, 2> result = -submatrix;

    const float expectedValues[2] =
    {
        -5.0,
        -8.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractScalarTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    const Vector<float, 2> result = submatrix - 1;

    const float expectedValues[2] =
    {
        4.0,
        7.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractScalarTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    const Vector<float, 2> result = submatrix - 1;

    const float expectedValues[2] =
    {
        4.0,
        7.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    const Vector<float, 2> result = submatrix - 1;

    const float expectedValues[2] =
    {
        4.0,
        7.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> submatrix(2,
                                                                         matrix,
                                                                         1,
                                                                         1);

    // Test

    const Vector<float, 2> result = submatrix - 1;

    const float expectedValues[2] =
    {
        4.0,
        7.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix, 1, 1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 - vector1;
    const Vector<float, 2> result2 = submatrix1 - vector2;
    const Vector<float, 2> result3 = submatrix1 - vector3;
    const Vector<float, 2> result4 = submatrix1 - vector4;
    const Vector<float, 2> result5 = submatrix1 - vector5;
    const Vector<float, 2> result6 = submatrix1 - vector6;
    const Vector<float, 2> result7 = submatrix1 - submatrix2;
    const Vector<float, 2> result8 = submatrix1 - submatrix3;
    const Vector<float, 2> result9 = submatrix1 - submatrix4;
    const Vector<float, 2> result10 = submatrix1 - submatrix5;

    const float expectedValues[2] =
    {
        0.0,
        6.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result1 == expected);
    const bool compare3 = (result1 == expected);
    const bool compare4 = (result1 == expected);
    const bool compare5 = (result1 == expected);
    const bool compare6 = (result1 == expected);
    const bool compare7 = (result1 == expected);
    const bool compare8 = (result1 == expected);
    const bool compare9 = (result1 == expected);
    const bool compare10 = (result1 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix, 1, 1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 - vector1;
    const Vector<float, 2> result2 = submatrix1 - vector2;
    const Vector<float, 2> result3 = submatrix1 - vector3;
    const Vector<float, 2> result4 = submatrix1 - vector4;
    const Vector<float, 2> result5 = submatrix1 - vector5;
    const Vector<float, 2> result6 = submatrix1 - vector6;
    const Vector<float, 2> result7 = submatrix1 - submatrix2;
    const Vector<float, 2> result8 = submatrix1 - submatrix3;
    const Vector<float, 2> result9 = submatrix1 - submatrix4;
    const Vector<float, 2> result10 = submatrix1 - submatrix5;

    const float expectedValues[2] =
    {
        0.0,
        6.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result1 == expected);
    const bool compare3 = (result1 == expected);
    const bool compare4 = (result1 == expected);
    const bool compare5 = (result1 == expected);
    const bool compare6 = (result1 == expected);
    const bool compare7 = (result1 == expected);
    const bool compare8 = (result1 == expected);
    const bool compare9 = (result1 == expected);
    const bool compare10 = (result1 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix1(2,
                                                                    matrix,
                                                                    1,
                                                                    1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 - vector1;
    const Vector<float, 2> result2 = submatrix1 - vector2;
    const Vector<float, 2> result3 = submatrix1 - vector3;
    const Vector<float, 2> result4 = submatrix1 - vector4;
    const Vector<float, 2> result5 = submatrix1 - vector5;
    const Vector<float, 2> result6 = submatrix1 - vector6;
    const Vector<float, 2> result7 = submatrix1 - submatrix2;
    const Vector<float, 2> result8 = submatrix1 - submatrix3;
    const Vector<float, 2> result9 = submatrix1 - submatrix4;
    const Vector<float, 2> result10 = submatrix1 - submatrix5;

    const float expectedValues[2] =
    {
        0.0,
        6.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result1 == expected);
    const bool compare3 = (result1 == expected);
    const bool compare4 = (result1 == expected);
    const bool compare5 = (result1 == expected);
    const bool compare6 = (result1 == expected);
    const bool compare7 = (result1 == expected);
    const bool compare8 = (result1 == expected);
    const bool compare9 = (result1 == expected);
    const bool compare10 = (result1 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> submatrix1(2,
                                                                    matrix,
                                                                    1,
                                                                    1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    const Vector<float, 2> result1 = submatrix1 - vector1;
    const Vector<float, 2> result2 = submatrix1 - vector2;
    const Vector<float, 2> result3 = submatrix1 - vector3;
    const Vector<float, 2> result4 = submatrix1 - vector4;
    const Vector<float, 2> result5 = submatrix1 - vector5;
    const Vector<float, 2> result6 = submatrix1 - vector6;
    const Vector<float, 2> result7 = submatrix1 - submatrix2;
    const Vector<float, 2> result8 = submatrix1 - submatrix3;
    const Vector<float, 2> result9 = submatrix1 - submatrix4;
    const Vector<float, 2> result10 = submatrix1 - submatrix5;

    const float expectedValues[2] =
    {
        0.0,
        6.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result1 == expected);
    const bool compare3 = (result1 == expected);
    const bool compare4 = (result1 == expected);
    const bool compare5 = (result1 == expected);
    const bool compare6 = (result1 == expected);
    const bool compare7 = (result1 == expected);
    const bool compare8 = (result1 == expected);
    const bool compare9 = (result1 == expected);
    const bool compare10 = (result1 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractEqualsScalarTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    submatrix -= 1;

    const Vector<float, 2>    result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

    const float expectedValues1[2] =
    {
        4.0,
        7.0
    };

    const float expectedValues2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 4.0, 6.0 },
        { 7.0, 7.0, 9.0 }
    };

    const Vector<float, 2>    expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractEqualsScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    submatrix -= 1;

    const Vector<float, 2>    result1 = submatrix;
    const Matrix<float, 3, 3> result2 = matrix;

    const float expectedValues1[2] =
    {
        4.0,
        7.0
    };

    const float expectedValues2[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 4.0, 6.0 },
        { 7.0, 7.0, 9.0 }
    };

    const Vector<float, 2>    expected1(expectedValues1);
    const Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractEqualsTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix, 1, 1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    submatrix1 -= vector1;
    const Vector<float, 2> result1 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector2;
    const Vector<float, 2> result2 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector3;
    const Vector<float, 2> result3 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector4;
    const Vector<float, 2> result4 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector5;
    const Vector<float, 2> result5 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector6;
    const Vector<float, 2> result6 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix2;
    const Vector<float, 2> result7 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix3;
    const Vector<float, 2> result8 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix4;
    const Vector<float, 2> result9 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix5;
    const Vector<float, 2> result10 = submatrix1;

    const float expectedValues[2] =
    {
        0.0,
        6.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = result1 == expected;
    const bool compare2 = result2 == expected;
    const bool compare3 = result3 == expected;
    const bool compare4 = result4 == expected;
    const bool compare5 = result5 == expected;
    const bool compare6 = result6 == expected;
    const bool compare7 = result7 == expected;
    const bool compare8 = result8 == expected;
    const bool compare9 = result9 == expected;
    const bool compare10 = result10 == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractEqualsTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix1(2,
                                                                    matrix,
                                                                    1,
                                                                    1);

    // Items to test against

    const float values1[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2> vector1(values1);

    float values2[2] =
    {
        5.0,
        2.0
    };

    Vector<float, 2, STORAGE_EXTERNAL> vector2(values2);

    const float values3[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2, STORAGE_CONSTANT> vector3(values3);

    const float values4[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME> vector4(2, values4);

    float values5[2] =
    {
        5.0,
        2.0
    };

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> vector5(2, values5);

    const float values6[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> vector6(2,
                                                                       values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix1(values7);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix1, 1, 1);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix2(values8);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix3(matrix2, 1, 1);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix3(values9);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix4(2,
                                                                    matrix3,
                                                                    1,
                                                                    1);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix4(values10);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(2, matrix4, 1, 1);

    // Test

    submatrix1 -= vector1;
    const Vector<float, 2> result1 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector2;
    const Vector<float, 2> result2 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector3;
    const Vector<float, 2> result3 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector4;
    const Vector<float, 2> result4 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector5;
    const Vector<float, 2> result5 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= vector6;
    const Vector<float, 2> result6 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix2;
    const Vector<float, 2> result7 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix3;
    const Vector<float, 2> result8 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix4;
    const Vector<float, 2> result9 = submatrix1;

    matrix = Matrix<float, 3, 3>(values);

    submatrix1 -= submatrix5;
    const Vector<float, 2> result10 = submatrix1;

    const float expectedValues[2] =
    {
        0.0,
        6.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare1 = result1 == expected;
    const bool compare2 = result2 == expected;
    const bool compare3 = result3 == expected;
    const bool compare4 = result4 == expected;
    const bool compare5 = result5 == expected;
    const bool compare6 = result6 == expected;
    const bool compare7 = result7 == expected;
    const bool compare8 = result8 == expected;
    const bool compare9 = result9 == expected;
    const bool compare10 = result10 == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyScalarTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    Vector<float, 2> result = submatrix * 2;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyScalarTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    Vector<float, 2> result = submatrix * 2;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyScalarTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    Vector<float, 2> result = submatrix * 2;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyScalarTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> submatrix(2,
                                                                         matrix,
                                                                         1,
                                                                         1);

    // Test

    Vector<float, 2> result = submatrix * 2;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyTestExternal()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 3, STORAGE_EXTERNAL> submatrix1(matrix, 0, 1);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix7(values7);

    Matrix<float, 1, 3, STORAGE_EXTERNAL> submatrix2(matrix7, 2, 0);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 1, 3, STORAGE_CONSTANT> submatrix3(matrix8, 2, 0);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix9(values9);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix4(1, 3, matrix9, 2, 0);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(1, 3, matrix10, 2, 0);

    // Test

    const Matrix<float, 3, 3> result1 = submatrix1 * matrix1;
    const Matrix<float, 3, 3> result2 = submatrix1 * matrix2;
    const Matrix<float, 3, 3> result3 = submatrix1 * matrix3;
    const Matrix<float, 3, 3> result4 = submatrix1 * matrix4;
    const Matrix<float, 3, 3> result5 = submatrix1 * matrix5;
    const Matrix<float, 3, 3> result6 = submatrix1 * matrix6;
    const Matrix<float, 3, 3> result7 = submatrix1 * submatrix2;
    const Matrix<float, 3, 3> result8 = submatrix1 * submatrix3;
    const Matrix<float, 3, 3> result9 = submatrix1 * submatrix4;
    const Matrix<float, 3, 3> result10 = submatrix1 * submatrix5;

    const float expectedValues[3][3] =
    {
        {  6.0,  4.0, 2.0 },
        { 15.0, 10.0, 5.0 },
        { 24.0, 16.0, 8.0 },
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyTestConstant()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 3, STORAGE_CONSTANT> submatrix1(matrix, 0, 1);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix7(values7);

    Matrix<float, 1, 3, STORAGE_EXTERNAL> submatrix2(matrix7, 2, 0);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 1, 3, STORAGE_CONSTANT> submatrix3(matrix8, 2, 0);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix9(values9);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix4(1, 3, matrix9, 2, 0);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(1, 3, matrix10, 2, 0);

    // Test

    const Matrix<float, 3, 3> result1 = submatrix1 * matrix1;
    const Matrix<float, 3, 3> result2 = submatrix1 * matrix2;
    const Matrix<float, 3, 3> result3 = submatrix1 * matrix3;
    const Matrix<float, 3, 3> result4 = submatrix1 * matrix4;
    const Matrix<float, 3, 3> result5 = submatrix1 * matrix5;
    const Matrix<float, 3, 3> result6 = submatrix1 * matrix6;
    const Matrix<float, 3, 3> result7 = submatrix1 * submatrix2;
    const Matrix<float, 3, 3> result8 = submatrix1 * submatrix3;
    const Matrix<float, 3, 3> result9 = submatrix1 * submatrix4;
    const Matrix<float, 3, 3> result10 = submatrix1 * submatrix5;

    const float expectedValues[3][3] =
    {
        {  6.0,  4.0, 2.0 },
        { 15.0, 10.0, 5.0 },
        { 24.0, 16.0, 8.0 },
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyTestExternalRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 3, STORAGE_EXTERNAL> submatrix1(matrix, 0, 1);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix7(values7);

    Matrix<float, 1, 3, STORAGE_EXTERNAL> submatrix2(matrix7, 2, 0);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 1, 3, STORAGE_CONSTANT> submatrix3(matrix8, 2, 0);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix9(values9);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix4(1, 3, matrix9, 2, 0);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(1, 3, matrix10, 2, 0);

    // Test

    const Matrix<float, 3, 3> result1 = submatrix1 * matrix1;
    const Matrix<float, 3, 3> result2 = submatrix1 * matrix2;
    const Matrix<float, 3, 3> result3 = submatrix1 * matrix3;
    const Matrix<float, 3, 3> result4 = submatrix1 * matrix4;
    const Matrix<float, 3, 3> result5 = submatrix1 * matrix5;
    const Matrix<float, 3, 3> result6 = submatrix1 * matrix6;
    const Matrix<float, 3, 3> result7 = submatrix1 * submatrix2;
    const Matrix<float, 3, 3> result8 = submatrix1 * submatrix3;
    const Matrix<float, 3, 3> result9 = submatrix1 * submatrix4;
    const Matrix<float, 3, 3> result10 = submatrix1 * submatrix5;

    const float expectedValues[3][3] =
    {
        {  6.0,  4.0, 2.0 },
        { 15.0, 10.0, 5.0 },
        { 24.0, 16.0, 8.0 },
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyTestConstantRunTime()
{
    // Setup / Operation

    // Item to test

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 3, STORAGE_CONSTANT> submatrix1(matrix, 0, 1);

    // Items to test against

    const float values1[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values1);

    float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values2);

    const float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, DIMENSIONS_RUN_TIME, DIMENSIONS_RUN_TIME> matrix4(1,
                                                                    3,
                                                                    values4);

    float values5[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> matrix5(1, 3, values5);

    const float values6[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> matrix6(1, 3, values6);

    const float values7[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix7(values7);

    Matrix<float, 1, 3, STORAGE_EXTERNAL> submatrix2(matrix7, 2, 0);

    const float values8[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix8(values8);

    const Matrix<float, 1, 3, STORAGE_CONSTANT> submatrix3(matrix8, 2, 0);

    const float values9[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix9(values9);

    Matrix<float,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> submatrix4(1, 3, matrix9, 2, 0);

    const float values10[3][3] =
    {
        { 9.0, 8.0, 7.0 },
        { 6.0, 5.0, 4.0 },
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 3, 3> matrix10(values10);

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix5(1, 3, matrix10, 2, 0);

    // Test

    const Matrix<float, 3, 3> result1 = submatrix1 * matrix1;
    const Matrix<float, 3, 3> result2 = submatrix1 * matrix2;
    const Matrix<float, 3, 3> result3 = submatrix1 * matrix3;
    const Matrix<float, 3, 3> result4 = submatrix1 * matrix4;
    const Matrix<float, 3, 3> result5 = submatrix1 * matrix5;
    const Matrix<float, 3, 3> result6 = submatrix1 * matrix6;
    const Matrix<float, 3, 3> result7 = submatrix1 * submatrix2;
    const Matrix<float, 3, 3> result8 = submatrix1 * submatrix3;
    const Matrix<float, 3, 3> result9 = submatrix1 * submatrix4;
    const Matrix<float, 3, 3> result10 = submatrix1 * submatrix5;

    const float expectedValues[3][3] =
    {
        {  6.0,  4.0, 2.0 },
        { 15.0, 10.0, 5.0 },
        { 24.0, 16.0, 8.0 },
    };

    const Matrix<float, 3, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);
    const bool compare4 = (result4 == expected);
    const bool compare5 = (result5 == expected);
    const bool compare6 = (result6 == expected);
    const bool compare7 = (result7 == expected);
    const bool compare8 = (result8 == expected);
    const bool compare9 = (result9 == expected);
    const bool compare10 = (result10 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true) &
                            UNIT_TEST_CASE_EQUAL(compare5, true) &
                            UNIT_TEST_CASE_EQUAL(compare6, true) &
                            UNIT_TEST_CASE_EQUAL(compare7, true) &
                            UNIT_TEST_CASE_EQUAL(compare8, true) &
                            UNIT_TEST_CASE_EQUAL(compare9, true) &
                            UNIT_TEST_CASE_EQUAL(compare10, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyEqualsTestScalarExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    submatrix *= 2;

    Vector<float, 2>    result1 = submatrix;
    Matrix<float, 3, 3> result2 = matrix;

    const float expectedValues1[2] =
    {
        10.0,
        16.0
    };

    const float expectedValues2[3][3] =
    {
        { 1.0,  2.0, 3.0 },
        { 4.0, 10.0, 6.0 },
        { 7.0, 16.0, 9.0 }
    };

    Vector<float, 2>    expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyEqualsTestScalarExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    submatrix *= 2;

    Vector<float, 2>    result1 = submatrix;
    Matrix<float, 3, 3> result2 = matrix;

    const float expectedValues1[2] =
    {
        10.0,
        16.0
    };

    const float expectedValues2[3][3] =
    {
        { 1.0,  2.0, 3.0 },
        { 4.0, 10.0, 6.0 },
        { 7.0, 16.0, 9.0 }
    };

    Vector<float, 2>    expected1(expectedValues1);
    Matrix<float, 3, 3> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixGetValueTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    const float result1 = submatrix.getValue(0);
    const float result2 = submatrix.getValue(1);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 5.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 8.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixGetValueTestConstant()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    // Test

    const float result1 = submatrix.getValue(0);
    const float result2 = submatrix.getValue(1);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 5.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 8.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixGetValueTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    const float result1 = submatrix.getValue(0);
    const float result2 = submatrix.getValue(1);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 5.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 8.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixGetValueTestConstantRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> submatrix(2,
                                                                         matrix,
                                                                         1,
                                                                         1);

    // Test

    const float result1 = submatrix.getValue(0);
    const float result2 = submatrix.getValue(1);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 5.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 8.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixSetValueTestExternal()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    // Test

    submatrix.setValue(1, 10.0f);

    const float result = submatrix.getValue(1);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixSetValueTestExternalRunTime()
{
    // Setup / Operation

    const float values[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    // Test

    submatrix.setValue(1, 10.0f);

    const float result = submatrix.getValue(1);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 10.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixTransposeTestExternal()
{
    // Setup / Operation

    const float values[6] =
    {
        0.0,
        0.0,
        1.0,
        2.0,
        3.0,
        0.0
    };

    Vector<float, 6> vector(values);
    Vector<float, 3, STORAGE_EXTERNAL> subvector(vector, 2);

    // Test

    const Matrix<float, 1, 3> result1 = subvector.transpose();
    const Matrix<float, 1, 3> result2 = subvector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixTransposeTestConstant()
{
    // Setup / Operation

    const float values[6] =
    {
        0.0,
        0.0,
        1.0,
        2.0,
        3.0,
        0.0
    };

    Vector<float, 6> vector(values);
    const Vector<float, 3, STORAGE_CONSTANT> subvector(vector, 2);

    // Test

    const Matrix<float, 1, 3> result1 = subvector.transpose();
    const Matrix<float, 1, 3> result2 = subvector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixTransposeTestExternalRunTime()
{
    // Setup / Operation

    const float values[6] =
    {
        0.0,
        0.0,
        1.0,
        2.0,
        3.0,
        0.0
    };

    Vector<float, 6> vector(values);
    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> subvector(3,
                                                                   vector,
                                                                   2);

    // Test

    const Matrix<float, 1, 3> result1 = subvector.transpose();
    const Matrix<float, 1, 3> result2 = subvector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixTransposeTestConstantRunTime()
{
    // Setup / Operation

    const float values[6] =
    {
        0.0,
        0.0,
        1.0,
        2.0,
        3.0,
        0.0
    };

    Vector<float, 6> vector(values);
    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> subvector(3,
                                                                         vector,
                                                                         2);

    // Test

    const Matrix<float, 1, 3> result1 = subvector.transpose();
    const Matrix<float, 1, 3> result2 = subvector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    const Matrix<float, 1, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixPrintTestExternal()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, 2, STORAGE_EXTERNAL> submatrix(matrix, 1, 1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixPrintTestConstant()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, 2, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixPrintTestExternalRunTime()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> submatrix(2,
                                                                   matrix,
                                                                   1,
                                                                   1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixPrintTestConstantRunTime()
{
    // Setup

    const float values[3][3] =
    {
        { 0.00001, 0.0001,    0.01 },
        {     0.1,    1.0,    10.0 },
        {   100.0, 1000.0, 10000.0 }
    };

    Matrix<float, 3, 3> matrix(values);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> submatrix(2,
                                                                         matrix,
                                                                         1,
                                                                         1);

    Matrice::print("\n");
    submatrix.print();

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(true, true));
}

//------------------------------------------------------------------------------
bool VectorTest::nestedSubmatrixOperatorEqualsTestExternal()
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

    Vector<float, 2, STORAGE_EXTERNAL> nestedSubmatrix(submatrix, 1, 1);

    // Test
    
    const float expectedValues[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = nestedSubmatrix == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::nestedSubmatrixOperatorEqualsTestConstant()
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

    const Matrix<float, 4, 4, STORAGE_CONSTANT> submatrix(matrix, 1, 1);

    const Vector<float, 2, STORAGE_CONSTANT> nestedSubmatrix(submatrix, 1, 1);

    // Test
    
    const float expectedValues[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = nestedSubmatrix == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::nestedSubmatrixOperatorEqualsTestExternalRunTime()
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

    Vector<float,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL> nestedSubmatrix(2, submatrix, 1, 1);

    // Test
    
    const float expectedValues[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = nestedSubmatrix == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::nestedSubmatrixOperatorEqualsTestConstantRunTime()
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

    const Matrix<float,
                 DIMENSIONS_RUN_TIME,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> submatrix(4, 4, matrix, 1, 1);

    const Vector<float,
                 DIMENSIONS_RUN_TIME,
                 STORAGE_CONSTANT> nestedSubmatrix(2, submatrix, 1, 1);

    // Test
    
    const float expectedValues[2] =
    {
        5.0,
        2.0
    };

    const Vector<float, 2> expected(expectedValues);

    const bool compare = nestedSubmatrix == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::subvectorOperatorEqualsTestExternal()
{
    // Setup / Operation

    const float values[5] =
    {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0
    };

    Vector<float, 5> vector(values);

    Vector<float, 3, STORAGE_EXTERNAL> subvector(vector, 1);

    // Test
    
    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = subvector == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::subvectorOperatorEqualsTestConstant()
{
    // Setup / Operation

    const float values[5] =
    {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0
    };

    Vector<float, 5> vector(values);

    const Vector<float, 3, STORAGE_CONSTANT> subvector(vector, 1);

    // Test
    
    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = subvector == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::subvectorOperatorEqualsTestExternalRunTime()
{
    // Setup / Operation

    const float values[5] =
    {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0
    };

    Vector<float, 5> vector(values);

    Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> subvector(3,
                                                                   vector,
                                                                   1);

    // Test
    
    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = subvector == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::subvectorOperatorEqualsTestConstantRunTime()
{
    // Setup / Operation

    const float values[5] =
    {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0
    };

    Vector<float, 5> vector(values);

    const Vector<float, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> subvector(3,
                                                                         vector,
                                                                         1);

    // Test
    
    const float expectedValues[3] =
    {
        2.0,
        3.0,
        4.0
    };

    const Vector<float, 3> expected(expectedValues);

    const bool compare = subvector == expected;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}
