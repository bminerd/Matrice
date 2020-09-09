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
/// @file MatrixStorage.h
/// @author Ben Minerd
/// @date 9/4/2020
/// @brief MatrixStorage class header file.
///

#ifndef MATRICE_MATRIX_STORAGE_H
#define MATRICE_MATRIX_STORAGE_H

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
// Classes
//------------------------------------------------------------------------------

///
/// @brief Base class for all matrix-based classes. Specializations (ex. 3x3
/// matrices) can be added by inheriting from this class.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @note Currently supports only row-major matrices.
/// @note The underlying array indexing is done by incrementing pointers.
/// Normally this approach is avoided in Matrice due to poor readability, but the
/// performance gains are ~10x versus using for-loops and standard indexing.
///
template <typename ValueType,
          uint32_t N,
          uint32_t M,
          Storage StorageOption = STORAGE_INTERNAL>
class MatrixStorage : public MatrixBase<ValueType>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixStorage() :
        MatrixBase<ValueType>(N, M, (ValueType*) myValues),
        myValues()
    {
    }

    //--------------------------------------------------------------------------
    MatrixStorage(const ValueType initializationValues[N][M]) :
        MatrixBase<ValueType>(N, M, (ValueType*) myValues),
        myValues()
    {
        setValuesProtected(initializationValues);
    }

    // //--------------------------------------------------------------------------
    // MatrixStorage(const MatrixStorage& matrix) :
    //     MatrixBase<ValueType>(N, M, (ValueType*) myValues),
    //     myValues()
    // {
    //     setStaticValuesProtected(matrix.myValues);
    // }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    MatrixStorage(const MatrixStorage<ValueType, N, M, StorageOption2>& matrix) :
        MatrixBase<ValueType>(N, M, (ValueType*) myValues)
    {
        operator=(matrix);
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~MatrixStorage()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    MatrixStorage<ValueType, N, M, StorageOption>& operator=(
                   const MatrixStorage<ValueType, N, M, StorageOption2>& matrix)
    {
        MatrixBase<ValueType>::copyValuesProtected(matrix);

        return (*this);
    }

    //
    //--------------------------------------------------------------------------
    ValueType& operator()(const uint32_t row, const uint32_t column)
    {
        return MatrixBase<ValueType>::getValue(row, column);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row, const uint32_t column) const
    {
        return MatrixBase<ValueType>::getValue(row, column);
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator+() const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorUnaryPlus(matrix);

        return matrix;
    }
    
    // Unary minus operator
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator-() const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorUnaryMinus(matrix);

        return matrix;
    }

    // Addition operator
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator+(
              const MatrixStorage<ValueType, N, M, StorageOption>& matrix) const
    {
        MatrixStorage<ValueType, N, M> resultMatrix;

        MatrixBase<ValueType>::operatorAdd(matrix, resultMatrix);

        return resultMatrix;
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator-(
              const MatrixStorage<ValueType, N, M, StorageOption>& matrix) const
    {
        MatrixStorage<ValueType, N, M> resultMatrix;

        MatrixBase<ValueType>::operatorSubtract(matrix, resultMatrix);

        return resultMatrix;
    }

    // Multiplication operator
    //--------------------------------------------------------------------------
    template <uint32_t M2, Storage StorageOption2>
    MatrixStorage<ValueType, N, M2> operator*(
             const MatrixStorage<ValueType, M, M2, StorageOption2>& matrix) const
    {
        MatrixStorage<ValueType, N, M2> resultMatrix;

        MatrixBase<ValueType>::operatorMultiplyNByM(matrix, resultMatrix);
        
        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    MatrixStorage<ValueType, N, 1> operator*(
             const MatrixStorage<ValueType, M, 1, StorageOption2>& matrix) const
    {
        MatrixStorage<ValueType, N, 1> resultMatrix;

        MatrixBase<ValueType>::operatorMultiplyNBy1(matrix, resultMatrix);

        return resultMatrix;
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator+(
                                                   const ValueType scalar) const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorAddScalar(matrix, scalar);

        return matrix;
    }

    // Addition-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M, StorageOption>& operator+=(
                                                         const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorAddEquals(scalar);

        return (*this);
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator-(
                                                   const ValueType scalar) const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorSubtractScalar(matrix, scalar);
        
        return matrix;
    }

    // Subtraction-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M, StorageOption>& operator-=(
                                                         const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorSubtractEquals(scalar);

        return (*this);
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator*(
                                                   const ValueType scalar) const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorMultiplyScalar(matrix, scalar);

        return matrix;
    }

    // Multiplication-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M, StorageOption>& operator*=(
                                                         const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorMultiplyEqualsScalar(scalar);

        return (*this);
    }

