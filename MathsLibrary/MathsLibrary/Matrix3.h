#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz);
	~Matrix3();

	// Return reference to vector axis
	Vector3& operator[](size_t n);

	// Cast matrix as array of floats
	explicit operator float*();

	// Set matrix to transformation matrix rotating around X axis by angle
	void setRotateX(float angle);
	// Set matrix to transformation matrix rotating around Y axis by angle
	void setRotateY(float angle);
	// Set matrix to transformation matrix rotating around Z axis by angle
	void setRotateZ(float angle);


protected:
	union {
		struct {
			Vector3 m_xAxis;
			Vector3 m_yAxis;
			Vector3 m_zAxis;
		};
		Vector3 m_axis[3];
		float m_element[3][3];
	};
};

// Vector transformation
Vector3 operator*(const Matrix3& a, const Vector3& v);

// Matrix concatenation
Matrix3 operator*(const Matrix3& a, const Matrix3& b);