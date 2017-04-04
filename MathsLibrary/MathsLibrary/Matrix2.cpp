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
	// TODO Matrix2[] operator
	return m_xAxis;
}

Matrix2::operator float*()
{
	// Returns pointer to first element in union
	return m_element[0];
}

void Matrix2::setRotate(float angle)
{
	// TODO Matrix2 setRotate
}

Vector2 operator*(const Matrix2 & a, const Vector2 & v)
{
	//TODO 2D vector transformation
	return Vector2();
}

Matrix2 operator*(const Matrix2 & a, const Matrix2 & b)
{
	//TODO 2D Matrix concatenation
	return Matrix2();
}
