// BNSMatrix.h
//
// Author: Justin Marple with Team BNS
// Contact: jmarple@umass.edu
// Date: 12/11/2014
//
// This header file includes source code that
// can be used to program applications that
// require complex matrix operations.
//
// Source Code:
//   BNSMatrix.c
//   BNSMatrixArithmetic.c
//
// Dependencies:
//   Core\BNSHeap.c
//   Core\BNSHeap.h
//
// Basic Usage:
//   Matrix mat1;
//   CreateNewMatrix(mat1, 3, 3);
//   SetMatrixAt(mat1, 0, 0, 3.14);
//   float det = FindMatrixDeterminant(mat1);
//   etc.
//
// ------------------------------------------------------------------------
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// The author can be contacted by email at jmarple@umass.edu
//
// ------------------------------------------------------------------------

#ifndef __BNS_MATRIX_H
#define __BNS_MATRIX_H

#ifndef __BNS_HEAP_H
#include "../Core/BNSHeap.h"
#endif

struct Matrix
{
	// Number of rows
	int m;

	// Number of columns
	int n;

	// Number f
	bool inUse;

	// Location in our "Matrix Builder" buffer
	int bufferLocation;
};

// CreateNewMatrix(...)
// Creates a unique matrix defaulted with zeros
// m is the height (# of rows), n is the width (# of cols)
//  aka. we are creating an mxn matrix
void CreateZerosMatrix(struct Matrix *mat, int m, int n);

// CreateIdentityMatrix(...)
// Creates a unique nxn identity matrix, where the
//   major digonals will be filled with zeros
void CreateIdentityMatrix(struct Matrix *mat, int n);

// CreateMatrix(...)
// Initalizes a matrix given an character input
// Returns true if
bool CreateMatrix(struct Matrix *mat, char* s);

// SetMatrixAt(...)
// Sets a specific location in a matrix
// m is the row, n is the column
void SetMatrixAt(struct Matrix *mat, int m, int n, float value);

// GetMatrixAt(...)
// Returns the value at a certain point in the matrix
// m is the row, n is the column
float GetMatrixAt(struct Matrix *mat, int m, int n);

// MatrixMultiplication(...)
// Multiply A*B and returns to dst.
bool MatrixMult(struct Matrix *dst, struct Matrix A, struct Matrix B);

// MatrixInv(...)
// Finds A^-1 and returns it to dst
bool MatrixInv(struct Matrix *dst, struct Matrix A);

// MatrixAdd(...)
// Adds A + B and returns the result to dst
bool MatrixAdd(struct Matrix *dst, struct Matrix A, struct Matrix B);

// MatrixSub(...)
// Subtracts A - B and returns the result to dst
bool MatrixSub(struct Matrix *dst, struct Matrix A, struct Matrix B);

// MatrixTranspose(...)
// Returns the transpose of A to dst
void MatrixTranspose(struct Matrix *dst, struct Matrix A);

// MatrixDeterminant(...)
// Returns the determinant of a given nxn matrix
float MatrixDeterminant(struct Matrix *A);

// MatrixTrace(...)
// Returns the trace of Matrix A
float MatrixTrace(struct Matrix *A);

// MultiplyScalarToMatrix(...)
// Multiplies each element in a matrix by a given scalar
void MultiplyScalarToMatrix(struct Matrix *mat, float scalar);

// DivideScalarToMatrix(...)
// Divides each element in a matrix by a given scalar
void DivideScalarToMatrix(struct Matrix *mat, float scalar);

#endif
