
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

struct Entrant
{
	wchar_t Name[30];
	wchar_t Phone[10];
	int Estimates[4];
};