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

#include <cstdint>

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
          std::uint32_t N,
          Storage StorageOption = STORAGE_INTERNAL>
class Vector : public Matrix<ValueType, N, 1, StorageOption>
{
public:

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
    template <typename ValuePointerType>
    Vector(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
        Matrix<ValueType, N, 1, StorageOption>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Vector(const MatrixInterface<ValueType,
                                 DIMENSIONS_RUN_TIME,
                                 1,
                                 ValuePointerType>& matrix) :
        Matrix<ValueType, N, 1, StorageOption>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const Vector<ValueType, N, StorageOption>& vector) :
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
    template <typename ValuePointerType>
    Vector<ValueType, N, StorageOption>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
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
    ValueType& operator()(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType>::setValues;

    //--------------------------------------------------------------------------
    ValueType& getValue(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValue(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    ValueType& getValueFast(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    void setValue(const std::uint32_t row, const ValueType value)
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
template <typename ValueType, std::uint32_t N>
class Vector<ValueType, N, STORAGE_EXTERNAL> :
                                public Matrix<ValueType, N, 1, STORAGE_EXTERNAL>
{
public:

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
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    Vector(MatrixInterface<ValueType, ParentN, ParentM>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN>
    Vector(MatrixInterface<ValueType, ParentN, 1>& vector,
           const std::uint32_t row) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(vector, row, 0)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Vector(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
        Matrix<ValueType, N, 1, STORAGE_EXTERNAL>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Vector(const MatrixInterface<ValueType,
                                 DIMENSIONS_RUN_TIME,
                                 1,
                                 ValuePointerType>& matrix) :
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
    template <typename ValuePointerType>
    Vector<ValueType, N, STORAGE_EXTERNAL>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
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
    ValueType& operator()(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType>::setValues;

    //--------------------------------------------------------------------------
    ValueType& getValue(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValue(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    ValueType& getValueFast(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    void setValue(const std::uint32_t row, const ValueType value)
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
template <typename ValueType, std::uint32_t N>
class Vector<ValueType, N, STORAGE_CONSTANT> :
                                public Matrix<ValueType, N, 1, STORAGE_CONSTANT>
{
public:

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
    template <std::uint32_t ParentN,
              std::uint32_t ParentM,
              typename ValuePointerType>
    Vector(const MatrixInterface<ValueType,
                                 ParentM,
                                 ParentN,
                                 ValuePointerType>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(matrix, row, column)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, typename ValuePointerType>
    Vector(
         const MatrixInterface<ValueType, ParentN, 1, ValuePointerType>& vector,
         const std::uint32_t row) :
        Matrix<ValueType, N, 1, STORAGE_CONSTANT>(vector, row, 0)
    {
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType>
    Vector(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
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
    template <typename ValuePointerType>
    Vector<ValueType, N, STORAGE_CONSTANT>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
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
    ValueType& operator()(const std::uint32_t row)
    {
        return MatrixBase<ValueType, const ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t row) const
    {
        return MatrixBase<ValueType, const ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ValueType& getValue(const std::uint32_t row)
    {
        return MatrixBase<ValueType, const ValueType>::getValue(row, 0);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValue(const std::uint32_t row) const
    {
        return MatrixBase<ValueType, const ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    ValueType& getValueFast(const std::uint32_t row)
    {
        return MatrixBase<ValueType, const ValueType>::getValueFast(row, 0);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const std::uint32_t row) const
    {
        return MatrixBase<ValueType, const ValueType>::getValueFast(row, 0);
    }
};

///
/// @brief 
/// @tparam ValueType Type of value to be stored in this matrix (ex. double,
/// float, uint32_t, etc.).
/// @tparam N Number of vector rows.
/// @tparam StorageOption Where the vector array storage should be placed.
///
template <typename ValueType>
class Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_INTERNAL> :
                                public Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------
    
    //--------------------------------------------------------------------------
    Vector(const std::uint32_t N) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>(N)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const std::uint32_t N, const ValueType initializationValues[]) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>(
                                     N,
                                     *(ValueType (*)[][1]) initializationValues)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const Vector<ValueType,
                        DIMENSIONS_RUN_TIME,
                        STORAGE_INTERNAL>& vector) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>(1, vector)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, Storage StorageOption>
    Vector(const Vector<ValueType, N, StorageOption>& vector) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>(1, vector)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValuePointerType>
    Vector(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>(1, matrix)
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
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_INTERNAL>& operator=(
                           const Vector<ValueType, DIMENSIONS_RUN_TIME>& vector)
    {
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>::operator=(vector);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption>
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_INTERNAL>& operator=(
            const Vector<ValueType, DIMENSIONS_RUN_TIME, StorageOption>& vector)
    {
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>::operator=(vector);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <Storage StorageOption>
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_INTERNAL>& operator=(
         const Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, StorageOption>& matrix)
    {
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValuePointerType>
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_INTERNAL>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
    {
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_INTERNAL>& operator=(
                                                       const ValueType values[])
    {
        setValues(values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType>::setValues;

    //--------------------------------------------------------------------------
    ValueType& getValue(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValue(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    ValueType& getValueFast(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    void setValue(const std::uint32_t row, const ValueType value)
    {
        return MatrixBase<ValueType>::setValue(row, 0, value);
    }

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[])
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
template <typename ValueType>
class Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL> :
              public Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Vector(const std::uint32_t N, ValueType storageValues[]) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>(
                                            N,
                                            *(ValueType (*)[][1]) storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, std::uint32_t ParentM>
    Vector(const std::uint32_t N,
           MatrixInterface<ValueType, ParentN, ParentM>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>(N,
                                                                    matrix,
                                                                    row,
                                                                    column)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, typename ValuePointerType>
    Vector(const std::uint32_t N,
           MatrixInterface<ValueType, ParentN, 1, ValuePointerType>& vector,
           const std::uint32_t row) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>(N,
                                                                    vector,
                                                                    row,
                                                                    0)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValuePointerType>
    Vector(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, Storage StorageOption>
    Vector(const Matrix<ValueType, N, 1, StorageOption>& matrix) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const Vector<ValueType,
                        DIMENSIONS_RUN_TIME,
                        STORAGE_EXTERNAL>& vector) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>(vector)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, Storage StorageOption>
    Vector(const Vector<ValueType, N, StorageOption>& vector) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_EXTERNAL>(vector)
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
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL>& operator=(
                                         const Vector<ValueType,
                                                      DIMENSIONS_RUN_TIME,
                                                      STORAGE_EXTERNAL>& vector)
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_EXTERNAL>::operator=(vector);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, Storage StorageOption>
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL>& operator=(
                              const Vector<ValueType, N, StorageOption>& vector)
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_EXTERNAL>::operator=(vector);

        return (*this);
    }
    
    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValuePointerType>
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_EXTERNAL>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_EXTERNAL>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType,
           DIMENSIONS_RUN_TIME,
           STORAGE_EXTERNAL>& operator=(const ValueType values[])
    {
        setValues(values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    using MatrixBase<ValueType>::setValues;

    //--------------------------------------------------------------------------
    ValueType& getValue(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValue(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    ValueType& getValueFast(const std::uint32_t row)
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const std::uint32_t row) const
    {
        return MatrixBase<ValueType>::getValueFast(row, 0);
    }

    //--------------------------------------------------------------------------
    void setValue(const std::uint32_t row, const ValueType value)
    {
        return MatrixBase<ValueType>::setValue(row, 0, value);
    }

    //--------------------------------------------------------------------------
    void setValues(const ValueType values[])
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
template <typename ValueType>
class Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT> :
              public Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Vector(const std::uint32_t N, const ValueType storageValues[]) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>(
                                            N,
                                            *(ValueType (*)[][1]) storageValues)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN,
              std::uint32_t ParentM,
              typename ValuePointerType>
    Vector(const std::uint32_t N,
           const MatrixInterface<ValueType,
                                 ParentN,
                                 ParentM,
                                 ValuePointerType>& matrix,
           const std::uint32_t row,
           const std::uint32_t column) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>(N,
                                                                    matrix,
                                                                    row,
                                                                    column)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t ParentN, typename ValuePointerType>
    Vector(
         const std::uint32_t N,
         const MatrixInterface<ValueType, ParentN, 1, ValuePointerType>& vector,
         const std::uint32_t row) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>(N,
                                                                    vector,
                                                                    row,
                                                                    0)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValuePointerType>
    Vector(const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N>
    Vector(const Matrix<ValueType, N, 1, STORAGE_CONSTANT>& matrix) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>(matrix)
    {
    }

    //--------------------------------------------------------------------------
    Vector(const Vector<ValueType,
                        DIMENSIONS_RUN_TIME,
                        STORAGE_CONSTANT>& vector) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>(vector)
    {
    }

    //--------------------------------------------------------------------------
    template <std::uint32_t N>
    Vector(const Vector<ValueType, N, STORAGE_CONSTANT>& vector) :
        Matrix<ValueType, DIMENSIONS_RUN_TIME, 1, STORAGE_CONSTANT>(vector)
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
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT>& operator=(
         const Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT>& vector)
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_CONSTANT>::operator=(vector);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, Storage StorageOption>
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT>& operator=(
                              const Vector<ValueType, N, StorageOption>& vector)
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_CONSTANT>::operator=(vector);

        return (*this);
    }
    
    // Assignment operator
    //--------------------------------------------------------------------------
    template <std::uint32_t N, typename ValuePointerType>
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT>& operator=(
               const MatrixInterface<ValueType, N, 1, ValuePointerType>& matrix)
    {
        Matrix<ValueType,
               DIMENSIONS_RUN_TIME,
               1,
               STORAGE_CONSTANT>::operator=(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    Vector<ValueType, DIMENSIONS_RUN_TIME, STORAGE_CONSTANT>& operator=(
                                                       const ValueType values[])
    {
        MatrixBase<ValueType, const ValueType>::setValuesPointerProtected(
                                                                        values);

        return (*this);
    }

    //--------------------------------------------------------------------------
    ValueType& operator()(const std::uint32_t row)
    {
        return MatrixBase<ValueType, const ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t row) const
    {
        return MatrixBase<ValueType, const ValueType>::operator()(row, 0);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ValueType& getValue(const std::uint32_t row)
    {
        return MatrixBase<ValueType, const ValueType>::getValue(row, 0);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValue(const std::uint32_t row) const
    {
        return MatrixBase<ValueType, const ValueType>::getValue(row, 0);
    }

    //--------------------------------------------------------------------------
    ValueType& getValueFast(const std::uint32_t row)
    {
        return MatrixBase<ValueType, const ValueType>::getValueFast(row, 0);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const std::uint32_t row) const
    {
        return MatrixBase<ValueType, const ValueType>::getValueFast(row, 0);
    }
};

}; // namespace Matrice

#endif // MATRICE_VECTOR_H
