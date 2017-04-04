#include <math.h>
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
	// TODO throw exception if n>2
	return m_component[n];
}

const float & Vector3::operator[](size_t n) const
{
	// TODO throw exception if n>2
	return m_component[n];
}

Vector3::operator float*()
{
	// Return array of components
	return m_component;
}

float Vector3::dot(const Vector3 & b) const
{
	// Multiply corresponding vector components, then add products together
	float product = m_component[0] * b[0] + m_component[1] * b[1] + m_component[2] * b[2];
	return product;
}

Vector3 Vector3::cross(const Vector3 & b) const
{
	Vector3 product;
	product[0] = m_component[1] * b[2] - m_component[2] * b[1];
	product[1] = m_component[2] * b[0] - m_component[0]*b[2];
	product[2] = m_component[0] * b[1] - m_component[1] * b[0];
	return product;
}

float Vector3::magnitude() const
{
	// Calculate magnitude through pythagoras equation
	// Take square root of sum of components squared
	float magnitude = sqrtf((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
	return magnitude;
}

void Vector3::normalise()
{
	// divide all components by magnitude
	
	// Calculate 1/magnitude
	float magReciprocal = 1.0 / magnitude();
	// Multiply each component by 1/magnitude
	m_x *= magReciprocal;
	m_y *= magReciprocal;
	m_z *= magReciprocal;
}

Vector3 operator+(const Vector3 & a, const Vector3 & b)
{
	// Add corresponding vector components to get components of resultant vector
	return Vector3(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

Vector3 operator-(const Vector3 & a, const Vector3 & b)
{
	// Subtract corresponding vector components to get components of resultant vector
	return Vector3(a[0] - b[0], a[1] - b[1], a[2]-b[2]);
}

Vector3 operator*(const Vector3 & v, float f)
{
	// Multiply all components by f to get components of resultant vector
	return Vector3(v[0] * f, v[1] * f, v[2]*f);
}

Vector3 operator*(float f, const Vector3 & v)
{
	// Multiply all components by f to get components of resultant vector
	return Vector3(v[0] * f, v[1] * f, v[2] * f);
}
