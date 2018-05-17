#include "Graphics.h"

void OrthographicViewing::Run()
{
	int numPixX = 800;
	int numPixY = 600;
	int left = -(numPixX / 2);
	int right = (numPixX / 2);
	int top = (numPixY / 2);
	int bottom = -(numPixY / 2);
	int near = -10;
	int far = -30;

	Line* lines[] = {
		//new Line(Position3f(-100.0f, 0.0f, -18.0f), Position3f(100.0f, 0.0f, -18.0f))
		new Line(Position3f(0.0f, 0.0f, -18.0f), Position3f(0.0f, 0.0f, -18.0f))
	};

	Color **image = new Color*[numPixY];
	for (int i = 0; i < numPixY; i++)
		image[i] = new Color[numPixX];

	////// View Port Projection Matrix ////////////////////////////////////
	float Mvp_Values[16] = { numPixX / 2.0f, 0, 0, (numPixX - 1) / 2.0f, //
							 0, numPixY / 2.0f, 0, (numPixY - 1) / 2.0f, //
							 0, 0, 1, 0,								 //
							 0, 0, 0, 1 };								 //
	Matrix4fx4f Mvp = Matrix4fx4f(Mvp_Values);							 //
	///////////////////////////////////////////////////////////////////////

	////// Orthographic Projection Matrix /////////////////////////////////////////////////////////////////
	float Morth_Values[16] = { 2 / ((float)right - left), 0, 0, -((float)right + left) / (right - left), //
		0, 2 / ((float)top - bottom), 0, -((float)top + bottom) / (top - bottom),						 //
		0, 0, 2 / ((float)near - far), -((float)near + far) / (near - far),								 //
		0, 0, 0, 1 };																					 //
	Matrix4fx4f Morth = Matrix4fx4f(Morth_Values);														 //
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	Matrix4fx4f M = Mvp * Morth;

	// Main Loop
	for (Line* l : lines)
	{
		Position3f p = M * l->head;
		Position3f q = M * l->tail;
				
		image[(int)p.x][(int)p.y] = Color(255, 255, 255);
		image[(int)q.x][(int)q.y] = Color(255, 255, 255);
	}

	SaveBitmap(numPixX, numPixY, &image);
	//delete[] objects;
	delete[] image;
}