protected:

    //--------------------------------------------------------------------------
    // Protected methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    inline void setValuesProtected(const ValueType values[N][M])
    {
        int32_t i;
        int32_t j;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                MatrixBase<ValueType>::getValueFast(i, j) = values[i][j];
            }
        }
    }

    //--------------------------------------------------------------------------
    inline void setValuesProtected(const ValueType values[N])
    {
        int32_t i;

        for (i = 0; i < N; i++)
        {
            MatrixBase<ValueType>::getValueFast(i, 0) = values[i];
        }
    }

    //--------------------------------------------------------------------------
    inline void setStaticValuesProtected(const ValueType values[N][M])
    {
        ValueType* myValuePointer =
                                   &(MatrixBase<ValueType>::getValueFast(0, 0));
        const ValueType* valuePointer = &(values[0][0]);

        int32_t i = N * M;

        while (i--)
        {
            (*myValuePointer++) = (*valuePointer++);
        }
    }

    //--------------------------------------------------------------------------
    inline void setStaticValuesProtected(const ValueType values[N])
    {
        ValueType* myValuePointer =
                                   &(MatrixBase<ValueType>::getValueFast(0, 0));
        const ValueType* valuePointer = &(values[0]);

        int32_t i = N * M;

        while (i--)
        {
            (*myValuePointer++) = (*valuePointer++);
        }
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    ValueType myValues[N][M];
};

template <typename ValueType, uint32_t N, uint32_t M>
class MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL> :
                                                    public MatrixBase<ValueType>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixStorage(ValueType storageValues[N][M]) :
        MatrixBase<ValueType>(N, M, (ValueType*) storageValues)
    {
    }


    //--------------------------------------------------------------------------
    MatrixStorage(ValueType storageValues[N][M],
                  const ValueType initializationValues[N][M]) :
        MatrixBase<ValueType>(N, M, (ValueType*) storageValues)
    {
        setValuesProtected(initializationValues);
    }

    //--------------------------------------------------------------------------
    MatrixStorage(const MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL>& matrix) :
        MatrixBase<ValueType>(N, M, matrix)
    {
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption1, Storage StorageOption2>
    MatrixStorage<ValueType, N, M, StorageOption1>& operator=(
                   const MatrixStorage<ValueType, N, M, StorageOption2>& matrix)
    {
       MatrixBase<ValueType>::copyValuesProtected(matrix);

        return (*this);
    }

    // Addition operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    MatrixStorage<ValueType, N, M> operator+(
             const MatrixStorage<ValueType, N, M, StorageOption2>& matrix) const
    {
        MatrixStorage<ValueType, N, M> resultMatrix;

        MatrixBase<ValueType>::operatorAdd(matrix, resultMatrix);

        return resultMatrix;
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    MatrixStorage<ValueType, N, M> operator-(
             const MatrixStorage<ValueType, N, M, StorageOption2>& matrix) const
    {
        MatrixStorage<ValueType, N, M> resultMatrix;

        MatrixBase<ValueType>::operatorSubtract(matrix, resultMatrix);

        return resultMatrix;
    }

    //--------------------------------------------------------------------------
    template <uint32_t M2, Storage StorageOption2>
    MatrixStorage<ValueType, N, M2> operator*(
            const MatrixStorage<ValueType, M, M2, StorageOption2>& matrix) const
    {
        MatrixStorage<ValueType, N, M2> resultMatrix;

        MatrixBase<ValueType>::operatorMultiplyNByM(matrix, resultMatrix);
        
        return resultMatrix;
    }


    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator+(const ValueType scalar) const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorAddScalar(matrix, scalar);

        return matrix;
    }

    // Addition-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator+=(const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorAddEquals(*this, scalar);

        return (*this);
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator-(const ValueType scalar) const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorSubtractScalar(matrix, scalar);
        
        return matrix;
    }

    // Subtraction-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL>& operator-=(
                                                         const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorSubtractEquals(scalar);

        return (*this);
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M> operator*(const ValueType scalar) const
    {
        MatrixStorage<ValueType, N, M> matrix;

        MatrixBase<ValueType>::operatorMultiplyScalar(matrix, scalar);

        return matrix;
    }

    // Multiplication-equals operator (scalar)
    //--------------------------------------------------------------------------
    MatrixStorage<ValueType, N, M, STORAGE_EXTERNAL>& operator*=(
                                                         const ValueType scalar)
    {
        MatrixBase<ValueType>::operatorMultiplyEqualsScalar(scalar);

        return (*this);
    }

protected:

    using MatrixBase<ValueType>::getValueFast;

    //--------------------------------------------------------------------------
    // Protected methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    inline void setValuesProtected(const ValueType values[][M])
    {
        int32_t i;
        int32_t j;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                MatrixBase<ValueType>::getValueFast(i, j) = values[i][j];
            }
        }
    }

    //--------------------------------------------------------------------------
    inline void setValuesProtected(const ValueType values[N])
    {
        int32_t i;

        for (i = 0; i < N; i++)
        {
            MatrixBase<ValueType>::getValueFast(i, 0) = values[i];
        }
    }

    //--------------------------------------------------------------------------
    inline void setStaticValuesProtected(const ValueType values[][M])
    {
        ValueType* myValuePointer =
                                   &(MatrixBase<ValueType>::getValueFast(0, 0));
        const ValueType* valuePointer = &(values[0][0]);

        int32_t i = N * M;

        while (i--)
        {
            (*myValuePointer++) = (*valuePointer++);
        }
    }

    //--------------------------------------------------------------------------
    inline void setStaticValuesProtected(const ValueType values[N])
    {
        ValueType* myValuePointer =
                                   &(MatrixBase<ValueType>::getValueFast(0, 0));
        const ValueType* valuePointer = &(values[0]);

        int32_t i = N * M;

        while (i--)
        {
            (*myValuePointer++) = (*valuePointer++);
        }
    }
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_STORAGE_H
