#include "Ray.h"

Ray::Ray()
{
	direction;
	position;
}

Ray::Ray(Position3f pPos, Transform pTrans, Vector3f pVec)
{
	position = pPos;
	coordinateTransform = pTrans;
	direction = pVec;
}

Position3f Ray::getPosition()
{
	return position;
}

Transform Ray::getCoordTransform()
{
	return coordinateTransform;
}

Vector3f Ray::getDirection()
{
	return direction;
}