#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(float xx, float xy, float yx, float yy);
	~Matrix2();

	// Return reference to vector axis
	Vector2& operator[](size_t n);

	// Cast matrix as array of floats
	explicit operator float*();

	// Set matrix to be a transformation matrix rotating by angle
	void setRotate(float angle);

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