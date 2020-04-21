#include"Fun.h"
#include"stdafx.h"
#include "math.h"
#include"limits.h"

bool Bit(int*a, int*b)
{
	if (sizeof(a) != sizeof(b))
		return 0;
	for (int i = 0; i < sizeof(unsigned int); ++i)
	{
		if (a[i] != b[i])
			return 0;
	}
		return 1;
}

char* Bit3(unsigned int a)
{
	unsigned int s = sizeof(a)*CHAR_BIT;
	char* arrd = new char[s + 1]{};
	for (int i = 0; i < s; ++i)
	{
		if ((a&(1 << i)) == 0)
			arrd[s - i - 1] = '0';
		else
			arrd[s - i - 1] = '1';
	}
	return arrd;
}

int* Byit4(unsigned int a)
{
	int n = sizeof(a);
	int *arr = new int[n] {};
	for (int i = 0; i < n; ++i)
	{
		arr[i] = (a >> (i * 8)) & 255;
	}
	return arr;
}

char* Bit5(unsigned int a)
{
	int*r = Byit4(a);
	int n = sizeof(a)*CHAR_BIT;
	char* arrd = new char[n + 1]{};
	for (int k = 0; k < sizeof(a); ++k)
	{
		for (int i = 0; i < CHAR_BIT; ++i)
		{
			if ((r[k] & (1 << i)) == 0)
				arrd[CHAR_BIT*(1 + k) - i - 1] = '0';
			else
				arrd[CHAR_BIT*(1 + k) - i - 1] = '1';
		}
	}
	delete[] Byit4(a);
	return arrd;
}

char* Bit6(unsigned int* a, int n)
{
	int s = CHAR_BIT * sizeof(unsigned int);
	char* arrd = new char[n*s + 1]{};
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < s; ++i)
		{
			if ((*a&(1 << i)) == 0)
				arrd[s*(1 + k) - i - 1] = '0';
			else
				arrd[s*(1 + k) - i - 1] = '1';
		}
		++a;
	}
	return arrd;
}