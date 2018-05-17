#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "RayTestResult.h"
#include "Vector3f.h"

class Transform
{
	public:
		Transform();
		Transform(Vector3f, Vector3f, Vector3f);

		Vector3f u;
		Vector3f v;
		Vector3f w;
	private:
};

#endif // TRANSFORM_H