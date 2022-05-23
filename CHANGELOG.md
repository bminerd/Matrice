# Matrice Change Log

All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).

## Change Log Categories

* `[BUG FIX]` Bugs or regressions have been resolved.
* `[FEATURE]` Functionality has been added or improved.
* `[REMOVED]` Functionality has been removed.
* `[QUALITY]` Nonfunctional quality changes to infrastructure, code appearance, etc.

Change Log entries must follow the format:

* `[LABEL]` Description of changes. [Resolves #issue].

### Unreleased Changes

These issues have been fully implemented and merged into develop.

* `[QUALITY]` Added newline to end of Matrice.cpp. [Resolves #70].
* `[FEATURE]` Changed deallocate() definitions to pass pointer as a reference for clearing to zero. [Resolves #68].
* `[FEATURE]` Change getRow() and getColumn() in MatrixInterface to return a submatrix instead of a deep copy of the row/colum. [Resolves #42].
* `[QUALITY]` Fixed all warnings after enabling -Wall for Matrice_Test_App.
Disabled multi-line comment warning due to Plat4m header file header [Resolves #67].
* `[FEATURE]` Added template specializations for run-time dimensions to Matrix and Vector classes. [Resolves #63].
* `[FEATURE]` Updated all MatrixBase operator methods to standardize matrix traversal. [Resolves #61].
* `[QUALITY]` Added documentation for writing Matrice-based APIs. [Resolves #62].
* `[FEATURE]` Updated all operator()() methods to go through MatrixBase::operator()() and added procompiler check for enabling calling getValue() for bounds checking. Default accessor for MatrixBase::operator()() is now getValueFast() which has no bounds checking. Added Vector::getValueFast() methods for consistency. [Resolves #60].
* `[BUG FIX]` Fixed size of row vector returned by MatrixInterface::getRow(). Wild pointer for M > N. [Resolves #59].
* `[BUG FIX]` Fixed bounds check on MatrixInterface submatrix constructor. [Resolves #58].
* `[QUALITY]` Removed ambiguous constructors from Matrix and Vector. [Resolves #56].
* `[FEATURE]` Added ValuePointerType template parameter to Matrix and Vector constructors and operator=() methods with MatrixInterface as the single parameter. [Resolves #48].
* `[QUALITY]` Improved toString() output readability. [Resolves #40].
* `[BUG FIX]` Fixed submatrix traversal bug in transpose() and simplified control flow. [Resolves #47].
* `[BUG FIX]` Fixed more missing std:: prefix for int/uint types required by some compilers. [Resolves #46].
* `[BUG FIX]` Fixed missing std:: prefix for int/uint types required by some compilers. [Resolves #45].

### v1.0.0

Released: 2021-03-08

* `[BUG FIX]` Fixed submatrix traversal bug in operatorMultiplyMBy1() and simplified logical flow. [Resolves #43].
* `[FEATURE]` Improved operatorMultiplyMByM2() speed of execution. [Resolves #35].
* `[FEATURE]` Added Matrix copy constructor for same storage. [Resolves #41].
* `[BUG FIX]` Fixed missing std:: prefix for standard library calls. [Resolves #39].
* `[BUG FIX]` Added null pointer check for Matrice::printCallback. [Resolves #38].
* `[FEATURE]` Added toString() and print() methods to MatrixBase. [Resolves #23].
* `[FEATURE]` Changed Matrix and Vector submatrix/subvector constructors to accept MatrixInterface as the parent matrix. [Resolves #36].
* `[FEATURE]` Added += and -= operators for Matrix and Vector types. [Resolves #25].
* `[BUG FIX]` Fixed result iteration size in MatrixBase::operatorMultiplyMBy1(). [Resolves #33].
* `[FEATURE]` Added constructor to Vector for subvectors. [Resolves #26].
* `[BUG FIX]` Fixed submatrix column jump calculation to include parent matrix column jump. [Resolves #27].
* `[BUG FIX]` Fixed setValue() calculation for submatrices. Added setValue() to Vector. [Resolves #28].
* `[FEATURE]` Changed MatrixInterface::operator() to call MatrixBase::getValueFast(). [Resolves #29].
* `[BUG FIX]` Fixed getValueFast() calculation for submatrices. [Resolves #24].
* `[FEATURE]` Added typecast operators for Matrix and Vector that allow conversion between different value types. [Resolves #20].
* `[BUG FIX]` Fixed bounds checking in MatrixBase::getValue(). [Resolves #19].
* `[FEATURE]` Added constant memory mapping support to Matrix and Vector classes. Increased acceptance test coverage to include operations between Matrix and Vector objects with different memory mappings. [Resolves #17].
* `[FEATURE]` Exposed setValues() method for setting all Matrix values to single value to Matrix and Vector. [Resolves #18].
* `[FEATURE]` Renamed MatrixStorage to MatrixInterface and refactored to push storage template option and partial template specializations to subclasses. Matrix now provides template parameter for storage location and partial template specializations for some dimensions. Vector is now subclass of Matrix. [Resolves #10].
* `[FEATURE]` Added skew / cross product equivalent matrix methods to MatrixBase and MatrixStorage 3x1 specializations. [Resolves #16].
* `[QUALITY]` Added support for VSCode Remote Container building and debugging in plat4m_linux_dev Docker container. [Resolves #15].
* `[FEATURE]` Added cross and dot product methods to MatrixBase. Added Nx1 and 3x1 partial template specializations to MatrixStorage. [Resolves #14].
* `[FEATURE]` Added 1x1 partial template specializations to Matrix and MatrixStorage with a ValueType cast operator. [Resolves #13].
* `[FEATURE]` Added operator()() and getValue() methods to Vector. [Resolves #12].
* `[FEATURE]` Moved magnitude() and norm() methods to MatrixBase. [Resolves #11].
* `[FEATURE]` Added magnitude() and norm() methods to Vector. [Resolves #9].
* `[FEATURE]` Added transpose() / T() methods to MatrixStorage and MatrixBase. [Resolves #8].
* `[FEATURE]` Added getRow() / row() and getColumn() / col() methods to MatrixStorage and MatrixBase. [Resolves #7].
* `[FEATURE]` Added setValues() methods and assignment operators to Matrix and Vector for array types. Refactored portions of MatrixBase and MatrixStorage for readability and consistency. [Resolves #6].
* `[BUG FIX]` Fixed missing assignment operators in Vector class for conversion between storage types. [Resolves #5].
* `[FEATURE]` Added in-place submatrix functionality to Matrix and Vector classes through modifications to MatrixBase and MatrixStorage. [Resolves #3].
* `[FEATURE]` Added external memory mapping support to Vector class. [Resolves #4].
* `[BUG FIX]` Fixed initialization of Matrix::columns for NxM template. [Resolves #2].
* `[FEATURE]` Added MatrixStorage class between MatrixBase and outer API classes (Matrix, Vector, etc.) to reduce template flash usage and allow for external storage. Added Matrice_Test_App with acceptance tests for mathematical operator overloads. [Resolves #1].
