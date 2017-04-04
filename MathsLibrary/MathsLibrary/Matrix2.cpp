#include <math.h>
#include "Matrix2.h"


Matrix2::Matrix2(): m_xAxis(Vector2()), m_yAxis(Vector2())
{
}

Matrix2::Matrix2(float xx, float xy, float yx, float yy): m_xAxis(Vector2(xx,xy)), m_yAxis(Vector2(yx,yy))
{
}


Matrix2::~Matrix2()
{
}

Vector2 & Matrix2::operator[](size_t n)
{
	// TODO throw exception if n > 1
	return m_axis[n];
}

const Vector2 & Matrix2::operator[](size_t n) const
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
	m_xAxis = Vector2(cosf(angle), sinf(angle));
	m_yAxis = Vector2(-sinf(angle), cosf(angle));
}

Vector2 operator*(const Matrix2 & a, const Vector2 & v)
{
	//TODO comment vector transformation
	// TODO refactor as for loop
	Vector2 transformed;
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
