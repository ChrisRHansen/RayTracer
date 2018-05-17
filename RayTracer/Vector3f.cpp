#include "Vector3f.h"

Vector3f::Vector3f()
{
    x = 1.0f;
    y = 1.0f;
    z = 1.0f;
}

Vector3f::Vector3f(float pX, float pY, float pZ)
{
    x = pX;
    y = pY;
    z = pZ;
}

Vector3f Vector3f::operator+(const Vector3f& other)
{
    Vector3f vector;

    vector.x = this->x + other.x;
    vector.y = this->y + other.y;
    vector.z = this->z + other.z;

    return vector;
}

Vector3f Vector3f::operator-(const Vector3f& other)
{
    Vector3f vector;

    vector.x = this->x - other.x;
    vector.y = this->y - other.y;
    vector.z = this->z - other.z;
    
    return vector;
}

Vector3f Vector3f::operator+(const float& value)
{
    Vector3f vector;

    vector.x = this->x + value;
    vector.y = this->y + value;
    vector.z = this->z + value;

    return vector;
}

Vector3f Vector3f::operator-(const float& value)
{
    Vector3f vector;

    vector.x = this->x - value;
    vector.y = this->y - value;
    vector.z = this->z - value;

    return vector;
}

Vector3f Vector3f::operator+(const Position3f& other)
{
    Vector3f vector;

    vector.x = this->x + other.x;
    vector.y = this->y + other.y;
    vector.z = this->z + other.z;

    return vector;
}

Vector3f Vector3f::operator-(const Position3f& other)
{
    Vector3f vector;

    vector.x = this->x - other.x;
    vector.y = this->y - other.y;
    vector.z = this->z - other.z;

    return vector;
}

Vector3f Vector3f::operator*(const float& value)
{
    Vector3f vector;

    vector.x = this->x * value;
    vector.y = this->y * value;
    vector.z = this->z * value;

    return vector;
}

Vector3f Vector3f::operator/(const float& value)
{
    Vector3f vector;

    vector.x = this->x / value;
    vector.y = this->y / value;
    vector.z = this->z / value;

    return vector;
}

float Vector3f::operator*(const Vector3f& other)
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

float Vector3f::operator*(const Position3f& other)
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

float Vector3f::DotProduct(const Vector3f& other)
{ 
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3f Vector3f::CrossProduct(const Vector3f& other)
{
    Vector3f vector;

    vector.x = this->y * other.z - this->z * other.y;
    vector.y = this->z * other.x - this->x * other.z;
    vector.z = this->x * other.y - this->y * other.x;

    return vector;
}

Vector3f Vector3f::negated()
{
    return Vector3f(-x, -y, -z);
}

Vector3f Vector3f::normalized()
{
    Vector3f vector;

    float mag = magnitude();

    vector.x = this->x / mag;
    vector.y = this->y / mag;
    vector.z = this->z / mag;

    return vector;
}

float Vector3f::angleBetween(const Vector3f& other)
{
    return this->DotProduct(other) / (magnitude() * other.magnitude());
}

float Vector3f::magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}