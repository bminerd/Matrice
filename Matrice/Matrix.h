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

#include <Matrice/Matrice.h>
#include <Matrice/MatrixStorage.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

///
/// @brief Class that inherits from MatrixBase to provide a general N x M matrix
/// implementation.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
/// @tparam M Number of matrix columns.
///
template <typename ValueType,
          uint32_t N,
          uint32_t M,
          Storage StorageOption = STORAGE_INTERNAL>
class Matrix : public MatrixStorage<ValueType, N, M, StorageOption>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = M;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixStorage<ValueType, N, M, StorageOption>()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[N][M]) :
        MatrixStorage<ValueType, N, M, StorageOption>(initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const MatrixStorage<ValueType, N, M, StorageOption2>& matrix) :
        MatrixStorage<ValueType, N, M, StorageOption>()
    {
        MatrixStorage<ValueType, N, M, StorageOption>::operator=(matrix);
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
    Matrix<ValueType, N, M, StorageOption>& operator=(
                    const MatrixStorage<ValueType, N, M, StorageOption>& matrix)
    {
        MatrixStorage<ValueType, N, M, StorageOption>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    template <Storage StorageOption2>
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, StorageOption>& operator=(
                   const MatrixStorage<ValueType, N, M, StorageOption2>& matrix)
    {
        MatrixStorage<ValueType, N, M, StorageOption>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, StorageOption>& operator=(
                                                   const ValueType values[N][M])
    {
        MatrixStorage<ValueType, N, M, StorageOption>::operator=(values);

        return (*this);
    }
};

template <typename ValueType, uint32_t N, uint32_t M>
class Matrix<ValueType, N, M, STORAGE_EXTERNAL> :
                         public MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = M;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[N][M]) :
        MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, uint32_t ParentM, Storage StorageOption>
    Matrix(Matrix<ValueType, ParentN, ParentM, StorageOption>& matrix,
           const uint32_t row,
           const uint32_t column) :
        MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, M, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[N][M])
    {
        MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL>::operator=(values);

        return (*this);
    }
};

template <typename ValueType, uint32_t N, Storage StorageOption>
class Matrix<ValueType, N, N, StorageOption> :
                            public MatrixStorage<ValueType, N, N, StorageOption>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = N;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixStorage<ValueType, N, N, StorageOption>()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[N][N]) :
        MatrixStorage<ValueType, N, N, StorageOption>(initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const MatrixStorage<ValueType, N, N, StorageOption2>& matrix) :
        MatrixStorage<ValueType, N, N, StorageOption>()
    {
        MatrixStorage<ValueType, N, N, StorageOption>::operator=(matrix);
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, N, StorageOption>& operator=(
                                                   const ValueType values[N][N])
    {
        MatrixStorage<ValueType, N, N, StorageOption>::operator=(values);

        return (*this);
    }
};

template <typename ValueType, uint32_t N>
class Matrix<ValueType, N, N, STORAGE_EXTERNAL> :
                         public MatrixStorage<ValueType, N, N, STORAGE_EXTERNAL>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = N;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[N][N]) :
        MatrixStorage<ValueType, N, N, STORAGE_EXTERNAL>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, uint32_t ParentM, Storage StorageOption>
    Matrix(Matrix<ValueType, ParentN, ParentM, StorageOption>& matrix,
           const uint32_t row,
           const uint32_t column) :
        MatrixStorage<ValueType, N, N, STORAGE_EXTERNAL>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, N, N, STORAGE_EXTERNAL>& operator=(
                   const MatrixStorage<ValueType, N, N, StorageOption2>& matrix)
    {
        MatrixStorage<ValueType, N, N, STORAGE_EXTERNAL>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, N, N, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[N][N])
    {
        MatrixStorage<ValueType, N, N, STORAGE_EXTERNAL>::operator=(values);

        return (*this);
    }
};


template <typename ValueType, Storage StorageOption>
class Matrix<ValueType, 1, 1, StorageOption> :
                            public MatrixStorage<ValueType, 1, 1, StorageOption>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = 1;
    static const uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix() :
        MatrixStorage<ValueType, 1, 1, StorageOption>()
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValues[1][1]) :
        MatrixStorage<ValueType, 1, 1, StorageOption>(initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    Matrix(const ValueType initializationValue) :
        MatrixStorage<ValueType, 1, 1, StorageOption>(initializationValue)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix(const MatrixStorage<ValueType, 1, 1, StorageOption2>& matrix) :
        MatrixStorage<ValueType, 1, 1, StorageOption>()
    {
        MatrixStorage<ValueType, 1, 1, StorageOption>::operator=(matrix);
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, StorageOption>& operator=(
                                                   const ValueType values[1][1])
    {
        MatrixStorage<ValueType, 1, 1, StorageOption>::operator=(values);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, StorageOption>& operator=(const ValueType value)
    {
        MatrixStorage<ValueType, 1, 1, StorageOption>::operator=(value);

        return (*this);
    }
};

template <typename ValueType>
class Matrix<ValueType, 1, 1, STORAGE_EXTERNAL> :
                         public MatrixStorage<ValueType, 1, 1, STORAGE_EXTERNAL>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = 1;
    static const uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Matrix(ValueType storageValues[1][1]) :
        MatrixStorage<ValueType, 1, 1, STORAGE_EXTERNAL>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Matrix<ValueType, 1, 1, STORAGE_EXTERNAL>& operator=(
                   const MatrixStorage<ValueType, 1, 1, StorageOption2>& matrix)
    {
        MatrixStorage<ValueType, 1, 1, STORAGE_EXTERNAL>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, STORAGE_EXTERNAL>& operator=(
                                                   const ValueType values[1][1])
    {
        MatrixStorage<ValueType, 1, 1, STORAGE_EXTERNAL>::operator=(values);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Matrix<ValueType, 1, 1, STORAGE_EXTERNAL>& operator=(const ValueType value)
    {
        MatrixStorage<ValueType, 1, 1, STORAGE_EXTERNAL>::operator=(value);

        return (*this);
    }
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_H
