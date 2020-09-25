//------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2016 Benjamin Minerd
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
/// @file Vector.h
/// @author Ben Minerd
/// @date 2/18/2016
/// @brief Vector class header file.
///

#ifndef MATRICE_VECTOR_H
#define MATRICE_VECTOR_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <Matrice/Matrice.h>
#include <Matrice/Matrix.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

template <typename ValueType,
          uint32_t N,
          Storage StorageOption = STORAGE_INTERNAL>
class Vector : public MatrixStorage<ValueType, N, 1, StorageOption>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------
    
    //--------------------------------------------------------------------------
    Vector() :
        MatrixStorage<ValueType, N, 1, StorageOption>()
    {
    }

    //--------------------------------------------------------------------------
    Vector(const ValueType values[N]) :
        MatrixStorage<ValueType, N, 1, StorageOption>(
                                                  *(ValueType (*)[N][1]) values)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector(const MatrixStorage<ValueType, N, 1, StorageOption2>& matrix) :
        MatrixStorage<ValueType, N, 1, StorageOption>()
    {
        MatrixStorage<ValueType, N, 1, StorageOption>::operator=(matrix);
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Vector()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, N, StorageOption>& operator=(
                    const MatrixStorage<ValueType, N, 1, StorageOption>& matrix)
    {
        MatrixStorage<ValueType, N, 1, StorageOption>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector<ValueType, N, StorageOption>& operator=(
                   const MatrixStorage<ValueType, N, 1, StorageOption2>& matrix)
    {
        MatrixStorage<ValueType, N, 1, StorageOption>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, N, StorageOption>& operator=(const ValueType values[N])
    {
        setValues(values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const uint32_t row)
    {
        return (Matrix<ValueType, N, 1, StorageOption>::getValue(row, 0));
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row) const
    {
        return (Matrix<ValueType, N, 1, StorageOption>::getValue(row, 0));
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[N])
    {
        MatrixBase<ValueType>::setValuesProtected(values);
    }
};

template <typename ValueType, uint32_t N>
class Vector<ValueType, N, STORAGE_EXTERNAL> :
                         public MatrixStorage<ValueType, N, 1, STORAGE_EXTERNAL>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------
    
    //--------------------------------------------------------------------------
    Vector() :
        MatrixStorage<ValueType, N, 1, STORAGE_EXTERNAL>()
    {
    }

    //--------------------------------------------------------------------------
    Vector(ValueType values[N]) :
        MatrixStorage<ValueType, N, 1, STORAGE_EXTERNAL>(
                                                  *(ValueType (*)[N][1]) values)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, uint32_t ParentM, Storage StorageOption>
    Vector(Matrix<ValueType, ParentN, ParentM, StorageOption>& matrix,
           const uint32_t row,
           const uint32_t column) :
        MatrixStorage<ValueType, N, 1, STORAGE_EXTERNAL>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Vector()
    {
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector<ValueType, N, STORAGE_EXTERNAL>& operator=(
                   const MatrixStorage<ValueType, N, 1, StorageOption2>& matrix)
    {
        MatrixStorage<ValueType, N, 1, STORAGE_EXTERNAL>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, N, STORAGE_EXTERNAL>& operator=(const ValueType values[N])
    {
        setValues(values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const uint32_t row)
    {
        return getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row) const
    {
        return getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixStorage<ValueType, N, 1, STORAGE_EXTERNAL>::getValue;

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[N])
    {
        MatrixBase<ValueType>::setValuesProtected(values);
    }
};

}; // namespace Matrice

#endif // MATRICE_VECTOR_H
