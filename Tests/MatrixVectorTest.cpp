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
/// @file MatrixVectorTest.cpp
/// @author Andrew Harmon
/// @date 9/24/2020
/// @brief MatrixVectorTest class source file.
///

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <string.h>

#include <Plat4m_Core/Plat4m.h>

#include <Tests/MatrixVectorTest.h>
#include <Matrice/Matrix.h>
#include <Matrice/Vector.h>

using Matrice::MatrixVectorTest;
using Plat4m::UnitTest;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

const UnitTest::TestCallbackFunction
    MatrixVectorTest::myTestCallbackFunctions[] =
{
    &MatrixVectorTest::matrixTimesVectorStorageInternalTest,
    &MatrixVectorTest::matrixTimesVectorStorageExternalTest,
    &MatrixVectorTest::matrix4By5TimesVectorStorageInternalTest,
    &MatrixVectorTest::matrix4By5TimesVectorStorageExternalTest,
    &MatrixVectorTest::matrix4By5TimesVectorStorageConstantTest,
    &MatrixVectorTest::matrixAddEqualsVectorStorageInternalTest,
    &MatrixVectorTest::matrixAddEqualsVectorStorageExternalTest,
    &MatrixVectorTest::vectorAddEqualsMatrixStorageInternalTest,
    &MatrixVectorTest::vectorAddEqualsMatrixStorageExternalTest,
    &MatrixVectorTest::matrixSubtractEqualsVectorStorageInternalTest,
    &MatrixVectorTest::matrixSubtractEqualsVectorStorageExternalTest,
    &MatrixVectorTest::vectorSubtractEqualsMatrixStorageInternalTest,
    &MatrixVectorTest::vectorSubtractEqualsMatrixStorageExternalTest
};

//------------------------------------------------------------------------------
// Public constructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
MatrixVectorTest::MatrixVectorTest() :
    UnitTest("MatrixVectorTest",
             myTestCallbackFunctions,
             Plat4m::arraySize(myTestCallbackFunctions))
{
}

//------------------------------------------------------------------------------
// Public virtual destructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
MatrixVectorTest::~MatrixVectorTest()
{
}

//------------------------------------------------------------------------------
// Public static methods
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
bool MatrixVectorTest::matrixTimesVectorStorageInternalTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    const float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3> matrix1(values1);

    const float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values2);

    const float values3[3] =
    {
        14.0,
        32.0,
        50.0
    };

    Vector<float, 3> expected(values3);

    // Test

    Vector<float, 3> actual;

    actual = matrix1 * vector1;

    bool result1 = (actual == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true));
}

