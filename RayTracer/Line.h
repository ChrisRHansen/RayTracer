#ifndef LINE_H
#define LINE_H

#include "Position3f.h"

class Line
{
	public:
		Line();
		Line(Position3f, Position3f);

		Position3f head;
		Position3f tail;
	private:
};

#endif // LINE_H
