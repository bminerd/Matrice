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

    static bool operatorValueTypeCastInternalTest();

    static bool operatorValueTypeCastExternalTest();

    static bool operatorValueTypeCastConstantTest();

    static bool operatorValueTypeCastInternalTest2();

    static bool operatorValueTypeCastExternalTest2();

    static bool operatorValueTypeCastConstantTest2();

    static bool operatorAssignmentInternalTest();

    static bool operatorAssignmentExternalTest();

    static bool operatorAssignmentConstantTest();

    static bool operatorAssignmentInternalTest2();

    static bool operatorAssignmentExternalTest2();

    static bool operatorAssignmentConstantTest2();

    static bool operatorEqualsInternalTest();

    static bool operatorEqualsExternalTest();

    static bool operatorEqualsConstantTest();

    static bool operatorParenthesesInternalTest();

    static bool operatorParenthesesExternalTest();

    static bool operatorParenthesesConstantTest();

    static bool operatorParenthesesInternalTest2();

    static bool operatorParenthesesExternalTest2();

    static bool operatorAddScalarInternalTest();

    static bool operatorAddScalarExternalTest();

    static bool operatorAddScalarConstantTest();

    static bool operatorAddInternalTest();

    static bool operatorAddExternalTest();

    static bool operatorAddConstantTest();

    static bool operatorAddEqualsScalarInternalTest();

    static bool operatorAddEqualsScalarExternalTest();

    static bool operatorUnaryMinusInternalTest();

    static bool operatorUnaryMinusExternalTest();

    static bool operatorUnaryMinusConstantTest();

    static bool operatorSubtractScalarInternalTest();

    static bool operatorSubtractScalarExternalTest();

    static bool operatorSubtractScalarConstantTest();

    static bool operatorSubtractInternalTest();

    static bool operatorSubtractExternalTest();

    static bool operatorSubtractConstantTest();

    static bool operatorSubtractEqualsScalarInternalTest();

    static bool operatorSubtractEqualsScalarExternalTest();

    static bool operatorMultiplyScalarInternalTest();

    static bool operatorMultiplyScalarExternalTest();

    static bool operatorMultiplyScalarConstantTest();

    static bool operatorMultiply4By5InternalTest();

    static bool operatorMultiply4By5ExternalTest();

    static bool operatorMultiply4By5ConstantTest();

    static bool operatorMultiply3By3InternalTest();

    static bool operatorMultiply3By3ExternalTest();

    static bool operatorMultiply3By3ConstantTest();

    static bool operatorMultiplyEqualsScalarInternalTest();

    static bool operatorMultiplyEqualsScalarExternalTest();

    static bool getValueInternalTest();

    static bool getValueExternalTest();

    static bool getValueConstantTest();

    static bool getValueInternalTest2();

    static bool getValueExternalTest2();

    static bool setValueInternalTest();

    static bool setValueExternalTest();

    static bool setValuesInternalTest();

    static bool setValuesExternalTest();

    static bool getRowInternalTest();

    static bool getRowExternalTest();

    static bool getRowConstantTest();

    static bool getColumnInternalTest();

    static bool getColumnExternalTest();

    static bool getColumnConstantTest();

    static bool transposeInternalTest();

    static bool transposeExternalTest();

    static bool transposeConstantTest();

    static bool magnitudeInternalTest();

    static bool magnitudeExternalTest();

    static bool magnitudeConstantTest();

    static bool crossProduct3by1InternalTest();

    static bool crossProduct3by1ExternalTest();

    static bool crossProduct3by1ConstantTest();

    static bool dotProductInternalTest();

    static bool dotProductExternalTest();

    static bool dotProductConstantTest();

    static bool toCrossProductEquivalentMatrixInternalTest();

    static bool toCrossProductEquivalentMatrixExternalTest();

    static bool toCrossProductEquivalentMatrixConstantTest();

    static bool submatrixOperatorAddScalarExternalTest();

    static bool submatrixOperatorAddScalarConstantTest();

    static bool submatrixOperatorAddExternalTest();

    static bool submatrixOperatorAddConstantTest();

    static bool submatrixOperatorAddEqualsScalarExternalTest();

    static bool submatrixOperatorUnaryMinusExternalTest();

    static bool submatrixOperatorUnaryMinusConstantTest();

    static bool submatrixOperatorSubtractScalarExternalTest();

    static bool submatrixOperatorSubtractScalarConstantTest();

    static bool submatrixOperatorSubtractExternalTest();

    static bool submatrixOperatorSubtractConstantTest();

    static bool submatrixOperatorSubtractEqualsScalarExternalTest();

    static bool submatrixOperatorMultiplyScalarExternalTest();

    static bool submatrixOperatorMultiplyScalarConstantTest();

    static bool submatrixOperatorMultiplyExternalTest();

    static bool submatrixOperatorMultiplyConstantTest();

    static bool submatrixOperatorMultiplyEqualsScalarExternalTest();

    static bool submatrixGetValueExternalTest();

    static bool submatrixGetValueConstantTest();

    static bool submatrixSetValueExternalTest();

    static bool nestedSubmatrixOperatorEquals();

private:

    //--------------------------------------------------------------------------
    // Private static data members
    //--------------------------------------------------------------------------

    static const Plat4m::UnitTest::TestCallbackFunction
                                                      myTestCallbackFunctions[];
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_TEST_H
