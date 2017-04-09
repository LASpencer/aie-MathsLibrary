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
}