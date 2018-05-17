#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Matrix3fx3f.h"
#include "Position3f.h"
#include "SceneSurface.h"
#include "Ray.h"
#include "RayTestResult.h"

class Triangle : public SceneSurface
{
	public:
		Triangle();
		Triangle(Position3f, Position3f, Position3f, Color);

		RayTestResult TestViewRay(Ray&) override;
		Vector3f GetNormalAt(Position3f&) override;

		Position3f a;
		Position3f b;
		Position3f c;
	private:
};

#endif // TRIANGLE_H
