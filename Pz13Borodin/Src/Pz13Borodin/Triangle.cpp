#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle(int side, int height):_side(side),_height(height){}

int Triangle::Volume()
{
	return _side*_side*_height/6;
}

bool Triangle::operator==(const Triangle& other) const 
{
	return (_side==other._side)&&(_height==other._height);
}

std::ostream & operator<<(std::ostream& stream, Triangle& other)
{
	stream << other._side <<" "<< other._height << std::endl;
	return stream;
}
