#include <math.h>
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

float Vector4::dot(const Vector4 & b) const
{
	// Multiply corresponding vector components, then add products together
	float product = m_component[0] * b[0] + m_component[1] * b[1] + m_component[2] * b[2] + m_component[3] * b[3];
	return product;
}

Vector4 Vector4::cross(const Vector4 & b) const
{
	// Treat as Vector3 cross product, then set w = 0
	Vector4 product;
	product[0] = m_component[1] * b[2] - m_component[2] * b[1];
	product[1] = m_component[2] * b[0] - m_component[0] * b[2];
	product[2] = m_component[0] * b[1] - m_component[1] * b[0];
	product[3] = 0;
	return product;
}

float Vector4::magnitude() const
{
	// Calculate magnitude through pythagoras equation
	// Take square root of sum of components squared
	float magnitude = sqrtf((m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w));
	return magnitude;
}

void Vector4::normalise()
{
	// divide all components by magnitude

	// Calculate 1/magnitude
	float magReciprocal = 1.0 / magnitude();
	// Multiply each component by 1/magnitude
	m_x *= magReciprocal;
	m_y *= magReciprocal;
	m_z *= magReciprocal;
	m_w *= magReciprocal;
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