//------------------------------------------------------------------------------
bool MatrixVectorTest::matrixTimesVectorStorageExternalTest()
{
    //
    // Procedure:
    //
    // Test: 
    //

    // Setup / Operation

    static float values1[3][3] =
    {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    Matrix<float, 3, 3, STORAGE_EXTERNAL> matrix1(values1);

    static float values2[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector1(values2);

    static const float values3[3] =
    {
        14.0,
        32.0,
        50.0
    };

    Vector<float, 3> expected(values3);

    // Test

    static float values4[3] =
    {
        0.0,
        0.0,
        0.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> actual(values4);

    actual = matrix1 * vector1;

    bool result1 = (actual == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(result1, true));
}

//------------------------------------------------------------------------------
bool MatrixVectorTest::matrix4By5TimesVectorStorageInternalTest()
{
    // Setup / Operation

    const float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    Matrix<float, 4, 5> matrix1(values1);

    const float values2[5] =
    {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0
    };

    Vector<float, 5> vector1(values2);

    const float values3[4] =
    {
         55.0,
        130.0,
        205.0,
        280.0
    };

    Vector<float, 4> expected(values3);

    // Test

    Vector<float, 4> result = matrix1 * vector1;

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixVectorTest::matrix4By5TimesVectorStorageExternalTest()
{
    // Setup / Operation

    float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    Matrix<float, 4, 5, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[5] =
    {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0
    };

    Vector<float, 5> vector1(values2);

    const float values3[4] =
    {
         55.0,
        130.0,
        205.0,
        280.0
    };

    Vector<float, 4> expected(values3);

    // Test

    Vector<float, 4> result = matrix1 * vector1;

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixVectorTest::matrix4By5TimesVectorStorageConstantTest()
{
    // Setup / Operation

    const float values1[4][5] =
    {
        {  1.0,  2.0,  3.0,  4.0,  5.0 },
        {  6.0,  7.0,  8.0,  9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 }
    };

    const Matrix<float, 4, 5, STORAGE_CONSTANT> matrix1(values1);

    const float values2[5] =
    {
        1.0,
        2.0,
        3.0,
        4.0,
        5.0
    };

    Vector<float, 5> vector1(values2);

    const float values3[4] =
    {
         55.0,
        130.0,
        205.0,
        280.0
    };

    Vector<float, 4> expected(values3);

    // Test

    Vector<float, 4> result = matrix1 * vector1;

    const bool compare = (result == expected);

    return UNIT_TEST_REPORT(UNIT_TEST_CASE_EQUAL(compare, true));
}

//------------------------------------------------------------------------------
bool MatrixVectorTest::matrixAddEqualsVectorStorageInternalTest()
{
    // Setup / Operation

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1> matrix1(values1);

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector1(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values4);

    // Test

    matrix1 += vector1;
    Matrix<float, 3, 1> result1 = matrix1;

    matrix1 = Matrix<float, 3, 1>(values1);

    matrix1 += vector2;
    Matrix<float, 3, 1> result2 = matrix1;

    matrix1 = Matrix<float, 3, 1>(values1);

    matrix1 += vector3;
    Matrix<float, 3, 1> result3 = matrix1;

    const float expectedValues[3][1] =
    {
        { 4.0 },
        { 4.0 },
        { 4.0 }
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
bool MatrixVectorTest::matrixAddEqualsVectorStorageExternalTest()
{
    // Setup / Operation

    const float initialValues[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector1(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values4);

    // Test

    matrix1 += vector1;
    Matrix<float, 3, 1> result1 = matrix1;

    matrix1 = Matrix<float, 3, 1>(initialValues);

    matrix1 += vector2;
    Matrix<float, 3, 1> result2 = matrix1;

    matrix1 = Matrix<float, 3, 1>(initialValues);

    matrix1 += vector3;
    Matrix<float, 3, 1> result3 = matrix1;

    const float expectedValues[3][1] =
    {
        { 4.0 },
        { 4.0 },
        { 4.0 }
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
bool MatrixVectorTest::vectorAddEqualsMatrixStorageInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    const float values2[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1> matrix1(values2);

    float values3[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix2(values3);
    
    const float values4[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix3(values4);

    // Test

    vector1 += matrix1;
    Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += matrix2;
    Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 += matrix3;
    Vector<float, 3> result3 = vector1;

    const float expectedValues[3] =
    {
        4.0,
        4.0,
        4.0
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
bool MatrixVectorTest::vectorAddEqualsMatrixStorageExternalTest()
{
    // Setup / Operation

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

    const float values2[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1> matrix1(values2);

    float values3[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix2(values3);
    
    const float values4[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix3(values4);

    // Test

    vector1 += matrix1;
    Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += matrix2;
    Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 += matrix3;
    Vector<float, 3> result3 = vector1;

    const float expectedValues[3] =
    {
        4.0,
        4.0,
        4.0
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
bool MatrixVectorTest::matrixSubtractEqualsVectorStorageInternalTest()
{
    // Setup / Operation

    const float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1> matrix1(values1);

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector1(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values4);

    // Test

    matrix1 -= vector1;
    Matrix<float, 3, 1> result1 = matrix1;

    matrix1 = Matrix<float, 3, 1>(values1);

    matrix1 -= vector2;
    Matrix<float, 3, 1> result2 = matrix1;

    matrix1 = Matrix<float, 3, 1>(values1);

    matrix1 -= vector3;
    Matrix<float, 3, 1> result3 = matrix1;

    const float expectedValues[3][1] =
    {
        { -2.0 },
        {  0.0 },
        {  2.0 }
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
bool MatrixVectorTest::matrixSubtractEqualsVectorStorageExternalTest()
{
    // Setup / Operation

    const float initialValues[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    float values1[3][1] =
    {
        { 1.0 },
        { 2.0 },
        { 3.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix1(values1);

    const float values2[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3> vector1(values2);

    float values3[3] =
    {
        3.0,
        2.0,
        1.0
    };

    Vector<float, 3, STORAGE_EXTERNAL> vector2(values3);
    
    const float values4[3] =
    {
        3.0,
        2.0,
        1.0
    };

    const Vector<float, 3, STORAGE_CONSTANT> vector3(values4);

    // Test

    matrix1 -= vector1;
    Matrix<float, 3, 1> result1 = matrix1;

    matrix1 = Matrix<float, 3, 1>(initialValues);

    matrix1 -= vector2;
    Matrix<float, 3, 1> result2 = matrix1;

    matrix1 = Matrix<float, 3, 1>(initialValues);

    matrix1 -= vector3;
    Matrix<float, 3, 1> result3 = matrix1;

    const float expectedValues[3][1] =
    {
        { -2.0 },
        {  0.0 },
        {  2.0 }
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
bool MatrixVectorTest::vectorSubtractEqualsMatrixStorageInternalTest()
{
    // Setup / Operation

    const float values1[3] =
    {
        1.0,
        2.0,
        3.0
    };

    Vector<float, 3> vector1(values1);

    const float values2[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1> matrix1(values2);

    float values3[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix2(values3);
    
    const float values4[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix3(values4);

    // Test

    vector1 -= matrix1;
    Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= matrix2;
    Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(values1);

    vector1 -= matrix3;
    Vector<float, 3> result3 = vector1;

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
bool MatrixVectorTest::vectorSubtractEqualsMatrixStorageExternalTest()
{
    // Setup / Operation

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

    const float values2[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1> matrix1(values2);

    float values3[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    Matrix<float, 3, 1, STORAGE_EXTERNAL> matrix2(values3);
    
    const float values4[3][1] =
    {
        { 3.0 },
        { 2.0 },
        { 1.0 }
    };

    const Matrix<float, 3, 1, STORAGE_CONSTANT> matrix3(values4);

    // Test

    vector1 -= matrix1;
    Vector<float, 3> result1 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= matrix2;
    Vector<float, 3> result2 = vector1;

    vector1 = Vector<float, 3>(initialValues);

    vector1 -= matrix3;
    Vector<float, 3> result3 = vector1;

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
