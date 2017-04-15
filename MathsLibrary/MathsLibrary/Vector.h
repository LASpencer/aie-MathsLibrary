#pragma once
#include <math.h>

namespace lasmath {
	template<size_t DIM>
	class Vector
	{
	public:
		Vector() {
			m_component = { 0.0f };
		};

		// HACK find a more elegant method than this
		// Double check requirements, maybe initializer list/array is allowed?
#if DIM == 2
		Vector(float x, float y) {
			m_component[0] = x;
			m_component[1] = y;
		};
#elif DIM == 3
		Vector(float x, float y, float z) {
			m_component[0] = x;
			m_component[1] = y;
			m_component[2] = z;
		};
#elif DIM == 4
		Vector(float x, float y, float z, float w) {
			m_component[0] = x;
			m_component[1] = y;
			m_component[2] = z;
			m_component[3] = w;
		};
#endif

		~Vector()
		{};

		// return reference to vector component
		float& operator[](size_t n) {
			//TODO throw exception if n>1
			return m_component[n];
		};
		const float& operator[](size_t n) const {
			//TODO throw exception if n>1
			return m_component[n];
		};

		// cast vector as array of floats
		explicit operator float*() {
			// Return array of components
			return m_component;
		};

		//// cast as Vector3 with z = 0
		//explicit operator Vector3();

		//// cast as Vector4 with z=0 and w=0;
		//explicit operator Vector4();

		// Dot multiplication of two vectors
		float dot(const Vector<DIM>& b) const {
			float product = 0.0f;
			// Iterate over corresponding components, multiplying them and adding to total
			for (size_t i = 0; i < DIM; ++i) {
				product += m_component[i] * b[i];
			}
			return product;
		};

#if DIM == 3
		// Cross multiplication of two vectors
		Vector<3> cross(const Vector<3>& b) const {
			Vector<3> product;
			product[0] = m_component[1] * b[2] - m_component[2] * b[1];
			product[1] = m_component[2] * b[0] - m_component[0] * b[2];
			product[2] = m_component[0] * b[1] - m_component[1] * b[0];
			return product;
		};
#elif DIM == 4
		// Cross multiplication of two vectors
		Vector<4> cross(const Vector<4>& b) const {
			Vector<4> product;
			product[0] = m_component[1] * b[2] - m_component[2] * b[1];
			product[1] = m_component[2] * b[0] - m_component[0] * b[2];
			product[2] = m_component[0] * b[1] - m_component[1] * b[0];
			product[3] = 0.0f;
			return product;
	};
#endif

		// Returns square of vector's magnitude
		float magnitudeSquared() const {
			// Square of magnitude is quicker to calculate than magnitude and is
			// useful when magnitude only needs to be compared to a value
			float magSquared = 0.0f;
			for (size_t i = 0; i < DIM; ++i) {
				magSquared += m_component[i] * m_component[i];
			}
			return magSquared;
		};

		// Returns magnitude of vector
		float magnitude() const {
			// Calculate magnitude through pythagoras equation
			// Take square root of sum of components squared
			return sqrtf(magnitudeSquared());
		};

		// Converts vector to a unit vector with same direction
		void normalise() {
		// Divide all components by magnitude
			float magReciprocal = 1.0f / magnitude();
			for (size_t i = 0; i < DIM; ++i) {
				m_component[i] *= magReciprocal;
			}
		};

		/* Compares magnitude of vector to value given.
		Returns 0 if equal, -1 if vector magnitude is lower, 1 if vector magnitude is greater
		*/
		int compareMagnitude(float f) const{
			float difference = magnitudeSquared() - (f*f);
			if (difference < 0.0) {
				return -1;
			}
			else if (difference >0.0) {
				return 1;
			}
			else {
				return 0;
			}
		};

		// Arithmetic operators

		Vector<DIM> operator+(const Vector<DIM>& a, const Vector<DIM>& b);
		Vector<DIM> operator-(const Vector<DIM>& a, const Vector<DIM>& b);
		Vector<DIM> operator*(const Vector<DIM>& v, float f);
		Vector<DIM> operator*(float f, const Vector<DIM>& v);

		// Compare magnitudes of vectors
		bool operator>(const Vector<DIM>& a, const Vector<DIM>& b);
		bool operator<(const Vector<DIM>& a, const Vector<DIM>& b);
		bool operator>=(const Vector<DIM>& a, const Vector<DIM>& b);
		bool operator<=(const Vector<DIM>& a, const Vector<DIM>& b);

		// Vectors are equal if all components are equal
		bool operator==(const Vector<DIM>& a, const Vector<DIM>& b);
		bool operator!=(const Vector<DIM>& a, const Vector<DIM>& b);

	protected:
		float m_component[DIM];
	};

}