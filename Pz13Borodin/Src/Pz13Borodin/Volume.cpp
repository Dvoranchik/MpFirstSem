#include "stdafx.h"
#include "Volume.h"

bool Volume::operator()(int data, int value)
{
	return data==value;
}

bool Volume::operator()(double data, double value)
{
	return abs(data)==abs(value);
}

bool Volume::operator()(Triangle& ob, int sought)
{
	return ob.Volume()==sought;
}
