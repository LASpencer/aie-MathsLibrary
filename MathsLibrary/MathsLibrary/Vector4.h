#pragma once

//#ifdef MATHSLIBRARY_EXPORTS
//#define MATHSLIBRARY_API __declspec(dllexport)
//#else
//#define MATHSLIBRARY_API __declspec(dllimport)
//#endif

namespace lasmath {
	class Vector4
	{
	public:
		Vector4();
		Vector4(float x, float y, float z, float w);
		~Vector4();

		// return reference to vector component
		float& operator[](size_t n);
		const float& operator[](size_t n) const;

		// cast vector as array of floats
		explicit operator float*();

		// Dot multiplication of two vectors
		float dot(const Vector4& b) const;

		// Cross multiplication of two vectors
		Vector4 cross(const Vector4& b) const;

		// Returns magnitude of vector
		float magnitude() const;

		// Returns square of vector's magnitude
		float magnitudeSquared() const;

		// Converts vector to a unit vector with same direction
		void normalise();

	protected:
		// Components of vector
		union {
			struct {
				float m_x;
				float m_y;
				float m_z;
				float m_w;
			};
			float m_component[4];
		};
	};

	Vector4 operator+(const Vector4& a, const Vector4& b);
	Vector4 operator-(const Vector4& a, const Vector4& b);
	Vector4 operator*(const Vector4& v, float f);
	Vector4 operator*(float f, const Vector4& v);

	// Compare magnitudes of vectors
	bool operator>(const Vector4& a, const Vector4& b);
	bool operator<(const Vector4& a, const Vector4& b);
	bool operator>=(const Vector4& a, const Vector4& b);
	bool operator<=(const Vector4& a, const Vector4& b);

	// Compare vector magnitude to given float
	bool operator>(const Vector4& v, float f);
	bool operator>(float f, const Vector4& v);
	bool operator<(const Vector4& v, float f);
	bool operator<(float f, const Vector4& v);
	bool operator>=(const Vector4& v, float f);
	bool operator>=(float f, const Vector4& v);
	bool operator<=(const Vector4& v, float f);
	bool operator<=(float f, const Vector4& v);

	// Vectors are equal if all components are equal
	bool operator==(const Vector4& a, const Vector4& b);
}