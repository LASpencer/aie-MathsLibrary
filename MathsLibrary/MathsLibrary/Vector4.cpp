#include "Vector4.h"



Vector4::Vector4(): m_x(0),m_y(0),m_z(0),m_w(0)
{
}

Vector4::Vector4(float x, float y, float z, float w): m_x(x),m_y(y),m_z(z),m_w(w)
{
}


Vector4::~Vector4()
{
}

float & Vector4::operator[](size_t n)
{
	// TODO throw exception if n>3
	return m_component[n];
}

const float & Vector4::operator[](size_t n) const
{
	// TODO throw exception if n>3
	return m_component[n];
}

Vector4::operator float*()
{
	// Return array of components
	return m_component;
}

float Vector4::dot(const Vector4 & b)
{
	// TODO Vector4 dot product
	return 0.0f;
}

Vector4 Vector4::cross(const Vector4 & b)
{
	// TODO vector4 cross product
	// Treat as vector3 cross product, then figure out what w should be? Probably 0
	return Vector4();
}

float Vector4::magnitude()
{
	// TODO Vector4 magnitude
	return 0.0f;
}

void Vector4::normalise()
{
	// TODO normalise vector4
}

Vector4 operator+(const Vector4 & a, const Vector4 & b)
{
	// Add corresponding vector components to get components of resultant vector
	return Vector4(a[0]+b[0],a[1]+b[1],a[2]+b[2],a[3]+b[3]);
}

Vector4 operator-(const Vector4 & a, const Vector4 & b)
{
	// Subtract corresponding vector components to get components of resultant vector
	return Vector4(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

Vector4 operator*(const Vector4 & v, float f)
{
	// Multiply all components by f to get components of resultant vector
	return Vector4(v[0] * f, v[1] * f, v[2] * f, v[3]*f);
}

Vector4 operator*(float f, const Vector4 & v)
{
	// Multiply all components by f to get components of resultant vector
	return Vector4(v[0] * f, v[1] * f, v[2] * f, v[3] * f);
}
