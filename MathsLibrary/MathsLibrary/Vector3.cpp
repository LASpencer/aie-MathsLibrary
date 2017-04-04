#include "Vector3.h"



Vector3::Vector3(): m_x(0), m_y(0),m_z(0)
{
}

Vector3::Vector3(float x, float y, float z): m_x(x),m_y(y),m_z(z)
{
}


Vector3::~Vector3()
{
}

float & Vector3::operator[](size_t n)
{
	// TODO Vector3[] operator
	float b = 0.0f;
	return b;
}

Vector3::operator float*()
{
	// Return array of components
	return m_component;
}

float Vector3::dot(const Vector3 & b)
{
	// TODO vector3 dot product
	return 0.0f;
}

Vector3 Vector3::cross(const Vector3 & b)
{
	// TODO Vector3 cross product
	return Vector3();
}

float Vector3::magnitude()
{
	// TODO vector3 magnitude
	return 0.0f;
}

void Vector3::normalise()
{
	// TODO vector3 normalise
}

Vector3 operator+(const Vector3 & a, const Vector3 & b)
{
	// TODO Vector3 addition
	return Vector3();
}

Vector3 operator-(const Vector3 & a, const Vector3 & b)
{
	//TODO vector3 subtraction
	return Vector3();
}

Vector3 operator*(const Vector3 & v, float f)
{
	// TODO vector3 scale
	return Vector3();
}

Vector3 operator*(float f, const Vector3 & v)
{
	// TODO vector3 scale
	return Vector3();
}
