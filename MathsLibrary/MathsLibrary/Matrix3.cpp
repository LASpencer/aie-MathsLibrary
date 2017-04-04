#include "Matrix3.h"


Matrix3::Matrix3() : m_xAxis(Vector3()), m_yAxis(Vector3()), m_zAxis(Vector3())
{
}

Matrix3::Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz): m_xAxis(xx,xy,xz), m_yAxis(yx,yy,yz), m_zAxis(zx,zy,zz)
{
}


Matrix3::~Matrix3()
{
}

Vector3& Matrix3::operator[](size_t n)
{
	// TODO Matrix3[] operator
	return m_xAxis;
}

Matrix3::operator float*()
{
	//TODO cast Matrix3 as float*
	return nullptr;
}

void Matrix3::setRotateX(float angle)
{
	// TODO Matrix3 rotateX
}

void Matrix3::setRotateY(float angle)
{
	// TODO matrix3 rotateY
}

void Matrix3::setRotateZ(float angle)
{
	//TODO matrix3 rotateZ
}

Vector3 operator*(const Matrix3 & a, const Vector3 & v)
{
	// TODO 3D Vector Transformation
	return Vector3();
}

Matrix3 operator*(const Matrix3 & a, const Matrix3 & b)
{
	// TODO 3D Matrix concatenation
	return Matrix3();
}
