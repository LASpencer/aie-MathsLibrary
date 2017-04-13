#pragma once
//#ifdef MATHSLIBRARY_EXPORTS
//#define MATHSLIBRARY_API __declspec(dllexport)
//#else
//#define MATHSLIBRARY_API __declspec(dllimport)
//#endif


namespace lasmath {
	class Vector3;
	class Vector4;

	class Vector2
	{
	public:
		Vector2();
		Vector2(float x, float y);
		~Vector2();


		// return reference to vector component
		float& operator[](size_t n);
		const float& operator[](size_t n) const;

		// cast vector as array of floats
		explicit operator float*();

		// cast as Vector3 with z = 0
		explicit operator Vector3();

		// cast as Vector4 with z=0 and w=0;
		explicit operator Vector4();

		// Dot multiplication of two vectors
		float dot(const Vector2& b) const;

		// Returns magnitude of vector
		float magnitude() const;

		// Returns square of vector's magnitude
		float magnitudeSquared() const;

		// Converts vector to a unit vector with same direction
		void normalise();

		/* Compares magnitude of vector to value given.
		Returns 0 if equal, -1 if vector magnitude is lower, 1 if vector magnitude is greater
		*/
		int compareMagnitude(float f);

	protected:
		// Components of vector
		union {
			struct {
				float m_x;
				float m_y;
			};
			float m_component[2];
		};
	};

	// Arithmetic operators

	Vector2 operator+(const Vector2& a, const Vector2& b);
	Vector2 operator-(const Vector2& a, const Vector2& b);
	Vector2 operator*(const Vector2& v, float f);
	Vector2 operator*(float f, const Vector2& v);

	// Compare magnitudes of vectors
	bool operator>(const Vector2& a, const Vector2& b);
	bool operator<(const Vector2& a, const Vector2& b);
	bool operator>=(const Vector2& a, const Vector2& b);
	bool operator<=(const Vector2& a, const Vector2& b);

	// Vectors are equal if all components are equal
	bool operator==(const Vector2& a, const Vector2& b);
	bool operator!=(const Vector2& a, const Vector2& b);
}