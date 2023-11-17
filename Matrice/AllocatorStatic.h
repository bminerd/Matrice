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
/// @file AllocatorStatic.h
/// @author Ben Minerd
/// @date 4/5/2022
/// @brief AllocatorStatic class header file.
///

#ifndef MATRICE_ALLOCATOR_STATIC_H
#define MATRICE_ALLOCATOR_STATIC_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>

#include <Matrice/Matrice.h>
#include <Matrice/Allocator.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

template <std::uint32_t AllocationByteCount>
class AllocatorStatic : public Allocator
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    AllocatorStatic() :
        Allocator(),
        myMemory(),
        myMemoryIndex(0)
    {
    }

    //--------------------------------------------------------------------------
    // Public destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    ~AllocatorStatic()
    {
    }

private:

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    std::uint8_t myMemory[AllocationByteCount];

    std::uint32_t myMemoryIndex;

    //--------------------------------------------------------------------------
    // Private virtual methods overridden for Allocator
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    virtual void* driverAllocate(const std::size_t count)
    {
        void* memory = 0;
    
        if ((myMemoryIndex + count) > AllocationByteCount)
        {
            MATRICE_REPORT_ERROR(ERROR_ALLOCATOR_NOT_ENOUGH_MEMORY);
        }
        
        memory = &(myMemory[myMemoryIndex]);
        myMemoryIndex += count;
        
        return memory;
    }

    //--------------------------------------------------------------------------
    virtual void driverDeallocate(void*& pointer, const std::size_t count)
    {
        if ((&(myMemory[myMemoryIndex]) - count) != pointer)
        {
            MATRICE_REPORT_ERROR(ERROR_ALLOCATOR_FRAGMENTED_DEALLOCATION);
        }

        myMemoryIndex -= count;

        pointer = 0;
    }

    //--------------------------------------------------------------------------
    virtual std::size_t driverGetFreeMemorySize()
    {
        return (sizeof(myMemory) - myMemoryIndex);
    }
};

}; // namespace Matrice

#endif // MATRICE_ALLOCATOR_STATIC_H
