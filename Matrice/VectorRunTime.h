//------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2022 Benjamin Minerd
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
/// @file VectorRunTime.h
/// @author Ben Minerd
/// @date 5/12/2022
/// @brief VectorRunTime class header file.
///

#ifndef MATRICE_VECTOR_RUN_TIME_H
#define MATRICE_VECTOR_RUN_TIME_H

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

///
/// @brief Class that inherits from MatrixInterface to provide a general N x M
/// matrix implementation.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of matrix rows.
/// @tparam M Number of matrix columns.
/// @tparam StorageOption Where the matrix array storage should be placed.
///
template <typename ValueType, Storage StorageOption = STORAGE_INTERNAL>
using VectorRunTime = Vector<ValueType,
                             DIMENSIONS_RUN_TIME,
                             StorageOption>;

}; // namespace Matrice

#endif // MATRICE_VECTOR_RUN_TIME_H
