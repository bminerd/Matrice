# Plat4m_Math

## Project Overview

Plat4m_Math is a lightweight linear algebra library for matrix operations written with C++ templates. The API is meant to be clean and expressive, similar to existing C++ matrix libraries like Eigen, however, it's been optimized for embedded systems to minimize resource usage. Compared to Eigen, it runs slightly slower but uses much less ROM because the operations are not linearized like Eigen.

## Features

- Clean, expressive API in C++ that uses templates and operator overloading to simplify operations
- Template-based proportional RAM usage without using dynamically-allocated memory
- Optimized matrix traversing logic that is ~10x faster than traditional nested for-loops (based on real-world testing)

## Supported Matrix Types and Operations

- N-by-M Matrix
  - Addition (scalar and matrix)
  - Subtraction (scalar and matrix)
  - Multiplication (scalar and matrix)
  - Transpose
- N-by-1 Vector
  - Addition and subtraction provided by N-by-M Matrix (scalar and vector)
  - Multiplication (optimized vector)
- RotationMatrix
  - Conversion to quaternion
- Quaternion
  - Conversion to rotation matrix
- In progress
  - Homogeneous transformation matrix
  - Square matrix and specialized operations (ex. determiniant)