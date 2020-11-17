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

* `[LABEL]` Description of changes. [Resolves #issue].

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
