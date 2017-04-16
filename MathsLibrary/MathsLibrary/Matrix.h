#pragma once
#include "Vector.h"

namespace lasmath {
	class Matrix
	{
	public:
		Matrix();
		~Matrix();
	protected:
		template<size_t ROWS>
		// Compares float arrays and returns true if all members are equal
		static bool areColumnsEqual(float* first, float* second) {
			//TODO add tolerance if necessary
			for (size_t i = 0; i < ROWS; ++i) {
				if (first[i] != second[i]) {
					return false;
				}
			}
			return true;
		}

		template<size_t ROWS, size_t COLUMNS>
		// Swaps rows in matrix
		static void swapRows(float** theMatrix, size_t first, size_t second) {
			//TODO argument exception if first or second > ROWS
			// Swap values of first and second row for every column
			for (size_t i = 0; i < COLUMNS; ++i) {
				float temp = theMatrix[i][first];
				theMatrix[i][first] = theMatrix[i][second];
				theMatrix[i][second] = temp;
			}
		}

		template<size_t ROWS, size_t COLUMNS>
		// Multiplies all elements in row by factor
		static void multiplyRow(float** theMatrix, size_t row, float factor) {
			//TODO argument exception if row > ROWS
			for (size_t i = 0; i < COLUMNS; ++i) {
				theMatrix[i][row] *= factor;
			}
		}

		// Adds source row multiplied by factor to target row
		template<size_t ROWS, size_t COLUMNS>
		static void addRow(float** theMatrix, size_t sourceRow, size_t targetRow, float factor) {
			//TODO argument exception if sourceRow or targetRow > ROWS
			for (size_t i = 0; i < COLUMNS; ++i) {
				theMatrix[i][targetRow] += factor * theMatrix[i][sourceRow];
			}
		}

		template<size_t ORDER, size_t RESULT_COLUMNS>
		/*	Performs inverse of transform on result to either undo a transformation or get inverse matrix
			Returns true if inversion is possible, or false if transform is singular or too poorly conditioned
			transform = ORDERxORDER column major transformation matrix, will be converted to reduced echelon form
			result = ORDERxRESULT_COLUMNS column major matrix, will be transformed by inverse of transform
		*/
		static bool invertTransform(float* transform, float* result) {
			// HACK this relies on a bunch of pointer arithmetic, since matrices aren't templated (yet?)
			Vector<ORDER> emptyColumn;
			bool matrixInvertable = true;
			// Create 2d arrays holding pointers to matrix elements, so [] operator rather than pointer arithmetic can be used
			float* transformArray[ORDER];
			float* resultArray[RESULT_COLUMNS];
			for (size_t col = 0; col < ORDER; ++col) {
				transformArray[col] = transform + (ORDER * col);
			}
			for (size_t col = 0; col < RESULT_COLUMNS; ++col) {
				resultArray[col] = result + (ORDER*col);
			}

			// Use row operations to make rowReduced into identity matrix
			for (size_t i = 0; i < ORDER && matrixInvertable; ++i) {
				float reducedColumn[ORDER] = { 0.0f };					// How current column will appear in reduced echelon form
				reducedColumn[i] = 1.0f;
				// Perform row operations until current column is in reduced echelon form
				if (!areColumnsEqual<ORDER>(transformArray[i], reducedColumn)) {
					if (areColumnsEqual<ORDER>(transformArray[i], (float*)emptyColumn)) {		// If column has no values, matrix must be singular
						matrixInvertable = false;
						break;
					}
					else if (transformArray[i][i] == 0.0f) {		// If pivot position is 0, swap with lower row
						bool rowFound = false;				// flag variable to check if row to swap with has been found
						for (size_t row = i + 1; row < ORDER; ++row) {
							if (transformArray[i][row] != 0.0f) {			// If row has value in relevant column
								swapRows<ORDER, ORDER>(transformArray, i, row);			// Swap row with pivot row
								swapRows<ORDER, RESULT_COLUMNS>(resultArray, i, row);	// Perform same operation on result matrix
								rowFound = true;
								break;
							}
						}
						if (!rowFound) {
							//If pivot position cannot be given a non-zero value without breaking echelon form
							//matrix cannot be inverted
							matrixInvertable = false;
							break;
						}
					}
					if (transformArray[i][i] != 1.0f) {									// If pivot position isn't 1
						float quotient = 1.0f / transformArray[i][i];
						multiplyRow<ORDER, ORDER>(transformArray, i, quotient);			// Divide row by pivot position value
						multiplyRow<ORDER, RESULT_COLUMNS>(resultArray, i, quotient);
					}
					// Now that leading entry of current row is 1, subtract from other rows so entries in that column are 0
					for (size_t row = 0; row < ORDER; ++row) {
						if (row!=i && transformArray[i][row] != 0.0f) {
							float factor = -transformArray[i][row];
							addRow<ORDER, ORDER>(transformArray, i, row, factor);
							addRow<ORDER, RESULT_COLUMNS>(resultArray, i, row, factor);
						}
					}
				}
			}
			return matrixInvertable;
		}
	};

}
