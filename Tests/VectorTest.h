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
/// @file VectorTest.h
/// @author Ben Minerd
/// @date 9/23/2020
/// @brief VectorTest class header file.
///

#ifndef MATRICE_VECTOR_TEST_H
#define MATRICE_VECTOR_TEST_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <Plat4m_Core/UnitTest/UnitTest.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

class VectorTest : public Plat4m::UnitTest
{
public:
    
    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    VectorTest();

    //--------------------------------------------------------------------------
    // Public virtual destructors
    //--------------------------------------------------------------------------

    virtual ~VectorTest();

    //--------------------------------------------------------------------------
    // Public static methods
    //--------------------------------------------------------------------------

    static bool operatorValueTypeCastTestInternal();
    static bool operatorValueTypeCastTestExternal();
    static bool operatorValueTypeCastTestConstant();

    static bool operatorValueTypeCastTest2Internal();
    static bool operatorValueTypeCastTest2External();
    static bool operatorValueTypeCastTest2Constant();
    static bool operatorValueTypeCastTest2InternalRunTime();
    static bool operatorValueTypeCastTest2ExternalRunTime();
    static bool operatorValueTypeCastTest2ConstantRunTime();

    static bool operatorAssignmentTestInternal();
    static bool operatorAssignmentTestExternal();
    static bool operatorAssignmentTestConstant();
    static bool operatorAssignmentTestInternalRunTime();
    static bool operatorAssignmentTestExternalRunTime();
    static bool operatorAssignmentTestConstantRunTime();

    static bool operatorAssignmentTest2Internal();
    static bool operatorAssignmentTest2External();
    static bool operatorAssignmentTest2Constant();
    static bool operatorAssignmentTest2InternalRunTime();
    static bool operatorAssignmentTest2ExternalRunTime();
    static bool operatorAssignmentTest2ConstantRunTime();

    static bool operatorEqualsTestInternal();
    static bool operatorEqualsTestExternal();
    static bool operatorEqualsTestConstant();
    static bool operatorEqualsTestInternalRunTime();
    static bool operatorEqualsTestExternalRunTime();
    static bool operatorEqualsTestConstantRunTime();

    static bool operatorEqualsTest2Internal();
    static bool operatorEqualsTest2External();
    static bool operatorEqualsTest2Constant();
    static bool operatorEqualsTest2InternalRunTime();
    static bool operatorEqualsTest2ExternalRunTime();
    static bool operatorEqualsTest2ConstantRunTime();

    static bool operatorParenthesesTestInternal();
    static bool operatorParenthesesTestExternal();
    static bool operatorParenthesesTestConstant();
    static bool operatorParenthesesTestInternalRunTime();
    static bool operatorParenthesesTestExternalRunTime();
    static bool operatorParenthesesTestConstantRunTime();

    static bool operatorParenthesesTest2Internal();
    static bool operatorParenthesesTest2External();
    static bool operatorParenthesesTest2InternalRunTime();
    static bool operatorParenthesesTest2ExternalRunTime();

    static bool operatorAddScalarTestInternal();
    static bool operatorAddScalarTestExternal();
    static bool operatorAddScalarTestConstant();
    static bool operatorAddScalarTestInternalRunTime();
    static bool operatorAddScalarTestExternalRunTime();
    static bool operatorAddScalarTestConstantRunTime();

    static bool operatorAddTestInternal();
    static bool operatorAddTestExternal();
    static bool operatorAddTestConstant();
    static bool operatorAddTestInternalRunTime();
    static bool operatorAddTestExternalRunTime();
    static bool operatorAddTestConstantRunTime();

    static bool operatorAddEqualsScalarTestInternal();
    static bool operatorAddEqualsScalarTestExternal();
    static bool operatorAddEqualsScalarTestInternalRunTime();
    static bool operatorAddEqualsScalarTestExternalRunTime();

    static bool operatorAddEqualsTestInternal();
    static bool operatorAddEqualsTestExternal();
    static bool operatorAddEqualsTestInternalRunTime();
    static bool operatorAddEqualsTestExternalRunTime();

    static bool operatorUnaryMinusTestInternal();
    static bool operatorUnaryMinusTestExternal();
    static bool operatorUnaryMinusTestConstant();
    static bool operatorUnaryMinusTestInternalRunTime();
    static bool operatorUnaryMinusTestExternalRunTime();
    static bool operatorUnaryMinusTestConstantRunTime();

