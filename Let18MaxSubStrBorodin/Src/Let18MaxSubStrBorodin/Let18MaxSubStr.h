#pragma once
#include "stdafx.h"
#include "Let18MaxSubStrBorodinApi.hpp"

class MaxSubStr
{
public:
	LET18MAXSUBSTRBORODIN_API MaxSubStr(std::string file1,std::string file2);
	LET18MAXSUBSTRBORODIN_API std::string FindSubStr();

	std::string _file1;
	std::string _file2;
};