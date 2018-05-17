#include "Line.h"

Line::Line()
{

}

Line::Line(Position3f head, Position3f tail)
{
	this->head = head;
	this->tail = tail;
}