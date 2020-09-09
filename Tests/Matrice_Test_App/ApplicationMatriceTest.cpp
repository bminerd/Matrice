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
/// @file ApplicationMatriceTest.cpp
/// @author Ben Minerd
/// @date 4/14/2020
/// @brief ApplicationMatriceTest class source file.
///

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <ApplicationMatriceTest.h>

using Matrice::ApplicationMatriceTest;

//------------------------------------------------------------------------------
// Private static data members
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public constructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
ApplicationMatriceTest::ApplicationMatriceTest() :
    Plat4m::ApplicationUnitTestApp("MATRICE_TEST_APP",
                                   "MATRICE_TEST",
                                   "1.0.0"),
    mySystem(),
    myProcessor(),
    myMatrixTest()
{
}

//------------------------------------------------------------------------------
// Public virtual destructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
ApplicationMatriceTest::~ApplicationMatriceTest()
{
}

//------------------------------------------------------------------------------
// Private methods implemented from Application
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void ApplicationMatriceTest::driverRun()
{
    initializeSystem();

    runParentApplication();
}

//------------------------------------------------------------------------------
// Private methods
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void ApplicationMatriceTest::initializeSystem()
{
    addUnitTest(myMatrixTest);
}
