#ifndef BITMAPWRITER_H
#define BITMAPWRITER_H

#include "Color.h"

void SaveBitmap(int w, int h, Color** (*image));

#endif // BITMAPWRITER_H