# Writing Matrice-Based APIs

## Background

Matrice is designed to give the user maximum flexibility as to where the memory for a given Matrix is stored -- in memory internal to the Matrix, in memory external to the Matrix, or in constant memory external to the Matrix. These different options are selected with the `Matrice::Storage` enumerated type which can be either `STORAGE_INTERNAL` (which is the default), `STORAGE_EXTERNAL`, or `STORAGE_CONSTANT`.

When writing an API based on Matrice, there are a few things to consider if you want your functions to be maximally flexbile with the least number of template parameters required. Not only does using fewer template parameters reduce code clutter, it also reduces the compiled code size by limiting the number of different functions that ultimately get created by the compiler.

Matrice has four main classes: `MatrixBase`, `MatrixInterface`, `Matrix`, and `Vector`. Vector inherits from Matrix, Matrix inherits from MatrixInterface, and MatrixInterface inherits from MatrixBase. In general, MatrixInterface is the best place to write APIs against as it has the least number of template parameters, but also still has static matrix bounds (unlike MatrixBase) which enforces matrix dimensions at compile time.

**The main thing to consider when writing a function or method based on Matrice types is whether the parameter is const or not. If it is constant, the ValuePointerType template parameter should be used.**

Function parameters should be const if they shouldn't be modified during the scope of the function. Following this practice in Matrice allows you to pass in a Matrix with the `STORAGE_CONSTANT` flag when applicable.

## Non-Const Function Parameter

A function parameter that is _**non-const**_ should be declared like:

``` c++
template <typename ValueType, uint32_t N, uint32_t M>
void function(MatrixInterface<ValueType, N, M>& matrix)
{
    ...
}
```

When calling this function, you can pass either a Matrix with `STORAGE_INTERNAL` or `STORAGE_EXTERNAL`, but _**not**_ `STORAGE_CONSTANT`:

``` c++
Matrix<float, 3, 2> matrix1; // Same as Matrix<float, 3, 2, STORAGE_INTERNAL>

float matrix2Values[4][4] =
{
    {...},
};
Matrix<float, 3, 2, STORAGE_EXTERNAL> matrix2(matrix2Values);

const float matrix3Values[4][4] =
{
    {...},
};
const Matrix<float, 3, 2, STORAGE_CONSTANT> matrix3(matrix3Values);

function(matrix1); // Compiles

function(matrix2); // Compiles

function(matrix3); // Compiler error
```

## Const Function Parameter

A function parameter that is _**const**_ should be declared like:

``` c++
template <typename ValueType, uint32_t N, uint32_t M, typename ValuePointerType>
void function(const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix)
{
    ...
}
```

When calling this function, you can pass a Matrix with `STORAGE_INTERNAL`, `STORAGE_EXTERNAL`, or `STORAGE_CONSTANT`:

``` c++
Matrix<float, 3, 2> matrix1; // Same as Matrix<float, 3, 2, STORAGE_INTERNAL>

float matrix2Values[4][4] =
{
    {...},
};
Matrix<float, 3, 2, STORAGE_EXTERNAL> matrix2(matrix2Values);

const float matrix3Values[4][4] =
{
    {...},
};
const Matrix<float, 3, 2, STORAGE_CONSTANT> matrix3(matrix3Values);

function(matrix1); // Compiles

function(matrix2); // Compiles

function(matrix3); // Compiles
```

If there are multiple **const** parameters, each one should have its own ValuePointerType template parameter:

``` c++
template <typename ValueType,
          uint32_t N,
          uint32_t M,
          typename ValuePointerType1,
          typename ValuePointerType2,
          typename ValuePointerType3>
void function(
             const MatrixInterface<ValueType, N, M, ValuePointerType1>& matrix1,
             const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix2,
             const MatrixInterface<ValueType, N, M, ValuePointerType2>& matrix3)
{
    ...
}
```

## Function Return Values

Matrice types returned from a function should also be of type MatrixInterface. The same rules listed above for _**const**_ and _**non-const**_ also apply:

``` c++
template <typename ValueType, uint32_t N, uint32_t M, typename ValuePointerType>
MatrixInterface<ValueType, N, M> function(
              const MatrixInterface<ValueType, N, M, ValuePointerType>& matrix1)
{
    Matrix<ValueType, N, M> resultMatrix;

    ...

    return resultMatrix;
}
```

**Note:** There are very few cases where you would need to return a Matrix that could be either const _**or**_ non-const. If, for example, you had a class with an acessor method that returned a reference to a const Matrix with the `STORAGE_CONSTANT` template parameter set, you could simply set the return value as the exact type:

``` c++
class MyClass
{
    const Matrix<float, 3, 2, STORAGE_CONSTANT> myMatrix;

    const Matrix<float, 3, 2, STORAGE_CONSTANT>& getMatrix() const
    {
        return myMatrix;
    }
}
```
