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

### v1.1.0

Released: 2023-11-17

* `[QUALITY]` Added newline to end of Matrice.cpp.
* `[FEATURE]` Changed deallocate() definitions to pass pointer as a reference for clearing to zero.
* `[FEATURE]` Change getRow() and getColumn() in MatrixInterface to return a submatrix instead of a deep copy of the row/colum.
* `[QUALITY]` Fixed all warnings after enabling -Wall for Matrice_Test_App. Disabled multi-line comment warning due to Plat4m header file header.
* `[FEATURE]` Added template specializations for run-time dimensions to Matrix and Vector classes.
* `[FEATURE]` Updated all MatrixBase operator methods to standardize matrix traversal.
* `[QUALITY]` Added documentation for writing Matrice-based APIs.
* `[FEATURE]` Updated all operator()() methods to go through MatrixBase::operator()() and added procompiler check for enabling calling getValue() for bounds checking. Default accessor for MatrixBase::operator()() is now getValueFast() which has no bounds checking. Added Vector::getValueFast() methods for consistency.
* `[BUG FIX]` Fixed size of row vector returned by MatrixInterface::getRow(). Wild pointer for M > N.
* `[BUG FIX]` Fixed bounds check on MatrixInterface submatrix constructor.
* `[QUALITY]` Removed ambiguous constructors from Matrix and Vector.
* `[FEATURE]` Added ValuePointerType template parameter to Matrix and Vector constructors and operator=() methods with MatrixInterface as the single parameter.
* `[QUALITY]` Improved toString() output readability.
* `[BUG FIX]` Fixed submatrix traversal bug in transpose() and simplified control flow.
* `[BUG FIX]` Fixed more missing std:: prefix for int/uint types required by some compilers.
* `[BUG FIX]` Fixed missing std:: prefix for int/uint types required by some compilers.

### v1.0.0

Released: 2021-03-08

* `[BUG FIX]` Fixed submatrix traversal bug in operatorMultiplyMBy1() and simplified logical flow.
* `[FEATURE]` Improved operatorMultiplyMByM2() speed of execution.
* `[FEATURE]` Added Matrix copy constructor for same storage.
* `[BUG FIX]` Fixed missing std:: prefix for standard library calls.
* `[BUG FIX]` Added null pointer check for Matrice::printCallback.
* `[FEATURE]` Added toString() and print() methods to MatrixBase.
* `[FEATURE]` Changed Matrix and Vector submatrix/subvector constructors to accept MatrixInterface as the parent matrix.
* `[FEATURE]` Added += and -= operators for Matrix and Vector types.
* `[BUG FIX]` Fixed result iteration size in MatrixBase::operatorMultiplyMBy1().
* `[FEATURE]` Added constructor to Vector for subvectors.
* `[BUG FIX]` Fixed submatrix column jump calculation to include parent matrix column jump.
* `[BUG FIX]` Fixed setValue() calculation for submatrices. Added setValue() to Vector.
* `[FEATURE]` Changed MatrixInterface::operator() to call MatrixBase::getValueFast().
* `[BUG FIX]` Fixed getValueFast() calculation for submatrices.
* `[FEATURE]` Added typecast operators for Matrix and Vector that allow conversion between different value types.
* `[BUG FIX]` Fixed bounds checking in MatrixBase::getValue().
* `[FEATURE]` Added constant memory mapping support to Matrix and Vector classes. Increased acceptance test coverage to include operations between Matrix and Vector objects with different memory mappings.
* `[FEATURE]` Exposed setValues() method for setting all Matrix values to single value to Matrix and Vector.
* `[FEATURE]` Renamed MatrixStorage to MatrixInterface and refactored to push storage template option and partial template specializations to subclasses. Matrix now provides template parameter for storage location and partial template specializations for some dimensions. Vector is now subclass of Matrix.
* `[FEATURE]` Added skew / cross product equivalent matrix methods to MatrixBase and MatrixStorage 3x1 specializations.
* `[QUALITY]` Added support for VSCode Remote Container building and debugging in plat4m_linux_dev Docker container.
* `[FEATURE]` Added cross and dot product methods to MatrixBase. Added Nx1 and 3x1 partial template specializations to MatrixStorage.
* `[FEATURE]` Added 1x1 partial template specializations to Matrix and MatrixStorage with a ValueType cast operator.
* `[FEATURE]` Added operator()() and getValue() methods to Vector.
* `[FEATURE]` Moved magnitude() and norm() methods to MatrixBase.
* `[FEATURE]` Added magnitude() and norm() methods to Vector.
* `[FEATURE]` Added transpose() / T() methods to MatrixStorage and MatrixBase.
* `[FEATURE]` Added getRow() / row() and getColumn() / col() methods to MatrixStorage and MatrixBase.
* `[FEATURE]` Added setValues() methods and assignment operators to Matrix and Vector for array types. Refactored portions of MatrixBase and MatrixStorage for readability and consistency.
* `[BUG FIX]` Fixed missing assignment operators in Vector class for conversion between storage types.
* `[FEATURE]` Added in-place submatrix functionality to Matrix and Vector classes through modifications to MatrixBase and MatrixStorage.
* `[FEATURE]` Added external memory mapping support to Vector class.
* `[BUG FIX]` Fixed initialization of Matrix::columns for NxM template.
* `[FEATURE]` Added MatrixStorage class between MatrixBase and outer API classes (Matrix, Vector, etc.) to reduce template flash usage and allow for external storage. Added Matrice_Test_App with acceptance tests for mathematical operator overloads.
