#include <math.h>
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
	m_yAxis = Vector4(0, cosf(angle), sinf(angle),0);
	m_zAxis = Vector4(0, -sinf(angle), cosf(angle),0);
}

void Matrix4::setRotateY(float angle)
{
	// Set y axis as unit vector (0,1,0,0)
	m_yAxis = Vector4(0, 1, 0,0);
	// Set t axis as no translation
	m_tAxis = Vector4(0, 0, 0, 1);
	// Set x and z axes as unit vectors rotated around y axis by given angle
	m_xAxis = Vector4(cosf(angle), 0, -sinf(angle),0);
	m_zAxis = Vector4(sinf(angle), 0, cosf(angle),0);
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
