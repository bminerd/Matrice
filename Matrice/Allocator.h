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
/// @file Allocator.h
/// @author Ben Minerd
/// @date 4/5/2022
/// @brief Allocator class header file.
///

#ifndef MATRICE_ALLOCATOR_H
#define MATRICE_ALLOCATOR_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>
#include <cstddef>
#include <new>

#include <Matrice/Matrice.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

class Allocator
{
public:

    //--------------------------------------------------------------------------
    // Public static methods
    //--------------------------------------------------------------------------
    
    static void* allocate(const std::size_t count);

    //--------------------------------------------------------------------------
    template <typename T, typename ... Arguments>
    static T* allocate(Arguments&... arguments)
    {
        void* memoryPointer = allocate(sizeof(T));

        T* item = new(memoryPointer) T(arguments...);

        return item;
    }

    //--------------------------------------------------------------------------
    template <typename T>
    static T* allocateArray(const std::size_t count)
    {
        void* memoryPointer = allocate(sizeof(T) * count);

        T* array = (T*) memoryPointer;

        return array;
    }

    static void deallocate(void*& pointer, const std::size_t count);

    //--------------------------------------------------------------------------
    template <typename T>
    static void deallocate(T*& pointer)
    {
        deallocate(pointer, sizeof(T));
    }

    //--------------------------------------------------------------------------
    template <typename T>
    static void deallocateArray(T*& pointer, const std::size_t count)
    {
        deallocate((void*&)pointer, sizeof(T) * count);
    }

    static std::size_t getFreeMemorySize();

protected:

    //--------------------------------------------------------------------------
    // Protected constructors
    //--------------------------------------------------------------------------

    Allocator();

    //--------------------------------------------------------------------------
    // Protected virtual destructors
    //--------------------------------------------------------------------------

    virtual ~Allocator();

private:

    //--------------------------------------------------------------------------
    // Private static data members
    //--------------------------------------------------------------------------

    static Allocator* myDriver;

    //--------------------------------------------------------------------------
    // Private pure virtual methods
    //--------------------------------------------------------------------------

    virtual void* driverAllocate(const std::size_t count) = 0;

    virtual void driverDeallocate(void*& pointer, const std::size_t count) = 0;

    virtual std::size_t driverGetFreeMemorySize() = 0;
};

}; // namespace Matrice

#endif // MATRICE_ALLOCATOR_H
