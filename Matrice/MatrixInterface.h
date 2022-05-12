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
    operator Matrix<ValueType2,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    STORAGE_INTERNAL>() const
    {
        Matrix<ValueType2,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(N, M);

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
    template <typename ValuePointerType2>
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator=(
                               const MatrixInterface<ValueType,
                                                     DIMENSIONS_RUN_TIME,
                                                     DIMENSIONS_RUN_TIME,
                                                     ValuePointerType2>& matrix)
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
    template <typename ValuePointerType2>
    bool operator==(const MatrixInterface<ValueType,
                                          DIMENSIONS_RUN_TIME,
                                          DIMENSIONS_RUN_TIME,
                                          ValuePointerType2>& matrix) const
    {
        return MatrixBase<ValueType, ValuePointerType>::operatorEquals(matrix);
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

    // Addition operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               DIMENSIONS_RUN_TIME,
                                               ValuePointerType2>& matrix) const
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

    // Addition-equals operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface<ValueType, N, M, ValuePointerType>& operator+=(
                               const MatrixInterface<ValueType,
                                                     DIMENSIONS_RUN_TIME,
                                                     DIMENSIONS_RUN_TIME,
                                                     ValuePointerType2>& matrix)
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

    // Subtraction operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               DIMENSIONS_RUN_TIME,
                                               ValuePointerType2>& matrix) const
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

    // Subtraction-equals operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface<ValueType, N, M>& operator-=(
                               const MatrixInterface<ValueType,
                                                     DIMENSIONS_RUN_TIME,
                                                     DIMENSIONS_RUN_TIME,
                                                     ValuePointerType2>& matrix)
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

    // Multiplication operator (this * M by M2)
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator*(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               DIMENSIONS_RUN_TIME,
                                               ValuePointerType2>& matrix) const
    {
        if (matrix.getRows() != M)
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> resultMatrix(N, matrix.getColumns());

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

    // Multiplication operator (this * M by 1)
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> operator*(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               1,
                                               ValuePointerType2>& matrix) const
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
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(
                                                           (ValueType*) values);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, M, STORAGE_INTERNAL> getRow(
                                                  const std::uint32_t row) const
    {
        Matrix<ValueType, 1, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::getRow(matrix, row);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, M, STORAGE_INTERNAL> row(const std::uint32_t row) const
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
        MatrixBase<ValueType, ValuePointerType>(
                                       N,
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
    template <std::uint32_t N2, std::uint32_t M2, typename ValuePointerType2>
    MatrixInterface(
          ValuePointerType storageValues[N][M],
          const MatrixInterface<ValueType, N2, M2, ValuePointerType2>& matrix) :
        MatrixBase<ValueType, ValuePointerType>(
                                              N,
                                              M,
                                              (ValuePointerType*) storageValues,
                                              0,
                                              matrix)
    {
        if ((N2 != N) || (M2 != M))
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }
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
                             matrix.getColumnJump() + (matrix.getColumns() - M))
    {
        if (((row + N) > matrix.getRows()) ||
                                           ((column + M) > matrix.getColumns()))
        {
            MATRICE_REPORT_ERROR(ERROR_SUBMATRIX_BOUNDS_INVALID);
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
template <typename ValueType, std::uint32_t N, std::uint32_t M>
class MatrixInterface<ValueType, N, M, const ValueType> :
                                   public MatrixBase<ValueType, const ValueType>
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

        MatrixBase<ValueType, const ValueType>::operatorTypeCast(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    template <typename ValueType2>
    operator Matrix<ValueType2,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    STORAGE_INTERNAL>() const
    {
        Matrix<ValueType2,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(N, M);

        MatrixBase<ValueType, const ValueType>::operatorTypeCast(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    template <typename ValueType2>
    operator Vector<ValueType2, N, STORAGE_INTERNAL>() const
    {
        Vector<ValueType2, N, STORAGE_INTERNAL> vector;

        MatrixBase<ValueType, const ValueType>::operatorTypeCast(vector);

        return vector;
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M, const ValueType>& operator=(
                const MatrixInterface<ValueType, N, M, const ValueType>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType, N, M, const ValueType>& operator=(
                                                   const ValueType values[N][M])
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                     (const ValueType*) values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    bool operator==(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        return MatrixBase<ValueType, const ValueType>::operatorEquals(matrix);
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    bool operator==(const MatrixInterface<ValueType,
                                          DIMENSIONS_RUN_TIME,
                                          DIMENSIONS_RUN_TIME,
                                          ValuePointerType2>& matrix) const
    {
        return MatrixBase<ValueType, const ValueType>::operatorEquals(matrix);
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+() const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::operatorUnaryPlus(matrix);

        return matrix;
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::operatorAddScalar(matrix,
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

        MatrixBase<ValueType, const ValueType>::operatorAdd(matrix,
                                                            resultMatrix);

        return resultMatrix;
    }

    // Addition operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator+(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               DIMENSIONS_RUN_TIME,
                                               ValuePointerType2>& matrix) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType, const ValueType>::operatorAdd(matrix,
                                                            resultMatrix);

        return resultMatrix;
    }

    // Unary minus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-() const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::operatorUnaryMinus(matrix);

        return matrix;
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::operatorSubtractScalar(matrix,
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

        MatrixBase<ValueType, const ValueType>::operatorSubtract(matrix,
                                                                 resultMatrix);

        return resultMatrix;
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator-(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               DIMENSIONS_RUN_TIME,
                                               ValuePointerType2>& matrix) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType, const ValueType>::operatorSubtract(matrix,
                                                                 resultMatrix);

        return resultMatrix;
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_INTERNAL> operator*(
                                                   const ValueType scalar) const
    {
        Matrix<ValueType, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::operatorMultiplyScalar(matrix,
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

        MatrixBase<ValueType, const ValueType>::operatorMultiplyMByM2(
                                                                  matrix,
                                                                  resultMatrix);
        
        return resultMatrix;
    }

    // Multiplication operator (this * M by M2)
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator*(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               DIMENSIONS_RUN_TIME,
                                               ValuePointerType2>& matrix) const
    {
        // M and M2 can be equal to 0=DIMENSIONS_RUN_TIME, so use getRows() and
        // getColumns() for dimesions check instead of M and M2

        if (matrix.getRows() !=
                           MatrixBase<ValueType, const ValueType>::getColumns())
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> resultMatrix(
                              MatrixBase<ValueType, const ValueType>::getRows(),
                              matrix.getColumns());

        MatrixBase<ValueType, const ValueType>::operatorMultiplyMByM2(
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

        MatrixBase<ValueType, const ValueType>::operatorMultiplyMBy1(
                                                                  matrix,
                                                                  resultMatrix);

        return resultMatrix;
    }

    // Multiplication operator (this * M by 1)
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> operator*(
                         const MatrixInterface<ValueType,
                                               DIMENSIONS_RUN_TIME,
                                               1,
                                               ValuePointerType2>& matrix) const
    {
        Matrix<ValueType, N, 1, STORAGE_INTERNAL> resultMatrix;

        MatrixBase<ValueType, const ValueType>::operatorMultiplyMBy1(
                                                                  matrix,
                                                                  resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType, const ValueType>::setValues;

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[N][M])
    {
        MatrixBase<ValueType, const ValueType>::setValuesProtected(
                                                           (ValueType*) values);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, M, STORAGE_INTERNAL> getRow(
                                                  const std::uint32_t row) const
    {
        Matrix<ValueType, 1, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::getRow(matrix, row);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, M, STORAGE_INTERNAL> row(const std::uint32_t row) const
    {
        return getRow(row);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, STORAGE_INTERNAL> getColumn(
                                               const std::uint32_t column) const
    {
        Matrix<ValueType, N, 1, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::getColumn(matrix, column);

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

        MatrixBase<ValueType, const ValueType>::transpose(matrix);

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
    MatrixInterface(const ValueType storageValues[N][M]) :
        MatrixBase<ValueType, const ValueType>(N,
                                               M,
                                               (const ValueType*) storageValues,
                                               0)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN,
              std::uint32_t ParentM,
              typename ValuePointerType>
    MatrixInterface(const MatrixInterface<ValueType,
                                          ParentN,
                                          ParentM,
                                          ValuePointerType>& matrix,
                    const std::uint32_t row,
                    const std::uint32_t column) :
        MatrixBase<ValueType, const ValueType>(
                             N,
                             M,
                             &(matrix.getValue(row, column)),
                             matrix.getColumnJump() + (matrix.getColumns() - M))
    {
        if (((row + N) > matrix.getRows()) ||
                                           ((column + M) > matrix.getColumns()))
        {
            MATRICE_REPORT_ERROR(ERROR_SUBMATRIX_BOUNDS_INVALID);
        }
    }

    //--------------------------------------------------------------------------
    MatrixInterface(
              const MatrixInterface<ValueType, N, M, const ValueType>& matrix) :
        MatrixBase<ValueType, const ValueType>(matrix)
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
template <typename ValueType, typename ValuePointerType>
class MatrixInterface<ValueType,
                      DIMENSIONS_RUN_TIME,
                      DIMENSIONS_RUN_TIME,
                      ValuePointerType> :
                                  public MatrixBase<ValueType, ValuePointerType>
{
public:

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <typename ValueType2>
    operator Matrix<ValueType2,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    STORAGE_INTERNAL>() const
    {
        Matrix<ValueType2,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorTypeCast(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    template <typename ValueType2, std::uint32_t N, std::uint32_t M>
    operator Matrix<ValueType2, N, M, STORAGE_INTERNAL>() const
    {
        if ((N != MatrixBase<ValueType, ValuePointerType>::getRows()) ||
                     M != MatrixBase<ValueType, ValuePointerType>::getColumns())
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType2, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, ValuePointerType>::operatorTypeCast(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValueType2>
    operator Vector<ValueType2, N, STORAGE_INTERNAL>() const
    {
        Vector<ValueType2, N, STORAGE_INTERNAL> vector;

        MatrixBase<ValueType, ValuePointerType>::operatorTypeCast(vector);

        return vector;
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator=(
                                const MatrixInterface<ValueType,
                                                      DIMENSIONS_RUN_TIME,
                                                      DIMENSIONS_RUN_TIME,
                                                      ValuePointerType>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator=(
              const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t M>
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator=(
                                             const ValuePointerType values[][M])
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(
                                                    (ValuePointerType*) values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    bool operator==(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        return MatrixBase<ValueType, ValuePointerType>::operatorEquals(matrix);
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator+() const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorUnaryPlus(matrix);

        return matrix;
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator+(const ValueType scalar) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorAddScalar(matrix,
                                                                   scalar);

        return matrix;
    }

    // Addition operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator+(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> resultMatrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorAdd(matrix,
                                                             resultMatrix);

        return resultMatrix;
    }

    // Addition-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator+=(const ValueType scalar)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorAddEqualsScalar(
                                                                        scalar);

        return (*this);
    }

    // Addition-equals operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator+=(
              const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorAddEquals(matrix);

        return (*this);
    }

    // Unary minus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator-() const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorUnaryMinus(matrix);

        return matrix;
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator-(const ValueType scalar) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorSubtractScalar(matrix,
                                                                        scalar);
        
        return matrix;
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator-(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> resultMatrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorSubtract(matrix,
                                                                  resultMatrix);

        return resultMatrix;
    }

    // Subtraction-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator-=(const ValueType scalar)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorSubtractEqualsScalar(
                                                                        scalar);

        return (*this);
    }

    // Subtraction-equals operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator-=(
              const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorSubtractEquals(matrix);

        return (*this);
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator*(const ValueType scalar) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                         MatrixBase<ValueType, ValuePointerType>::getRows(),
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyScalar(matrix,
                                                                        scalar);

        return (matrix);
    }

    // Multiplication operator (this * M by M2)
    //--------------------------------------------------------------------------
    template <std::uint32_t M, std::uint32_t M2, typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator*(
        const MatrixInterface<ValueType, M, M2, ValuePointerType2>& matrix)
                                                                           const
    {
        // M and M2 can be equal to 0=DIMENSIONS_RUN_TIME, so use getRows() and
        // getColumns() for dimesions check instead of M and M2

        if (matrix.getRows() !=
                          MatrixBase<ValueType, ValuePointerType>::getColumns())
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> resultMatrix(
                             MatrixBase<ValueType, ValuePointerType>::getRows(),
                             matrix.getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyMByM2(
                                                                  matrix,
                                                                  resultMatrix);
        
        return (resultMatrix);
    }

    // Multiplication operator (this * M by 1)
    //--------------------------------------------------------------------------
    template <std::uint32_t M, typename ValuePointerType2>
    Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> operator*(
                         const MatrixInterface<ValueType,
                                               M,
                                               1,
                                               ValuePointerType2>& matrix) const
    {
        if (MatrixBase<ValueType, ValuePointerType>::getColumns() !=
                                                               matrix.getRows())
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_INTERNAL> resultMatrix(
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyMBy1(
                                                                  matrix,
                                                                  resultMatrix);

        return (resultMatrix);
    }

    // Multiplication-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    ValuePointerType>& operator*=(const ValueType scalar)
    {
        MatrixBase<ValueType, ValuePointerType>::operatorMultiplyEqualsScalar(
                                                                        scalar);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <std::uint32_t M>
    void setValues(const ValueType values[][M])
    {
        MatrixBase<ValueType, ValuePointerType>::setValuesProtected(
                                                           (ValueType*) values);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> getRow(const std::uint32_t row) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                         1,
                         MatrixBase<ValueType, ValuePointerType>::getColumns());

        MatrixBase<ValueType, ValuePointerType>::getRow(matrix, row);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> row(const std::uint32_t row) const
    {
        return getRow(row);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> getColumn(
                                               const std::uint32_t column) const
    {
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> matrix(
                            MatrixBase<ValueType, ValuePointerType>::getRows());

        MatrixBase<ValueType, ValuePointerType>::getColumn(matrix, column);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> col(
                                               const std::uint32_t column) const
    {
        return getColumn(column);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> transpose() const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          MatrixBase<ValueType, ValuePointerType>::getColumns(),
                          MatrixBase<ValueType, ValuePointerType>::getRows());

        MatrixBase<ValueType, ValuePointerType>::transpose(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> T() const
    {
        return transpose();
    }

protected:

    //--------------------------------------------------------------------------
    // Protected constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixInterface(const std::uint32_t N,
                    const std::uint32_t M,
                    ValuePointerType* storageValues) :
        MatrixBase<ValueType, ValuePointerType>(N, M, storageValues, 0)
    {
    }

    //--------------------------------------------------------------------------
    MatrixInterface(const std::uint32_t N,
                    const std::uint32_t M,
                    ValuePointerType* storageValues,
                    const ValuePointerType* initializationValues) :
        MatrixBase<ValueType, ValuePointerType>(N,
                                                M,
                                                storageValues,
                                                0,
                                                initializationValues)
    {
    }
    
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface(ValuePointerType* storageValues,
                    const MatrixInterface<ValueType,
                                          DIMENSIONS_RUN_TIME,
                                          DIMENSIONS_RUN_TIME,
                                          ValuePointerType2>& matrix) :
        MatrixBase<ValueType, ValuePointerType>(matrix.getRows(),                                
                                                matrix.getColumns(),
                                                storageValues,
                                                0,
                                                matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    MatrixInterface(const std::uint32_t N,
                    const std::uint32_t M,
                    MatrixInterface<ValueType, ParentN, ParentM>& matrix,
                    const std::uint32_t row,
                    const std::uint32_t column) :
        MatrixBase<ValueType, ValuePointerType>(
                             N,
                             M,
                             &(matrix.getValue(row, column)),
                             matrix.getColumnJump() + (matrix.getColumns() - M))
    {
        if (((row + N) > matrix.getRows()) ||
                                           ((column + M) > matrix.getColumns()))
        {
            MATRICE_REPORT_ERROR(ERROR_SUBMATRIX_BOUNDS_INVALID);
        }
    }

    //--------------------------------------------------------------------------
    MatrixInterface(const MatrixInterface<ValueType,
                                          DIMENSIONS_RUN_TIME,
                                          DIMENSIONS_RUN_TIME,
                                          ValuePointerType>& matrix) :
        MatrixBase<ValueType, ValuePointerType>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixInterface(const MatrixInterface<ValueType,
                                          DIMENSIONS_RUN_TIME,
                                          DIMENSIONS_RUN_TIME,
                                          ValuePointerType2>& matrix) :
        MatrixBase<ValueType, ValuePointerType>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
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
template <typename ValueType>
class MatrixInterface<ValueType,
                      DIMENSIONS_RUN_TIME,
                      DIMENSIONS_RUN_TIME,
                      const ValueType> :
                                   public MatrixBase<ValueType, const ValueType>
{
public:

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <typename ValueType2>
    operator Matrix<ValueType2,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    STORAGE_INTERNAL>() const
    {
        Matrix<ValueType2,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorTypeCast(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    template <typename ValueType2, std::uint32_t N, std::uint32_t M>
    operator Matrix<ValueType2, N, M, STORAGE_INTERNAL>() const
    {
        if ((N != MatrixBase<ValueType, const ValueType>::getRows()) ||
                     M != MatrixBase<ValueType, const ValueType>::getColumns())
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType2, N, M, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::operatorTypeCast(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValueType2>
    operator Vector<ValueType2, N, STORAGE_INTERNAL>() const
    {
        Vector<ValueType2, N, STORAGE_INTERNAL> vector;

        MatrixBase<ValueType, const ValueType>::operatorTypeCast(vector);

        return vector;
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    const ValueType>& operator=(
                                const MatrixInterface<ValueType,
                                                       DIMENSIONS_RUN_TIME,
                                                       DIMENSIONS_RUN_TIME,
                                                       const ValueType>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M>
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    const ValueType>& operator=(
                const MatrixInterface<ValueType, N, M, const ValueType>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template < std::uint32_t M>
    MatrixInterface<ValueType,
                    DIMENSIONS_RUN_TIME,
                    DIMENSIONS_RUN_TIME,
                    const ValueType>& operator=(const ValueType values[][M])
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                     (const ValueType*) values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    bool operator==(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        return MatrixBase<ValueType, const ValueType>::operatorEquals(matrix);
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator+() const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorUnaryPlus(matrix);

        return matrix;
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator+(const ValueType scalar) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorAddScalar(matrix,
                                                                  scalar);

        return matrix;
    }

    // Addition operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator+(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> resultMatrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorAdd(matrix,
                                                            resultMatrix);

        return resultMatrix;
    }

    // Unary minus operator
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator-() const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorUnaryMinus(matrix);

        return matrix;
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator-(const ValueType scalar) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorSubtractScalar(matrix,
                                                                       scalar);
        
        return matrix;
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M, typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator-(
        const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> resultMatrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorSubtract(matrix,
                                                                 resultMatrix);

        return resultMatrix;
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator*(const ValueType scalar) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          MatrixBase<ValueType, const ValueType>::getRows(),
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::operatorMultiplyScalar(matrix,
                                                                       scalar);

        return (matrix);
    }

    // Multiplication operator (this * M by M2)
    //--------------------------------------------------------------------------
    template <std::uint32_t M, std::uint32_t M2, typename ValuePointerType2>
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> operator*(
        const MatrixInterface<ValueType, M, M2, ValuePointerType2>& matrix)
                                                                           const
    {
        // M and M2 can be equal to 0=DIMENSIONS_RUN_TIME, so use getRows() and
        // getColumns() for dimesions check instead of M and M2

        if (matrix.getRows() !=
                           MatrixBase<ValueType, const ValueType>::getColumns())
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> resultMatrix(
                              MatrixBase<ValueType, const ValueType>::getRows(),
                              matrix.getColumns());

        MatrixBase<ValueType, const ValueType>::operatorMultiplyMByM2(
                                                                  matrix,
                                                                  resultMatrix);
        
        return (resultMatrix);
    }

    // Multiplication operator (this * M by 1)
    //--------------------------------------------------------------------------
    template <std::uint32_t M, typename ValuePointerType2>
    Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> operator*(
                         const MatrixInterface<ValueType,
                                               M,
                                               1,
                                               ValuePointerType2>& matrix) const
    {
        if (MatrixBase<ValueType, const ValueType>::getColumns() !=
                                                               matrix.getRows())
        {
            MATRICE_REPORT_ERROR(ERROR_DIMENSIONS_INVALID);
        }

        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_INTERNAL> resultMatrix(
                             MatrixBase<ValueType, const ValueType>::getRows());

        MatrixBase<ValueType, const ValueType>::operatorMultiplyMBy1(
                                                                  matrix,
                                                                  resultMatrix);

        return (resultMatrix);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> getRow(const std::uint32_t row) const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                          1,
                          MatrixBase<ValueType, const ValueType>::getColumns());

        MatrixBase<ValueType, const ValueType>::getRow(matrix, row);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> row(const std::uint32_t row) const
    {
        return getRow(row);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> getColumn(
                                               const std::uint32_t column) const
    {
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> matrix;

        MatrixBase<ValueType, const ValueType>::getColumn(matrix, column);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_INTERNAL> col(
                                               const std::uint32_t column) const
    {
        return getColumn(column);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> transpose() const
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               DIMENSIONS_RUN_TIME,
               STORAGE_INTERNAL> matrix(
                           MatrixBase<ValueType, const ValueType>::getColumns(),
                           MatrixBase<ValueType, const ValueType>::getRows());

        MatrixBase<ValueType, const ValueType>::transpose(matrix);

        return matrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType,
           DIMENSIONS_RUN_TIME,
           DIMENSIONS_RUN_TIME,
           STORAGE_INTERNAL> T() const
    {
        return transpose();
    }

protected:

    //--------------------------------------------------------------------------
    // Protected constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixInterface(const std::uint32_t N,
                    const std::uint32_t M,
                    const ValueType* storageValues) :
        MatrixBase<ValueType, const ValueType>(N, M, storageValues, 0)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, 
              std::uint32_t ParentM,
              typename ValuePointerType>
    MatrixInterface(const std::uint32_t N,
                    const std::uint32_t M,
                    const MatrixInterface<ValueType,
                                          ParentN,
                                          ParentM,
                                          ValuePointerType>& matrix,
                    const std::uint32_t row,
                    const std::uint32_t column) :
        MatrixBase<ValueType, const ValueType>(
                             N,
                             M,
                             &(matrix.getValue(row, column)),
                             matrix.getColumnJump() + (matrix.getColumns() - M))
    {
        if (((row + N) > matrix.getRows()) ||
                                           ((column + M) > matrix.getColumns()))
        {
            MATRICE_REPORT_ERROR(ERROR_SUBMATRIX_BOUNDS_INVALID);
        }
    }

    //--------------------------------------------------------------------------
    MatrixInterface(const MatrixInterface<ValueType,
                                          DIMENSIONS_RUN_TIME,
                                          DIMENSIONS_RUN_TIME,
                                          const ValueType>& matrix) :
        MatrixBase<ValueType, const ValueType>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, std::uint32_t M>
    MatrixInterface(
              const MatrixInterface<ValueType, N, M, const ValueType>& matrix) :
        MatrixBase<ValueType, const ValueType>(matrix)
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
