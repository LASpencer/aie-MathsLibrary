#include <math.h>
#include "Vector3.h"


namespace lasmath {
	Vector3::Vector3() : m_x(0), m_y(0), m_z(0)
	{
	}

	Vector3::Vector3(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
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
		product[1] = m_component[2] * b[0] - m_component[0] * b[2];
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

	float Vector3::magnitudeSquared() const
	{
		// Square of magnitude is quicker to calculate than magnitude and is
		// useful when magnitude only needs to be compared to a value
		float magnitudeSquared = (m_x * m_x) + (m_y * m_y) + (m_z*m_z);
		return magnitudeSquared;
	}

	void Vector3::normalise()
	{
		// divide all components by magnitude

		// Calculate 1/magnitude
		float magReciprocal = 1.0f / magnitude();
		// Multiply each component by 1/magnitude
		m_x *= magReciprocal;
		m_y *= magReciprocal;
		m_z *= magReciprocal;
	}

	int Vector3::compareMagnitude(float f)
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

	Vector3 operator+(const Vector3 & a, const Vector3 & b)
	{
		// Add corresponding vector components to get components of resultant vector
		return Vector3(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
	}

	Vector3 operator-(const Vector3 & a, const Vector3 & b)
	{
		// Subtract corresponding vector components to get components of resultant vector
		return Vector3(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
	}

	Vector3 operator*(const Vector3 & v, float f)
	{
		// Multiply all components by f to get components of resultant vector
		return Vector3(v[0] * f, v[1] * f, v[2] * f);
	}

	Vector3 operator*(float f, const Vector3 & v)
	{
		// Multiply all components by f to get components of resultant vector
		return Vector3(v[0] * f, v[1] * f, v[2] * f);
	}

	bool operator>(const Vector3& a, const Vector3& b)
	{
		float aMagnitudeSquared = a.magnitudeSquared();
		float bMagnitudeSquared = b.magnitudeSquared();
		return aMagnitudeSquared > bMagnitudeSquared;
	}
	bool operator<(const Vector3& a, const Vector3& b)
	{
		// This operator should be read as "Magnitude of a is less than magnitude of b"
		// Since the magnitudes only need to be compared, the quicker magnitudeSquared method is used
		return b > a;
	}

	bool operator<=(const Vector3& a, const Vector3& b)
	{
		// This operator should be read as "Magnitude of a is less than or equal to magnitude of b"
		// Note that == is defined as vectors having equal magnitude and direction
		// So "a<b || a==b" is not the same as "a<=b", as they evaluate differently when magnitudes
		// are equal but not direction.
		return !(a > b);
	}

	bool operator>=(const Vector3& a, const Vector3& b)
	{
		// This operator should be read as "Magnitude of a is greater than or equal to magnitude of b"
		// Note that == is defined as vectors having equal magnitude and direction
		// So "a>b || a==b" is not the same as "a>=b", as they evaluate differently when magnitudes
		// are equal but not direction.
		return !(b > a);
	}


	bool operator==(const Vector3 & a, const Vector3 & b)
	{
		// Vectors are equal if all components are equal
		if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const Vector3 & a, const Vector3 & b)
	{
		return !(a == b);
	}
}