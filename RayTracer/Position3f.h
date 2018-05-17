#ifndef POSITION3F_H
#define POSITION3F_H

#include "Vector3f.h"

class Vector3f;

class Position3f
{
	public:
		Position3f();
		Position3f(float, float, float);

		Position3f operator+(const Position3f&);
		Vector3f operator-(const Position3f&);
		Position3f operator+(const Vector3f&);

		Position3f operator*(const float&);

		float operator*(const Position3f&);

		Vector3f toVector();
		Position3f negated();

		float x;
		float y;
		float z;
	private:
};

#endif // POSITION3F_H
