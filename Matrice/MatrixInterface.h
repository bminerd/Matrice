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

template <typename ValueType, std::uint32_t N, std::uint32_t M, Storage>
class Matrix;

template <typename ValueType, std::uint32_t N, Storage>
class Vector;

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
template <typename ValueType,
          std::uint32_t N,
          std::uint32_t M,
          typename ValuePointerType = ValueType>
class MatrixInterface : public MatrixBase<ValueType, ValuePointerType>
{
public:

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <typename ValueType2>
    operator Matrix<ValueType2, N, M, STORAGE_INTERNAL>() const
    {
        Matrix<ValueType2, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::operatorTypeCast(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    template <typename ValueType2>
    operator Vector<ValueType2, N, STORAGE_INTERNAL>() const
    {
        Vector<ValueType2, N, STORAGE_INTERNAL> vector;

        MatrixBase<ValueType, ValuePointerType>::operatorTypeCast(vector);

        return vector;
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator=(
               const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator=(
              const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator=(
                                            const ValuePointerType values[N][M])
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(
                                                    (ValuePointerType*) values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    bool operator==(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        return MatrixBase<ValueType, ValuePointerType>::operatorEquals(matrix);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const std::uint32_t row, const std::uint32_t column)
    {
        return MatrixBase<ValueType, ValuePointerType>::getValueFast(row,
                                                                     column);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t row,
                                const std::uint32_t column) const
    {
        return MatrixBase<ValueType, ValuePointerType>::getValueFast(row,
                                                                     column);
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+() const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::operatorUnaryPlus(matrix);

        return matrix;
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::operatorAddScalar(matrix,
                                                                   scalar);

        return matrix;
    }

    // Addition operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType, ValuePointerType>::operatorAdd(matrix,
                                                             resultMatrix);

        return resultMatrix;
    }

    // Addition-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator+=(
                                                         const ValueType scalar)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorAddEqualsScalar(
                                                                        scalar);

        return (*this);
    }

    // Addition-equals operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator+=(
              const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorAddEquals(matrix);

        return (*this);
    }

    // Unary minus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-() const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::operatorUnaryMinus(matrix);

        return matrix;
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::operatorSubtractScalar(matrix,
                                                                        scalar);
        
        return matrix;
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType, ValuePointerType>::operatorSubtract(matrix,
                                                                  resultMatrix);

        return resultMatrix;
    }

    // Subtraction-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M>& operator-=(const ValueType scalar)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorSubtractEqualsScalar(
                                                                        scalar);

        return (*this);
    }

    // Subtraction-equals operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface<ValueType, N, M>& operator-=(
              const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorSubtractEquals(matrix);

        return (*this);
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator*(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyScalar(matrix,
                                                                        scalar);

        return matrix;
    }

    // Multiplication operator (this * M by M2)
    //--------------------------------------------------------------------------
    template <std::uint32_t M2, typename ValuePointerType2>
    Matrix<ValueType, N, M2, STORAGE_INTERNAL> operator*(
        const MatrixInterface<ValueType, M, M2, ValuePointerType2>& matrix)
                                                                           const
    {
        Matrix<ValueType, N, M2, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyMByM2(
                                                                  matrix,                                                          
                                                                  resultMatrix);
        
        return resultMatrix;
    }

    // Multiplication operator (this * M by 1)
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> operator*(
        const MatrixInterface<ValueType, M, 1, ValuePointerType2>& matrix) const
    {
        Matrix<ValueType, N, 1, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyMBy1(
                                                                  matrix,
                                                                  resultMatrix);

        return resultMatrix;
    }

    // Multiplication-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator*=(
                                                         const ValueType scalar)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyEqualsScalar(
                                                                        scalar);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType, ValuePointerType>::setValues;

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[N][M])
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected((
                                                            ValueType*) values);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, N, STORAGE_INTERNAL> getRow(
                                                  const std::uint32_t row) const
    {
        Matrix<ValueType, 1, N, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::getRow(matrix, row);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, N, STORAGE_INTERNAL> row(const std::uint32_t row) const
    {
        return getRow(row);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> getColumn(
                                               const std::uint32_t column) const
    {
        Matrix<ValueType, N, 1, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::getColumn(matrix, column);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> col(
                                               const std::uint32_t column) const
    {
        return getColumn(column);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, M, N, STORAGE_INTERNAL> transpose() const
    {
        Matrix<ValueType, M, N, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::transpose(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, M, N, STORAGE_INTERNAL> T() const
    {
        return transpose();
    }

protected:

    //--------------------------------------------------------------------------
    // Protected constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixInterface(ValuePointerType storageValues[N][M]) :
        MatrixBase<ValueType, ValuePointerType>(
                                              N,
                                              M,
                                              (ValuePointerType*) storageValues,
                                              0)
    {
    }

    //--------------------------------------------------------------------------
    MatrixInterface(ValuePointerType storageValues[N][M],
                    const ValuePointerType initializationValues[N][M]) :
        MatrixBase<ValueType, ValuePointerType>(N,
                              M,
                              (ValuePointerType*) storageValues,
                              0,
                              (ValuePointerType*) initializationValues)
    {
    }
    
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface(
            ValuePointerType storageValues[N][M],
            const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) :
        MatrixBase<ValueType, ValuePointerType>(
                                              N,                                
                                              M,
                                              (ValuePointerType*) storageValues,
                                              0,
                                              matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    MatrixInterface(MatrixInterface<ValueType, ParentN, ParentM>& matrix,
                    const std::uint32_t row,
                    const std::uint32_t column) :
        MatrixBase<ValueType, ValuePointerType>(
                                         N,
                                         M,
                                         &(matrix.getValue(row, column)),
                                         matrix.getColumnJump() + (ParentM - M))
    {
        if (((row + N + 1) > ParentN) || ((column + M + 1) > ParentM))
        {
            // Error, submatrix beyond parent matrix bounds
        }
    }

    //--------------------------------------------------------------------------
    MatrixInterface(
             const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix) :
        MatrixBase<ValueType, ValuePointerType>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface(
            const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) :
        MatrixBase<ValueType, ValuePointerType>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Protected destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~MatrixInterface()
    {
    }
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_INTERFACE_H
