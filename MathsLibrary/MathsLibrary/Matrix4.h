#pragma once
#include "Matrix.h"
#include "Vector.h"

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
		Vector<4>& operator[](size_t n);
		const Vector<4>& operator[](size_t n) const;

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

		// Calculates inverse of this matrix and copies it to dest
		// Returns true if matrix is invertable, returns false if singular or poorly conditioned
		bool calculateInverse(Matrix4& dest);

	protected:
		union {
			struct {
				Vector<4> m_xAxis;
				Vector<4> m_yAxis;
				Vector<4> m_zAxis;
				Vector<4> m_tAxis;
			};
			Vector<4> m_axis[4];
			float m_element[4][4];
		};
	};

	// Vector transformation
	Vector<4> operator*(const Matrix4& a, const Vector<4>& v);

	// Matrix concatenation
	Matrix4 operator*(const Matrix4& a, const Matrix4& b);
}