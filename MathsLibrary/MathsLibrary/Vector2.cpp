#include "Vector2.h"



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
	// TODO Vector2[]
	float b = 0.0f;
	return b;
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
	// TODO Vector2 addition
	return Vector2();
}

Vector2 operator-(const Vector2 & a, const Vector2 & b)
{
	//TODO vector2 subtraction
	return Vector2();
}

Vector2 operator*(const Vector2 & v, float f)
{
	//TODO scale Vector2
	return Vector2();
}

Vector2 operator*(float f, const Vector2 & v)
{
	//TODO Vector2 scale
	return Vector2();
}
