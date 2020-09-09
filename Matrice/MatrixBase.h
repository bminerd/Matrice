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
/// @file MatrixBase.h
/// @author Ben Minerd
/// @date 2/18/2016
/// @brief MatrixBase class header file.
///

#ifndef MATRICE_MATRIX_BASE_H
#define MATRICE_MATRIX_BASE_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>

#include <Matrice/Matrice.h>

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
template <typename ValueType>
class MatrixBase
{
protected:

    //--------------------------------------------------------------------------
    // Protected constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixBase(const uint32_t rows,
               const uint32_t columns,
               ValueType* valuesPointer) :
        myRows(rows),
        myColumns(columns),
        myValuesPointer(valuesPointer)
    {
    }

    //--------------------------------------------------------------------------
    MatrixBase(const MatrixBase& matrix) :
        myRows(matrix.myRows),
        myColumns(matrix.myColumns),
        myValuesPointer(matrix.myValuesPointer)
    {
    }

    //--------------------------------------------------------------------------
    // Protected destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~MatrixBase()
    {
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ValueType& getValue(const uint32_t row, const uint32_t column)
    {
        ValueType* value = 0;

        if ((row <= myRows) && (column <= myColumns))
        {
            value = &getValueFast(row, column);
        }

        return (*value);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& getValue(const uint32_t row, const uint32_t column) const
    {
        ValueType* value = 0;

        if ((row <= myRows) && (column <= myColumns))
        {
            value = &getValueFast(row, column);
        }

        return (*value);
    }

    ///
    /// @brief Gets the value at (row, column) of this matrix.
    /// @param row Row of value to get.
    /// @param row Column of value to get.
    /// @return Reference to the value at (row, column).
    /// @note This method doesn't perform any index error checking and is meant
    /// for internal use only. The method getValue() should be used instead.
    ///
    //--------------------------------------------------------------------------
    ValueType& getValueFast(const uint32_t row, const uint32_t column)
    {
        ValueType (& arrayReference)[myRows][myColumns] =
                             *(ValueType (*)[myRows][myColumns]) myValuesPointer;

        return (arrayReference[row][column]);
        // return ((*(ValueType *[myRows][myColumns])myValuesPointer)[row][column]);
    }

    ///
    /// @brief Gets the value at (row, column) of this matrix.
    /// @param row Row of value to get.
    /// @param row Column of value to get.
    /// @return Constant reference to the value at (row, column).
    /// @note This method doesn't perform any index error checking and is meant
    /// for internal use only. The method getValue() should be used instead.
    ///
    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const uint32_t row,
                                  const uint32_t column) const
    {
        ValueType (& arrayReference)[myRows][myColumns] =
                             *(ValueType (*)[myRows][myColumns]) myValuesPointer;

        return (arrayReference[row][column]);
    }

    //--------------------------------------------------------------------------
    void setValue(const uint32_t row,
                  const uint32_t column,
                  const ValueType value)
    {
        ValueType (* arrayPointer)[myColumns] =
                                     (ValueType (*)[myColumns]) myValuesPointer;

        arrayPointer[row][column] = value;
    }

    //--------------------------------------------------------------------------
    void setValues(const ValueType value)
    {
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*thisValuePointer++) = value;
        }
    }

    // //--------------------------------------------------------------------------
    // void setValues(const ValueType* values)
    // {
    //     setValuesProtected(values);
    // }

    // //--------------------------------------------------------------------------
    // void setStaticValues(const ValueType* values)
    // {
    //     setStaticValuesProtected(values);
    // }

    //--------------------------------------------------------------------------
    void T(MatrixBase<ValueType>& matrix)
    {
        return transpose(matrix);
    }

    //--------------------------------------------------------------------------
    void transpose(MatrixBase<ValueType>& matrix)
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = 0;

        while (i != (myRows * myColumns))
        {
            matrix.getValueFast((i % myColumns), (i / myColumns)) = (*thisValuePointer++);

            i++;
        }
    }

    //--------------------------------------------------------------------------
    ValueType maxValue() const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType maxValue = (*thisValuePointer);

        int32_t i = myRows * myColumns;

        while (i--)
        {
            if ((*thisValuePointer) > maxValue)
            {
                maxValue = (*thisValuePointer);
            }

            thisValuePointer++;
        }

        return maxValue;
    }

    //--------------------------------------------------------------------------
    ValueType minValue() const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType minValue = (*thisValuePointer);

        int32_t i = myRows * myColumns;

        while (i--)
        {
            if ((*thisValuePointer) < minValue)
            {
                minValue = (*thisValuePointer);
            }

            thisValuePointer++;
        }

        return minValue;
    }

    //--------------------------------------------------------------------------
    void limitValues(const ValueType lowerLimitValue,
                     const ValueType upperLimitValue)
    {
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            if ((*thisValuePointer) < lowerLimitValue)
            {
                (*thisValuePointer) = lowerLimitValue;
            }
            else if ((*thisValuePointer) > upperLimitValue)
            {
                (*thisValuePointer) = upperLimitValue;
            }

            thisValuePointer++;
        }
    }

    //--------------------------------------------------------------------------
    void limitUpperValue(const ValueType limitValue)
    {
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            if ((*thisValuePointer) > limitValue)
            {
                (*thisValuePointer) = limitValue;
            }

            thisValuePointer++;
        }
    }

    //--------------------------------------------------------------------------
    void limitLowerValue(const ValueType limitValue)
    {
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            if ((*thisValuePointer) < limitValue)
            {
                (*thisValuePointer) = limitValue;
            }

            thisValuePointer++;
        }
    }

    //--------------------------------------------------------------------------
    // Public overloaded operators
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixBase<ValueType>& operator=(const MatrixBase<ValueType>& matrix)
    {
        setValuesProtected(matrix.myValuesPointer);

        return (*this);
    }

    //
    //--------------------------------------------------------------------------
    ValueType& operator()(const uint32_t row, const uint32_t column)
    {
        return getValue(row, column);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& operator()(const uint32_t row, const uint32_t column) const
    {
        return getValue(row, column);
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    void operatorUnaryPlus(MatrixBase<ValueType>& matrix) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*valuePointer++) = +(*thisValuePointer++);
        }
    }
    
    // Unary minus operator
    //--------------------------------------------------------------------------
    void operatorUnaryMinus(MatrixBase<ValueType>& matrix) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*valuePointer++) = -(*thisValuePointer++);
        }
    }

    // Addition operator
    //--------------------------------------------------------------------------
    void operatorAdd(const MatrixBase<ValueType>& matrix,
                     MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));
        ValueType* resultValuePointer = &(resultMatrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*resultValuePointer++) = (*thisValuePointer++) + (*valuePointer++);
        }
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    void operatorSubtract(const MatrixBase<ValueType>& matrix,
                          MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));
        ValueType* resultValuePointer = &(resultMatrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*resultValuePointer++) = (*thisValuePointer++) - (*valuePointer++);
        }
    }

    // Multiplication operator
    //
    // Format is:
    //
    //           (left)   (right)
    // result  =  this  *  matrix
    //
    // Algorithm:
    //
    // Loop through every element in the resulting myRows * myColumns2 matrix. For every
    // element, perform the sum of the current row of the left matrix times the
    // current column of the right matrix.
    //
    //     result      =        this     *    matrix
    //
    //       M2                   M            M2
    //   |C11 C12 C13|      |A11 A12 A13| |B11 B12 B13|
    // N |C21 C22 C23| =  N |A21 A22 A23| |B21 B22 B23| N2 = M
    //   |C31 C32 C33|      |A31 A32 A33| |B31 B32 B33|
    //
    //    result   =       this   *    matrix
    //
    //       M2              M           M2
    //   |C11 C12|      |A11 A12 A13| |B11 B12|
    // N |C21 C22| =  N |A21 A22 A23| |B21 B22| N2 = M
    //                                |B31 B32|
    //
    // result =      this * matrix
    //
    //    M2           M      M2
    //   |C1|      |A11 A12| |B1|
    // N |C2| =  N |A21 A22| |B2| N2 = M
    //
    //--------------------------------------------------------------------------
    void operatorMultiplyNByM(const MatrixBase<ValueType>& matrix,
                              MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* leftPointer  = &(getValueFast(0, 0));
        const ValueType* rightPointer = &(matrix.getValueFast(0, 0));
        ValueType* resultPointer = &(resultMatrix.getValueFast(0, 0));

        uint32_t i = 0;

        const uint32_t resultColumns = resultMatrix.myColumns;
        const uint32_t resultSize = myRows * resultColumns;

        // Loop through every element (myRows * myColumns2) in the resulting Matrix starting
        // at (1, 1) moving left-to-right, top-to-bottom until (N, M2)
        while (i++ < resultSize)
        {
            int32_t rowSize = (int32_t) myColumns;

            // Loop
            while (rowSize--)
            {
                (*resultPointer) += (*leftPointer++) * (*rightPointer);

                rightPointer += resultColumns;
            }

            resultPointer++;

            //
            // Integer divide i / resultColumns gives the first element in the
            // current row of the left matrix
            //
            leftPointer = &(getValueFast((i / resultColumns), 0));

            //
            // Integer modulo i % resultColumns gives the first element in the
            // current column of the right matrix
            //
            rightPointer = &(matrix.getValueFast(0, (i % resultColumns)));
        }
    }

    //--------------------------------------------------------------------------
    void operatorMultiplyNBy1(const MatrixBase<ValueType>& matrix,
                              MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* leftPointer  = &(getValueFast(0, 0));
        const ValueType* rightPointer = &(matrix.getValueFast(0, 0));
        ValueType* resultPointer = &(resultMatrix.getValueFast(0, 0));

        int32_t i = myColumns;

        // Loop through every element (N) in the resulting Vector starting
        // at (1) moving top-to-bottom until (N)
        while (i--)
        {
            int32_t rowSize = (int32_t) myColumns;

            // Loop
            while (rowSize--)
            {
                (*resultPointer) += (*leftPointer++) * (*rightPointer++);
            }

            resultPointer++;

            //
            // First element in the right matrix
            //
            rightPointer = &(matrix.getValueFast(0, 0));
        }
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    void operatorAddScalar(MatrixBase<ValueType>& matrix,
                           const ValueType scalar) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*valuePointer++) = (*thisValuePointer++) + scalar;
        }
    }

    // Addition-equals operator (scalar)
    //--------------------------------------------------------------------------
    void operatorAddEqualsScalar(const ValueType scalar)
    {
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*thisValuePointer++) += scalar;
        }
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    void operatorSubtractScalar(MatrixBase<ValueType>& matrix,
                                const ValueType scalar) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = (int32_t) (myRows * myColumns);

        while (i--)
        {
            (*valuePointer++) = (*thisValuePointer++) - scalar;
        }
    }

    // Subtraction-equals operator (scalar)
    //--------------------------------------------------------------------------
    void operatorSubtractEqualsScalar(const ValueType scalar)
    {
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = (int32_t) (myRows * myColumns);

        while (i--)
        {
            (*thisValuePointer++) -= scalar;
        }
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    void operatorMultiplyScalar(MatrixBase<ValueType>& matrix,
                                const ValueType scalar) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = (int32_t) (myRows * myColumns);

        while (i--)
        {
            (*valuePointer++) = (*thisValuePointer++) * scalar;
        }
    }

    // Multiplication-equals operator (scalar)
    //--------------------------------------------------------------------------
    void operatorMultiplyEqualsScalar(const ValueType scalar)
    {
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = (int32_t) (myRows * myColumns);

        while (i--)
        {
            (*thisValuePointer++) *= scalar;
        }
    }

protected:

    //--------------------------------------------------------------------------
    inline void setValuesProtected(ValueType values[])
    {
        myValuesPointer = values;
    }

    //--------------------------------------------------------------------------
    inline void setValuesProtected(const ValueType values[])
    {
        myValuesPointer = values;
    }

    //--------------------------------------------------------------------------
    inline void copyValuesProtected(const MatrixBase<ValueType>& matrix)
    {
        ValueType* myValuePointer =
                                   &(MatrixBase<ValueType>::getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        while (i--)
        {
            (*myValuePointer++) = (*valuePointer++);
        }
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    const uint32_t myRows;

    const uint32_t myColumns;

    ValueType* myValuesPointer;
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_BASE_H
