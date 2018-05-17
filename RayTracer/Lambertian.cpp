#include "Graphics.h"

void Lambertian::Run()
{
	int numPixX = 800;
	int numPixY = 600;
	int left = -(numPixX / 2);
	int right = (numPixX / 2);
	int top = -(numPixY / 2);
	int bottom = (numPixY / 2);

	float focal_length = (float)((numPixX / 2.0f) / tan((double)45 / 2));

	Sphere* sphere = new Sphere(Position3f(1, 1, -8), 1.0f, Color(255, 0, 0));
	Sphere* sphere2 = new Sphere(Position3f(-1.5, -1, -6), 1.0f, Color(0, 255, 0));
	Triangle* triangle1 = new Triangle(Position3f(20, 5, 20),
										Position3f(0, 5, 50),
										Position3f(20, 5, 50), Color(0, 0, 255));

	SceneSurface* objects[] = {
		sphere
		, sphere2
		//, triangle1
	};

	Position3f light(-3, 3, 0);
	float intensity = 1.0f;

	Vector3f u(1, 0, 0);
	Vector3f v(0, 1, 0);
	Vector3f w(0, 0, 1);

	Transform eye(u, v, w);

	Color **image = new Color*[numPixY];
	for (int i = 0; i < numPixY; i++)
		image[i] = new Color[numPixX];

	// Main Loop
	auto origin = Position3f(0, 0, 0);
	for (int i = 0; i < numPixX; i++)
	{
		for (int j = 0; j < numPixY; j++)
		{
			for (SceneSurface* object : objects)
			{
				float imgPlane_u = left + (right - left) * (i + 0.5f) / numPixX;
				float imgPlane_v = bottom + (top - bottom) * (j + 0.5f) / numPixY;

				Vector3f direction = (w.negated() * focal_length) + (u * imgPlane_u) + (v * imgPlane_v);

				Ray viewingRay(origin, eye, direction);

				RayTestResult testResult = object->TestViewRay(viewingRay);

				if (testResult.m_bRayHit)
				{
					Position3f hitPoint = (origin + (direction * testResult.m_fDist));

					Vector3f light_direction = (light - hitPoint).normalized();
					Vector3f view_direction = direction.negated().normalized();
					Vector3f surface_normal = object->GetNormalAt(hitPoint);

					image[j][i] = object->color * intensity * fmax(0, surface_normal * light_direction);
				}
			}
		}
	}

	SaveBitmap(numPixX, numPixY, &image);
	//delete[] objects;
	delete[] image;
}