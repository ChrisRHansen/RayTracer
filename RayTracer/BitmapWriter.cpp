#include "BitmapWriter.h"

#include <fstream>
#include <png++\png.hpp>

void SaveBitmap(int w, int h, Color** (*image))
{
	png::image<png::rgb_pixel> png(w, h);

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
		{
			png[j][i] = png::rgb_pixel((*image)[j][i].red, (*image)[j][i].green, (*image)[j][i].blue);
		}

	png.write("images\\image.png");
}