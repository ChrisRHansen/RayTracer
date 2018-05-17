#include "Position3f.h"

Position3f::Position3f()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Position3f::Position3f(float pX, float pY, float pZ)
{
	x = pX;
	y = pY;
	z = pZ;
}

Position3f Position3f::operator+(const Position3f& other)
{
	Position3f position;

	position.x = this->x + other.x;
	position.y = this->y + other.y;
	position.z = this->z + other.z;

	return position;
}

Vector3f Position3f::operator-(const Position3f& other)
{
	Vector3f vector;

	vector.x = this->x - other.x;
	vector.y = this->y - other.y;
	vector.z = this->z - other.z;

	return vector;
}

Position3f Position3f::operator+(const Vector3f& other)
{
	Position3f position;

	position.x = this->x + other.x;
	position.y = this->y + other.y;
	position.z = this->z + other.z;

	return position;
}

Position3f Position3f::operator*(const float& value)
{
	Position3f position;

	position.x = this->x * value;
	position.y = this->y * value;
	position.z = this->z * value;

	return position;
}

float Position3f::operator*(const Position3f& other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3f Position3f::toVector()
{
	return Vector3f(x, y, z);
}

Position3f Position3f::negated()
{
	return Position3f(-x, -y, -z);
}