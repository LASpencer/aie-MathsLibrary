#include "unittest.h"
#include <iostream>
#include <iomanip>

#ifndef NO_DEFAULT_STREAM_OPERATOR

	std::ostream& operator << (std::ostream& os, Vector2& rhs) { 
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1]; return os; }
	std::ostream& operator << (std::ostream& os, Vector3& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2]; return os; }
	std::ostream& operator << (std::ostream& os, Vector4& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2] << "," << std::setprecision(12) << a[3]; return os; }
	std::ostream& operator << (std::ostream& os, Matrix2& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 4; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 3 ))
				os << ",";
		}
		return os;
	}
	std::ostream& operator << (std::ostream& os, Matrix3& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 9; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 8))
				os << ",";
		}
		return os;
	}
	std::ostream& operator << (std::ostream& os, Matrix4& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 16; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 15))
				os << ",";
		}
		return os;
	}

#endif

static const float DEFAULT_TOLERANCE = 0.00001f;

bool compare(float a, float b, float tolerance = DEFAULT_TOLERANCE) {
	if (abs(a - b) > tolerance)
		return false;
	return true;
}

bool compare( Vector2& A,  Vector2& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = (float*)A;
	 float* b = (float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance)
		return false;
	return true;
}

bool compare( Vector3& A,  Vector3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance)
		return false;
	return true;
}

bool compare( Vector4& A,  Vector4& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance || 
		abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

bool compare( Matrix2& A,  Matrix2& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance ||
		abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

bool compare( Matrix3& A,  Matrix3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance ||
		abs(a[3] - b[3]) > tolerance || abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance ||
		abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance || abs(a[8] - b[8]) > tolerance)
		return false;
	return true;
}

bool compare( Matrix4& A,  Matrix4& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance ||
		abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance || abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance ||
		abs(a[8] - b[8]) > tolerance || abs(a[9] - b[9]) > tolerance || abs(a[10] - b[10]) > tolerance || abs(a[11] - b[11]) > tolerance ||
		abs(a[12] - b[12]) > tolerance || abs(a[13] - b[13]) > tolerance || abs(a[14] - b[14]) > tolerance || abs(a[15] - b[15]) > tolerance)
		return false;
	return true;
}

// additional compare functions
bool compare(int a, int b) {
	return a == b;
}

bool compare(bool a, bool b) {
	return a == b;
}

// end additional compare functions

template <typename T>
bool TestFunc(const char* msg, T& a, T& b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match - \n\tB: (" << b << ")\n";
		return false;
	}
	return true;
}
// needed for comparing a float variable with a const float
template <typename T>
bool TestFunc(const char* msg, T& a, float b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match -\n\tB: (" << b << ")\n";
		return false;
	}
	return true;
}

#define TEST(a, b, c) {if (TestFunc(a, b, c) == false) {return false;}}

