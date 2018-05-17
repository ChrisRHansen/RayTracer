#include "Matrix3fx3f.h"

Matrix3fx3f::Matrix3fx3f()
{

}

Matrix3fx3f::Matrix3fx3f(float (&vals)[9])
{
	values[0][0] = vals[0];
	values[0][1] = vals[1];
	values[0][2] = vals[2];

	values[1][0] = vals[3];
	values[1][1] = vals[4];
	values[1][2] = vals[5];

	values[2][0] = vals[6];
	values[2][1] = vals[7];
	values[2][2] = vals[8];
}

Matrix3fx3f::Matrix3fx3f(float (&row1)[3], float (&row2)[3], float (&row3)[3])
{
	values[0][0] = row1[0];
	values[0][1] = row1[1];
	values[0][2] = row1[2];

	values[1][0] = row2[0];
	values[1][1] = row2[1];
	values[1][2] = row2[2];

	values[2][0] = row3[0];
	values[2][1] = row3[1];
	values[2][2] = row3[2];
}

float Matrix3fx3f::determinant()
{
	return values[0][0] * (values[1][1] * values[2][2] - values[1][2] * values[2][1])
		 - values[0][1] * (values[1][0] * values[2][2] - values[1][2] * values[2][0])
		 - values[0][2] * (values[1][0] * values[2][1] - values[1][1] * values[2][0]);
}