#include <math.h>
#include "Vector.h"

namespace lasmath {
	Vector::Vector()
	{
	}
	Vector::~Vector()
	{
	}
	bool operator>(const Vector & a, const Vector & b)
	{
		float aMagnitudeSquared = a.magnitudeSquared();
		float bMagnitudeSquared = b.magnitudeSquared();
		return aMagnitudeSquared > bMagnitudeSquared;
	}
	bool operator<(const Vector& a, const Vector & b)
	{
		// This operator should be read as "Magnitude of a is less than magnitude of b"
		// Since the magnitudes only need to be compared, the quicker magnitudeSquared method is used
		return b > a;
	}

	bool operator<=(const Vector& a, const Vector & b)
	{
		// This operator should be read as "Magnitude of a is less than or equal to magnitude of b"
		// Note that == is defined as vectors having equal magnitude and direction
		// So "a<b || a==b" is not the same as "a<=b", as they evaluate differently when magnitudes
		// are equal but not direction.
		return !(a > b);
	}

	bool operator>(const Vector & v, float f)
	{
		// This operator should be read as "Magnitude of v is greater than |f|"
		float magSquared = v.magnitudeSquared();
		float numberSquared = f * f;
		return (magSquared > numberSquared);
	}

	bool operator>(float f, const Vector & v)
	{
		// This operator should be read as "|f| is greater than the magnitude of v"
		float magSquared = v.magnitudeSquared();
		float numberSquared = f * f;
		return (numberSquared > magSquared);
	}

	bool operator<(const Vector & v, float f)
	{
		// This operator should be read as "Magnitude of v is less than |f|"
		return f > v;
	}

	bool operator<(float f, const Vector & v)
	{
		// This operator should be read as "|f| is less than the magnitude of v"
		return v > f;
	}

	bool operator>=(const Vector & v, float f)
	{
		// This operator should be read as "Magnitude of v is greater than or equal to |f|"
		// A vector cannot be equal to a float
		return !(f > v);
	}

	bool operator>=(float f, const Vector & v)
	{
		// This operator should be read as "|f| is greater than or equal to the magnitude of v"
		// A vector cannot be equal to a float
		return !(v > f);
	}

	bool operator<=(const Vector & v, float f)
	{
		return !(v > f);
	}

	bool operator<=(float f, const Vector & v)
	{
		return !(f > v);
	}

	bool operator>=(const Vector& a, const Vector & b)
	{
		// This operator should be read as "Magnitude of a is greater than or equal to magnitude of b"
		// Note that == is defined as vectors having equal magnitude and direction
		// So "a>b || a==b" is not the same as "a>=b", as they evaluate differently when magnitudes
		// are equal but not direction.
		return !(b > a);
	}
	int Vector::compareMagnitude(float f)
	{
		// magnitudeSquared() used to avoid calculating square roots
		float difference = magnitudeSquared() - (f*f);
		if (difference < 0.0) {
			return -1;
		} else if (difference >0.0){
			return 1;
		} else{
			return 0;
		}
	}
}