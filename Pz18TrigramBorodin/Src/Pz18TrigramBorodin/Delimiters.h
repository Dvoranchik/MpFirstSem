#pragma once
#include "stdafx.h"
#include "Pz18TrigramBorodinApi.hpp"

struct Delimiters
{
	PZ18TRIGRAMBORODIN_API Delimiters();
	PZ18TRIGRAMBORODIN_API bool IsSings(const char& elem) const;

	bool _table[256]{};
};
