#include "stdafx.h"
#include"Functions.h"

int Lenghtplus(char* arr)
{
	int l = 0;
	while (*arr != '.' && *arr)
	{
		++l;
		++arr;
	}
	return l;
}


double Representation(char* arr,int b)
{
	int digit = 0.;
	double c = 1;
	int pozition = Lenghtplus(arr);
	for(int i=pozition-1;i>=0;--i)
	{
		int temp = arr[i] - '0';
		if (temp >= 0 && temp <= 9)
		{
			digit += temp * c;
		}
		if(arr[i]>='A' && arr[i]<='H')
			{
				int	dig1 = arr[i] - 'A' + 10;
					digit += dig1 * c;
			}
		if (arr[i] >= 'a' && arr[i] <= 'h')
		{
			int dig2 = arr[i] - 'a' + 10;
			digit += dig2 * c;
		}
	c*=b;
	}
	return digit;
}

double Fraction(char*arr, int b)
{
	double digit = 0.;
	double c = b;
	int pozition = Lenghtplus(arr);
	if (arr[pozition] != '\0')
	{
		for (int i = pozition + 1; arr[i] != '\0'; ++i)
		{
			int temp = arr[i] - '0';
			if (temp >= 0 && temp <= 9)
			{
				digit += temp / c;
			}
			if (arr[i] >= 'A' && arr[i] <= 'H')
			{
				int	dig1 = arr[i] - 'A' + 10;
				digit += dig1 / c;
			}
			if (arr[i] >= 'a' && arr[i] <= 'h')
			{
				int dig2 = arr[i] - 'a' + 10;
				digit += dig2 / c;
			}
			c *= b;
		}
	}
	return digit;
}
double Digit(char*arr, int b)
{
	double a = Representation(arr, b);
	double c = Fraction(arr, b);
	double result = a + c;
	return result;
}
