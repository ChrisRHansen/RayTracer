#include "Color.h"

Color::Color()
{
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	red = r;
	green = g;
	blue = b;
}

Color Color::operator+(const Color& other)
{
	return Color((this->red + other.red) / 2.0f, (this->green + other.green) / 2.0f, (this->blue + other.blue) / 2.0f);
}

Color Color::operator*(const float& value)
{
	return Color(this->red * value, this->green * value, this->blue * value);
}