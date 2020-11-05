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
    &VectorTest::operatorValueTypeCastInternalTest,
    &VectorTest::operatorValueTypeCastExternalTest,
    &VectorTest::operatorValueTypeCastConstantTest,
    &VectorTest::operatorAssignmentInternalTest,
    &VectorTest::operatorAssignmentExternalTest,
    &VectorTest::operatorAssignmentConstantTest,
    &VectorTest::operatorAssignmentInternalTest2,
    &VectorTest::operatorAssignmentExternalTest2,
    &VectorTest::operatorAssignmentConstantTest2,
    &VectorTest::operatorEqualsInternalTest,
    &VectorTest::operatorEqualsExternalTest,
    &VectorTest::operatorEqualsConstantTest,
    &VectorTest::operatorParenthesesInternalTest,
    &VectorTest::operatorParenthesesExternalTest,
    &VectorTest::operatorParenthesesConstantTest,
    &VectorTest::operatorParenthesesInternalTest2,
    &VectorTest::operatorParenthesesExternalTest2,
    &VectorTest::operatorAddScalarInternalTest,
    &VectorTest::operatorAddScalarExternalTest,
    &VectorTest::operatorAddScalarConstantTest,
    &VectorTest::operatorAddInternalTest,
    &VectorTest::operatorAddExternalTest,
    &VectorTest::operatorAddConstantTest,
    &VectorTest::operatorAddEqualsScalarInternalTest,
    &VectorTest::operatorAddEqualsScalarExternalTest,
    &VectorTest::operatorUnaryMinusInternalTest,
    &VectorTest::operatorUnaryMinusExternalTest,
    &VectorTest::operatorUnaryMinusConstantTest,
    &VectorTest::operatorSubtractScalarInternalTest,
    &VectorTest::operatorSubtractScalarExternalTest,
    &VectorTest::operatorSubtractScalarConstantTest,
    &VectorTest::operatorSubtractInternalTest,
    &VectorTest::operatorSubtractExternalTest,
    &VectorTest::operatorSubtractConstantTest,
    &VectorTest::operatorSubtractEqualsScalarInternalTest,
    &VectorTest::operatorSubtractEqualsScalarExternalTest,
    &VectorTest::operatorMultiplyScalarInternalTest,
    &VectorTest::operatorMultiplyScalarExternalTest,
    &VectorTest::operatorMultiplyScalarConstantTest,
    &VectorTest::operatorMultiplyInternalTest,
    &VectorTest::operatorMultiplyExternalTest,
    &VectorTest::operatorMultiplyConstantTest,
    &VectorTest::operatorMultiplyEqualsScalarInternalTest,
    &VectorTest::operatorMultiplyEqualsScalarExternalTest,
    &VectorTest::getValueInternalTest,
    &VectorTest::getValueExternalTest,
    &VectorTest::getValueConstantTest,
    &VectorTest::getValueInternalTest2,
    &VectorTest::getValueExternalTest2,
    &VectorTest::setValuesInternalTest,
    &VectorTest::setValuesExternalTest,
    &VectorTest::transposeInternalTest,
    &VectorTest::transposeExternalTest,
    &VectorTest::transposeConstantTest,
    &VectorTest::magnitudeInternalTest,
    &VectorTest::magnitudeExternalTest,
    &VectorTest::magnitudeConstantTest,
    &VectorTest::crossProductInternalTest,
    &VectorTest::crossProductExternalTest,
    &VectorTest::crossProductConstantTest,
    &VectorTest::dotProductInternalTest,
    &VectorTest::dotProductExternalTest,
    &VectorTest::dotProductConstantTest,
    &VectorTest::toCrossProductEquivalentMatrixInternalTest,
    &VectorTest::toCrossProductEquivalentMatrixExternalTest,
    &VectorTest::toCrossProductEquivalentMatrixConstantTest,
    &VectorTest::submatrixOperatorAddScalarExternalTest,
    &VectorTest::submatrixOperatorAddScalarConstantTest,
    &VectorTest::submatrixOperatorAddExternalTest,
    &VectorTest::submatrixOperatorAddConstantTest,
    &VectorTest::submatrixOperatorAddEqualsScalarExternalTest,
    &VectorTest::submatrixOperatorUnaryMinusExternalTest,
    &VectorTest::submatrixOperatorUnaryMinusConstantTest,
    &VectorTest::submatrixOperatorSubtractScalarExternalTest,
    &VectorTest::submatrixOperatorSubtractScalarConstantTest,
    &VectorTest::submatrixOperatorSubtractExternalTest,
    &VectorTest::submatrixOperatorSubtractConstantTest,
    &VectorTest::submatrixOperatorSubtractEqualsScalarExternalTest,
    &VectorTest::submatrixOperatorMultiplyScalarExternalTest,
    &VectorTest::submatrixOperatorMultiplyScalarConstantTest,
    &VectorTest::submatrixOperatorMultiplyExternalTest,
    &VectorTest::submatrixOperatorMultiplyConstantTest,
    &VectorTest::submatrixOperatorMultiplyEqualsScalarExternalTest
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
bool VectorTest::operatorValueTypeCastInternalTest()
{
    // Setup / Operation

    const float values[1] =
    {
        1.0
    };

    Vector<float, 1> vector(values);

    // Test
    
    float result = vector;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 1.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorValueTypeCastExternalTest()
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
bool VectorTest::operatorValueTypeCastConstantTest()
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
bool VectorTest::operatorAssignmentInternalTest()
{
    // Setup / Operation

    const float values1[3] =
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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    // Test

    Vector<float, 3> result1;
    result1 = vector1;

    Vector<float, 3> result2;
    result2 = vector2;

    Vector<float, 3> result3;
    result3 = vector3;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentExternalTest()
{
    // Setup / Operation

    const float values1[3] =
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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    // Test

    float resultValues1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> result1(resultValues1);
    result1 = vector1;

    float resultValues2[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> result2(resultValues2);
    result2 = vector2;

    float resultValues3[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> result3(resultValues3);
    result3 = vector3;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentConstantTest()
{
    // Setup / Operation

    const float values1[3] =
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
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values3);

    // Test

    const float resultValues1[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_CONSTANT> result1(resultValues1);
    result1 = vector1;

    const float resultValues2[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_CONSTANT> result2(resultValues2);
    result2 = vector2;

    const float resultValues3[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_CONSTANT> result3(resultValues3);
    result3 = vector3;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentInternalTest2()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentExternalTest2()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAssignmentConstantTest2()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    const float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector3(values3);

    float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector4(values4);

    float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector5(values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector6(values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector7(values7);

    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true)  &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, true)  &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, true)  &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsExternalTest()
{
    // Setup / Operation

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    const float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector3(values3);

    float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector4(values4);

    float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector5(values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector6(values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector7(values7);

    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true)  &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, true)  &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, true)  &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorEqualsConstantTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector2(values2);

    const float values3[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3> vector3(values3);

    float values4[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector4(values4);

    float values5[3] =
    {
        1.0,
        2.0,
        4.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector5(values5);

    const float values6[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector6(values6);

    const float values7[3] =
    {
        1.0,
        2.0,
        4.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector7(values7);

    // Test

    bool result1 = vector1 == vector2;
    bool result2 = vector1 == vector3;
    bool result3 = vector1 == vector4;
    bool result4 = vector1 == vector5;
    bool result5 = vector1 == vector6;
    bool result6 = vector1 == vector7;

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true)  &
                            UNIT_TEST_CASE_EQUAL(result2, false) &
                            UNIT_TEST_CASE_EQUAL(result3, true)  &
                            UNIT_TEST_CASE_EQUAL(result4, false) &
                            UNIT_TEST_CASE_EQUAL(result5, true)  &
                            UNIT_TEST_CASE_EQUAL(result6, false));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesInternalTest()
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

    float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesExternalTest()
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

    float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesConstantTest()
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

    float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesInternalTest2()
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

    float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorParenthesesExternalTest2()
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

    float result1 = vector(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarInternalTest()
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

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddScalarExternalTest()
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
bool VectorTest::operatorAddScalarConstantTest()
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
bool VectorTest::operatorAddInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

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

    // Test

    Vector<float, 3> result1 = vector1 + vector2;
    Vector<float, 3> result2 = vector1 + vector3;
    Vector<float, 3> result3 = vector1 + vector4;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddExternalTest()
{
    // Setup / Operation

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

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

    // Test

    Vector<float, 3> result1 = vector1 + vector2;
    Vector<float, 3> result2 = vector1 + vector3;
    Vector<float, 3> result3 = vector1 + vector4;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddConstantTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

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

    // Test

    Vector<float, 3> result1 = vector1 + vector2;
    Vector<float, 3> result2 = vector1 + vector3;
    Vector<float, 3> result3 = vector1 + vector4;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorAddEqualsScalarInternalTest()
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
    Vector<float, 3> result = vector;

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
bool VectorTest::operatorAddEqualsScalarExternalTest()
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
    Vector<float, 3> result = vector;

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
bool VectorTest::operatorUnaryMinusInternalTest()
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

    Vector<float, 3> result = - vector;

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
bool VectorTest::operatorUnaryMinusExternalTest()
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

    Vector<float, 3> result = - vector;

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
bool VectorTest::operatorUnaryMinusConstantTest()
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

    Vector<float, 3> result = - vector;

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
bool VectorTest::operatorSubtractScalarInternalTest()
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

    Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarExternalTest()
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

    Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractScalarConstantTest()
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

    Vector<float, 3> result = vector - 1;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector4(values4);

    // Test

    Vector<float, 3> result1 = vector1 - vector2;
    Vector<float, 3> result2 = vector1 - vector3;
    Vector<float, 3> result3 = vector1 - vector4;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractExternalTest()
{
    // Setup / Operation

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3> vector4(values4);

    // Test

    Vector<float, 3> result1 = vector1 - vector2;
    Vector<float, 3> result2 = vector1 - vector3;
    Vector<float, 3> result3 = vector1 - vector4;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractConstantTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector2(values2);

    const float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector3(values3);

    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector4(values4);

    // Test

    Vector<float, 3> result1 = vector1 - vector2;
    Vector<float, 3> result2 = vector1 - vector3;
    Vector<float, 3> result3 = vector1 - vector4;

    const float expectedValues[3] =
    {
        -2.0,
         0.0,
         2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsScalarInternalTest()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorSubtractEqualsScalarExternalTest()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        0.0,
        1.0,
        2.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarInternalTest()
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

    Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarExternalTest()
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

    Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyScalarConstantTest()
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

    Vector<float, 3> result = vector * 2;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    const float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values2);

    float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values4);

    // Test

    Matrix<float, 3, 3> result1 =  vector1 * matrix1;
    Matrix<float, 3, 3> result2 =  vector1 * matrix2;
    Matrix<float, 3, 3> result3 =  vector1 * matrix3;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
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
bool VectorTest::operatorMultiplyExternalTest()
{
    // Setup / Operation

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

    const float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values2);

    float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values4);

    // Test

    Matrix<float, 3, 3> result1 =  vector1 * matrix1;
    Matrix<float, 3, 3> result2 =  vector1 * matrix2;
    Matrix<float, 3, 3> result3 =  vector1 * matrix3;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
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
bool VectorTest::operatorMultiplyConstantTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

    const float values2[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3> matrix1(values2);

    float values3[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    Matrix<float, 1, 3, STORAGE_EXTERNAL> matrix2(values3);

    const float values4[1][3] =
    {
        { 3.0, 2.0, 1.0 }
    };

    const Matrix<float, 1, 3, STORAGE_CONSTANT> matrix3(values4);

    // Test

    Matrix<float, 3, 3> result1 =  vector1 * matrix1;
    Matrix<float, 3, 3> result2 =  vector1 * matrix2;
    Matrix<float, 3, 3> result3 =  vector1 * matrix3;

    const float expectedValues[3][3] =
    {
        { 3.0, 2.0, 1.0 },
        { 6.0, 4.0, 2.0 },
        { 9.0, 6.0, 3.0 }
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
bool VectorTest::operatorMultiplyEqualsScalarInternalTest()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::operatorMultiplyEqualsScalarExternalTest()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        2.0,
        4.0,
        6.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueInternalTest()
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

    float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueExternalTest()
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

    float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueConstantTest()
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

    float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 3.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueInternalTest2()
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

    float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::getValueExternalTest2()
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

    float result = vector.getValue(2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result, 4.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::setValuesInternalTest()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::setValuesExternalTest()
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
    Vector<float, 3> result = vector;

    const float expectedValues[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> expected(expectedValues);
    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeInternalTest()
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

    Matrix<float, 1, 3> result1 = vector.transpose();
    Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    Matrix<float, 1, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeExternalTest()
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

    Matrix<float, 1, 3> result1 = vector.transpose();
    Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    Matrix<float, 1, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::transposeConstantTest()
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

    Matrix<float, 1, 3> result1 = vector.transpose();
    Matrix<float, 1, 3> result2 = vector.T();

    const float expectedValues[1][3] =
    {
        { 1.0, 2.0, 3.0 }
    };

    Matrix<float, 1, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::magnitudeInternalTest()
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
bool VectorTest::magnitudeExternalTest()
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
bool VectorTest::magnitudeConstantTest()
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
bool VectorTest::crossProductInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

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

    // Test

    Vector<float, 3> result1 = vector1.cross(vector2);
    Vector<float, 3> result2 = vector1.cross(vector3);
    Vector<float, 3> result3 = vector1.cross(vector4);

    float expectedValues[3] =
    {
        -3.0,
         6.0,
        -3.0
    };

    Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::crossProductExternalTest()
{
    // Setup / Operation

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

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

    // Test

    Vector<float, 3> result1 = vector1.cross(vector2);
    Vector<float, 3> result2 = vector1.cross(vector3);
    Vector<float, 3> result3 = vector1.cross(vector4);

    float expectedValues[3] =
    {
        -3.0,
         6.0,
        -3.0
    };

    Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::crossProductConstantTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

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

    // Test

    Vector<float, 3> result1 = vector1.cross(vector2);
    Vector<float, 3> result2 = vector1.cross(vector3);
    Vector<float, 3> result3 = vector1.cross(vector4);

    float expectedValues[3] =
    {
        -3.0,
         6.0,
        -3.0
    };

    Vector<float, 3> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);
    const bool compare3 = (result3 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true));
}

//------------------------------------------------------------------------------
bool VectorTest::dotProductInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

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

    // Test

    const float result1 = vector1.dot(vector2);
    const float result2 = vector1.dot(vector3);
    const float result3 = vector1.dot(vector4);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result3, 32.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::dotProductExternalTest()
{
    // Setup / Operation

    float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values1);

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

    // Test

    const float result1 = vector1.dot(vector2);
    const float result2 = vector1.dot(vector3);
    const float result3 = vector1.dot(vector4);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result3, 32.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::dotProductConstantTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector1(values1);

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

    // Test

    const float result1 = vector1.dot(vector2);
    const float result2 = vector1.dot(vector3);
    const float result3 = vector1.dot(vector4);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result2, 32.0f) &
                            UNIT_TEST_CASE_EQUAL(result3, 32.0f));
}

//------------------------------------------------------------------------------
bool VectorTest::toCrossProductEquivalentMatrixInternalTest()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector(values);

    Matrix<float, 3, 3> result1 = vector.toCrossProductEquivalentMatrix();
    Matrix<float, 3, 3> result2 = vector.skew();

    // Test

    float expectedValues[3][3] =
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
bool VectorTest::toCrossProductEquivalentMatrixExternalTest()
{
    // Setup / Operation

    float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector(values);

    Matrix<float, 3, 3> result1 = vector.toCrossProductEquivalentMatrix();
    Matrix<float, 3, 3> result2 = vector.skew();

    // Test

    float expectedValues[3][3] =
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
bool VectorTest::toCrossProductEquivalentMatrixConstantTest()
{
    // Setup / Operation

    const float values[3] =
    {
        1.0,
        2.0,
        3.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector(values);

    Matrix<float, 3, 3> result1 = vector.toCrossProductEquivalentMatrix();
    Matrix<float, 3, 3> result2 = vector.skew();

    // Test

    float expectedValues[3][3] =
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
bool VectorTest::submatrixOperatorAddScalarExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 + 1;
    Vector<float, 2> result2 = submatrix2 + 1;

    const float expectedValues[2] =
    {
        6.0,
        9.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddScalarConstantTest()
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

    const Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Vector<float, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 + 1;
    Vector<float, 2> result2 = submatrix2 + 1;

    const float expectedValues[2] =
    {
        6.0,
        9.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 + submatrix2;
    Vector<float, 2> result2 = submatrix2 + submatrix1;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddConstantTest()
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

    const Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Vector<float, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 + submatrix2;
    Vector<float, 2> result2 = submatrix2 + submatrix1;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorAddEqualsScalarExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 += 1;
    submatrix2 += 1;
    Vector<float, 2>    result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Vector<float, 2>    result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

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

    Vector<float, 2>    expected1(expectedValues1);
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
bool VectorTest::submatrixOperatorUnaryMinusExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = -submatrix1;
    Vector<float, 2> result2 = -submatrix2;

    const float expectedValues[2] =
    {
        -5.0,
        -8.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorUnaryMinusConstantTest()
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

    const Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Vector<float, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = -submatrix1;
    Vector<float, 2> result2 = -submatrix2;

    const float expectedValues[2] =
    {
        -5.0,
        -8.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractScalarExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 - 1;
    Vector<float, 2> result2 = submatrix2 - 1;

    const float expectedValues[2] =
    {
        4.0,
        7.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractScalarConstantTest()
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

    const Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Vector<float, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 - 1;
    Vector<float, 2> result2 = submatrix2 - 1;

    const float expectedValues[2] =
    {
        4.0,
        7.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 - submatrix2;
    Vector<float, 2> result2 = submatrix2 - submatrix1;

    const float expectedValues1[2] =
    {
        0.0,
        6.0
    };

    const float expectedValues2[2] =
    {
         0.0,
        -6.0
    };

    Vector<float, 2> expected1(expectedValues1);
    Vector<float, 2> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractConstantTest()
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

    const Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Vector<float, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 - submatrix2;
    Vector<float, 2> result2 = submatrix2 - submatrix1;

    const float expectedValues1[2] =
    {
        0.0,
        6.0
    };

    const float expectedValues2[2] =
    {
         0.0,
        -6.0
    };

    Vector<float, 2> expected1(expectedValues1);
    Vector<float, 2> expected2(expectedValues2);

    const bool compare1 = (result1 == expected1);
    const bool compare2 = (result2 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorSubtractEqualsScalarExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 -= 1;
    submatrix2 -= 1;

    Vector<float, 2>    result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Vector<float, 2>    result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

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

    Vector<float, 2>    expected1(expectedValues1);
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
bool VectorTest::submatrixOperatorMultiplyScalarExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 * 2;
    Vector<float, 2> result2 = submatrix2 * 2;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyScalarConstantTest()
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

    const Vector<float, 2, STORAGE_CONSTANT> submatrix1(matrix1, 1, 1);
    const Vector<float, 2, STORAGE_CONSTANT> submatrix2(matrix2, 1, 1);

    // Test

    Vector<float, 2> result1 = submatrix1 * 2;
    Vector<float, 2> result2 = submatrix2 * 2;

    const float expectedValues[2] =
    {
        10.0,
        16.0
    };

    Vector<float, 2> expected(expectedValues);

    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyExternalTest()
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

    const float values3[1][3] =
    {
        { 9.0, 8.0, 7.0 }
    };

    Matrix<float, 1, 3> matrix3(values3);

    Vector<float, 3, STORAGE_EXTERNAL> submatrix1(matrix1, 0, 1);
    Vector<float, 3, STORAGE_EXTERNAL> submatrix2(matrix2, 0, 1);

    // Test

    Matrix<float, 3, 3> result1 = submatrix1 * matrix3;
    Matrix<float, 3, 3> result2 = submatrix2 * matrix3;

    const float expectedValues[3][3] =
    {
        { 18.0, 16.0, 14.0 },
        { 45.0, 40.0, 35.0 },
        { 72.0, 64.0, 56.0 },
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyConstantTest()
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

    const float values3[1][3] =
    {
        { 9.0, 8.0, 7.0 }
    };

    Matrix<float, 1, 3> matrix3(values3);

    const Vector<float, 3, STORAGE_CONSTANT> submatrix1(matrix1, 0, 1);
    const Vector<float, 3, STORAGE_CONSTANT> submatrix2(matrix2, 0, 1);

    // Test

    Matrix<float, 3, 3> result1 = submatrix1 * matrix3;
    Matrix<float, 3, 3> result2 = submatrix2 * matrix3;

    const float expectedValues[3][3] =
    {
        { 18.0, 16.0, 14.0 },
        { 45.0, 40.0, 35.0 },
        { 72.0, 64.0, 56.0 },
    };

    Matrix<float, 3, 3> expected(expectedValues);
    const bool compare1 = (result1 == expected);
    const bool compare2 = (result2 == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true));
}

//------------------------------------------------------------------------------
bool VectorTest::submatrixOperatorMultiplyEqualsScalarExternalTest()
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

    Vector<float, 2, STORAGE_EXTERNAL> submatrix1(matrix1, 1, 1);
    Vector<float, 2, STORAGE_EXTERNAL> submatrix2(matrix2, 1, 1);

    // Test

    submatrix1 *= 2;
    submatrix2 *= 2;

    Vector<float, 2>    result1 = submatrix1;
    Matrix<float, 3, 3> result2 = matrix1;
    Vector<float, 2>    result3 = submatrix2;
    Matrix<float, 3, 3> result4 = matrix2;

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
    const bool compare3 = (result3 == expected1);
    const bool compare4 = (result4 == expected2);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare1, true) &
                            UNIT_TEST_CASE_EQUAL(compare2, true) &
                            UNIT_TEST_CASE_EQUAL(compare3, true) &
                            UNIT_TEST_CASE_EQUAL(compare4, true));
}
