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
/// @file Matrix.h
/// @author Ben Minerd
/// @date 2/17/2016
/// @brief Matrix class header file.
///

#ifndef MATRICE_MATRIX_H
#define MATRICE_MATRIX_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>

#include <Matrice/Matrice.h>
#include <Matrice/MatrixInterface.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

///
/// @brief Class that inherits from MatrixInterface to provide a general N x M
/// matrix implementation.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
/// @tparam M Number of matrix columns.
/// @tparam StorageOption Where the matrix array storage should be placed.
///
template <typename ValueType,
          std::uint32_t N,
          std::uint32_t M,
          Storage StorageOption = STORAGE_INTERNAL>
class Matrix : public MatrixInterface<ValueType, N, M>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = N;
    static const std::uint32_t columns = M;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixInterface<ValueType, N, M>(myValues),
        myValues()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[N][M]) :
        MatrixInterface<ValueType, N, M>(myValues, initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, N, M>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, N, M, StorageOption2>& matrix) :
        MatrixInterface<ValueType, N, M>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    virtual ~Matrix()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, M, StorageOption>& operator=(
                          const Matrix<ValueType, N, M, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, N, M>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, M, StorageOption>& operator=(
               const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, N, M>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, StorageOption>& operator=(
                                                   const ValueType values[N][M])
    {
        MatrixBase<ValueType>::setValuesProtected((ValueType*) values);

        return (*this);
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    ValueType myValues[N][M];
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where StorageOption = STORAGE_EXTERNAL.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
/// @tparam M Number of matrix columns.
///
template <typename ValueType, std::uint32_t N, std::uint32_t M>
class Matrix<ValueType, N, M, STORAGE_EXTERNAL> :
                                         public MatrixInterface<ValueType, N, M>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = N;
    static const std::uint32_t columns = M;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[N][M]) :
        MatrixInterface<ValueType, N, M>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    Matrix(MatrixInterface<ValueType, ParentN, ParentM>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        MatrixInterface<ValueType, N, M>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, N, M>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const Matrix<ValueType, N, M, STORAGE_EXTERNAL>& matrix) :
        MatrixInterface<ValueType, N, M>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, M, STORAGE_EXTERNAL>& operator=(
                          const Matrix<ValueType, N, M, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, N, M>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, M, STORAGE_EXTERNAL>& operator=(
               const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, N, M>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[N][M])
    {
        MatrixInterface<ValueType, N, M>::operator=(values);

        return (*this);
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where StorageOption = STORAGE_CONSTANT.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
/// @tparam M Number of matrix columns.
///
template <typename ValueType, std::uint32_t N, std::uint32_t M>
class Matrix<ValueType, N, M, STORAGE_CONSTANT> :
                        public MatrixInterface<ValueType, N, M, const ValueType>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = N;
    static const std::uint32_t columns = M;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(const ValueType storageValues[N][M]) :
        MatrixInterface<ValueType, N, M, const ValueType>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN,
              std::uint32_t ParentM,
              typename ValuePointerType>
    Matrix(
         MatrixInterface<ValueType, ParentN, ParentM, ValuePointerType>& matrix,
         const std::uint32_t row,
         const std::uint32_t column) :
        MatrixInterface<ValueType, N, M, const ValueType>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, M, STORAGE_CONSTANT>& operator=(
                          const Matrix<ValueType, N, M, StorageOption2>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, M, STORAGE_CONSTANT>& operator=(
               const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = M (i.e. Matrix is square).
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows and columns.
/// @tparam StorageOption Where the matrix array storage should be placed.
///
template <typename ValueType, std::uint32_t N, Storage StorageOption>
class Matrix<ValueType, N, N, StorageOption> :
                                         public MatrixInterface<ValueType, N, N>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = N;
    static const std::uint32_t columns = N;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixInterface<ValueType, N, N>(myValues),
        myValues()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[N][N]) :
        MatrixInterface<ValueType, N, N>(myValues, initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, N, N, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, N, N>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const Matrix<ValueType, N, N>& matrix) :
        MatrixInterface<ValueType, N, N>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, N, N, StorageOption2>& matrix) :
        MatrixInterface<ValueType, N, N>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, N, StorageOption>& operator=(
                          const Matrix<ValueType, N, N, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, N, N>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, N, StorageOption>& operator=(
                        const Matrix<ValueType, N, N, STORAGE_EXTERNAL>& matrix)
    {
        MatrixInterface<ValueType, N, N>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, N, StorageOption>& operator=(
               const MatrixInterface<ValueType, N, N, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, N, N>::operator=(matrix);

        return (*this);
    }


    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, N, StorageOption>& operator=(
                                                   const ValueType values[N][N])
    {
        MatrixInterface<ValueType, N, N>::operator=(values);

        return (*this);
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    ValueType myValues[N][N];
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = M (i.e. Matrix is square) and StorageOption = STORAGE_EXTERNAL.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows and columns
/// @tparam StorageOption Where the matrix array storage should be placed.
///
template <typename ValueType, std::uint32_t N>
class Matrix<ValueType, N, N, STORAGE_EXTERNAL> :
                                         public MatrixInterface<ValueType, N, N>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = N;
    static const std::uint32_t columns = N;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[N][N]) :
        MatrixInterface<ValueType, N, N>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    Matrix(MatrixInterface<ValueType, ParentN, ParentM>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        MatrixInterface<ValueType, N, N>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, N, N, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, N, N>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, N, N, StorageOption2>& matrix) :
        MatrixInterface<ValueType, N, N>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, N, STORAGE_EXTERNAL>& operator=(
                          const Matrix<ValueType, N, N, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, N, N>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, N, STORAGE_EXTERNAL>& operator=(
               const MatrixInterface<ValueType, N, N, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, N, N>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, N, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[N][N])
    {
        MatrixInterface<ValueType, N, N>::operator=(values);

        return (*this);
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = M and StorageOption = STORAGE_CONSTANT.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
/// @tparam M Number of matrix columns.
///
template <typename ValueType, std::uint32_t N>
class Matrix<ValueType, N, N, STORAGE_CONSTANT> :
                        public MatrixInterface<ValueType, N, N, const ValueType>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = N;
    static const std::uint32_t columns = N;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(const ValueType storageValues[N][N]) :
        MatrixInterface<ValueType, N, N, const ValueType>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN,
              std::uint32_t ParentM,
              typename ValuePointerType>
    Matrix(
         MatrixInterface<ValueType, ParentN, ParentM, ValuePointerType>& matrix,
         const std::uint32_t row,
         const std::uint32_t column) :
        MatrixInterface<ValueType, N, N, const ValueType>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, N, N, StorageOption2>& matrix) :
        MatrixInterface<ValueType, N, N, const ValueType>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, N, STORAGE_CONSTANT>& operator=(
                        const Matrix<ValueType, N, N, STORAGE_CONSTANT>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, N, STORAGE_CONSTANT>& operator=(
                          const Matrix<ValueType, N, N, StorageOption2>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, N, STORAGE_CONSTANT>& operator=(
               const MatrixInterface<ValueType, N, N, ValuePointerType>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where M = 1 (i.e. Matrix is a column vector).
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
/// @tparam StorageOption Where the matrix array storage should be placed.
///
template <typename ValueType, std::uint32_t N, Storage StorageOption>
class Matrix<ValueType, N, 1, StorageOption> :
                                         public MatrixInterface<ValueType, N, 1>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixInterface<ValueType, N, 1>(myValues),
        myValues()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[N][1]) :
        MatrixInterface<ValueType, N, 1>(myValues, initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, N, 1>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const Matrix<ValueType, N, 1, StorageOption>& matrix) :
        MatrixInterface<ValueType, N, 1>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, N, 1, StorageOption2>& matrix) :
        MatrixInterface<ValueType, N, 1>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Matrix()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, 1>& operator=(
                          const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, N, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, 1, StorageOption>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, N, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, StorageOption>& operator=(
                                                   const ValueType values[N][1])
    {
        MatrixBase<ValueType>::setValuesProtected((ValueType*) values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dotProduct(const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        return MatrixBase<ValueType>::dotProductVector(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dot(const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        return dotProduct(matrix);
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    ValueType myValues[N][1];
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where M = 1 (i.e. Matrix is a column vector) and StorageOption =
/// STORAGE_EXTERNAL.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
///
template <typename ValueType, std::uint32_t N>
class Matrix<ValueType, N, 1, STORAGE_EXTERNAL> :
                                         public MatrixInterface<ValueType, N, 1>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[N][1]) :
        MatrixInterface<ValueType, N, 1>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    Matrix(MatrixInterface<ValueType, ParentN, ParentM>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        MatrixInterface<ValueType, N, 1>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, N, 1>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, N, 1, StorageOption2>& matrix) :
        MatrixInterface<ValueType, N, 1>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Matrix()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, 1, STORAGE_EXTERNAL>& operator=(
                          const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, N, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, 1, STORAGE_EXTERNAL>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, N, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, 1, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[N][1])
    {
        MatrixInterface<ValueType, N, 1>::operator=(values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dotProduct(const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        return MatrixBase<ValueType>::dotProductVector(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dot(const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        return dotProduct(matrix);
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where M = 1 (i.e. Matrix is a column Vector) and StorageOption =
/// STORAGE_CONSTANT.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
///
template <typename ValueType, std::uint32_t N>
class Matrix<ValueType, N, 1, STORAGE_CONSTANT> :
                        public MatrixInterface<ValueType, N, 1, const ValueType>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = N;
    static const std::uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(const ValueType storageValues[N][1]) :
        MatrixInterface<ValueType, N, 1, const ValueType>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN,
              std::uint32_t ParentM,
              typename ValuePointerType>
    Matrix(
         MatrixInterface<ValueType, ParentN, ParentM, ValuePointerType>& matrix,
         const std::uint32_t row,
         const std::uint32_t column) :
        MatrixInterface<ValueType, N, 1, const ValueType>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, 1, STORAGE_CONSTANT>& operator=(
                          const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, N, 1, STORAGE_CONSTANT>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = 3 and M = 1 (i.e. Matrix is a 3-element column vector).
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam StorageOption Where the matrix array storage should be placed.
///
template <typename ValueType, Storage StorageOption>
class Matrix<ValueType, 3, 1, StorageOption> :
                                         public MatrixInterface<ValueType, 3, 1>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixInterface<ValueType, 3, 1>(myValues),
        myValues()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[3][1]) :
        MatrixInterface<ValueType, 3, 1>(myValues, initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const MatrixInterface<ValueType, 3, 1>& matrix) :
        MatrixInterface<ValueType, 3, 1>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const Matrix<ValueType, 3, 1, StorageOption>& matrix) :
        MatrixInterface<ValueType, 3, 1>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, 3, 1, StorageOption2>& matrix) :
        MatrixInterface<ValueType, 3, 1>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Matrix()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 1, StorageOption>& operator=(
                           const Matrix<ValueType, 3, 1, StorageOption>& matrix)
    {
        MatrixInterface<ValueType, 3, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1, StorageOption>& operator=(
                          const Matrix<ValueType, 3, 1, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, 3, 1, ValueType>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, 3, 1, StorageOption>& operator=(
               const MatrixInterface<ValueType, 3, 1, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, 3, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 1, StorageOption>& operator=(
                                                   const ValueType values[3][1])
    {
        MatrixBase<ValueType>::setValuesProtected((ValueType*) values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1> crossProduct(
                          const Matrix<ValueType, 3, 1, StorageOption2>& matrix)
    {
        Matrix<ValueType, 3, 1> resultMatrix;

        MatrixBase<ValueType>::crossProductVector(matrix, resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1> cross(
                          const Matrix<ValueType, 3, 1, StorageOption2>& matrix)
    {
        return crossProduct(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dotProduct(const Matrix<ValueType, 3, 1, StorageOption2>& matrix)
    {
        return MatrixBase<ValueType>::dotProductVector(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dot(const Matrix<ValueType, 3, 1, StorageOption2>& matrix)
    {
        return dotProduct(matrix);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 3> toCrossProductEquivalentMatrix() const
    {
        Matrix<ValueType, 3, 3> resultMatrix;

        MatrixBase<ValueType>::toCrossProductEquivalentMatrix(resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 3> skew() const
    {
        return toCrossProductEquivalentMatrix();
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    ValueType myValues[3][1];
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = 3, M = 1 (i.e. Matrix is a column vector), and StorageOption =
/// STORAGE_EXTERNAL.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
///
template <typename ValueType>
class Matrix<ValueType, 3, 1, STORAGE_EXTERNAL> :
                                         public MatrixInterface<ValueType, 3, 1>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[3][1]) :
        MatrixInterface<ValueType, 3, 1>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    Matrix(MatrixInterface<ValueType, ParentN, ParentM>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        MatrixInterface<ValueType, 3, 1>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, 3, 1, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, 3, 1>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const Matrix<ValueType, 3, 1, StorageOption2>& matrix) :
        MatrixInterface<ValueType, 3, 1>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Matrix()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1, STORAGE_EXTERNAL>& operator=(
                          const Matrix<ValueType, 3, 1, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, 3, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, 3, 1, STORAGE_EXTERNAL>& operator=(
               const MatrixInterface<ValueType, 3, 1, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, 3, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 1, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[3][1])
    {
        MatrixInterface<ValueType, 3, 1>::operator=(values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1> crossProduct(
                    const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        Matrix<ValueType, 3, 1> resultMatrix;

        MatrixBase<ValueType>::crossProductVector(matrix, resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1> cross(
                    const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        return crossProduct(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dotProduct(
                    const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        return MatrixBase<ValueType>::dotProductVector(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dot(const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        return dotProduct(matrix);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 3> toCrossProductEquivalentMatrix() const
    {
        Matrix<ValueType, 3, 3> resultMatrix;

        MatrixBase<ValueType>::toCrossProductEquivalentMatrix(resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 3> skew() const
    {
        return toCrossProductEquivalentMatrix();
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = 3, M = 1 (i.e. Matrix is a 3x1 column Vector) and StorageOption =
/// STORAGE_CONSTANT.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
///
template <typename ValueType>
class Matrix<ValueType, 3, 1, STORAGE_CONSTANT> :
                        public MatrixInterface<ValueType, 3, 1, const ValueType>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = 3;
    static const std::uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(const ValueType storageValues[3][1]) :
        MatrixInterface<ValueType, 3, 1, const ValueType>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN,
              std::uint32_t ParentM,
              typename ValuePointerType>
    Matrix(
         MatrixInterface<ValueType, ParentN, ParentM, ValuePointerType>& matrix,
         const std::uint32_t row,
         const std::uint32_t column) :
        MatrixInterface<ValueType, 3, 1, const ValueType>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 1, STORAGE_CONSTANT>& operator=(
                        const Matrix<ValueType, 3, 1, STORAGE_CONSTANT>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1, STORAGE_CONSTANT>& operator=(
                          const Matrix<ValueType, 3, 1, StorageOption2>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 1, STORAGE_CONSTANT>& operator=(
                                 const MatrixInterface<ValueType, 3, 1>& matrix)
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        matrix);

        return (*this);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1> crossProduct(
                    const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        Matrix<ValueType, 3, 1> resultMatrix;

        MatrixBase<ValueType, const ValueType>::crossProductVector(
                                                                  matrix,
                                                                  resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 3, 1> cross(
                    const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        return crossProduct(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dotProduct(
                    const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        return MatrixBase<ValueType, const ValueType>::dotProductVector(matrix);
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    ValueType dot(const Matrix<ValueType, 3, 1, StorageOption2>& matrix) const
    {
        return dotProduct(matrix);
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 3> toCrossProductEquivalentMatrix() const
    {
        Matrix<ValueType, 3, 3> resultMatrix;

        MatrixBase<ValueType, const ValueType>::toCrossProductEquivalentMatrix(
                                                                  resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    Matrix<ValueType, 3, 3> skew() const
    {
        return toCrossProductEquivalentMatrix();
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = 1 and M = 1 (i.e. Matrix is a single element).
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam StorageOption Where the matrix array storage should be placed.
/// @note This class isn't intended to be directly used. However, some Matrix
/// math operations result in single-element results and this partial template
/// specialization provides some convenience methods.
///
template <typename ValueType, Storage StorageOption>
class Matrix<ValueType, 1, 1, StorageOption> :
                                         public MatrixInterface<ValueType, 1, 1>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = 1;
    static const std::uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixInterface<ValueType, 1, 1>(myValues),
        myValues()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[1][1]) :
        MatrixInterface<ValueType, 1, 1>(myValues, initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValue) :
        MatrixInterface<ValueType, 1, 1>(myValues)
    {
        myValues[0][0] = initializationValue;
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, 1, 1, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, 1, 1>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const Matrix<ValueType, 1, 1>& matrix) :
        MatrixInterface<ValueType, 1, 1>(myValues, matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    operator ValueType() const
    {
        return MatrixBase<ValueType>::getValue(0, 0);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 1, 1, StorageOption>& operator=(
                          const Matrix<ValueType, 1, 1, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, 1, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, 1, 1, StorageOption>& operator=(
               const MatrixInterface<ValueType, 1, 1, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, 1, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, StorageOption>& operator=(
                                                   const ValueType values[1][1])
    {
        MatrixInterface<ValueType, 1, 1>::operator=(values);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, StorageOption>& operator=(const ValueType value)
    {
        MatrixInterface<ValueType, 1, 1>::operator=(value);

        return (*this);
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    ValueType myValues[1][1];
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = 1, M = 1 (i.e. Matrix is a single element), and StorageOption =
/// STORAGE_EXTERNAL.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @note This class isn't intended to be directly used. However, some Matrix
/// math operations result in single-element results and this partial template
/// specialization provides some convenience methods.
///
template <typename ValueType>
class Matrix<ValueType, 1, 1, STORAGE_EXTERNAL> :
                                         public MatrixInterface<ValueType, 1, 1>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = 1;
    static const std::uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[1][1]) :
        MatrixInterface<ValueType, 1, 1>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix(const MatrixInterface<ValueType, 1, 1, ValuePointerType>& matrix) :
        MatrixInterface<ValueType, 1, 1>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    operator ValueType() const
    {
        return MatrixBase<ValueType>::getValue(0, 0);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Matrix<ValueType, 1, 1, STORAGE_EXTERNAL>& operator=(
               const MatrixInterface<ValueType, 1, 1, ValuePointerType>& matrix)
    {
        MatrixInterface<ValueType, 1, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[1][1])
    {
        MatrixInterface<ValueType, 1, 1>::operator=(values);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, STORAGE_EXTERNAL>& operator=(const ValueType value)
    {
        MatrixInterface<ValueType, 1, 1>::operator=(value);

        return (*this);
    }
};

///
/// @brief Partial template specialization of Matrix<ValueType, N, M, Storage>
/// where N = 1, M = 1 (i.e. Matrix is a 1x1 column Vector) and StorageOption =
/// STORAGE_CONSTANT.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
///
template <typename ValueType>
class Matrix<ValueType, 1, 1, STORAGE_CONSTANT> :
                        public MatrixInterface<ValueType, 1, 1, const ValueType>
{
public:

    typedef ValueType ValueT;
    static const std::uint32_t rows = 1;
    static const std::uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(const ValueType storageValues[1][1]) :
        MatrixInterface<ValueType, 1, 1, const ValueType>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    operator ValueType() const
    {
        return MatrixBase<ValueType, const ValueType>::getValue(0, 0);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 1, 1, STORAGE_CONSTANT>& operator=(
                          const Matrix<ValueType, 1, 1, StorageOption2>& matrix)
    {
        MatrixInterface<ValueType, 1, 1, const ValueType>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, STORAGE_CONSTANT>& operator=(
                                 const MatrixInterface<ValueType, 1, 1>& matrix)
    {
        MatrixInterface<ValueType, 1, 1, const ValueType>::operator=(matrix);

        return (*this);
    }
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_H
