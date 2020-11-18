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

///
/// @brief Class that inherits from Matrix to provide a general N element
/// row vector implementation.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of vector rows.
/// @tparam StorageOption Where the vector array storage should be placed.
///
template <typename ValueType,
          uint32_t N,
          Storage StorageOption = STORAGE_INTERNAL>
class Vector : public Matrix<ValueType, N, 1, StorageOption>
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
    Vector(const ValueType initializationValues[N]) :
        Matrix<ValueType, N, 1, StorageOption>(
                                    *(ValueType (*)[N][1]) initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const MatrixInterface<ValueType, N, 1>& matrix) :
        Matrix<ValueType, N, 1, StorageOption>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector(const Matrix<ValueType, N, 1, StorageOption2>& matrix) :
        Matrix<ValueType, N, 1, StorageOption>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector(const Vector<ValueType, N, StorageOption2>& vector) :
        Matrix<ValueType, N, 1, StorageOption>(vector)
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
    Vector<ValueType, N, StorageOption>& operator=(
                             const Vector<ValueType, N, StorageOption2>& vector)
    {
        Matrix<ValueType, N, 1, StorageOption>::operator=(vector);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector<ValueType, N, StorageOption>& operator=(
                          const Matrix<ValueType, N, 1, StorageOption2>& matrix)
    {
        Matrix<ValueType, N, 1, StorageOption>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, N, StorageOption>& operator=(
                                 const MatrixInterface<ValueType, N, 1>& matrix)
    {
        Matrix<ValueType, N, 1, StorageOption>::operator=(matrix);

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
        return getValue(row);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row) const
    {
        return getValue(row);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType>::setValues;

    //--------------------------------------------------------------------------
    ValueType& getValue(const uint32_t row)
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValue(const uint32_t row) const
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    void setValue(const uint32_t row, const ValueType value)
    {
        return MatrixBase<ValueType>::setValue(row, 0, value);
    }

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[N])
    {
        MatrixBase<ValueType>::setValuesProtected(values);
    }
};

///
/// @brief Partial template specialization of Vector<ValueType, N, Storage>
/// where StorageOption = STORAGE_EXTERNAL.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of vector rows.
///
template <typename ValueType, uint32_t N>
class Vector<ValueType, N, STORAGE_EXTERNAL> :
                                public Matrix<ValueType, N, 1, STORAGE_EXTERNAL>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Vector(ValueType storageValues[N]) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(
                                           *(ValueType (*)[N][1]) storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, uint32_t ParentM, Storage StorageOption2>
    Vector(Matrix<ValueType, ParentN, ParentM, StorageOption2>& matrix,
           const uint32_t row,
           const uint32_t column) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, Storage StorageOption2>
    Vector(Vector<ValueType, ParentN, StorageOption2>& vector,
           const uint32_t row) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(vector, row, 0)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const MatrixInterface<ValueType, N, 1>& matrix) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector(const Matrix<ValueType, N, 1, StorageOption2>& matrix) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector(const Vector<ValueType, N, StorageOption2>& vector) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(vector)
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
                             const Vector<ValueType, N, StorageOption2>& vector)
    {
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>::operator=(vector);

        return (*this);
    }
    
    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, N, STORAGE_EXTERNAL>& operator=(
                                 const MatrixInterface<ValueType, N, 1>& matrix)
    {
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>::operator=(matrix);

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
        return getValue(row);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row) const
    {
        return getValue(row);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType>::setValues;

    //--------------------------------------------------------------------------
    ValueType& getValue(const uint32_t row)
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValue(const uint32_t row) const
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    void setValue(const uint32_t row, const ValueType value)
    {
        return MatrixBase<ValueType>::setValue(row, 0, value);
    }

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[N])
    {
        MatrixBase<ValueType>::setValuesProtected(values);
    }
};


///
/// @brief Partial template specialization of Vector<ValueType, N, Storage>
/// where StorageOption = STORAGE_CONSTANT.
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of vector rows.
///
template <typename ValueType, uint32_t N>
class Vector<ValueType, N, STORAGE_CONSTANT> :
                                public Matrix<ValueType, N, 1, STORAGE_CONSTANT>
{
public:

    typedef ValueType ValueT;
    static const uint32_t rows = N;
    static const uint32_t columns = 1;

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Vector(const ValueType storageValues[N]) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(
                                           *(ValueType (*)[N][1]) storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, uint32_t ParentM, Storage StorageOption2>
    Vector(Matrix<ValueType, ParentN, ParentM, StorageOption2>& matrix,
           const uint32_t row,
           const uint32_t column) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <uint32_t ParentN, Storage StorageOption2>
    Vector(Vector<ValueType, ParentN, StorageOption2>& vector,
           const uint32_t row) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(vector, row, 0)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const MatrixInterface<ValueType, N, 1>& matrix) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector(const Matrix<ValueType, N, 1, StorageOption2>& matrix) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <Storage StorageOption2>
    Vector(const Vector<ValueType, N, StorageOption2>& vector) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(vector)
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
    Vector<ValueType, N, STORAGE_CONSTANT>& operator=(
                             const Vector<ValueType, N, StorageOption2>& vector)
    {
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>::operator=(vector);

        return (*this);
    }
    
    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, N, STORAGE_CONSTANT>& operator=(
                                 const MatrixInterface<ValueType, N, 1>& matrix)
    {
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, N, STORAGE_CONSTANT>& operator=(const ValueType values[N])
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const uint32_t row)
    {
        return getValue(row);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row) const
    {
        return getValue(row);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ValueType& getValue(const uint32_t row)
    {
        return MatrixBase<ValueType, const ValueType>::getValue(row, 0);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValue(const uint32_t row) const
    {
        return MatrixBase<ValueType, const ValueType>::getValue(row, 0);
    }
};

}; // namespace Matrice

#endif // MATRICE_VECTOR_H
