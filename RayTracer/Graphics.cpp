#include "Graphics.h"

void Graphics::DrawLine(Line* l, Matrix4fx4f& M, Color** image)
{
	Position3f p = M * l->head;
	Position3f q = M * l->tail;

	if (q.x < p.x)
	{
		Position3f& temp = p;
		p = q;
		q = temp;
	}

	float m = ((float)q.y - p.y) / ((float)q.x - p.x);

	// if this line is running more than it is rising...
	if ((m > 0 && m <= 1) || (m > -1 && m <= 0))
	{
		int y = p.y;
		for (int x = p.x; x < q.x; x++)
		{
			image[x][y] = Color(255, 255, 255);

			float midPointCondition = (p.y - q.y) * x + (q.x - p.x) * (y + 0.5f) + p.x * q.y - q.x * p.y;
			/* A more efficient form of this is available using an incremental method.
				* Page 165 */

			if (midPointCondition < 0)
				y += 1;
		}
	}
	// otherwise it is rising more than it is running
	else
	{
		int x = p.x;
		for (int y = p.y; y < q.y; y++)
		{
			image[x][y] = Color(255, 255, 255);

			float midPointCondition = (p.y - q.y) * x + (q.x - p.x) * (y + 0.5f) + p.x * q.y - q.x * p.y;

			if (midPointCondition < 0)
				x += 1;
		}
	}
}