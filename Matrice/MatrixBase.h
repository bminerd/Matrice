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
#include <limits>
#include <algorithm>
#include <cmath>
#include <cstdio>

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
/// @tparam ValuePointerType Type of value pointer to be stored in this matrix.
/// In general, this should be the same as ValueType except for matrices with
/// constant storage. In this case, ValuePointerType = const ValuePointer.
/// @note Currently supports only row-major matrices.
/// @note The underlying array indexing is done by incrementing pointers.
/// Normally this approach is avoided in Matrice due to poor readability, but the
/// performance gains are ~10x versus using for-loops and standard indexing.
///
template <typename ValueType, typename ValuePointerType = ValueType>
class MatrixBase
{
public:

    //--------------------------------------------------------------------------
    // Public operator overloads
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixBase<ValueType, ValuePointerType>& operator=(
                          const MatrixBase<ValueType, ValuePointerType>& matrix)
    {
        setValuesPointerProtected(matrix);

        return (*this);
    }

    // Assignment operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixBase<ValueType, ValuePointerType>& operator=(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix)
    {
        setValuesPointerProtected(matrix);

        return (*this);
    }

    //
    //--------------------------------------------------------------------------
    ValueType& operator()(const std::uint32_t rowIndex,
                          const std::uint32_t columnIndex)
    {
        return getValue(rowIndex, columnIndex);
    }

    //
    //--------------------------------------------------------------------------
    const ValueType& operator()(const std::uint32_t rowIndex,
                                const std::uint32_t columnIndex) const
    {
        return getValue(rowIndex, columnIndex);
    }

    //--------------------------------------------------------------------------
    // Public methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    std::uint32_t getRows() const
    {
        return myRows;
    }

    //--------------------------------------------------------------------------
    std::uint32_t getColumns() const
    {
        return myColumns;
    }

    //--------------------------------------------------------------------------
    std::uint32_t getColumnJump() const
    {
        return myColumnJump;
    }

    //--------------------------------------------------------------------------
    ValueType& getValue(const std::uint32_t rowIndex,
                        const std::uint32_t columnIndex)
    {
        ValueType* value = 0;

        if ((rowIndex < myRows) && (columnIndex < myColumns))
        {
            value = &(getValueFast(rowIndex, columnIndex));
        }
        else
        {
            // Throw error
        }

        return (*value);
    }

    //
    //--------------------------------------------------------------------------
    const ValuePointerType& getValue(const std::uint32_t rowIndex,
                                     const std::uint32_t columnIndex) const
    {
        const ValuePointerType* value = 0;

        if ((rowIndex < myRows) && (columnIndex < myColumns))
        {
            value = &(getValueFast(rowIndex, columnIndex));
        }
        else
        {
            // Throw error
        }

        return (*value);
    }

    ///
    /// @brief Gets the value at (rowIndex, columnIndex) of this matrix.
    /// @param rowIndex Row index of value to get.
    /// @param columnIndex Column index of value to get.
    /// @return Reference to the value at (rowIndex, columnIndex).
    /// @note This method doesn't perform any index error checking and is meant
    /// for internal use only. The method getValue() should be used instead.
    ///
    //--------------------------------------------------------------------------
    ValuePointerType& getValueFast(const std::uint32_t rowIndex,
                                   const std::uint32_t columnIndex)
    {
        std::uint32_t valueOffset = 
                          (rowIndex * (myColumns + myColumnJump)) + columnIndex;

        return (myValuesPointer[valueOffset]);
    }

    ///
    /// @brief Gets the value at (rowIndex, columnIndex) of this matrix.
    /// @param rowIndex Row index of value to get.
    /// @param columnIndex Column index of value to get.
    /// @return Constant reference to the value at (rowIndex, columnIndex).
    /// @note This method doesn't perform any index error checking and is meant
    /// for internal use only. The method getValue() should be used instead.
    ///
    //--------------------------------------------------------------------------
    const ValueType& getValueFast(const std::uint32_t rowIndex,
                                  const std::uint32_t columnIndex) const
    {
        std::uint32_t valueOffset = 
                          (rowIndex * (myColumns + myColumnJump)) + columnIndex;

        return (myValuesPointer[valueOffset]);
    }

