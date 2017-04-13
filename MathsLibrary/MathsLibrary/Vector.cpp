//#include <math.h>
//#include "Vector.h"

//namespace lasmath {
//	Vector::Vector()
//	{
//	}
//	Vector::~Vector()
//	{
//	}
//	bool operator>(const Vector & a, const Vector & b)
//	{
//		float aMagnitudeSquared = a.magnitudeSquared();
//		float bMagnitudeSquared = b.magnitudeSquared();
//		return aMagnitudeSquared > bMagnitudeSquared;
//	}
//	bool operator<(const Vector& a, const Vector & b)
//	{
//		// This operator should be read as "Magnitude of a is less than magnitude of b"
//		// Since the magnitudes only need to be compared, the quicker magnitudeSquared method is used
//		return b > a;
//	}
//
//	bool operator<=(const Vector& a, const Vector & b)
//	{
//		// This operator should be read as "Magnitude of a is less than or equal to magnitude of b"
//		// Note that == is defined as vectors having equal magnitude and direction
//		// So "a<b || a==b" is not the same as "a<=b", as they evaluate differently when magnitudes
//		// are equal but not direction.
//		return !(a > b);
//	}
//
//	bool operator>=(const Vector& a, const Vector & b)
//	{
//		// This operator should be read as "Magnitude of a is greater than or equal to magnitude of b"
//		// Note that == is defined as vectors having equal magnitude and direction
//		// So "a>b || a==b" is not the same as "a>=b", as they evaluate differently when magnitudes
//		// are equal but not direction.
//		return !(b > a);
//	}
//	int Vector::compareMagnitude(float f)
//	{
//		// magnitudeSquared() used to avoid calculating square roots
//		float difference = magnitudeSquared() - (f*f);
//		if (difference < 0.0) {
//			return -1;
//		} else if (difference >0.0){
//			return 1;
//		} else{
//			return 0;
//		}
//	}
//}