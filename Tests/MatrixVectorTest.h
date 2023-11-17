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
/// @file MatrixVectorTest.h
/// @author Andrew Harmon
/// @date 9/24/2020
/// @brief MatrixVectorTest class header file.
///

#ifndef MATRICE_MATRIX_VECTOR_TEST_H
#define MATRICE_MATRIX_VECTOR_TEST_H

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

class MatrixVectorTest : public Plat4m::UnitTest
{
public:
    
    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    MatrixVectorTest();

    //--------------------------------------------------------------------------
    // Public virtual destructors
    //--------------------------------------------------------------------------

    virtual ~MatrixVectorTest();

    //--------------------------------------------------------------------------
    // Public static methods
    //--------------------------------------------------------------------------

    static bool matrixTimesVectorStorageInternalTest();
    static bool matrixTimesVectorStorageExternalTest();

    static bool matrix4By5TimesVectorStorageInternalTest();
    static bool matrix4By5TimesVectorStorageExternalTest();
    static bool matrix4By5TimesVectorStorageConstantTest();
    
    static bool matrixAddEqualsVectorStorageInternalTest();
    static bool matrixAddEqualsVectorStorageExternalTest();

    static bool vectorAddEqualsMatrixStorageInternalTest();
    static bool vectorAddEqualsMatrixStorageExternalTest();

    static bool matrixSubtractEqualsVectorStorageInternalTest();
    static bool matrixSubtractEqualsVectorStorageExternalTest();

    static bool vectorSubtractEqualsMatrixStorageInternalTest();
    static bool vectorSubtractEqualsMatrixStorageExternalTest();

private:

    //--------------------------------------------------------------------------
    // Private static data members
    //--------------------------------------------------------------------------

    static const Plat4m::UnitTest::TestCallbackFunction
                                                      myTestCallbackFunctions[];
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_VECTOR_TEST_H
