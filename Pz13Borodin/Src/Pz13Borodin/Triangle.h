#pragma once
#include "stdafx.h"
#include "Pz13BorodinApi.hpp"
class Triangle
{
public:
	PZ13BORODIN_API Triangle() {}
	PZ13BORODIN_API Triangle(int side,int height);
	PZ13BORODIN_API int Volume();
	PZ13BORODIN_API bool operator==(const Triangle& other)const ;
	PZ13BORODIN_API friend std::ostream& operator<<(std::ostream& stream, Triangle& other);

private:
	int _side;
	int _height;
};