    static bool operatorSubtractScalarTestInternal();
    static bool operatorSubtractScalarTestExternal();
    static bool operatorSubtractScalarTestConstant();
    static bool operatorSubtractScalarTestInternalRunTime();
    static bool operatorSubtractScalarTestExternalRunTime();
    static bool operatorSubtractScalarTestConstantRunTime();

    static bool operatorSubtractTestInternal();
    static bool operatorSubtractTestExternal();
    static bool operatorSubtractTestConstant();
    static bool operatorSubtractTestInternalRunTime();
    static bool operatorSubtractTestExternalRunTime();
    static bool operatorSubtractTestConstantRunTime();

    static bool operatorSubtractEqualsTestScalarInternal();
    static bool operatorSubtractEqualsTestScalarExternal();
    static bool operatorSubtractEqualsTestScalarInternalRunTime();
    static bool operatorSubtractEqualsTestScalarExternalRunTime();

    static bool operatorSubtractEqualsTestInternal();
    static bool operatorSubtractEqualsTestExternal();
    static bool operatorSubtractEqualsTestInternalRunTime();
    static bool operatorSubtractEqualsTestExternalRunTime();

    static bool operatorMultiplyScalarTestInternal();
    static bool operatorMultiplyScalarTestExternal();
    static bool operatorMultiplyScalarTestConstant();
    static bool operatorMultiplyScalarTestInternalRunTime();
    static bool operatorMultiplyScalarTestExternalRunTime();
    static bool operatorMultiplyScalarTestConstantRunTime();

    static bool operatorMultiplyTestInternal();
    static bool operatorMultiplyTestExternal();
    static bool operatorMultiplyTestConstant();
    static bool operatorMultiplyTestInternalRunTime();
    static bool operatorMultiplyTestExternalRunTime();
    static bool operatorMultiplyTestConstantRunTime();

    static bool operatorMultiplyEqualsTestScalarInternal();
    static bool operatorMultiplyEqualsTestScalarExternal();
    static bool operatorMultiplyEqualsTestScalarInternalRunTime();
    static bool operatorMultiplyEqualsTestScalarExternalRunTime();

    static bool getValueTestInternal();
    static bool getValueTestExternal();
    static bool getValueTestConstant();
    static bool getValueTestInternalRunTime();
    static bool getValueTestExternalRunTime();
    static bool getValueTestConstantRunTime();

    static bool getValueTest2Internal();
    static bool getValueTest2External();
    static bool getValueTest2InternalRunTime();
    static bool getValueTest2ExternalRunTime();

    static bool setValueTestInternal();
    static bool setValueTestExternal();
    static bool setValueTestInternalRunTime();
    static bool setValueTestExternalRunTime();

    static bool setValuesTestInternal();
    static bool setValuesTestExternal();
    static bool setValuesTestInternalRunTime();
    static bool setValuesTestExternalRunTime();

    static bool transposeTestInternal();
    static bool transposeTestExternal();
    static bool transposeTestConstant();
    static bool transposeTestInternalRunTime();
    static bool transposeTestExternalRunTime();
    static bool transposeTestConstantRunTime();

    static bool magnitudeTestInternal();
    static bool magnitudeTestExternal();
    static bool magnitudeTestConstant();
    static bool magnitudeTestInternalRunTime();
    static bool magnitudeTestExternalRunTime();
    static bool magnitudeTestConstantRunTime();

    static bool crossProductTestInternal();
    static bool crossProductTestExternal();
    static bool crossProductTestConstant();
    // Vectors with run-time dimensions currently don't support cross product

    static bool dotProductTestInternal();
    static bool dotProductTestExternal();
    static bool dotProductTestConstant();
    // Vectors with run-time dimensions currently don't support dot product

    static bool toCrossProductEquivalentMatrixTestInternal();
    static bool toCrossProductEquivalentMatrixTestExternal();
    static bool toCrossProductEquivalentMatrixTestConstant();
    // Vectors with run-time dimensions currently don't support cross product
    // equivalent matrix

    static bool printTestInternal();
    static bool printTestExternal();
    static bool printTestConstant();
    static bool printTestInternalRunTime();
    static bool printTestExternalRunTime();
    static bool printTestConstantRunTime();

