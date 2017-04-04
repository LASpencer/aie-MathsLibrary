#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	
	// return reference to vector component
	float& operator[](size_t n);
	// cast vector as array of floats
	explicit operator float*();

	// Dot multiplication of two vectors
	float dot(const Vector2& b);

	// Returns magnitude of vector
	float magnitude();

	// Converts vector to a unit vector with same direction
	void normalise();


protected:
	// Components of vector
	float m_x;	
	float m_y;
};

// Arithmetic operators

Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& a, const Vector2& b);
Vector2 operator*(const Vector2& v, float f);
Vector2 operator*(float f, const Vector2& v);
