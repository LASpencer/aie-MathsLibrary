#pragma once
#include "Matrix.h"
#include "Vector4.h"

namespace lasmath {
	class Matrix4 : public Matrix
	{
	public:
		Matrix4();
		Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw,
			float zx, float zy, float zz, float zw, float tx, float ty, float tz, float tw);
		Matrix4(const Matrix4 &rhs);
		Matrix4 operator=(const Matrix4 &rhs);
		~Matrix4();

		// Return reference to vector axis
		Vector4& operator[](size_t n);
		const Vector4& operator[](size_t n) const;

		// Cast matrix as array of floats
		explicit operator float*();

		// Set matrix to transformation matrix rotating around X axis by angle
		void setRotateX(float angle);
		// Set matrix to transformation matrix rotating around Y axis by angle
		void setRotateY(float angle);
		// Set matrix to transformation matrix rotating around Z axis by angle
		void setRotateZ(float angle);
		// Set matrix to a transformation matrix rotating to orientation given by Euler angles
		void setEulerRotate(float alpha, float beta, float gamma);
		// Set matrix to a transformation matrix rotating to orientation given by Tait-Bryan angles
		void setTaitBryanRotate(float yaw, float pitch, float roll);

	protected:
		union {
			struct {
				Vector4 m_xAxis;
				Vector4 m_yAxis;
				Vector4 m_zAxis;
				Vector4 m_tAxis;
			};
			Vector4 m_axis[4];
			float m_element[4][4];
		};
	};

	// Vector transformation
	Vector4 operator*(const Matrix4& a, const Vector4& v);

	// Matrix concatenation
	Matrix4 operator*(const Matrix4& a, const Matrix4& b);
}