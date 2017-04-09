#pragma once

//#ifdef MATHSLIBRARY_EXPORTS
//#define MATHSLIBRARY_API __declspec(dllexport)
//#else
//#define MATHSLIBRARY_API __declspec(dllimport)
//#endif

namespace lasmath {
	class Vector3
	{
	public:
		Vector3();
		Vector3(float x, float y, float z);
		~Vector3();

		// return reference to vector component
		float& operator[](size_t n);
		const float& operator[](size_t n) const;

		// cast vector as array of floats
		explicit operator float*();

		// Dot multiplication of two vectors
		float dot(const Vector3& b) const;

		// Cross multiplication of two vectors
		Vector3 cross(const Vector3& b) const;

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
			};
			float m_component[3];
		};
	};

	// Arithmetic operators

	Vector3 operator+(const Vector3& a, const Vector3& b);
	Vector3 operator-(const Vector3& a, const Vector3& b);
	Vector3 operator*(const Vector3& v, float f);
	Vector3 operator*(float f, const Vector3& v);
}