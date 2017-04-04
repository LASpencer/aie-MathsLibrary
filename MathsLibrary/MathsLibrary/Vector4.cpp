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
	// TODO Vector4[] operator
	float b = 0.0f;
	return b;
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
	//TODO vector4 addition
	return Vector4();
}

Vector4 operator-(const Vector4 & a, const Vector4 & b)
{
	//TODO vector4 subtraction
	return Vector4();
}

Vector4 operator*(const Vector4 & v, float f)
{
	// TODO vector4 scale
	return Vector4();
}

Vector4 operator*(float f, const Vector4 & v)
{
	// TODO vector4 scale
	return Vector4();
}