    static bool submatrixOperatorAddScalarTestExternal();
    static bool submatrixOperatorAddScalarTestConstant();
    static bool submatrixOperatorAddScalarTestExternalRunTime();
    static bool submatrixOperatorAddScalarTestConstantRunTime();

    static bool submatrixOperatorAddTestExternal();
    static bool submatrixOperatorAddTestConstant();
    static bool submatrixOperatorAddTestExternalRunTime();
    static bool submatrixOperatorAddTestConstantRunTime();

    static bool submatrixOperatorAddEqualsScalarTestExternal();
    static bool submatrixOperatorAddEqualsScalarTestExternalRunTime();

    static bool submatrixOperatorAddEqualsTestExternal();
    static bool submatrixOperatorAddEqualsTestExternalRunTime();

    static bool submatrixOperatorUnaryMinusTestExternal();
    static bool submatrixOperatorUnaryMinusTestConstant();
    static bool submatrixOperatorUnaryMinusTestExternalRunTime();
    static bool submatrixOperatorUnaryMinusTestConstantRunTime();

    static bool submatrixOperatorSubtractScalarTestExternal();
    static bool submatrixOperatorSubtractScalarTestConstant();
    static bool submatrixOperatorSubtractScalarTestExternalRunTime();
    static bool submatrixOperatorSubtractScalarTestConstantRunTime();

    static bool submatrixOperatorSubtractTestExternal();
    static bool submatrixOperatorSubtractTestConstant();
    static bool submatrixOperatorSubtractTestExternalRunTime();
    static bool submatrixOperatorSubtractTestConstantRunTime();

    static bool submatrixOperatorSubtractEqualsScalarTestExternal();
    static bool submatrixOperatorSubtractEqualsScalarTestExternalRunTime();

    static bool submatrixOperatorSubtractEqualsTestExternal();
    static bool submatrixOperatorSubtractEqualsTestExternalRunTime();

    static bool submatrixOperatorMultiplyScalarTestExternal();
    static bool submatrixOperatorMultiplyScalarTestConstant();
    static bool submatrixOperatorMultiplyScalarTestExternalRunTime();
    static bool submatrixOperatorMultiplyScalarTestConstantRunTime();

    static bool submatrixOperatorMultiplyTestExternal();
    static bool submatrixOperatorMultiplyTestConstant();
    static bool submatrixOperatorMultiplyTestExternalRunTime();
    static bool submatrixOperatorMultiplyTestConstantRunTime();

    static bool submatrixOperatorMultiplyEqualsTestScalarExternal();
    static bool submatrixOperatorMultiplyEqualsTestScalarExternalRunTime();

    static bool submatrixGetValueTestExternal();
    static bool submatrixGetValueTestConstant();
    static bool submatrixGetValueTestExternalRunTime();
    static bool submatrixGetValueTestConstantRunTime();

    static bool submatrixSetValueTestExternal();
    static bool submatrixSetValueTestExternalRunTime();

    static bool submatrixTransposeTestExternal();
    static bool submatrixTransposeTestConstant();
    static bool submatrixTransposeTestExternalRunTime();
    static bool submatrixTransposeTestConstantRunTime();

    static bool submatrixPrintTestExternal();
    static bool submatrixPrintTestConstant();
    static bool submatrixPrintTestExternalRunTime();
    static bool submatrixPrintTestConstantRunTime();

    static bool nestedSubmatrixOperatorEqualsTestExternal();
    static bool nestedSubmatrixOperatorEqualsTestConstant();
    static bool nestedSubmatrixOperatorEqualsTestExternalRunTime();
    static bool nestedSubmatrixOperatorEqualsTestConstantRunTime();

    static bool subvectorOperatorEqualsTestExternal();
    static bool subvectorOperatorEqualsTestConstant();
    static bool subvectorOperatorEqualsTestExternalRunTime();
    static bool subvectorOperatorEqualsTestConstantRunTime();

private:

    //--------------------------------------------------------------------------
    // Private static data members
    //--------------------------------------------------------------------------

    static const Plat4m::UnitTest::TestCallbackFunction
                                                      myTestCallbackFunctions[];
};

}; // namespace Matrice

#endif // MATRICE_VECTOR_TEST_H
