#ifndef MATRIX4FX4F_H
#define MATRIX4FX4F_H

#include "Position3f.h"

class Matrix4fx4f
{
public:
	Matrix4fx4f();
	Matrix4fx4f(float(&n)[16]);
	Matrix4fx4f(float(&n)[4], float(&n1)[4], float(&n2)[4], float(&n3)[4]);

	Matrix4fx4f operator*(const Matrix4fx4f& other);
	Position3f operator*(const Position3f& other);

	float determinant();

	float values[4][4];
private:

};

#endif // MATRIX4FX4F_H
