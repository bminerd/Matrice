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
        Matrix<ValueType, N, 1, StorageOption>()
    {
    }

    //--------------------------------------------------------------------------
    Vector(const ValueType values[N]) :
        Matrix<ValueType, N, 1, StorageOption>()
    {
        Matrix<ValueType, N, 1>::setValuesProtected(values);
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Vector()
    {
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

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
};

}; // namespace Matrice

#endif // MATRICE_VECTOR_H
