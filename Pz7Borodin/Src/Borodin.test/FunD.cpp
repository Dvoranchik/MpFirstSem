#include "stdafx.h"
#include "Header.h"

#define RAND_MAX 0x7fff
int *RandArray(size_t size, int a, int b)
{
	int *arr = new int[size];

	srand((unsigned int)time(NULL));

	for (size_t i = 0; i < size; ++i)
		arr[i] = (b - a)*rand() / RAND_MAX + a;
	return arr;
}

int strcmp(char* a, char* b)
{
	for (int i = 0; a[i] && b[i]; ++i)
	{
		if (a[i] > b[i])
			return 1;
		if (b[i] > a[i])
			return -1;
	}
	return 0;
}

int strlen(char*a)
{
	int s = 0;
	for (; a[s]; ++s);
	return s;
}



