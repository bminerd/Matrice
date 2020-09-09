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
/// @file RowVector.h
/// @author Ben Minerd
/// @date 2/18/2016
/// @brief RowVector class header file.
///

#ifndef MATRICE_ROW_VECTOR_H
#define MATRICE_ROW_VECTOR_H

/*------------------------------------------------------------------------------
 * Include files
 *----------------------------------------------------------------------------*/

#include <Matrix.h>

/*------------------------------------------------------------------------------
 * Namespace
 *----------------------------------------------------------------------------*/

namespace Matrice
{

/*------------------------------------------------------------------------------
 * Class
 *----------------------------------------------------------------------------*/

template <typename ValueType, unsigned int N>
class RowVector : public Matrix<ValueType, 1, N>
{
public:

    /*--------------------------------------------------------------------------
     * Public constructors
     *------------------------------------------------------------------------*/
    
    //--------------------------------------------------------------------------
    RowVector() :
        Matrix<ValueType, N, 1>()
    {
    }

    //--------------------------------------------------------------------------
    RowVector(const ValueType values[N]) :
        Matrix<ValueType, 1, N>((ValueType(*)[N]) values)
    {
    }

    //--------------------------------------------------------------------------
    RowVector(const RowVector& rowVector) :
        Matrix<ValueType, 1, N>(rowVector)
    {
    }

    /*--------------------------------------------------------------------------
     * Public destructors
     *------------------------------------------------------------------------*/

    //--------------------------------------------------------------------------
    ~RowVector();

    /*--------------------------------------------------------------------------
     * Public methods
     *------------------------------------------------------------------------*/

    // Assignment operator
    //--------------------------------------------------------------------------
    RowVector<ValueType, N>& operator=(const Matrix<ValueType, 1, N>& matrix)
    {
        Matrix<ValueType, 1, N>::operator=(matrix);

        return (*this);
    }

private:
    
    /*--------------------------------------------------------------------------
     * Private data members
     *------------------------------------------------------------------------*/
};

}; // namespace Matrice

#endif // MATRICE_ROW_VECTOR_H
