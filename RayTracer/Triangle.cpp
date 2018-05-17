#include "Triangle.h"

Triangle::Triangle()
{
	a = Position3f(0, 0, 0);
	b = Position3f(0, 0, 0);
	c = Position3f(0, 0, 0);
}

Triangle::Triangle(Position3f pA, Position3f pB, Position3f pC, Color pColor)
{
	a = pA;
	b = pB;
	c = pC;
	color = pColor;
}

RayTestResult Triangle::TestViewRay(Ray &viewRay)
{
	RayTestResult result;

	Vector3f &d = viewRay.getDirection();
	Position3f &e = viewRay.getPosition();

	//////////////////////////////////////////////////////////
	float Avalues[9] = {a.x - b.x, a.x - c.x, d.x,			//
						a.y - b.y, a.y - c.y, d.y,			//
						a.z - b.z, a.z - c.z, d.z};			//
	Matrix3fx3f A(Avalues);									//
	//////////////////////////////////////////////////////////
	float Bvalues[9] = {a.x - e.x, a.x - c.x, d.x,			//
						a.y - e.y, a.y - c.y, d.y,			//
						a.z - e.z, a.z - c.z, d.z};			//
	Matrix3fx3f B(Bvalues);									//
	//////////////////////////////////////////////////////////
	float Gvalues[9] = {a.x - b.x, a.x - e.x, d.x,			//
						a.y - b.y, a.y - e.y, d.y,			//
						a.z - b.z, a.z - e.z, d.z};			//
	Matrix3fx3f G(Gvalues);									//
	//////////////////////////////////////////////////////////
	float Tvalues[9] = {a.x - b.x, a.x - c.x, a.x - e.x,	//
						a.y - b.y, a.y - c.y, a.y - e.y,	//
						a.z - b.z, a.z - c.z, a.z - e.z};	//
	Matrix3fx3f T(Tvalues);									//
	//////////////////////////////////////////////////////////

	float A_Det = A.determinant();
	float B_Det = B.determinant();
	float G_Det = G.determinant();
	float T_Det = T.determinant();

	float beta = B_Det / A_Det;
	float gamma = G_Det / A_Det;

	if (beta > 0 && gamma > 0 && beta + gamma < 1)
	{
		float t = T_Det / A_Det;

		result.m_iNumberOfSolutions = 1;
		result.m_bRayHit = true;
		result.m_fDist = t;
	}
	else
	{
		result.m_bRayHit = false;
	}

	return result;
}

Vector3f Triangle::GetNormalAt(Position3f &surface)
{
	Vector3f cross_product;

	Vector3f vec1(b.x - a.x, b.y - a.y, b.z - a.z);
	Vector3f vec2(c.x - b.x, c.y - b.y, c.z - b.z);

	cross_product.x = vec1.y * vec2.z - vec1.z * vec2.y;
	cross_product.y = vec1.z * vec2.x - vec1.x * vec2.z;
	cross_product.z = vec1.x * vec2.y - vec1.y * vec2.x;

	return cross_product.normalized();
}