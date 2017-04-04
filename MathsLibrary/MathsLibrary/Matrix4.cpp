#include "Matrix4.h"


Matrix4::Matrix4() : m_xAxis(Vector4()), m_yAxis(Vector4()), m_zAxis(Vector4()), m_tAxis(Vector4())
{
}

Matrix4::Matrix4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw,
	float zx, float zy, float zz, float zw, float tx, float ty, float tz, float tw) : 
	m_xAxis(Vector4(xx,xy,xz,xw)), m_yAxis(Vector4(yx,yy,yz,yw)), m_zAxis(Vector4(zx,zy,zz,zw)), m_tAxis(Vector4(tx,ty,tz,tw))
{
}


Matrix4::~Matrix4()
{
}

Vector4 & Matrix4::operator[](size_t n)
{
	// TODO Matrix4[] operator
	return m_xAxis;
}

Matrix4::operator float*()
{
	// return pointer to first element in union
	return m_element[0];
}

void Matrix4::setRotateX(float angle)
{
	// TODO Matrix4 RotateX
}

void Matrix4::setRotateY(float angle)
{
	//TODO Matrix4 RotateY
}

void Matrix4::setRotateZ(float angle)
{
	//TODO Matrix4 RotateZ
}

Vector4 operator*(const Matrix4 & a, const Vector4 & v)
{
	// TODO 3D Homologous vector transform
	return Vector4();
}

Matrix4 operator*(const Matrix4 & a, const Matrix4 & b)
{
	//TODO 3D homologous matrix concatenation
	return Matrix4();
}
