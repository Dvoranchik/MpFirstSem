#pragma once
#include "stdafx.h"
#include "Triangle.h"
#include "Pz13BorodinApi.hpp"
class Volume
{
public:
	PZ13BORODIN_API bool operator()(int data, int value);
	PZ13BORODIN_API bool operator()(double data, double value);
	PZ13BORODIN_API bool operator()(Triangle& ob,int sought );
private:
};