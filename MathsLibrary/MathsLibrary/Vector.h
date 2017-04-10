#pragma once

namespace lasmath {
	class Vector
	{
	public:
		Vector();
		~Vector();

		virtual float& operator[](size_t n) = 0;
		virtual const float& operator[](size_t n) const = 0;

		virtual float magnitudeSquared() const = 0;
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