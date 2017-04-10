#pragma once

namespace lasmath {
	class Vector
	{
	public:
		Vector();
		~Vector();

		// return reference to vector component
		virtual float& operator[](size_t n) = 0;
		virtual const float& operator[](size_t n) const = 0;

		// cast vector as array of floats
		virtual operator float*() =0;

		// Returns magnitude of vector
		virtual float magnitude() const = 0;

		// Returns square of vector's magnitude
		virtual float magnitudeSquared() const = 0;

		// Converts vector to a unit vector with same direction
		virtual void normalise() =0;
	};

	// Compare magnitudes of vectors
	bool operator>(const Vector& a, const Vector& b);
	bool operator<(const Vector& a, const Vector& b);
	bool operator>=(const Vector& a, const Vector& b);
	bool operator<=(const Vector& a, const Vector& b);

	// Compare vector magnitude to given float
	bool operator>(const Vector& v, float f);
	bool operator>(float f, const Vector& v);
	bool operator<(const Vector& v, float f);
	bool operator<(float f, const Vector& v);
	bool operator>=(const Vector& v, float f);
	bool operator>=(float f, const Vector& v);
	bool operator<=(const Vector& v, float f);
	bool operator<=(float f, const Vector& v);
}