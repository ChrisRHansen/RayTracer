#include "Matrix4fx4f.h"

Matrix4fx4f::Matrix4fx4f()
{

}

Matrix4fx4f::Matrix4fx4f(float(&vals)[16])
{
	values[0][0] = vals[0];
	values[0][1] = vals[1];
	values[0][2] = vals[2];
	values[0][3] = vals[3];

	values[1][0] = vals[4];
	values[1][1] = vals[5];
	values[1][2] = vals[6];
	values[1][3] = vals[7];

	values[2][0] = vals[8];
	values[2][1] = vals[9];
	values[2][2] = vals[10];
	values[2][3] = vals[11];

	values[3][0] = vals[12];
	values[3][1] = vals[13];
	values[3][2] = vals[14];
	values[3][3] = vals[15];
}

Matrix4fx4f::Matrix4fx4f(float(&row1)[4], float(&row2)[4], float(&row3)[4], float(&row4)[4])
{
	values[0][0] = row1[0];
	values[0][1] = row1[1];
	values[0][2] = row1[2];
	values[0][3] = row1[3];

	values[1][0] = row2[0];
	values[1][1] = row2[1];
	values[1][2] = row2[2];
	values[1][3] = row2[3];

	values[2][0] = row3[0];
	values[2][1] = row3[1];
	values[2][2] = row3[2];
	values[2][3] = row3[3];

	values[3][0] = row4[0];
	values[3][1] = row4[1];
	values[3][2] = row4[2];
	values[3][3] = row4[3];
}

Matrix4fx4f Matrix4fx4f::operator*(const Matrix4fx4f& other)
{
	Matrix4fx4f matrix;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			float value = 0;

			for (int h = 0; h < 4; h++)
				value += this->values[i][h] * other.values[h][j];

			matrix.values[i][j] = value;
		}

	return matrix;
}

Position3f Matrix4fx4f::operator*(const Position3f& other)
{
	Position3f position;

	float x = 0;
	x += this->values[0][0] * other.x;
	x += this->values[0][1] * other.y;
	x += this->values[0][2] * other.z;
	x += this->values[0][3] * 1;
	position.x = x;

	float y = 0;
	y += this->values[1][0] * other.x;
	y += this->values[1][1] * other.y;
	y += this->values[1][2] * other.z;
	y += this->values[1][3] * 1;
	position.y = y;

	float z = 0;
	z += this->values[2][0] * other.x;
	z += this->values[2][1] * other.y;
	z += this->values[2][2] * other.z;
	z += this->values[2][3] * 1;
	position.z = z;

	return position;
}

float Matrix4fx4f::determinant()
{
	return 0;/*values[0][0] * (values[1][1] * values[2][2] - values[1][2] * values[2][1])
		- values[0][1] * (values[1][0] * values[2][2] - values[1][2] * values[2][0])
		- values[0][2] * (values[1][0] * values[2][1] - values[1][1] * values[2][0]);*/
}