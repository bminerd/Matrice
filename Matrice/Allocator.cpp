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
/// @file AllocationMemory.cpp
/// @author Ben Minerd
/// @date 4/8/2014
/// @brief AllocationMemory class source file.
///

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <Matrice/Allocator.h>

using namespace Matrice;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

Allocator* Allocator::myDriver = 0;

//------------------------------------------------------------------------------
// Public static methods
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void* Allocator::allocate(const std::size_t count)
{
    return (myDriver->driverAllocate(count));
}

//------------------------------------------------------------------------------
void Allocator::deallocate(void* pointer, const std::size_t count)
{
    myDriver->driverDeallocate(pointer, count);
}

//------------------------------------------------------------------------------
size_t Allocator::getFreeMemorySize()
{
    return (myDriver->driverGetFreeMemorySize());
}

//------------------------------------------------------------------------------
// Protected constructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
Allocator::Allocator()
{
    if (myDriver == 0)
    {
        myDriver = this;
    }
}

//------------------------------------------------------------------------------
// Protected virtual destructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
Allocator::~Allocator()
{
    if (myDriver != 0)
    {
        myDriver = 0;
    }
}
