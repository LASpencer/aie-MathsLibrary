#include <math.h>
#include "Vector2.h"
//#include <exception>

namespace lasmath {
	Vector2::Vector2() : m_x(0), m_y(0)
	{
	}

	Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
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

	float Vector2::dot(const Vector2& b) const
	{
		// Multiply corresponding vector components, then add products together
		float product = m_component[0] * b[0] + m_component[1] * b[1];
		return product;
	}

	float Vector2::magnitude() const
	{
		// Calculate magnitude through pythagoras equation
		// Take square root of sum of components squared
		float magnitude = sqrtf((m_x * m_x) + (m_y * m_y));
		return magnitude;
	}

	float Vector2::magnitudeSquared() const
	{
		// Square of magnitude is quicker to calculate than magnitude and is
		// useful when magnitude only needs to be compared to a value
		float magnitudeSquared = (m_x * m_x) + (m_y * m_y);
		return magnitudeSquared;
	}

	void Vector2::normalise()
	{
		// Divide all components by magnitude

		// Calculate 1/magnitude
		float magReciprocal = 1.0f / magnitude();
		// Multiply each component by 1/magnitude
		m_x *= magReciprocal;
		m_y *= magReciprocal;
	}

	int Vector2::compareMagnitude(float f)
	{
		float difference = magnitudeSquared() - (f*f);
		if (difference < 0.0) {
			return -1;
		}
		else if (difference >0.0) {
			return 1;
		}
		else {
			return 0;
		}
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
		return Vector2(v[0] * f, v[1] * f);
	}

	Vector2 operator*(float f, const Vector2 & v)
	{
		// Multiply all components by f to get components of resultant vector
		return Vector2(v[0] * f, v[1] * f);
	}

	bool operator>(const Vector2& a, const Vector2& b)
	{
		float aMagnitudeSquared = a.magnitudeSquared();
		float bMagnitudeSquared = b.magnitudeSquared();
		return aMagnitudeSquared > bMagnitudeSquared;
	}
	bool operator<(const Vector2& a, const Vector2& b)
	{
		// This operator should be read as "Magnitude of a is less than magnitude of b"
		// Since the magnitudes only need to be compared, the quicker magnitudeSquared method is used
		return b > a;
	}

	bool operator<=(const Vector2& a, const Vector2& b)
	{
		// This operator should be read as "Magnitude of a is less than or equal to magnitude of b"
		// Note that == is defined as vectors having equal magnitude and direction
		// So "a<b || a==b" is not the same as "a<=b", as they evaluate differently when magnitudes
		// are equal but not direction.
		return !(a > b);
	}

	bool operator>=(const Vector2& a, const Vector2& b)
	{
		// This operator should be read as "Magnitude of a is greater than or equal to magnitude of b"
		// Note that == is defined as vectors having equal magnitude and direction
		// So "a>b || a==b" is not the same as "a>=b", as they evaluate differently when magnitudes
		// are equal but not direction.
		return !(b > a);
	}


	bool operator==(const Vector2 & a, const Vector2 & b)
	{
		// Vectors are equal if all components are equal
		if (a[0] == b[0] && a[1] == b[1]) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const Vector2 & a, const Vector2 & b)
	{
		return !(a == b);
	}
}