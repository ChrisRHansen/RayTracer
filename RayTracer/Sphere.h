#ifndef SPHERE_H
#define SPHERE_H

#include "Color.h"
#include "Position3f.h"
#include "Ray.h"
#include "RayTestResult.h"
#include "Vector3f.h"
#include "SceneSurface.h"

#include <math.h>

class Sphere : public SceneSurface
{
	public:
		Sphere();
		Sphere(Position3f, float, Color);

		RayTestResult TestViewRay(Ray&) override;
		Vector3f GetNormalAt(Position3f&) override;

		Position3f position;
		float radius;
		//Color color;
	private:
};

#endif // SPHERE_H