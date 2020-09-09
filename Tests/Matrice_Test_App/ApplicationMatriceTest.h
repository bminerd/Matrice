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
/// @file ApplicationMatriceTest.h
/// @author Ben Minerd
/// @date 5/1/2020
/// @brief ApplicationMatriceTest class header file.
///

#ifndef MATRICE_APPLICATION_MATRICE_TEST_H
#define MATRICE_APPLICATION_MATRICE_TEST_H

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <Plat4m_Core/UnitTest/ApplicationUnitTestApp.h>
#include <Plat4m_Core/Linux/SystemLinux.h>
#include <Plat4m_Core/Linux/ProcessorLinux.h>

#include <Tests/MatrixTest.h>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Matrice
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

class ApplicationMatriceTest : public Plat4m::ApplicationUnitTestApp
{
public:

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    ApplicationMatriceTest();

    //--------------------------------------------------------------------------
    // Public virtual destructors
    //--------------------------------------------------------------------------

    virtual ~ApplicationMatriceTest();

private:
    

    //--------------------------------------------------------------------------
    // Private data members
    //--------------------------------------------------------------------------

    Plat4m::SystemLinux mySystem;

    Plat4m::ProcessorLinux myProcessor;

    MatrixTest myMatrixTest;

    //--------------------------------------------------------------------------
    // Private methods implemented from Application
    //--------------------------------------------------------------------------

    void driverRun();

    //--------------------------------------------------------------------------
    // Private methods
    //--------------------------------------------------------------------------

    void initializeProcessor();

    void initializeSystem();
};

}; // namespace Matrice

#endif // MATRICE_APPLICATION_MATRICE_TEST_H

