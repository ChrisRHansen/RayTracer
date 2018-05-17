#ifndef MATRIX3FX3F_H
#define MATRIX3FX3F_H

class Matrix3fx3f
{
	public:
		Matrix3fx3f();
		Matrix3fx3f(float (&n)[9]);
		Matrix3fx3f(float (&n)[3], float(&n1)[3], float(&n2)[3]);

		float determinant();

		float values[3][3];
	private:

};

#endif // MATRIX3FX3F_H
