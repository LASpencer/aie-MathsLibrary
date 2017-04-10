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
}