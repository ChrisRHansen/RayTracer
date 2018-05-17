#ifndef COLOR_H
#define COLOR_H

class Color
{
	public:
		Color();
		Color(unsigned char, unsigned char, unsigned char);

		Color operator+(const Color&);

		Color operator*(const float&);

		unsigned char red;
		unsigned char green;
		unsigned char blue;
	private:
};

#endif // !COLOR_H