bool runUnitTests() {

	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("Vector2 addition", v2c, Vector2(18.5f,-44.24f));
	TEST("Vector3 addition", v3c, Vector3(18.5f,-44.24f,850));
	TEST("Vector4 addition", v4c, Vector4(18.5f,-44.24f,850,1));

	// vector subtraction
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TEST("Vector2 subtraction", v2c, Vector2(8.5f,-52.22f));
	TEST("Vector3 subtraction", v3c, Vector3(8.5f,-52.22f,874));
	TEST("Vector4 subtraction", v4c, Vector4(8.5f,-52.22f,874,-1));

	// vector post-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TEST("Vector2 post-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 post-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 post-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TEST("Vector2 pre-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 pre-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 pre-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector dot product
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	TEST("Vector2 dot", dot2, -124.937698364f);
	TEST("Vector3 dot", dot3, -10468.9375f);
	TEST("Vector4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	TEST("Vector3 cross", v3c, Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	TEST("Vector4 cross", v4c, Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector magnitude
	v2a = Vector2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	v3a = Vector3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();

	TEST("Vector2 magnitude", mag2, 50.0837593079f);
	TEST("Vector3 magnitude", mag3, 863.453735352f);
	TEST("Vector4 magnitude", mag4, 863.453735352f);

	// vector normalise
	v2a = Vector2(-13.5f, -48.23f);
	v2a.normalise();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.normalise();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.normalise();

	TEST("Vector2 normalise", v2a, Vector2(-0.269548f,-0.962987f));
	TEST("Vector3 normalise", v3a, Vector3(0.0156349f,-0.0558571f,0.998316f));
	TEST("Vector4 normalise", v4a, Vector4(0.270935f,-0.0537745f,0.961094f,0));

	// matrix rotation
	Matrix2 m2;
	Matrix3 m3a, m3b, m3c, m3d;
	Matrix4 m4a, m4b, m4c, m4d;
	m2.setRotate(4.576f);
	m3a.setRotateX(3.98f);
	m4a.setRotateX(4.5f);
	m3b.setRotateY(1.76f);
	m4b.setRotateY(-2.6f);
	m3c.setRotateZ(9.62f);
	m4c.setRotateZ(0.72f);

	TEST("Matrix2 set rotate", m2, Matrix2(-0.135966f,-0.990713f,0.990713f,-0.135966f));
	TEST("Matrix3 set rotate", m3a, Matrix3(1,0,0,0,-0.668648f,-0.743579f,0,0.743579f,-0.668648f));
	TEST("Matrix3 set rotate", m3b, Matrix3(-0.188077f,0,-0.982154f,0,1,0,0.982154f,0,-0.188077f));
	TEST("Matrix3 set rotate", m3c, Matrix3(-0.981005f,-0.193984f,0,0.193984f,-0.981005f,0,0,0,1));
	TEST("Matrix4 set rotate", m4a, Matrix4(1,0,0,0,0,-0.210796f,-0.97753f,0,0,0.97753f,-0.210796f,0,0,0,0,1));
	TEST("Matrix4 set rotate", m4b, Matrix4(-0.856889f,0,0.515501f,0,0,1,0,0,-0.515501f,0,-0.856889f,0,0,0,0,1));
	TEST("Matrix4 set rotate", m4c, Matrix4(0.751806f,0.659385f,0,0,-0.659385f,0.751806f,0,0,0,0,1,0,0,0,0,1));

	// vector transform
	v2a = Vector2(13.5f, -48.23f);
	v2c = m2 * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector2 matrix transform", v2c, Vector2(-49.6176567078f, -6.81697654724f));
	TEST("Vector3 matrix transform", v3b, Vector3(844.077941895f, -48.2299995422f, -175.38130188f));
	TEST("Vector3 matrix transform", v3c, Vector3(-22.5994224548f, 44.6950683594f, 862));
	TEST("Vector4 matrix transform", v4b, Vector4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	TEST("Vector4 matrix transform", v4c, Vector4(41.951499939f, -27.3578968048f, 862, 0));

	// matrix multiply
	Matrix2 m2b, m2c;
	m2b.setRotate(-2.145f);
	m2c = m2 * m2b;
	m3d = m3a * m3c;
	m4d = m4c * m4b;

	TEST("Matrix2 multiply", m2c, Matrix2(-0.757975637913f, 0.652282953262f, -0.652282953262f, -0.757975637913f));
	TEST("Matrix3 multiply", m3d, Matrix3(-0.981004655361f, 0.129707172513f, 0.14424264431f, 0.193984255195f, 0.655946731567f, 0.729454636574f, 0, 0.743579149246f, -0.668647944927f));
	TEST("Matrix4 multiply", m4d, Matrix4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0, -0.659384667873f, 0.751805722713f, 0, 0, -0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 0, 0, 0, 1));

	// homogeneous point translation
	m3b = Matrix3(1, 0, 0,
				  0, 1, 0,
				  0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	m3c.setRotateZ(2.2f);
	m3c[2] = Vector3(55, 44, 1);
	m4b = Matrix4(1, 0, 0, 0,
				  0, 1, 0, 0,
				  0, 0, 1, 0,
				  0, 0, 0, 1);
	m4b[3] = Vector4(55, 44, 99, 1);
	m4c.setRotateZ(2.2f);
	m4c[3] = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation A", v3b, Vector3(68.5f, -4.23f, 1));
	TEST("Vector3 matrix translation B", v3c, Vector3(86.0490112305f, 83.2981109619f, 1));
	TEST("Vector4 matrix translation A", v4b, Vector4(68.5f, -4.23f, 45, 1));
	TEST("Vector4 matrix translation B", v4c, Vector4(86.0490112305f, 83.2981109619f, 45, 1));

	// homogeneous vector translation
	m3b = Matrix3(1, 0, 0,
				  0, 1, 0,
				  0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	m3c.setRotateZ(2.2f);
	m3c[2] = Vector3(55, 44, 1);
	m4b = Matrix4(1, 0, 0, 0,
				  0, 1, 0, 0,
				  0, 0, 1, 0,
				  0, 0, 0, 1);
	m4b[3] = Vector4(55, 44, 99, 1);
	m4c.setRotateZ(2.2f);
	m4c[3] = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation C", v3b, Vector3(13.5f, -48.23f, 0));
	TEST("Vector3 matrix translation D", v3c, Vector3(31.0490131378f, 39.2981109619f, 0));
	TEST("Vector4 matrix translation C", v4b, Vector4(13.5f, -48.23f, -54, 0));
	TEST("Vector4 matrix translation D", v4c, Vector4(31.0490131378f, 39.2981109619f, -54, 0));
	
	// FOLLOWING TESTS WRITTEN FOR ADDITIONAL FEATURES
	// NOT PART OF REQUIREMENTS

	std::cout << "Basic requirements passed.\n";

	bool b_true = true;
	bool b_false = false;

	//Zero vector normalization
	v2a = Vector2();
	v2b = Vector2(1, 1);
	v3a = Vector3();
	v4a = Vector4();
	bool b1 = v2a.normalise();
	bool b2 = v3a.normalise();
	bool b3 = v4a.normalise();
	bool b4 = v2b.normalise();

	TEST("Vector2 zero normalization", b1, b_false);
	TEST("Vector3 zero normalization", b2, b_false);
	TEST("Vector4 zero normalization", b3, b_false);
	TEST("Vector2 valid normalization true", b4, b_true);

	// Vector2 magnitude squared
	v2a = Vector2(3.0f, 4.0f);
	mag2 = v2a.magnitudeSquared();
	TEST("Vector2 magnitude squared", mag2, 25.0f);

	// Vector3 magnitude squared
	v3a = Vector3(2.0f, 4.0f, 3.0f);
	mag3 = v3a.magnitudeSquared();
	TEST("Vector3 magnitude squared", mag3, 29.0f);

	// Vector4 magnitude squared
	v4a = Vector4(5.0f, 4.0f, 2.0f, 3.0f);
	mag4 = v4a.magnitudeSquared();
	TEST("Vector4 magnitude squared", mag4, 54.0f);

	// Vector2 vector to vector comparison
	v2a = Vector2(3.0f, 4.0f);
	v2b = Vector2(-2.0f, 5.0f);
	v2c = Vector2(4.0f, -4.0f);

	b1 = (v2a < v2b);
	b2 = (v2b < v2a);
	b3 = (v2b > v2c);
	b4 = (v2c > v2a);

	TEST("Vector2 comparison A", b1, b_true);
	TEST("Vector2 comparison B", b2, b_false);
	TEST("Vector2 comparison C", b3, b_false);
	TEST("Vector2 comparison D", b4, b_true);

	// Vector3 vector to vector comparison
	v3a = Vector3(3.0f, 6.0f, 4.0f);
	v3b = Vector3(2.0f, 4.0f, -7.0f);
	v3c = Vector3(-8.0f, -2.0f, 1.0f);

	b1 = (v3a < v3b);
	b2 = (v3b < v3a);
	b3 = (v3b > v3c);
	bool b5 = (v3c > v3a);

	TEST("Vector3 comparison A", b1, b_true);
	TEST("Vector3 comparison B", b2, b_false);
	TEST("Vector3 comparison C", b3, b_false);
	TEST("Vector3 comparison E", b5, b_true);

	// Vector4 vector to vector comparison

	v4a = Vector4(4.0f, 3.0f, 5.0f, 3.0f);
	v4b = Vector4(-3.0f, 6.0f, 4.0f, 0.0f);
	v4c = Vector4(2.0f, 2.0f, 2.0f, -7.0f);

	b1 = (v4a < v4b);
	b2 = (v4b < v4a);
	b3 = (v4b > v4c);
	b5 = (v4c > v4a);

	TEST("Vector4 comparison A", b1, b_true);
	TEST("Vector4 comparison B", b2, b_false);
	TEST("Vector4 comparison C", b3, b_false);
	TEST("Vector4 comparison E", b5, b_true);

	// Vector2 vector equality
	v2b = Vector2(3.0f, -4.0f);
	v2c = Vector2(3.0f, 4.0f);

	b1 = v2a == v2b;
	b2 = v2a == v2c;
	b3 = v2a != v2b;

	TEST("Vector2 equality A", b1, b_false);
	TEST("Vector2 equality B", b2, b_true);
	TEST("Vector3 equality C", b3, b_true);

	// Vector3 vector equality
	v3b = Vector3(3.0f, -6.0f, 4.0f);
	v3c = Vector3(3.0f, -6.0f, 4.0f);

	b1 = v3a == v3b;
	b2 = v3b == v3c;
	b3 = v3a != v3b;

	TEST("Vector3 equality A", b1, b_false);
	TEST("Vector3 equality B", b2, b_true);
	TEST("Vector3 equality C", b3, b_true);

	// Vector4 vector equality
	v4b = Vector4(-4.0f, 3.0f, 5.0f, 3.0f);
	v4c = Vector4(-4.0f, 3.0f, 5.0f, 3.0f);

	b1 = v4a == v4b;
	b2 = v4b == v4c;
	b3 = v4a != v4b;

	TEST("Vector4 equality A", b1, b_false);
	TEST("Vector4 equality B", b2, b_true);
	TEST("Vector4 equality C", b3, b_true);

	// Vector2 float comparison

	int equal = 0;
	int greater = 1;
	int less = -1;

	int i1 = v2a.compareMagnitude(5.0f);	//0
	int i2 = v2a.compareMagnitude(7.0f);	//-1
	int i3 = v2a.compareMagnitude(3.0f);	//1


	TEST("Vector2 float comparison A", i1, equal);
	TEST("Vector2 float comparison B", i2, less);
	TEST("Vector2 float comparison C", i3, greater);

	// Vector3 float comparison

	i1 = v3a.compareMagnitude(5.0f);	//1
	i2 = v3a.compareMagnitude(8.0f);	//-1

	TEST("Vector3 float comparison A", i1, greater);
	TEST("Vector3 float comparison B", i2, less);

	// Vector4 float comparison

	i1 = v4a.compareMagnitude(5.0f);	//1
	i2 = v4a.compareMagnitude(8.0f);	//-1

	TEST("Vector4 float comparison A", i1, greater);
	TEST("Vector4 float comparison B", i2, less);

	// Vector3 casting
	//TODO more casts?
	v3a = Vector3(3.0f, 4.0f, 5.0f);
	v2a = (Vector2)v3a;
	v4a = (Vector4)v3a;
	
	TEST("Vector3 cast as Vector2", v2a, Vector2(3.0f, 4.0f));
	TEST("Vector3 cast as Vector4", v4a, Vector4(3.0f, 4.0f, 5.0f, 0.0f));

	// vector complex assignments
	v2a = { 2,4 };
	v2b = { 6,1 };
	v2c = { 3,2 };
	v2a += v2b;
	TEST("Vector2 +=", v2a, Vector2(8, 5));
	v2a -= v2c;
	TEST("Vector2 -=", v2a, Vector2(5, 3));
	v2a *= 0.5f;
	TEST("Vector2 *=", v2a, Vector2(2.5f, 1.5f));

	// Matrix set identity
	m2.setIdentity();
	m3a.setIdentity();
	m4a.setIdentity();
	TEST("Matrix2 Identity", m2, Matrix2(1, 0, 0, 1));
	TEST("Matrix3 Identity", m3a, Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1));
	TEST("Matrix4 Identity", m4a, Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));

	// Euler rotation
	// TODO better euler angle tests?
	
	m3a.setEulerRotate(0.0f,3.98f,0.0f);
	m4a.setEulerRotate (0.0f, 4.5f, 0.0f);
	m3b.setEulerRotate(1.570799f, 1.76f, -1.570799f);
	m4b.setEulerRotate(1.570799f, -2.6f, -1.570799f);
	m3c.setEulerRotate(9.62f,0.0f,0.0f);
	m4c.setEulerRotate(0.72f,0.0f,0.0f);

	TEST("Matrix3 Euler rotate X", m3a, Matrix3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f));
	TEST("Matrix3 Euler rotate Y", m3b, Matrix3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f));
	TEST("Matrix3 Euler rotate Z", m3c, Matrix3(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1));
	TEST("Matrix4 Euler rotate X", m4a, Matrix4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));
	TEST("Matrix4 Euler rotate Y", m4b, Matrix4(-0.856889f, 0, 0.515501f, 0, 0, 1, 0, 0, -0.515501f, 0, -0.856889f, 0, 0, 0, 0, 1));
	TEST("Matrix4 Euler rotate Z", m4c, Matrix4(0.751806f, 0.659385f, 0, 0, -0.659385f, 0.751806f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));

	// Tate-bryan rotation
	// TODO better tests?
	m3a.setTaitBryanRotate(0.7853981f, 0.7853981f, 0.7853981f);
	m4a.setTaitBryanRotate(0.7853981f, 0.7853981f, 0.7853981f);
	TEST("Matrix3 Tate-Bryan rotation", m3a, Matrix3(0.5f, 0.5f, -0.7071068f, -0.1464466f, 0.8535534f, 0.5f, 0.8535534f, -0.1464466f, 0.5));
	TEST("Matrix4 Tate-Bryan rotation", m4a, Matrix4(0.5f, 0.5f, -0.7071068f,0, -0.1464466f, 0.8535534f, 0.5f,0, 0.8535534f, -0.1464466f, 0.5,0,0,0,0,1));

	// Matrix inversion
	m2 = { 2, -3,5,-7 };
	m2.calculateInverse(m2b);
	TEST("Matrix2 inversion works", m2b, Matrix2(-7, 3, -5, 2));
	TEST("Matrix2 inversion doesn't change matrix", m2, Matrix2(2, -3, 5, -7));
	m3a = {0,1,4,1,0,-3,2,3,8};
	m3a.calculateInverse(m3b);
	TEST("Matrix3 inversion works", m3b, Matrix3(-4.5f,-2,1.5f,7,4,-2,-1.5f,-1,0.5f));
	TEST("Matrix3 inversion doesn't change matrix", m3a, Matrix3(0, 1, 4, 1, 0, -3, 2, 3, 8));
	// matrix4 inversion test
	m4a = { 2,0,2,0,3,4,-1,-4,3,3,-1,-3,1,-3,-3,2 };
	m4a.calculateInverse(m4b);
	TEST("Matrix4 inversion works", m4b, Matrix4(0.125f, -0.75f, 1, 0, -1, -5, 6, -1, 0.375f, 0.75f, -1, 0, -1, -6, 7, -1));
	//TODO test it fails uninvertable matrices
	m2 = { 0,4,0,3 };
	b1 = m2.calculateInverse(m2b);
	TEST("Matrix2 uninvertable matrix", b1, b_false);
	TEST("Matrix2 inversion doesn't change matrix", m2, Matrix2(0,4,0,3));

	//Undo matrix transformation
	m2.setRotate(4.576f);
	m2b.setRotate(-2.145f);
	m2c = m2 * m2b;
	m2.transformByInverse(m2c);
	TEST("Matrix2 transform by inverse", m2c, m2b);

	v2a = Vector2(13.5f, -48.23f);
	v2c = m2 * v2a;
	m2.transformByInverse(v2c);
	TEST("Matrix2 inverse on vector", v2a, v2c);
	//TODO higher order tests

	//Matrix to euler angle
	m3a.setRotateZ(1.5f);
	m3b.setRotateY(1.57079632679f);
	m3c.setRotateX(0.4f);
	m3d = m3a * m3b * m3c;
	std::tuple<float, float, float, bool> eulerAngles = m3d.getTaitBryanOrientation();
	TEST("Matrix3 getTaitBryan locked yaw", std::get<0>(eulerAngles), 1.1f);
	TEST("Matrix3 getTaitBryan locked pitch", std::get<1>(eulerAngles), 1.57079632679f);
	TEST("Matrix3 getTaitBryan locked roll", std::get<2>(eulerAngles), 0.0f);

	m3a.setRotateZ(1.5f);
	m3b.setRotateY(1.0f);
	m3c.setRotateX(0.4f);
	m3d = m3a * m3b * m3c;
	eulerAngles = m3d.getTaitBryanOrientation();
	TEST("Matrix3 getTaitBryan 1 yaw", std::get<0>(eulerAngles), 1.5f);
	TEST("Matrix3 getTaitBryan 1 pitch", std::get<1>(eulerAngles), 1.0f);
	TEST("Matrix3 getTaitBryan 1 roll", std::get<2>(eulerAngles), 0.4f);

	m3a.setRotateZ(0.4f);
	m3b.setRotateX(1.1f);
	m3c.setRotateZ(0.7f);
	m3d = m3a * m3b * m3c;
	eulerAngles = m3d.getEulerOrientation();
	TEST("Matrix3 getEuler 1 alpha", std::get<0>(eulerAngles), 0.4f);
	TEST("Matrix3 getEuler 1 beta", std::get<1>(eulerAngles), 1.1f);
	TEST("Matrix3 getEuler 1 gamma", std::get<2>(eulerAngles), 0.7f);

	m3a.setRotateZ(0.8f);
	m3b.setRotateX(3.14159265f);
	m3c.setRotateZ(0.1f);
	m3d = m3a * m3b * m3c;
	eulerAngles = m3d.getEulerOrientation();
	TEST("Matrix3 getEuler locked alpha", std::get<0>(eulerAngles), 0.7f);
	TEST("Matrix3 getEuler locked beta", std::get<1>(eulerAngles), 3.14159265f);
	TEST("Matrix3 getEuler locked gamma", std::get<2>(eulerAngles), 0.0f);

	m3a = { 1,2,0,0,1,0,0,0,1 };
	m3b = { 1,2,0,-2,1,0,0,0,INFINITY };
	eulerAngles = m3a.getEulerOrientation();
	TEST("Matrix3 getEuler non-orthonormal basis fails", std::get<3>(eulerAngles), b_false);
	eulerAngles = m3b.getEulerOrientation();
	TEST("Matrix3 getEuler normalisation fails", std::get<3>(eulerAngles), b_false);

	return true;
}