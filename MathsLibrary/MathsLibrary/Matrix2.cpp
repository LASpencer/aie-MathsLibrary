#include <math.h>
#include "Matrix2.h"

namespace lasmath {
	Matrix2::Matrix2() : m_xAxis(Vector<2>()), m_yAxis(Vector<2>())
	{
	}

	Matrix2::Matrix2(float xx, float xy, float yx, float yy) : m_xAxis(Vector<2>(xx, xy)), m_yAxis(Vector<2>(yx, yy))
	{
	}

	Matrix2::Matrix2(const Matrix2 & rhs)
	{
		m_xAxis = rhs.m_xAxis;
		m_yAxis = rhs.m_yAxis;
	}

	Matrix2 Matrix2::operator=(const Matrix2 & rhs)
	{
		/* HACK for some reason changing vector class to use inheritance implicitely deleted assignment
		research causes more deeply, try to figure out solution/workaround
		*/
		m_xAxis = rhs.m_xAxis;
		m_yAxis = rhs.m_yAxis;
		return *this;
	}


	Matrix2::~Matrix2()
	{
	}

	Vector<2> & Matrix2::operator[](size_t n)
	{
		// TODO throw exception if n > 1
		return m_axis[n];
	}

	const Vector<2> & Matrix2::operator[](size_t n) const
	{
		// TODO throw exception if n > 1
		return m_axis[n];
	}

	Matrix2::operator float*()
	{
		// Returns pointer to first element in union
		return m_element[0];
	}

	void Matrix2::setRotate(float angle)
	{
		// Set axes as unit vectors rotated by given angle
		m_xAxis = Vector<2>(cosf(angle), sinf(angle));
		m_yAxis = Vector<2>(-sinf(angle), cosf(angle));
	}

	bool Matrix2::calculateInverse(Matrix2 & dest)
	{
		Matrix2 inverse(1,0,0,1);							//Start with identity matrix
		Matrix2 rowReduced = *this;							//Get copy of this matrix to row reduce
		bool invertable = Matrix::invertTransform<2,2>((float*)rowReduced, (float*)inverse);
		if (invertable) {
			dest = inverse;
		}
		return invertable;
	}

	Vector<2> operator*(const Matrix2 & a, const Vector<2> & v)
	{
		//TODO comment vector transformation
		// TODO refactor as for loop
		Vector<2> transformed;
		transformed[0] = a[0][0] * v[0] + a[1][0] * v[1];
		transformed[1] = a[0][1] * v[0] + a[1][1] * v[1];
		return transformed;
	}

	Matrix2 operator*(const Matrix2 & a, const Matrix2 & b)
	{
		//TODO comment 2D Matrix concatenation
		Matrix2 product;
		for (size_t i = 0; i < 2; ++i) {
			product[i] = a * b[i];
		}
		return product;
	}
}