#ifndef GRAPHICS
#define GRAPHICS

#include "BitmapWriter.h"
#include "Color.h"
#include "Line.h"
#include "Matrix4fx4f.h"
#include "Position3f.h"
#include "Ray.h"
#include "RayTestResult.h"
#include "SceneSurface.h"
#include "Sphere.h"
#include "Transform.h"
#include "Triangle.h"
#include "Vector3f.h"

#include <math.h>

#include <stdio.h>
#include <stdlib.h>

#include <fstream>

namespace ParallelRayTracer
{
	void Run();
}

namespace PerspectiveRayTracer
{
	void Run();
}

namespace Lambertian
{
	void Run();
}

namespace LambertianBlinn_Phong
{
	void Run();
}

namespace OrthographicViewing
{
	void Run();
}

namespace PerspectiveViewing
{
	void Run();
}

#endif // GRAPHICS
