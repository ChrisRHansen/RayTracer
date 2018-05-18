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
		// Fore-square
		new Line(Position3f(-50.0f, -50.0f, -18.0f), Position3f(-50.0f, 50.0f, -18.0f))
		, new Line(Position3f(-50.0f, 50.0f, -18.0f), Position3f(50.0f, 50.0f, -18.0f))
		, new Line(Position3f(50.0f, -50.0f, -18.0f), Position3f(50.0f, 50.0f, -18.0f))
		, new Line(Position3f(-50.0f, -50.0f, -18.0f), Position3f(50.0f, -50.0f, -18.0f))

		// Rear-square
		, new Line(Position3f(-20.0f, -20.0f, -36.0f), Position3f(-20.0f, 80.0f, -36.0f))
		, new Line(Position3f(-20.0f, 80.0f, -36.0f), Position3f(80.0f, 80.0f, -36.0f))
		, new Line(Position3f(80.0f, -20.0f, -36.0f), Position3f(80.0f, 80.0f, -36.0f))
		, new Line(Position3f(-20.0f, -20.0f, -36.0f), Position3f(80.0f, -20.0f, -36.0f))

		// Connecting lines
		, new Line(Position3f(-50.0f, -50.0f, -18.0f), Position3f(-20.0f, -20.0f, -36.0f))
		, new Line(Position3f(-50.0f, 50.0f, -18.0f), Position3f(-20.0f, 80.0f, -36.0f))
		, new Line(Position3f(50.0f, -50.0f, -18.0f), Position3f(80.0f, -20.0f, -36.0f))
		, new Line(Position3f(-50.0f, -50.0f, -18.0f), Position3f(-20.0f, -20.0f, -36.0f))
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

	////// Transformation Matrix //
	Matrix4fx4f M = Mvp * Morth; //
	///////////////////////////////

	// Main Loop
	for (Line* l : lines)
	{
		Graphics::DrawLine(l, M, image);
	}

	SaveBitmap(numPixX, numPixY, &image);
	//delete[] objects;
	delete[] image;
}