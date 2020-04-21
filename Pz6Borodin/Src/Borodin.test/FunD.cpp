#include "stdafx.h"
#include "Fun.h"
int Lenghtplus(const char* arr)
{
	int l = 0;
	while (*arr != '.' && *arr)
	{
		++l;
		++arr;
	}
	return l;
}

double FindRoots(double (*F)(double), double a, double b, double eps)
{
	double c=0.;
	while((b-a)/2>eps)
	{
		c = (a + b) / 2;
		if ((F(a)*F(c)) > 0)
			a = c;
		else
			b = c;
	}
	return c;
}
double FindRoots(double(*F)(double), double a, double b, double eps, double sqr)
{
	double c = 0.;
	while ((b - a) / 2>eps)
	{
		c = (a + b) / 2;
		if ((F(a) / (a-sqr) *F(c) / (c-sqr)) > 0)
			a = c;
		else
			b = c;
	}
	return c;

}


double Fallibility(double(*F)(double),double a, double b, double eps)
{
	if (F(a)*F(b)>0)
	{
		return -1;
	}
	return FindRoots(F, a, b, eps);
}

double Fallibility(double(*F)(double), double a, double b, double eps, double sqr)
{
	if (F(a) * F(b) >0)
	{
		return -1;
	}
	return FindRoots(F, a, b, eps,sqr);
}

int Summ(int a, int b)
{
	return a + b;
}

double Before(const char *arr)
{
	double digit = 0.;
	double c = 1;
	int pozition = Lenghtplus(arr);
	for (int i = pozition - 1; i >= 0; --i)
	{
		int temp = arr[i] - '0';
		digit += temp * c;
		c *= 10;
	}
	return digit;
}
double After( const char *arr)
{
	double digit = 0.;
	double c = 0.1;
	int pozition = Lenghtplus(arr);
	for (int i = pozition + 1; arr[i] != '\0'; ++i)
	{
		int temp = arr[i] - '0';
		digit += temp * c;
		c = c/10;
	}
	return digit;
}


double Digit( const char*arr)
{
	double a = Before(arr);
	double c = After(arr);
	return  a + c;
	
}
double Summ( const char *str1,const char *str2, const char *str3)
{
	return Digit(str1) + Digit(str2) + Digit(str3);
}