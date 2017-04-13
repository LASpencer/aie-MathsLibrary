#include <math.h>
#include "Matrix4.h"

namespace lasmath {
	Matrix4::Matrix4() : m_xAxis(Vector4()), m_yAxis(Vector4()), m_zAxis(Vector4()), m_tAxis(Vector4())
	{
	}

	Matrix4::Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw,
		float zx, float zy, float zz, float zw, float tx, float ty, float tz, float tw) :
		m_xAxis(Vector4(xx, xy, xz, xw)), m_yAxis(Vector4(yx, yy, yz, yw)), m_zAxis(Vector4(zx, zy, zz, zw)), m_tAxis(Vector4(tx, ty, tz, tw))
	{
	}

	Matrix4::Matrix4(const Matrix4 & rhs)
	{
		m_xAxis = rhs.m_xAxis;
		m_yAxis = rhs.m_yAxis;
		m_zAxis = rhs.m_zAxis;
		m_tAxis = rhs.m_tAxis;
	}

	Matrix4 Matrix4::operator=(const Matrix4 & rhs)
	{
		m_xAxis = rhs.m_xAxis;
		m_yAxis = rhs.m_yAxis;
		m_zAxis = rhs.m_zAxis;
		m_tAxis = rhs.m_tAxis;
		return *this;
	}


	Matrix4::~Matrix4()
	{
	}

	Vector4 & Matrix4::operator[](size_t n)
	{
		// TODO throw exception if n > 3
		return m_axis[n];
	}

	const Vector4 & Matrix4::operator[](size_t n) const
	{
		// TODO throw exception if n > 3
		return m_axis[n];
	}


	Matrix4::operator float*()
	{
		// return pointer to first element in union
		return m_element[0];
	}

	void Matrix4::setRotateX(float angle)
	{
		// Set x axis as unit vector (1,0,0,0)
		m_xAxis = Vector4(1, 0, 0, 0);
		// Set t axis as no translation
		m_tAxis = Vector4(0, 0, 0, 1);
		// Set y and z axes as unit vectors rotated around x axis by given angle
		m_yAxis = Vector4(0, cosf(angle), sinf(angle), 0);
		m_zAxis = Vector4(0, -sinf(angle), cosf(angle), 0);
	}

	void Matrix4::setRotateY(float angle)
	{
		// Set y axis as unit vector (0,1,0,0)
		m_yAxis = Vector4(0, 1, 0, 0);
		// Set t axis as no translation
		m_tAxis = Vector4(0, 0, 0, 1);
		// Set x and z axes as unit vectors rotated around y axis by given angle
		m_xAxis = Vector4(cosf(angle), 0, -sinf(angle), 0);
		m_zAxis = Vector4(sinf(angle), 0, cosf(angle), 0);
	}

	void Matrix4::setRotateZ(float angle)
	{
		// Set z axis as unit vector (0,0,1)
		m_zAxis = Vector4(0, 0, 1, 0);
		// Set t axis as no translation
		m_tAxis = Vector4(0, 0, 0, 1);
		// Set x and y axes as unit vectors rotated around z axis by given angle
		m_xAxis = Vector4(cosf(angle), sinf(angle), 0, 0);
		m_yAxis = Vector4(-sinf(angle), cosf(angle), 0, 0);
	}

	void Matrix4::setEulerRotate(float alpha, float beta, float gamma)
	{
		//z-x-z rotation
		//TODO further commenting
		float cosAlpha = cosf(alpha);
		float sinAlpha = sinf(alpha);
		float cosBeta = cosf(beta);
		float sinBeta = sinf(beta);
		float cosGamma = cosf(gamma);
		float sinGamma = sinf(gamma);
		m_xAxis = { cosAlpha*cosGamma - cosBeta*sinAlpha*sinGamma, cosGamma*sinAlpha + cosAlpha*cosBeta*sinGamma, sinBeta*sinGamma, 0 };
		m_yAxis = { -cosAlpha*sinGamma - cosBeta*cosGamma*sinAlpha, cosAlpha*cosBeta*cosGamma - sinAlpha*sinGamma, cosGamma*sinBeta, 0 };
		m_zAxis = { sinAlpha*sinBeta, -cosAlpha*sinBeta, cosBeta, 0 };
		m_tAxis = { 0, 0, 0, 1 };
	}

	void Matrix4::setTaitBryanRotate(float yaw, float pitch, float roll)
	{
		//z-y-x rotation
		//TODO further commenting
		float cosYaw = cosf(yaw);
		float sinYaw = sinf(yaw);
		float cosPitch = cosf(pitch);
		float sinPitch = sinf(pitch);
		float cosRoll = cosf(roll);
		float sinRoll = sinf(roll);

		m_xAxis = { cosYaw*cosPitch, sinYaw*cosPitch, -sinPitch, 0 };
		m_yAxis = { cosYaw*sinPitch*sinRoll - sinYaw*cosRoll, cosYaw*cosRoll + sinYaw*sinPitch*sinRoll, cosPitch*sinRoll, 0 };
		m_zAxis = { sinYaw*sinRoll + cosYaw*sinPitch*cosRoll, sinYaw*sinPitch*cosRoll - cosYaw*sinRoll, cosPitch*cosRoll, 0 };
		m_tAxis = { 0,0,0,1 };
	}

	bool Matrix4::calculateInverse(Matrix4 & dest)
	{
		Matrix4 inverse(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
		Matrix4 rowReduced = *this;
		bool invertable = Matrix::invertTransform<4, 4>((float*)rowReduced, (float*)inverse);
		if (invertable) {
			dest = inverse;
		}
		return invertable;
	}

	Vector4 operator*(const Matrix4 & a, const Vector4 & v)
	{
		// TODO 3D Homologous vector transform
		// TODO refactor as for loop
		Vector4 transformed;
		transformed[0] = a[0][0] * v[0] + a[1][0] * v[1] + a[2][0] * v[2] + a[3][0] * v[3];
		transformed[1] = a[0][1] * v[0] + a[1][1] * v[1] + a[2][1] * v[2] + a[3][1] * v[3];
		transformed[2] = a[0][2] * v[0] + a[1][2] * v[1] + a[2][2] * v[2] + a[3][2] * v[3];
		transformed[3] = a[0][3] * v[0] + a[1][3] * v[1] + a[2][3] * v[2] + a[3][3] * v[3];
		return transformed;
	}

	Matrix4 operator*(const Matrix4 & a, const Matrix4 & b)
	{
		//TODO comment 3D homologous matrix concatenation
		Matrix4 product;
		for (size_t i = 0; i < 4; ++i) {
			product[i] = a * b[i];
		}
		return product;
	}
}