    //--------------------------------------------------------------------------
    void setValue(const std::uint32_t rowIndex,
                  const std::uint32_t columnIndex,
                  const ValueType value)
    {
        std::uint32_t valueOffset = 
                          (rowIndex * (myColumns + myColumnJump)) + columnIndex;

        myValuesPointer[valueOffset] = value;
    }

    //--------------------------------------------------------------------------
    void setValues(const ValueType value)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*thisValuePointer++) = value;
            }
        }
        else
        {
            while (i--)
            {
                (*thisValuePointer) = value;

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    //--------------------------------------------------------------------------
    ValueType maxValue() const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        ValueType maxValue = (*thisValuePointer);

        std::int32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                if ((*thisValuePointer) > maxValue)
                {
                    maxValue = (*thisValuePointer);
                }

                thisValuePointer++;
            }
        }
        else
        {
            while (i--)
            {
                if ((*thisValuePointer) > maxValue)
                {
                    maxValue = (*thisValuePointer);
                }

                incrementValuePointer(thisValuePointer, i);
            }
        }

        return maxValue;
    }

    //--------------------------------------------------------------------------
    ValueType minValue() const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        ValueType minValue = (*thisValuePointer);

        std::int32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                if ((*thisValuePointer) < minValue)
                {
                    minValue = (*thisValuePointer);
                }

                thisValuePointer++;
            }
        }
        else
        {
            while (i--)
            {
                if ((*thisValuePointer) < minValue)
                {
                    minValue = (*thisValuePointer);
                }

                incrementValuePointer(thisValuePointer, i);
            }
        }

        return minValue;
    }

    //--------------------------------------------------------------------------
    void limitValues(const ValueType lowerLimitValue,
                     const ValueType upperLimitValue)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
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
        else
        {
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

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    //--------------------------------------------------------------------------
    void limitUpperValue(const ValueType limitValue)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                if ((*thisValuePointer) > limitValue)
                {
                    (*thisValuePointer) = limitValue;
                }

                thisValuePointer++;
            }
        }
        else
        {
            while (i--)
            {
                if ((*thisValuePointer) > limitValue)
                {
                    (*thisValuePointer) = limitValue;
                }

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    //--------------------------------------------------------------------------
    void limitLowerValue(const ValueType limitValue)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                if ((*thisValuePointer) < limitValue)
                {
                    (*thisValuePointer) = limitValue;
                }

                thisValuePointer++;
            }
        }
        else
        {
            while (i--)
            {
                if ((*thisValuePointer) < limitValue)
                {
                    (*thisValuePointer) = limitValue;
                }

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    //--------------------------------------------------------------------------
    ValueType magnitude() const
    {
        ValueType squaredSum = 0.0;

        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                squaredSum += square(*thisValuePointer++);
            }
        }
        else
        {
            while (i--)
            {
                squaredSum += square(*thisValuePointer);

                incrementValuePointer(thisValuePointer, i);
            }
        }

        return std::sqrt(squaredSum);
    }

    //--------------------------------------------------------------------------
    ValueType norm() const
    {
        return magnitude();
    }

    //--------------------------------------------------------------------------
    void incrementValuePointer(ValuePointerType*& valuePointer, const int i)
    {
        if ((i % myColumns) == 0)
        {
            valuePointer += myColumnJump + 1;
        }
        else
        {
            valuePointer++;
        }
    }

    //--------------------------------------------------------------------------
    void incrementValuePointer(const ValuePointerType*& valuePointer,
                               const int i) const
    {
        if ((i % myColumns) == 0)
        {
            valuePointer += myColumnJump + 1;
        }
        else
        {
            valuePointer++;
        }
    }

    //--------------------------------------------------------------------------
    void toString(char* string, const std::uint8_t precision = 10) const
    {
        std::uint32_t width = precision + 5;

        std::uint32_t nCharacters = 0;
        nCharacters += std::sprintf(&(string[nCharacters]), "\n");

        for (int i = 0; i < myRows; i++)
        {
            nCharacters += std::sprintf(&(string[nCharacters]), "[");

            for (int j = 0; j < myColumns; j++)
            {
                nCharacters += std::sprintf(&(string[nCharacters]),
                                            "%*g",
                                            width,
                                            getValueFast(i, j));
            }

            nCharacters += std::sprintf(&(string[nCharacters]), " ]\n");
        }
    }

    //--------------------------------------------------------------------------
    void print() const
    {
        char matrixString[128000];

        toString(matrixString);

        Matrice::print(matrixString);
    }

