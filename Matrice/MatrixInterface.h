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
/// @file MatrixInterface.h
/// @author Ben Minerd
/// @date 9/4/2020
/// @brief MatrixInterface class header file.
///

#ifndef MATRICE_MATRIX_INTERFACE_H
#define MATRICE_MATRIX_INTERFACE_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>

#include <Matrice/Matrice.h>
#include <Matrice/MatrixBase.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Forward class declarations
//------------------------------------------------------------------------------

template <typename ValueType, uint32_t N, uint32_t M, Storage>
class Matrix;

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

///
/// @brief Parent class for all outer API matrix-based classes. Specializations
/// (ex. 3x1 Matrix / Vector) can be added by inheriting from this class.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of rows.
/// @tparam M Number of columns.
/// @note Currently supports only row-major matrices.
/// @note The underlying array indexing is done by incrementing pointers.
/// Normally this approach is avoided due to poor readability, but the
/// performance gains are ~10x versus using for-loops and standard indexing.
///
template <typename ValueType, uint32_t N, uint32_t M>
class MatrixInterface : public MatrixBase<ValueType>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixInterface(ValueType storageValues[N][M]) :
        MatrixBase<ValueType>(N, M, (ValueType*) storageValues, 0)
    {
    }

    //--------------------------------------------------------------------------
    MatrixInterface(ValueType storageValues[N][M],
                    const ValueType initializationValues[N][M]) :
        MatrixBase<ValueType>(N,
                              M,
                              (ValueType*) storageValues,
                              0,
                              (ValueType*) initializationValues)
    {
    }
    
    //--------------------------------------------------------------------------
    MatrixInterface(ValueType storageValues[N][M],
                    const MatrixInterface<ValueType, N, M>& matrix) :
        MatrixBase<ValueType>(N, M, (ValueType*) storageValues, 0, matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, uint32_t ParentM>
    MatrixInterface(MatrixInterface<ValueType, ParentN, ParentM>& matrix,
                    const uint32_t row,
                    const uint32_t column) :
        MatrixBase<ValueType>(
                             N,
                             M,
                             &(matrix.getValue(row, column)), (ParentM - M) + 1)
    {
        if (((row + N + 1) > ParentN) || ((column + M + 1) > ParentM))
        {
            // Error, submatrix beyond parent matrix bounds
        }
    }

    //--------------------------------------------------------------------------
    MatrixInterface(const MatrixInterface<ValueType, N, M>& matrix) :
        MatrixBase<ValueType>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~MatrixInterface()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M>& operator=(
                                 const MatrixInterface<ValueType, N, M>& matrix)
    {
        MatrixBase<ValueType>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M>& operator=(const ValueType values[N][M])
    {
        MatrixBase<ValueType>::setValuesProtected((ValueType*) values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    bool operator==(const MatrixInterface<ValueType, N, M>& matrix)
    {
        return MatrixBase<ValueType>::operatorEquals(matrix);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const uint32_t row, const uint32_t column)
    {
        return MatrixBase<ValueType>::getValue(row, column);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row, const uint32_t column) const
    {
        return MatrixBase<ValueType>::getValue(row, column);
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+() const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::operatorUnaryPlus(matrix);

        return matrix;
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::operatorAddScalar(matrix, scalar);

        return matrix;
    }

    // Addition operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+(
                           const MatrixInterface<ValueType, N, M>& matrix) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType>::operatorAdd(matrix, resultMatrix);

        return resultMatrix;
    }

    // Addition-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M>& operator+=(const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorAddEqualsScalar(scalar);

        return (*this);
    }

    // Unary minus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-() const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::operatorUnaryMinus(matrix);

        return matrix;
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::operatorSubtractScalar(matrix, scalar);
        
        return matrix;
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-(
                           const MatrixInterface<ValueType, N, M>& matrix) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType>::operatorSubtract(matrix, resultMatrix);

        return resultMatrix;
    }

    // Subtraction-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M>& operator-=(const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorSubtractEqualsScalar(scalar);

        return (*this);
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator*(const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::operatorMultiplyScalar(matrix, scalar);

        return matrix;
    }

    // Multiplication operator (N by M)
    //--------------------------------------------------------------------------
    template <uint32_t M2>
    Matrix<ValueType, N, M2, STORAGE_INTERNAL> operator*(
                          const MatrixInterface<ValueType, M, M2>& matrix) const
    {
        Matrix<ValueType, N, M2, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType>::operatorMultiplyNByM(matrix, resultMatrix);
        
        return resultMatrix;
    }

    // Multiplication operator (N by 1)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> operator*(
                           const MatrixInterface<ValueType, M, 1>& matrix) const
    {
        Matrix<ValueType, N, 1, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType>::operatorMultiplyNBy1(matrix, resultMatrix);

        return resultMatrix;
    }

    // Multiplication-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M>& operator*=(const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorMultiplyEqualsScalar(scalar);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[N][M])
    {
        MatrixBase<ValueType>::setValuesProtected((ValueType*) values);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, N, STORAGE_INTERNAL> getRow(const uint32_t row)
    {
        Matrix<ValueType, 1, N, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::getRow(matrix, row);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, N, STORAGE_INTERNAL> row(const uint32_t row)
    {
        return getRow(row);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> getColumn(const uint32_t column)
    {
        Matrix<ValueType, N, 1, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::getColumn(matrix, column);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> col(const uint32_t column)
    {
        return getColumn(column);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, M, N, STORAGE_INTERNAL> transpose() const
    {
        Matrix<ValueType, M, N, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType>::transpose(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, M, N, STORAGE_INTERNAL> T() const
    {
        return transpose();
    }
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_INTERFACE_H