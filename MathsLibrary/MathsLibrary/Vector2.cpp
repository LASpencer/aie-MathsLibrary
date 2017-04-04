#include "Vector2.h"
//#include <exception>


Vector2::Vector2(): m_x(0), m_y(0)
{
}

Vector2::Vector2(float x, float y): m_x(x),m_y(y)
{
}


Vector2::~Vector2()
{
}

float & Vector2::operator[](size_t n)
{
	//TODO throw exception if n>1
	return m_component[n];
}

const float & Vector2::operator[](size_t n) const
{
	//TODO throw exception if n>1
	return m_component[n];
}

Vector2::operator float*()
{
	// Return array of components
	return m_component;
}

float Vector2::dot(const Vector2& b)
{
	// TODO Vector2 dot multiplication
	return 0.0f;
}

float Vector2::magnitude()
{
	// TODO vector2 magnitude
	return 0.0f;
}

void Vector2::normalise()
{
	// TODO normalize Vector2
}

Vector2 operator+(const Vector2 & a, const Vector2 & b)
{
	// Add corresponding vector components to get components of resultant vector
	return Vector2(a[0] + b[0], a[1] + b[1]);
}

Vector2 operator-(const Vector2 & a, const Vector2 & b)
{
	// Subtract corresponding vector components to get components of resultant vector
	return Vector2(a[0] - b[0], a[1] - b[1]);
}

Vector2 operator*(const Vector2 & v, float f)
{
	// Multiply all components by f to get components of resultant vector
	return Vector2(v[0]*f,v[1]*f);
}

Vector2 operator*(float f, const Vector2 & v)
{
	// Multiply all components by f to get components of resultant vector
	return Vector2(v[0] * f, v[1] * f);
}
