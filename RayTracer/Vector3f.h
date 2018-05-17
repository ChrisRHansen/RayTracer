#ifndef VECTOR3F_H
#define VECTOR3F_H

#include "Position3f.h"
#include "Vector3f.h"

#include <math.h>

class Position3f;

class Vector3f
{
	public:
		Vector3f();
		Vector3f(float, float, float);

		Vector3f operator+(const Vector3f&);
		Vector3f operator-(const Vector3f&);
		Vector3f operator+(const float&);
		Vector3f operator-(const float&);

		Vector3f operator+(const Position3f&);
		Vector3f operator-(const Position3f&);
		Vector3f operator*(const float&);
		Vector3f operator/(const float&);

		float operator*(const Vector3f&);
		float operator*(const Position3f&);

		float DotProduct(const Vector3f&);
		Vector3f CrossProduct(const Vector3f&);

		Vector3f negated();
		Vector3f normalized();

		float angleBetween(const Vector3f&);

		float magnitude() const;

		float x;
		float y;
		float z;
	private:
};

#endif // VECTOR3F_H