protected:

    //--------------------------------------------------------------------------
    // Protected constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixBase(const std::uint32_t rows,
               const std::uint32_t columns,
               ValuePointerType* valuesPointer,
               const std::uint32_t columnJump) :
        myRows(rows),
        myColumns(columns),
        myValuesPointer(valuesPointer),
        myColumnJump(columnJump)
    {
    }

    //--------------------------------------------------------------------------
    MatrixBase(const std::uint32_t rows,
               const std::uint32_t columns,
               ValuePointerType* valuesPointer,
               const std::uint32_t columnJump,
               const ValueType* initializationValuesPointer) :
        myRows(rows),
        myColumns(columns),
        myValuesPointer(valuesPointer),
        myColumnJump(columnJump)
    {
        setValuesProtected(initializationValuesPointer);
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointer2>
    MatrixBase(const std::uint32_t rows,
               const std::uint32_t columns,
               ValuePointerType* valuesPointer,
               const std::uint32_t columnJump,
               const MatrixBase<ValueType, ValuePointer2>& matrix) :
        myRows(rows),
        myColumns(columns),
        myValuesPointer(valuesPointer),
        myColumnJump(columnJump)
    {
        setValuesProtected(matrix);
    }


    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    MatrixBase(const MatrixBase<ValueType, ValuePointerType2>& matrix) :
        myRows(matrix.getRows()),
        myColumns(matrix.getColumns()),
        myValuesPointer(&(matrix.getValue(0, 0))),
        myColumnJump(matrix.getColumnJump())
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
    // Protected methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <typename ValueType2, typename ValuePointerType2>
    void operatorTypeCast(
                        MatrixBase<ValueType2, ValuePointerType2>& matrix) const
    {
        const ValuePointerType* myValuePointer = &(getValueFast(0, 0));
        ValuePointerType2* valuePointer = &(matrix.getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*valuePointer++) = (ValueType2) (*myValuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*valuePointer++) = (ValueType2) (*myValuePointer);

                incrementValuePointer(myValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                (*valuePointer) = (ValueType2) (*myValuePointer++);

                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                (*valuePointer) = (ValueType2) (*myValuePointer);

                incrementValuePointer(myValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    bool operatorEquals(
                   const MatrixBase<ValueType, ValuePointerType2>& matrix) const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        const ValuePointerType2* valuePointer = &(matrix.getValueFast(0, 0));
        const ValueType epsilon = std::numeric_limits<ValueType>::epsilon();

        std::int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                ValueType value1 = (*thisValuePointer++);
                ValueType value2 = (*valuePointer++);

                if (std::abs(value1 - value2) > epsilon)
                {
                    return false;
                }
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                ValueType value1 = (*thisValuePointer);
                ValueType value2 = (*valuePointer++);

                if (std::abs(value1 - value2) > epsilon)
                {
                    return false;
                }

                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                ValueType value1 = (*thisValuePointer++);
                ValueType value2 = (*valuePointer);

                if (std::abs(value1 - value2) > epsilon)
                {
                    return false;
                }

                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                ValueType value1 = (*thisValuePointer++);
                ValueType value2 = (*valuePointer++);

                if (std::abs(value1 - value2) > epsilon)
                {
                    return false;
                }

                incrementValuePointer(thisValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }

        return true;
    }

    // Unary plus operator
    //--------------------------------------------------------------------------
    void operatorUnaryPlus(MatrixBase<ValueType>& matrix) const
    {
        // Here for symmetry with operatorUnaryMinus() only
    }
    
    // Unary minus operator
    //--------------------------------------------------------------------------
    void operatorUnaryMinus(MatrixBase<ValueType>& matrix) const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*valuePointer++) = -(*thisValuePointer++);
            }
        }
        else
        {
            while (i--)
            {
                (*valuePointer++) = -(*thisValuePointer);

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    // Addition operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void operatorAdd(const MatrixBase<ValueType, ValuePointerType2>& matrix,
                     MatrixBase<ValueType>& resultMatrix) const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        const ValuePointerType2* valuePointer = &(matrix.getValueFast(0, 0));
        ValueType* resultValuePointer = &(resultMatrix.getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                      (*thisValuePointer++) + (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                        (*thisValuePointer) + (*valuePointer++);

                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                        (*thisValuePointer++) + (*valuePointer);

                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                (*resultValuePointer++) = (*thisValuePointer) + (*valuePointer);

                incrementValuePointer(thisValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }
    }

    // Subtraction operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void operatorSubtract(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix,
                         MatrixBase<ValueType>& resultMatrix) const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        const ValuePointerType2* valuePointer = &(matrix.getValueFast(0, 0));
        ValueType* resultValuePointer = &(resultMatrix.getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                      (*thisValuePointer++) - (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                        (*thisValuePointer) - (*valuePointer++);

                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                        (*thisValuePointer++) - (*valuePointer);

                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                (*resultValuePointer++) = (*thisValuePointer) - (*valuePointer);

                incrementValuePointer(thisValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
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
    template <typename ValuePointerType2>
    void operatorMultiplyMByM2(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix,
                         MatrixBase<ValueType>& resultMatrix) const
    {
        const ValuePointerType* leftPointer  = &(getValueFast(0, 0));
        const ValuePointerType2* rightPointer = &(matrix.getValueFast(0, 0));
        ValueType* resultPointer = &(resultMatrix.getValueFast(0, 0));

        std::uint32_t i = 0;

        const std::uint32_t resultColumns = resultMatrix.getColumns();

        std::uint32_t rightPointerIncrement = resultColumns;

        if (matrix.getColumnJump() != 0)
        {
            rightPointerIncrement += matrix.getColumnJump();
        }
        
        while (i < myRows)
        {
            std::uint32_t j = 0;

            while (j < resultColumns)
            {
                leftPointer = &(getValueFast(i, 0));
                rightPointer = &(matrix.getValueFast(0, j));

                std::uint32_t columns = myColumns;
                ValueType temp = 0;

                // Loop
                while (columns--)
                {
                    temp += (*leftPointer++) * (*rightPointer);

                    rightPointer += rightPointerIncrement;
                }

                (*resultPointer++) = temp;

                j++;
            }

            i++;
        }
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void operatorMultiplyMBy1(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix,
                         MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* leftPointer  = &(getValueFast(0, 0));
        const ValuePointerType2* rightPointer = &(matrix.getValueFast(0, 0));
        ValueType* resultPointer = &(resultMatrix.getValueFast(0, 0));

        std::uint32_t i = 0;

        std::uint32_t rightPointerIncrement = 1;

        if (matrix.getColumnJump() != 0)
        {
            rightPointerIncrement += matrix.getColumnJump();
        }
        
        while (i < myRows)
        {
            leftPointer = &(getValueFast(i, 0));
            rightPointer = &(matrix.getValueFast(0, 0));

            std::int32_t rowSize = (std::int32_t) myColumns;
            ValueType temp = 0;

            // Loop
            while (rowSize--)
            {
                temp += (*leftPointer++) * (*rightPointer);

                rightPointer += rightPointerIncrement;
            }

            (*resultPointer++) = temp;

            i++;
        }
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    void operatorAddScalar(MatrixBase<ValueType>& matrix,
                           const ValueType scalar) const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*valuePointer++) = (*thisValuePointer++) + scalar;
            }
        }
        else
        {
            while (i--)
            {
                (*valuePointer++) = (*thisValuePointer) + scalar;

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    // Addition-equals operator (scalar)
    //--------------------------------------------------------------------------
    void operatorAddEqualsScalar(const ValueType scalar)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*thisValuePointer++) += scalar;
            }
        }
        else
        {
            while (i--)
            {
                (*thisValuePointer) += scalar;

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    // Addition-equals operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void operatorAddEquals(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*thisValuePointer++) += (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*thisValuePointer) += (*valuePointer++);
            
                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                (*thisValuePointer++) += (*valuePointer);
                
                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                (*thisValuePointer) += (*valuePointer);
                
                incrementValuePointer(thisValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }
    }

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    void operatorSubtractScalar(MatrixBase<ValueType>& matrix,
                                const ValueType scalar) const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*valuePointer++) = (*thisValuePointer++) - scalar;
            }
        }
        else
        {
            while (i--)
            {
                (*valuePointer++) = (*thisValuePointer) - scalar;

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    // Subtraction-equals operator (scalar)
    //--------------------------------------------------------------------------
    void operatorSubtractEqualsScalar(const ValueType scalar)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*thisValuePointer++) -= scalar;
            }
        }
        else
        {
            while (i--)
            {
                (*thisValuePointer) -= scalar;

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    // Subtract-equals operator
    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void operatorSubtractEquals(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*thisValuePointer++) -= (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*thisValuePointer) -= (*valuePointer++);
            
                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                (*thisValuePointer++) -= (*valuePointer);
                
                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                (*thisValuePointer) -= (*valuePointer);
                
                incrementValuePointer(thisValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }
    }

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    void operatorMultiplyScalar(MatrixBase<ValueType>& matrix,
                                const ValueType scalar) const
    {
        const ValuePointerType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*valuePointer++) = (*thisValuePointer++) * scalar;
            }
        }
        else
        {
            while (i--)
            {
                (*valuePointer++) = (*thisValuePointer) * scalar;

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }

    // Multiplication-equals operator (scalar)
    //--------------------------------------------------------------------------
    void operatorMultiplyEqualsScalar(const ValueType scalar)
    {
        ValuePointerType* thisValuePointer = &(getValueFast(0, 0));

        std::uint32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*thisValuePointer++) *= scalar;
            }
        }
        else
        {
            while (i--)
            {
                (*thisValuePointer) *= scalar;

                incrementValuePointer(thisValuePointer, i);
            }
        }
    }
    
    //--------------------------------------------------------------------------
    void setValuesPointerProtected(ValuePointerType* values)
    {
        myValuesPointer = values;
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void setValuesPointerProtected(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix)
    {
        myValuesPointer = &(matrix.getValue(0, 0));
    }

    //--------------------------------------------------------------------------
    void setValuesProtected(const ValueType values[])
    {
        ValuePointerType* myValuePointer = &(getValueFast(0, 0));
        const ValuePointerType* valuePointer = values;

        std::int32_t i = myRows * myColumns;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*myValuePointer++) = (*valuePointer++);
            }
        }
        else
        {
            while (i--)
            {
                (*myValuePointer) = (*valuePointer);

                incrementValuePointer(myValuePointer, i);
            }
        }
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void setValuesProtected(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix)
    {
        ValuePointerType* myValuePointer = &(getValueFast(0, 0));
        const ValuePointerType2* valuePointer = &(matrix.getValueFast(0, 0));

        std::int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*myValuePointer++) = (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                (*myValuePointer) = (*valuePointer++);

                incrementValuePointer(myValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                (*myValuePointer++) = (*valuePointer);

                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                (*myValuePointer) = (*valuePointer);

                incrementValuePointer(myValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }
    }

    //--------------------------------------------------------------------------
    void getRow(MatrixBase<ValueType>& matrix,
                const std::uint32_t rowIndex) const
    {
        const ValuePointerType* myValuePointer = &(getValueFast(rowIndex, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::uint32_t i = myColumns;

        while (i--)
        {
            (*valuePointer++) = (*myValuePointer++);
        }
    }

    //--------------------------------------------------------------------------
    void getColumn(MatrixBase<ValueType>& matrix,
                   const std::uint32_t columnIndex) const
    {
        const ValuePointerType* myValuePointer =
                                                &(getValueFast(0, columnIndex));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        std::uint32_t i = myRows;

        if (myColumnJump == 0)
        {
            while (i--)
            {
                (*valuePointer++) = (*myValuePointer);

                myValuePointer += myColumns;
            }
        }
        else
        {
            while (i--)
            {
                (*valuePointer++) = (*myValuePointer);

                myValuePointer += myColumns + myColumnJump;
            }
        }
    }

    //--------------------------------------------------------------------------
    void transpose(MatrixBase<ValueType>& matrix) const
    {
        const ValuePointerType* thisValuePointer = 0;

        std::uint32_t i = 0;

        while (i < myRows)
        {
            std::uint32_t j = 0;

            // Submatrix column jumping is handled by getValueFast()
            thisValuePointer = &(getValueFast(i, 0));

            while (j < myColumns)
            {
                matrix.getValueFast(j, i) = (*thisValuePointer++);

                j++;
            }

            i++;
        }
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void crossProductMatrix(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix,
                         MatrixBase<ValueType>& resultMatrix)
    {
        std::uint32_t i = 0;

        while (i++ < myColumns)
        {
            resultMatrix.getValueFast(0, i) =
                getValueFast(1, i) * matrix.getValueFast(2, i) -
                                 getValueFast(2, i) * matrix.getValueFast(1, i);

            resultMatrix.getValueFast(1, i) =
                getValueFast(2, i) * matrix.getValueFast(0, i) -
                                 getValueFast(0, i) * matrix.getValueFast(2, i);

            resultMatrix.getValueFast(2, i) =
                getValueFast(0, i) * matrix.getValueFast(1, i) -
                                 getValueFast(1, i) * matrix.getValueFast(0, i);
        }
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    void crossProductVector(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix,
                         MatrixBase<ValueType>& resultMatrix) const
    {
        resultMatrix.getValueFast(0, 0) =
            getValueFast(1, 0) * matrix.getValueFast(2, 0) -
                                 getValueFast(2, 0) * matrix.getValueFast(1, 0);

        resultMatrix.getValueFast(1, 0) =
            getValueFast(2, 0) * matrix.getValueFast(0, 0) -
                                 getValueFast(0, 0) * matrix.getValueFast(2, 0);

        resultMatrix.getValueFast(2, 0) =
            getValueFast(0, 0) * matrix.getValueFast(1, 0) -
                                 getValueFast(1, 0) * matrix.getValueFast(0, 0);
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    ValueType dotProductMatrix(
                         const MatrixBase<ValueType, ValuePointerType2>& matrix,
                         MatrixBase<ValueType>& resultMatrix) const
    {
        ValuePointerType* myValuePointer = &(getValueFast(0, 0));
        const ValuePointerType2* valuePointer = &(matrix.getValueFast(0, 0));

        ValueType result = 0;

        std::uint32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                result += (*myValuePointer++) * (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                result += (*myValuePointer) * (*valuePointer++);

                incrementValuePointer(myValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                result += (*myValuePointer++) * (*valuePointer);

                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                result += (*myValuePointer) * (*valuePointer);

                incrementValuePointer(myValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }

        return result;
    }

    //--------------------------------------------------------------------------
    template <typename ValuePointerType2>
    ValueType dotProductVector(
                   const MatrixBase<ValueType, ValuePointerType2>& matrix) const
    {
        const ValuePointerType* myValuePointer = &(getValueFast(0, 0));
        const ValuePointerType2* valuePointer = &(matrix.getValueFast(0, 0));

        ValueType result = 0;

        std::uint32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                result += (*myValuePointer++) * (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.getColumnJump() == 0))
        {
            while (i--)
            {
                result += (*myValuePointer) * (*valuePointer++);

                incrementValuePointer(myValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.getColumnJump() != 0))
        {
            while (i--)
            {
                result += (*myValuePointer++) * (*valuePointer);

                matrix.incrementValuePointer(valuePointer, i);
            }
        }
        else
        {
            while (i--)
            {
                result += (*myValuePointer) * (*valuePointer);

                incrementValuePointer(myValuePointer, i);
                matrix.incrementValuePointer(valuePointer, i);
            }
        }

        return result;
    }

    // Compute the 3x3 skew / cross product equivalent matrix from a 3x1 vector
    // 
    // vector = | a1 |    -->    skew = |   0  -a3   a2 |
    //          | a2 |                  |  a3    0  -a1 |
    //          | a3 |                  | -a2   a1    0 |
    //
    //--------------------------------------------------------------------------
    void toCrossProductEquivalentMatrix(
                                      MatrixBase<ValueType>& resultMatrix) const
    {
        resultMatrix.getValueFast(0, 1) = -getValueFast(2, 0);
        resultMatrix.getValueFast(0, 2) =  getValueFast(1, 0);
        resultMatrix.getValueFast(1, 0) =  getValueFast(2, 0);
        resultMatrix.getValueFast(1, 2) = -getValueFast(0, 0);
        resultMatrix.getValueFast(2, 0) = -getValueFast(1, 0);
        resultMatrix.getValueFast(2, 1) =  getValueFast(0, 0);
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    const std::uint32_t myRows;

    const std::uint32_t myColumns;

    ValuePointerType* myValuesPointer;

    const std::uint32_t myColumnJump;
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_BASE_H
