#include "Transform.h"

Transform::Transform()
{
	u;
	v;
	w;
}

Transform::Transform(Vector3f pU, Vector3f pV, Vector3f pW)
{
	u = pU;
	v = pV;
	w = pW;
}