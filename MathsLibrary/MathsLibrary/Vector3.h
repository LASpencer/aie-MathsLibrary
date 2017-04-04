#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	// return reference to vector component
	float& operator[](size_t n);

	// cast vector as array of floats
	explicit operator float*();

	// Dot multiplication of two vectors
	float dot(const Vector3& b);

	// Cross multiplication of two vectors
	Vector3 cross(const Vector3& b);

	// Returns magnitude of vector
	float magnitude();

	// Converts vector to a unit vector with same direction
	void normalise();


protected:
	// Components of vector
	float m_x;
	float m_y;
	float m_z;
};

// Arithmetic operators

Vector3 operator+(const Vector3& a, const Vector3& b);
Vector3 operator-(const Vector3& a, const Vector3& b);
Vector3 operator*(const Vector3& v, float f);
Vector3 operator*(float f, const Vector3& v);