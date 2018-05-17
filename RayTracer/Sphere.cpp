#include "Sphere.h"

Sphere::Sphere()
{
	position;
	radius = 1.0f;
}

Sphere::Sphere(Position3f pPos, float pRad, Color pCol)
{
	position = pPos;
	radius = pRad;
	color = pCol;
}

RayTestResult Sphere::TestViewRay(Ray &viewRay)
{
	RayTestResult result;

	result.m_bRayHit = false;

	Position3f &c = position;
	float r = radius;
	Vector3f &d = viewRay.getDirection();
	Position3f &e = viewRay.getPosition();

	Vector3f neg_d = d.negated();

	Vector3f e_min_c = (e - c);
	float part = d*(e_min_c);
	float part2 = d * d;
	float discriminant = ((part * part) - (part2) * ((e_min_c * e_min_c) - (r * r)));

	if (discriminant > 0)
	{
		float t_add = ((neg_d * (e_min_c)) + sqrt(discriminant)) / (part2);
		float t_sub = ((neg_d * (e_min_c)) - sqrt(discriminant)) / (part2);

		float t = fmin(t_add, t_sub);

		if (t > 0)
		{
			result.m_iNumberOfSolutions = 2;
			result.m_bRayHit = true;
			result.m_fDist = t;
		}
	}
	else if (discriminant == 0)
	{
		float t_add = (neg_d * (e_min_c) + sqrt(discriminant)) / (part2);
		float t_sub = (neg_d * (e_min_c) - sqrt(discriminant)) / (part2);

		float t = fmin(t_add, t_sub);

		if (t > 0)
		{
			result.m_iNumberOfSolutions = 1;
			result.m_bRayHit = true;
			result.m_fDist = t;
		}
	}

	return result;
}

Vector3f Sphere::GetNormalAt(Position3f &surface)
{
	return (surface - position).normalized();
}