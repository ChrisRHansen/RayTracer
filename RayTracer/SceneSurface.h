#ifndef SCENESURFACE_H
#define SCENESURFACE_H

#include "Color.h"
#include "Ray.h"
#include "RayTestResult.h"
#include "Vector3f.h"

class SceneSurface
{
	public:
		virtual RayTestResult TestViewRay(Ray&) { return RayTestResult(); }
		virtual Vector3f GetNormalAt(Position3f&) { return Vector3f(); }

		Color color;
	private:
};

#endif // SCENESURFACE_H
