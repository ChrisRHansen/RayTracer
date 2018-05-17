#ifndef RAY3F_H
#define RAY3F_H

#include "Position3f.h"
#include "Transform.h"
#include "Vector3f.h"

class Ray
{
	public:
		Ray();
		Ray(Position3f, Transform, Vector3f);

		Position3f getPosition();
		Transform getCoordTransform();
		Vector3f getDirection();
	private:
		Position3f position;
		Transform coordinateTransform;
		Vector3f direction;
};

#endif // RAY3F_H