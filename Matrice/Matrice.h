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

#include <cstdint>

//------------------------------------------------------------------------------
// Definitions
//------------------------------------------------------------------------------

#define MATRICE_VERSION "1.1.0"

//------------------------------------------------------------------------------
// Macros
//------------------------------------------------------------------------------

#define MATRICE_REPORT_ERROR(error) \
    Matrice::reportError(error, __FILE__, __func__, __LINE__)

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{
    //--------------------------------------------------------------------------
    // Types
    //--------------------------------------------------------------------------

    enum Storage
    {
        STORAGE_INTERNAL = 0,
        STORAGE_EXTERNAL,
        STORAGE_CONSTANT
    };

    enum Error
    {
        ERROR_NONE = 0,
        ERROR_DIMENSIONS_INVALID,
        ERROR_SUBMATRIX_BOUNDS_INVALID,
        ERROR_ALLOCATOR_NOT_ENOUGH_MEMORY,
        ERROR_ALLOCATOR_FRAGMENTED_DEALLOCATION
    };

    enum Dimensions
    {
        DIMENSIONS_RUN_TIME = 0
    };

    typedef void (*PrintCallback)(const char*);

    typedef void (*ErrorCallback)(const Error,
                                  const char*,
                                  const char*,
                                  const char*,
                                  const std::uint32_t);

    typedef void (*EnterCriticalSectionCallback)();

    typedef void (*ExitCriticalSectionCallback)();

    //--------------------------------------------------------------------------
    // Functions
    //--------------------------------------------------------------------------

    void setPrintCallback(PrintCallback callback);

    void print(const char* string);

    void setErrorCallback(ErrorCallback callback);

    void reportError(const Error error,
                     const char* filename,
                     const char* functionName,
                     const std::uint32_t lineNumber);

    void setEnterAndExitCriticalSectionCallbacks(
                                     EnterCriticalSectionCallback enterCallback,
                                     ExitCriticalSectionCallback exitCallback);

    void enterCriticalSection();

    void exitCriticalSection();

    //--------------------------------------------------------------------------
    template <typename TValue>
    inline TValue square(const TValue value)
    {
        return (value * value);
    }
}; // namespace Matrice

#endif // MATRICE_H
