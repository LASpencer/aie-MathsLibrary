#pragma once
#include "Matrix.h"

//#ifdef MATHSLIBRARY_EXPORTS
//#define MATHSLIBRARY_API __declspec(dllexport)
//#else
//#define MATHSLIBRARY_API __declspec(dllimport)
//#endif

#include "Vector2.h"

namespace lasmath {
	class Matrix2: public Matrix
	{
	public:
		Matrix2();
		Matrix2(float xx, float xy, float yx, float yy);
		Matrix2(const Matrix2& rhs);
		Matrix2 operator=(const Matrix2& rhs);
		~Matrix2();

		// Return reference to vector axis
		Vector2& operator[](size_t n);
		const Vector2& operator[](size_t n) const;

		// Cast matrix as array of floats
		explicit operator float*();

		// Set matrix to be a transformation matrix rotating by angle
		void setRotate(float angle);

		// Calculates inverse of this matrix and copies it to dest
		// Returns true if matrix is invertable, returns false if singular or poorly conditioned
		bool calculateInverse(Matrix2& dest);
		//TODO undo transformation
		//TODO undo transformation on vector

	protected:
		union {
			struct {
				Vector2 m_xAxis;
				Vector2 m_yAxis;
			};
			Vector2 m_axis[2];
			float m_element[2][2];
		};
	};

	// Vector transformation
	Vector2 operator*(const Matrix2& a, const Vector2& v);

	// Matrix concatenation
	Matrix2 operator*(const Matrix2& a, const Matrix2& b);
}