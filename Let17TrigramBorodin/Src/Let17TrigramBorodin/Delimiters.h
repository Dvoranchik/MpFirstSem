#pragma once
#include "stdafx.h"
#include "Let17TrigramBorodinApi.hpp"
struct Delimiters
{
	LET17TRIGRAMBORODIN_API Delimiters();
	LET17TRIGRAMBORODIN_API bool IsSings(const char& elem) const;
	
	bool _table[256]{};
};
