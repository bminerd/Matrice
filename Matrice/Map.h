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
/// @file Map.h
/// @author Ben Minerd
/// @date 9/8/2020
/// @brief Map class header file.
///

#ifndef MATRICE_MAP_H
#define MATRICE_MAP_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>

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

template <class MatriceType>
class Map : public MatrixStorage<typename MatriceType::ValueT,
                                 MatriceType::rows,
                                 MatriceType::columns,
                                 STORAGE_EXTERNAL>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Map(typename MatriceType::ValueT storageValues[MatriceType::rows][MatriceType::columns]) :
        MatrixStorage<typename MatriceType::ValueT, MatriceType::rows, MatriceType::columns, STORAGE_EXTERNAL>(storageValues)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~Map()
    {
    }
    
    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    Map<MatriceType>& operator=(
        const MatrixStorage<typename MatriceType::ValueT, MatriceType::rows, MatriceType::columns, STORAGE_INTERNAL>& matrix)
    {
        MatrixStorage<typename MatriceType::ValueT, MatriceType::rows, MatriceType::columns, STORAGE_EXTERNAL>::operator=(matrix);

        return (*this);
    }

};

}; // namespace Matrice

#endif // MATRICE_MAP_H
