#include <math.h>
#include "Matrix3.h"

namespace lasmath {
	Matrix3::Matrix3() : m_xAxis(Vector3()), m_yAxis(Vector3()), m_zAxis(Vector3())
	{
	}

	Matrix3::Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz) : m_xAxis(xx, xy, xz), m_yAxis(yx, yy, yz), m_zAxis(zx, zy, zz)
	{
	}

	Matrix3::Matrix3(const Matrix3 & rhs)
	{
		m_xAxis = rhs.m_xAxis;
		m_yAxis = rhs.m_yAxis;
		m_zAxis = rhs.m_zAxis;
	}

	Matrix3 Matrix3::operator=(const Matrix3 & rhs)
	{
		m_xAxis = rhs.m_xAxis;
		m_yAxis = rhs.m_yAxis;
		m_zAxis = rhs.m_zAxis;
		return *this;
	}


	Matrix3::~Matrix3()
	{
	}

	Vector3& Matrix3::operator[](size_t n)
	{
		// TODO throw exception if n > 2
		return m_axis[n];
	}

	const Vector3 & Matrix3::operator[](size_t n) const
	{
		// TODO throw exception if n > 2
		return m_axis[n];
	}

	Matrix3::operator float*()
	{
		//returns pointer to first element in union
		return m_element[0];
	}

	void Matrix3::setRotateX(float angle)
	{
		// Set x axis as unit vector (1,0,0)
		m_xAxis = Vector3(1, 0, 0);
		// Set y and z axes as unit vectors rotated around x axis by given angle
		m_yAxis = Vector3(0, cosf(angle), sinf(angle));
		m_zAxis = Vector3(0, -sinf(angle), cosf(angle));
	}

	void Matrix3::setRotateY(float angle)
	{
		// Set y axis as unit vector (0,1,0)
		m_yAxis = Vector3(0, 1, 0);
		// Set x and z axes as unit vectors rotated around y axis by given angle
		m_xAxis = Vector3(cosf(angle), 0, -sinf(angle));
		m_zAxis = Vector3(sinf(angle), 0, cosf(angle));
	}

	void Matrix3::setRotateZ(float angle)
	{
		// Set z axis as unit vector (0,0,1)
		m_zAxis = Vector3(0, 0, 1);
		// Set x and y axes as unit vectors rotated around z axis by given angle
		m_xAxis = Vector3(cosf(angle), sinf(angle), 0);
		m_yAxis = Vector3(-sinf(angle), cosf(angle), 0);
	}

	void Matrix3::setEulerRotate(float alpha, float beta, float gamma)
	{
		//z-x-z rotation
		//TODO further commenting
		float cosAlpha = cosf(alpha);
		float sinAlpha = sinf(alpha);
		float cosBeta = cosf(beta);
		float sinBeta = sinf(beta);
		float cosGamma = cosf(gamma);
		float sinGamma = sinf(gamma);
		m_xAxis = { cosAlpha*cosGamma - cosBeta*sinAlpha*sinGamma, cosGamma*sinAlpha + cosAlpha*cosBeta*sinGamma, sinBeta*sinGamma };
		m_yAxis = { -cosAlpha*sinGamma - cosBeta*cosGamma*sinAlpha, cosAlpha*cosBeta*cosGamma - sinAlpha*sinGamma, cosGamma*sinBeta };
		m_zAxis = { sinAlpha*sinBeta, -cosAlpha*sinBeta, cosBeta };
	}

	void Matrix3::setTaitBryanRotate(float yaw, float pitch, float roll)
	{
		//z-y-x rotation
		//TODO further commenting
		float cosYaw = cosf(yaw);
		float sinYaw = sinf(yaw);
		float cosPitch = cosf(pitch);
		float sinPitch = sinf(pitch);
		float cosRoll = cosf(roll);
		float sinRoll = sinf(roll);

		m_xAxis = { cosYaw*cosPitch, sinYaw*cosPitch, -sinPitch };
		m_yAxis = { cosYaw*sinPitch*sinRoll - sinYaw*cosRoll, cosYaw*cosRoll + sinYaw*sinPitch*sinRoll, cosPitch*sinRoll };
		m_zAxis = { sinYaw*sinRoll + cosYaw*sinPitch*cosRoll, sinYaw*sinPitch*cosRoll - cosYaw*sinRoll, cosPitch*cosRoll };
	}

	bool Matrix3::calculateInverse(Matrix3 & dest)
	{
		Matrix3 inverse(1, 0, 0, 0, 1,0,0,0,1);							//Start with identity matrix
		Matrix3 rowReduced = *this;										//Get copy of this matrix to row reduce
		bool invertable = Matrix::invertTransform<3, 3>((float*)rowReduced, (float*)inverse);
		if (invertable) {
			dest = inverse;
		}
		return invertable;
	}

	Vector3 operator*(const Matrix3 & a, const Vector3 & v)
	{
		// TODO comment 3D Vector Transformation
		// TODO refactor as for loop
		Vector3 transformed;
		transformed[0] = a[0][0] * v[0] + a[1][0] * v[1] + a[2][0] * v[2];
		transformed[1] = a[0][1] * v[0] + a[1][1] * v[1] + a[2][1] * v[2];
		transformed[2] = a[0][2] * v[0] + a[1][2] * v[1] + a[2][2] * v[2];
		return transformed;
	}

	Matrix3 operator*(const Matrix3 & a, const Matrix3 & b)
	{
		//TODO comment 3D Matrix concatenation
		Matrix3 product;
		for (size_t i = 0; i < 3; ++i) {
			product[i] = a * b[i];
		}
		return product;
	}
}