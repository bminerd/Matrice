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
/// @file Matrice.cpp
/// @author Ben Minerd
/// @date 1/25/2021
/// @brief Matrice namespace source file.
///

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <Matrice/Matrice.h>

using namespace Matrice;

//------------------------------------------------------------------------------
// Local variables
//------------------------------------------------------------------------------

PrintCallback printCallback = 0;

ErrorCallback errorCallback = 0;

EnterCriticalSectionCallback enterCriticalSectionCallback = 0;

ExitCriticalSectionCallback exitCriticalSectionCallback = 0;

const char* errorNames[4] =
{
    "ERROR_NONE",
    "ERROR_DIMENSIONS_INVALID",
    "ERROR_SUBMATRIX_BOUNDS_INVALID",
    "ERROR_ALLOCATOR_NOT_ENOUGH_MEMOR"
};

//------------------------------------------------------------------------------
// Namespace functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Matrice::setPrintCallback(PrintCallback callback)
{
    printCallback = callback;
}

//------------------------------------------------------------------------------
void Matrice::print(const char* string)
{
    if (printCallback != 0)
    {
        (*printCallback)(string);
    }
}

//------------------------------------------------------------------------------
void Matrice::setErrorCallback(ErrorCallback callback)
{
    errorCallback = callback;
}

//------------------------------------------------------------------------------
void Matrice::reportError(const Error error,
                          const char* filename,
                          const char* functionName,
                          const std::uint32_t lineNumber)
{
    if (errorCallback != 0)
    {
        (*errorCallback)(error,
                         errorNames[error],
                         filename,
                         functionName,
                         lineNumber);
    }
}

//------------------------------------------------------------------------------
void setEnterAndExitCriticalSectionCallbacks(
                                     EnterCriticalSectionCallback enterCallback,
                                     ExitCriticalSectionCallback exitCallback)
{
    enterCriticalSectionCallback = enterCallback;
    exitCriticalSectionCallback = exitCallback;
}

//------------------------------------------------------------------------------
void Matrice::enterCriticalSection()
{
    if (enterCriticalSectionCallback != 0)
    {
        (*enterCriticalSectionCallback)();
    }
}

//------------------------------------------------------------------------------
void Matrice::exitCriticalSection()
{
    if (exitCriticalSectionCallback != 0)
    {
        (*exitCriticalSectionCallback)();
    }
}
