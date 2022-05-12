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
/// @file MatrixTest.h
/// @author Ben Minerd
/// @date 5/1/2020
/// @brief MatrixTest class header file.
///

#ifndef MATRICE_MATRIX_TEST_H
#define MATRICE_MATRIX_TEST_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>

#include <Matrice/MatrixInterface.h>

#include <Plat4m_Core/UnitTest/UnitTest.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

class MatrixTest : public Plat4m::UnitTest
{
public:
    
    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    MatrixTest();

    //--------------------------------------------------------------------------
    // Public virtual destructors
    //--------------------------------------------------------------------------

    virtual ~MatrixTest();

    //--------------------------------------------------------------------------
    // Public static methods
    //--------------------------------------------------------------------------

    template <typename ValueType,
              std::uint32_t N1,
              std::uint32_t M1,
              std::uint32_t N2,
              std::uint32_t M2,
              std::uint32_t N3,
              std::uint32_t M3,
              typename ValuePointerType1,
              typename ValuePointerType2>
    static void testFunction(
             const MatrixInterface<ValueType, N1, M1, ValuePointerType1>& matrix1,
             const MatrixInterface<ValueType, N2, M2, ValuePointerType2>& matrix2,
             MatrixInterface<ValueType, N3, M3>& result)
    {
        result = matrix1 * matrix2;
    }

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

    static bool operatorSubtractEqualsScalarTestInternal();
    static bool operatorSubtractEqualsScalarTestExternal();
    static bool operatorSubtractEqualsScalarTestInternalRunTime();
    static bool operatorSubtractEqualsScalarTestExternalRunTime();

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

    static bool operatorMultiplyTest4By5InternalTimes5By4();
    static bool operatorMultiplyTest4By5ExternalTimes5By4();
    static bool operatorMultiplyTest4By5ConstantTimes5By4();
    static bool operatorMultiplyTest4By5InternalRunTimeTimes5By4();
    static bool operatorMultiplyTest4By5ExternalRunTimeTimes5By4();
    static bool operatorMultiplyTest4By5ConstantRunTimeTimes5By4();

    static bool operatorMultiplyTest3By3InternalTimes3By3();
    static bool operatorMultiplyTest3By3ExternalTimes3By3();
    static bool operatorMultiplyTest3By3ConstantTimes3By3();
    static bool operatorMultiplyTest3By3InternalRunTimeTimes3By3();
    static bool operatorMultiplyTest3By3ExternalRunTimeTimes3By3();
    static bool operatorMultiplyTest3By3ConstantRunTimeTimes3By3();

    static bool operatorMultiplyTestInternalTimesVector();
    static bool operatorMultiplyTestExternalTimesVector();
    static bool operatorMultiplyTestConstantTimesVector();
    static bool operatorMultiplyTestInternalRunTimeTimesVector();
    static bool operatorMultiplyTestExternalRunTimeTimesVector();
    static bool operatorMultiplyTestConstantRunTimeTimesVector();

    static bool operatorMultiplyEqualsScalarTestInternal();
    static bool operatorMultiplyEqualsScalarTestExternal();
    static bool operatorMultiplyEqualsScalarTestInternalRunTime();
    static bool operatorMultiplyEqualsScalarTestExternalRunTime();

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

    static bool getRowTestInternal();
    static bool getRowTestExternal();
    static bool getRowTestConstant();
    static bool getRowTestInternalRunTime();
    static bool getRowTestExternalRunTime();
    static bool getRowTestConstantRunTime();

    static bool getColumnTestInternal();
    static bool getColumnTestExternal();
    static bool getColumnTestConstant();
    static bool getColumnTestInternalRunTime();
    static bool getColumnTestExternalRunTime();
    static bool getColumnTestConstantRunTime();

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

    static bool crossProductTest3by1Internal();
    static bool crossProductTest3by1External();
    static bool crossProductTest3by1Constant();
    // Matrices with run-time dimensions currently don't support cross product

    static bool dotProductTestInternal();
    static bool dotProductTestExternal();
    static bool dotProductTestConstant();
    // Matrices with run-time dimensions currently don't support dot product

    static bool toCrossProductEquivalentMatrixTestInternal();
    static bool toCrossProductEquivalentMatrixTestExternal();
    static bool toCrossProductEquivalentMatrixTestConstant();
    // Matrices with run-time dimensions currently don't support cross product
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

    static bool submatrixOperatorMultiplyTest2By2ExternalTimes2By2();
    static bool submatrixOperatorMultiplyTest2By2ConstantTimes2By2();
    static bool submatrixOperatorMultiplyTest2By2ExternalRunTimeTimes2By2();
    static bool submatrixOperatorMultiplyTest2By2ConstantRunTimeTimes2By2();

    static bool submatrixOperatorMultiplyTest2By2ExternalTimesVector();
    static bool submatrixOperatorMultiplyTest2By2ConstantTimesVector();
    static bool submatrixOperatorMultiplyTest2By2ExternalRunTimeTimesVector();
    static bool submatrixOperatorMultiplyTest2By2ConstantRunTimeTimesVector();

    static bool submatrixOperatorMultiplyTestEqualsScalarExternal();
    static bool submatrixOperatorMultiplyTestEqualsScalarExternalRunTime();

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
    static bool nestedSubmatrixOperatorEqualsTestExternalRunTime();

private:

    //--------------------------------------------------------------------------
    // Private static data members
    //--------------------------------------------------------------------------

    static const Plat4m::UnitTest::TestCallbackFunction
                                                      myTestCallbackFunctions[];
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_TEST_H
