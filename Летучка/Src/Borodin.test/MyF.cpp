#include "stdafx.h"
#include "MyF.h"
int size(unsigned char arr[N], char a, char b)
{
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] >= a && arr[i] <= b) 
			++sum;
	}
	return sum;
}