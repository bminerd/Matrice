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
/// @file Matrice.h
/// @author Ben Minerd
/// @date 8/29/2016
/// @brief Matrice namespace functions.
///

#ifndef MATRICE_H
#define MATRICE_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <math.h>

#include <Matrice/MatrixBase.h>
#include <Matrice/Matrix.h>
#include <Matrice/Vector.h>
#include <Matrice/RotationMatrix.h>
#include <Matrice/Quaternion.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{
    //--------------------------------------------------------------------------
    // Functions
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <typename TValue>
    inline TValue square(const TValue value)
    {
        return (value * value);
    }

    //--------------------------------------------------------------------------
    template <typename TValue>
    inline Quaternion<TValue> eulerAnglesToQuaternion(const TValue roll,
                                                      const TValue pitch,
                                                      const TValue yaw)
    {
        Quaternion<TValue> quaternion;

        const TValue cosRoll  = cos(roll / 2.0);
        const TValue sinRoll  = sin(roll / 2.0);
        const TValue cosPitch = cos(pitch / 2.0);
        const TValue sinPitch = sin(pitch / 2.0);
        const TValue cosYaw   = cos(yaw / 2.0);
        const TValue sinYaw   = sin(yaw / 2.0);

        quaternion.w() = (cosRoll * cosPitch * cosYaw) +
                         (sinRoll * sinPitch * sinYaw);

        quaternion.x() = (sinRoll * cosPitch * cosYaw) -
                         (cosRoll * sinPitch * sinYaw);

        quaternion.y() = (cosRoll * sinPitch * cosYaw) +
                         (sinRoll * cosPitch * sinYaw);

        quaternion.z() = (cosRoll * cosPitch * sinYaw) -
                         (sinRoll * sinPitch * cosYaw);

        return quaternion;
    }

    //--------------------------------------------------------------------------
    template <typename TValue>
    inline void quaternionToEulerAngles(const Quaternion<TValue>& quaternion,
                                        TValue& roll,
                                        TValue& pitch,
                                        TValue& yaw)
    {
        TValue numerator;
        TValue denominator;

        numerator = 2.0 * ((quaternion.w() * quaternion.x()) +
                           (quaternion.y() * quaternion.z()));

        denominator = 1.0 - 2.0 * (square(quaternion.x()) +
                                   square(quaternion.y()));

        roll = atan2(numerator, denominator);

        pitch = asin(2.0 * ((quaternion.w() * quaternion.y()) -
                            (quaternion.z() * quaternion.x())));

        numerator = 2.0 * ((quaternion.w() * quaternion.z()) +
                           (quaternion.x() * quaternion.y()));

        denominator = 1.0 - 2.0 * (square(quaternion.y()) +
                                   square(quaternion.z()));

        yaw = atan2(numerator, denominator);
    }

    //--------------------------------------------------------------------------
    template <typename TValue>
    inline Quaternion<TValue> rotationMatrixToQuaternion(
                                   const RotationMatrix<TValue>& rotationMatrix)
    {
        Quaternion<TValue> quaternion;

        quaternion.w() = 0.5 * sqrt(rotationMatrix(0, 0) +
                                    rotationMatrix(1, 1) +
                                    rotationMatrix(2, 2) + 1.0);

        quaternion.x() = (rotationMatrix(1, 2) - rotationMatrix(2, 1)) /
                         (4.0 * quaternion.w());

        quaternion.y() = (rotationMatrix(2, 0) - rotationMatrix(0, 2)) /
                         (4.0 * quaternion.w());

        quaternion.z() = (rotationMatrix(0, 1) - rotationMatrix(1, 0)) /
                         (4.0 * quaternion.w());

        return quaternion;
    }

    //--------------------------------------------------------------------------
    template <typename TValue>
    inline RotationMatrix<TValue> quaternionToRotationMatrix(
                                           const Quaternion<TValue>& quaternion)
    {
        RotationMatrix<TValue> rotationMatrix;

        rotationMatrix(0, 0) = square(quaternion.w()) +
                               square(quaternion.x()) -
                               square(quaternion.y()) -
                               square(quaternion.z());

        rotationMatrix(0, 1) = 2.0 * (quaternion.x() * quaternion.y() +
                                      quaternion.w() * quaternion.z());

        rotationMatrix(0, 2) = 2.0 * (quaternion.x() * quaternion.z() -
                                      quaternion.w() * quaternion.y());

        rotationMatrix(1, 0) = 2.0 * (quaternion.x() * quaternion.y() -
                                      quaternion.w() * quaternion.z());

        rotationMatrix(1, 1) = square(quaternion.w()) -
                               square(quaternion.x()) +
                               square(quaternion.y()) -
                               square(quaternion.z());

        rotationMatrix(1, 2) = 2.0 * (quaternion.y() * quaternion.z() +
                                      quaternion.w() * quaternion.x());

        rotationMatrix(2, 0) = 2.0 * (quaternion.x() * quaternion.z() +
                                      quaternion.w() * quaternion.y());

        rotationMatrix(2, 1) = 2.0 * (quaternion.y() * quaternion.z() -
                                      quaternion.w() * quaternion.x());

        rotationMatrix(2, 2) = square(quaternion.w()) -
                               square(quaternion.x()) -
                               square(quaternion.y()) +
                               square(quaternion.z());

        return rotationMatrix;
    }
}; // namespace Matrice

#endif // MATRICE_H
