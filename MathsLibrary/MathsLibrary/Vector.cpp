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
}