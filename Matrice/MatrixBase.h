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
public:

    //--------------------------------------------------------------------------
    // Public operator overloads
    //--------------------------------------------------------------------------

    // Assignment operator
    //--------------------------------------------------------------------------
    MatrixBase<ValueType>& operator=(const MatrixBase<ValueType>& matrix)
    {
        setValuesPointerProtected(matrix.myValuesPointer);

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

        uint32_t i = myRows * myColumns;

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

                incrementValuePointer(i);
            }
        }
    }

    //--------------------------------------------------------------------------
    ValueType maxValue() const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType maxValue = (*thisValuePointer);

        int32_t i = myRows * myColumns;

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
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType minValue = (*thisValuePointer);

        int32_t i = myRows * myColumns;

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
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

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
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

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
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        int32_t i = myRows * myColumns;

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

        const ValueType* thisValuePointer = &(getValueFast(0, 0));

        uint32_t i = myRows * myColumns;

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

        return sqrt(squaredSum);
    }

    //--------------------------------------------------------------------------
    ValueType norm() const
    {
        return magnitude();
    }

protected:

    //--------------------------------------------------------------------------
    // Protected constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    MatrixBase(const uint32_t rows,
               const uint32_t columns,
               ValueType* valuesPointer,
               const uint32_t columnJump = 0) :
        myRows(rows),
        myColumns(columns),
        myValuesPointer(valuesPointer),
        myColumnJump(columnJump)
    {
    }

    //--------------------------------------------------------------------------
    MatrixBase(const MatrixBase& matrix) :
        myRows(matrix.myRows),
        myColumns(matrix.myColumns),
        myValuesPointer(matrix.myValuesPointer),
        myColumnJump(matrix.myColumnJump)
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
    bool operatorEquals(const MatrixBase<ValueType>& matrix)
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));
        const ValueType epsilon = std::numeric_limits<ValueType>::epsilon();

        int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                ValueType value1 = (*thisValuePointer++);
                ValueType value2 = (*valuePointer++);

                if (fabs(value1 - value2) > epsilon)
                {
                    return false;
                }
            }
        }
        else if ((myColumnJump != 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                ValueType value1 = (*thisValuePointer);
                ValueType value2 = (*valuePointer++);

                if (fabs(value1 - value2) > epsilon)
                {
                    return false;
                }

                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.myColumnJump != 0))
        {
            while (i--)
            {
                ValueType value1 = (*thisValuePointer++);
                ValueType value2 = (*valuePointer);

                if (fabs(value1 - value2) > epsilon)
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

                if (fabs(value1 - value2) > epsilon)
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
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

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
    void operatorAdd(const MatrixBase<ValueType>& matrix,
                     MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));
        ValueType* resultValuePointer = &(resultMatrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                      (*thisValuePointer++) + (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                        (*thisValuePointer) + (*valuePointer++);

                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.myColumnJump != 0))
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
    void operatorSubtract(const MatrixBase<ValueType>& matrix,
                          MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));
        ValueType* resultValuePointer = &(resultMatrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                      (*thisValuePointer++) - (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                (*resultValuePointer++) =
                                        (*thisValuePointer) - (*valuePointer++);

                incrementValuePointer(thisValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.myColumnJump != 0))
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
    void operatorMultiplyNByM(const MatrixBase<ValueType>& matrix,
                              MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* leftPointer  = &(getValueFast(0, 0));
        const ValueType* rightPointer = &(matrix.getValueFast(0, 0));
        ValueType* resultPointer = &(resultMatrix.getValueFast(0, 0));

        uint32_t i = 0;

        const uint32_t resultColumns = resultMatrix.myColumns;
        const uint32_t resultSize = myRows * resultColumns;

        if ((myColumnJump == 0) && (matrix.myColumnJump == 0))
        {
            // Loop through every element (myRows * myColumns2) in the resulting
            // Matrix starting at (1, 1) moving left-to-right, top-to-bottom
            // until (N, M2)
            while (i++ < resultSize)
            {
                uint32_t columns = myColumns;

                // Loop
                while (columns--)
                {
                    (*resultPointer) += (*leftPointer++) * (*rightPointer);

                    rightPointer += resultColumns;
                }

                resultPointer++;

                //
                // Integer divide i / resultColumns gives the first element in
                // the current row of the left matrix
                //
                leftPointer = &(getValueFast((i / resultColumns), 0));

                //
                // Integer modulo i % resultColumns gives the first element in
                // the current column of the right matrix
                //
                rightPointer = &(matrix.getValueFast(0, (i % resultColumns)));
            }
        }
        else if ((myColumnJump != 0) && (matrix.myColumnJump == 0))
        {
            // Loop through every element (myRows * myColumns2) in the resulting
            // Matrix starting at (1, 1) moving left-to-right, top-to-bottom
            // until (N, M2)
            while (i++ < resultSize)
            {
                uint32_t columns = myColumns;

                // Loop
                while (columns--)
                {
                    (*resultPointer) += (*leftPointer++) * (*rightPointer);

                    rightPointer += resultColumns;
                }

                resultPointer++;

                //
                // Integer divide i / resultColumns gives the first element in
                // the current row of the left matrix
                //
                leftPointer = &(getValueFast((i / resultColumns), 0));
                leftPointer += (i / resultColumns) * myColumnJump;

                //
                // Integer modulo i % resultColumns gives the first element in
                // the current column of the right matrix
                //
                rightPointer = &(matrix.getValueFast(0, (i % resultColumns)));
            }
        }
        else if ((myColumnJump == 0) && (matrix.myColumnJump != 0))
        {
            // Loop through every element (myRows * myColumns2) in the resulting
            // Matrix starting at (1, 1) moving left-to-right, top-to-bottom
            // until (N, M2)
            while (i++ < resultSize)
            {
                uint32_t columns = myColumns;

                // Loop
                while (columns--)
                {
                    (*resultPointer) += (*leftPointer++) * (*rightPointer);

                    rightPointer += resultColumns + matrix.myColumnJump - 1;
                }

                resultPointer++;

                //
                // Integer divide i / resultColumns gives the first element in
                // the current row of the left matrix
                //
                leftPointer = &(getValueFast((i / resultColumns), 0));

                //
                // Integer modulo i % resultColumns gives the first element in
                // the current column of the right matrix
                //
                rightPointer = &(matrix.getValueFast(0, (i % resultColumns)));
            }
        }
        else
        {
            // Loop through every element (myRows * myColumns2) in the resulting
            // Matrix starting at (1, 1) moving left-to-right, top-to-bottom
            // until (N, M2)
            while (i++ < resultSize)
            {
                uint32_t columns = myColumns;

                // Loop
                while (columns--)
                {
                    (*resultPointer) += (*leftPointer++) * (*rightPointer);

                    rightPointer += resultColumns + matrix.myColumnJump -1;
                }

                resultPointer++;

                //
                // Integer divide i / resultColumns gives the first element in
                // the current row of the left matrix
                //
                leftPointer = &(getValueFast((i / resultColumns), 0));
                leftPointer += (i / resultColumns) * myColumnJump;

                //
                // Integer modulo i % resultColumns gives the first element in
                // the current column of the right matrix
                //
                rightPointer = &(matrix.getValueFast(0, (i % resultColumns)));
            }
        }
    }

    //--------------------------------------------------------------------------
    void operatorMultiplyNBy1(const MatrixBase<ValueType>& matrix,
                              MatrixBase<ValueType>& resultMatrix) const
    {
        const ValueType* leftPointer  = &(getValueFast(0, 0));
        const ValueType* rightPointer = &(matrix.getValueFast(0, 0));
        ValueType* resultPointer = &(resultMatrix.getValueFast(0, 0));

        uint32_t i = myColumns;

        if ((myColumnJump == 0) && (matrix.myColumnJump == 0))
        {
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
        else if ((myColumnJump != 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                int32_t rowSize = (int32_t) myColumns;

                // Loop
                while (rowSize--)
                {
                    (*resultPointer) += (*leftPointer) * (*rightPointer++);

                    incrementValuePointer(leftPointer, i);
                }

                resultPointer++;

                //
                // First element in the right matrix
                //
                rightPointer = &(matrix.getValueFast(0, 0));
            }
        }
        else if ((myColumnJump == 0) && (matrix.myColumnJump != 0))
        {
            while (i--)
            {
                int32_t rowSize = (int32_t) myColumns;

                // Loop
                while (rowSize--)
                {
                    (*resultPointer) += (*leftPointer++) * (*rightPointer);

                    matrix.incrementValuePointer(rightPointer, i);
                }

                resultPointer++;

                //
                // First element in the right matrix
                //
                rightPointer = &(matrix.getValueFast(0, 0));
            }
        }
        else
        {
            while (i--)
            {
                int32_t rowSize = (int32_t) myColumns;

                // Loop
                while (rowSize--)
                {
                    (*resultPointer) += (*leftPointer) * (*rightPointer);

                    matrix.incrementValuePointer(rightPointer, i);
                    incrementValuePointer(leftPointer, i);
                }

                resultPointer++;

                //
                // First element in the right matrix
                //
                rightPointer = &(matrix.getValueFast(0, 0));
            }
        }
    }

    // Addition operator (scalar)
    //--------------------------------------------------------------------------
    void operatorAddScalar(MatrixBase<ValueType>& matrix,
                           const ValueType scalar) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        uint32_t i = myRows * myColumns;

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
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        uint32_t i = myRows * myColumns;

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

    // Subtraction operator (scalar)
    //--------------------------------------------------------------------------
    void operatorSubtractScalar(MatrixBase<ValueType>& matrix,
                                const ValueType scalar) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        uint32_t i = myRows * myColumns;

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
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        uint32_t i = myRows * myColumns;

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

    // Multiplication operator (scalar)
    //--------------------------------------------------------------------------
    void operatorMultiplyScalar(MatrixBase<ValueType>& matrix,
                                const ValueType scalar) const
    {
        const ValueType* thisValuePointer = &(getValueFast(0, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        uint32_t i = myRows * myColumns;

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
        ValueType* thisValuePointer = &(getValueFast(0, 0));

        uint32_t i = myRows * myColumns;

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
    void setValuesPointerProtected(ValueType values[])
    {
        myValuesPointer = values;
    }

    //--------------------------------------------------------------------------
    void setValuesPointerProtected(const ValueType values[])
    {
        myValuesPointer = values;
    }

    //--------------------------------------------------------------------------
    void setValuesProtected(const ValueType values[])
    {
        ValueType* myValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = values;

        int32_t i = myRows * myColumns;

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
    void setValuesProtected(const MatrixBase<ValueType>& matrix)
    {
        ValueType* myValuePointer = &(getValueFast(0, 0));
        const ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        int32_t i = myRows * myColumns;

        if ((myColumnJump == 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                (*myValuePointer++) = (*valuePointer++);
            }
        }
        else if ((myColumnJump != 0) && (matrix.myColumnJump == 0))
        {
            while (i--)
            {
                (*myValuePointer) = (*valuePointer++);

                incrementValuePointer(myValuePointer, i);
            }
        }
        else if ((myColumnJump == 0) && (matrix.myColumnJump != 0))
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
    void getRow(MatrixBase<ValueType>& matrix, const uint32_t row)
    {
        const ValueType* myValuePointer = &(getValueFast(row, 0));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        uint32_t i = myColumns;

        while (i--)
        {
            (*valuePointer++) = (*myValuePointer++);
        }
    }

    //--------------------------------------------------------------------------
    void getColumn(MatrixBase<ValueType>& matrix, const uint32_t column)
    {
        const ValueType* myValuePointer = &(getValueFast(0, column));
        ValueType* valuePointer = &(matrix.getValueFast(0, 0));

        uint32_t i = myRows;

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
        const ValueType* thisValuePointer = &(getValueFast(0, 0));

        uint32_t i = 0;

        if (myColumnJump == 0)
        {
            while (i != (myRows * myColumns))
            {
                matrix.getValueFast((i % myColumns), (i / myColumns)) =
                                                          (*thisValuePointer++);

                i++;
            }
        }
        else
        {
            while (i != (myRows * myColumns))
            {
                matrix.getValueFast((i % myColumns), (i / myColumns)) =
                                                            (*thisValuePointer);

                incrementValuePointer(thisValuePointer, i);

                i++;
            }
        }
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    const uint32_t myRows;

    const uint32_t myColumns;

    ValueType* myValuesPointer;

    const uint32_t myColumnJump;

    //--------------------------------------------------------------------------
    // Private methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    void incrementValuePointer(ValueType*& valuePointer, const int i)
    {
        if ((i % myColumns) == 0)
        {
            valuePointer += myColumnJump;
        }
        else
        {
            valuePointer++;
        }
    }

    //--------------------------------------------------------------------------
    void incrementValuePointer(const ValueType*& valuePointer,
                               const int i) const
    {
        if ((i % myColumns) == 0)
        {
            valuePointer += myColumnJump;
        }
        else
        {
            valuePointer++;
        }
    }
};

}; // namespace Matrice

#endif // MATRICE_MATRIX_BASE_H
