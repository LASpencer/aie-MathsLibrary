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

		/* Compares magnitude of vector to value given.
			Returns 0 if equal, -1 if vector magnitude is lower, 1 if vector magnitude is greater
		*/
		int compareMagnitude(float f);
	};

	// Compare magnitudes of vectors
	bool operator>(const Vector& a, const Vector& b);
	bool operator<(const Vector& a, const Vector& b);
	bool operator>=(const Vector& a, const Vector& b);
	bool operator<=(const Vector& a, const Vector& b);

}