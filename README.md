# Plat4m_Math

## Project Overview

Plat4m_Math is a lightweight linear algebra library for matrix operations written with C++ template classes. The API is meant to be clean and expressive, similar to existing C++ matrix libraries like Eigen, however, it's been optimized for embedded systems to minimize resource usage. Compared to Eigen, Plat4m_Math operations run slightly slower but use much less ROM because the operations are not linearized like Eigen.

This project was designed to be fully interoperable with the Plat4m project (hence the Plat4m_ prefix), but it doesn't have any dependencies on Plat4m. Plat4m_Math is completely standalone. Consequently, the name Plat4m_Math may be changed in the future to reflect this.

## Features

- Clean, expressive API in C++ that uses templates and operator overloading to simplify mathematical operations
- Template-based proportional RAM usage without using dynamically-allocated memory
- Optimized matrix traversing logic that is ~10x faster than traditional nested for-loops (based on real-world testing)
- Only external dependency is stdint.h/cstdint

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
- Quaternion
- In progress
  - TransformationMatrix - Homogeneous transformation matrix
  - SquareMatrix - Specialized operations for square matrices (ex. determiniant)
  - Conversions between rotation matrices, quaternions, and Euler angles