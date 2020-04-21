#include "stdafx.h"
#include "MyFun.h"
#include "iostream"
using namespace std;
int logar(int x)
{
	if (x <= 0)
		return -2;
	
	int n = 0;
	int a = 1;

	while (a < x)
	{
		a *= 2;
		++n;
	}
	if (a == x)
		return n;
	
	return -1;
}


	int nodnorec(int a, int b)
{
		while (a != 0 && b != 0)
		{
			if (abs(a) >= abs(b))
				a = a % b;
			else
				b = b % a;
		}
		return abs(a + b);
}
	int nodrec(int a, int b)
	{
		if (a != 0 && b != 0)
		{
			if (abs(a) >= abs(b))
				a = a % b;
			else
				b = b % a;
			nodrec(a, b);
		}
		else
		return abs(a + b);
	}

	void Teilor(double a, double b, double dx, double e)
	{
		
		int n = 0;
		for (int i = 0; i <= 72; ++i)
		{
			cout << '_';
		}
		
		cout << endl;
		cout << "|" << "\tx" << "\t|" << "\tfx" << "\t|" << "\tn" << "\t|" <<"\t"<< "\te^(-x)"  << "\t|"  << endl;
		cout << endl;
		if (abs(a) <= 1)
		{
			cout << "|" << "\t" << a << "\t|" << "\t" << 0 << "\t|" << "\t" << n << "\t|" << "\t" << 0 << "\t|" << endl;
			a += dx;
		}
		while (a <= b)
		{
			cout << "|" << "\t" << a << "\t|"<<"\t" << trunc((tail(a, e, n) * 10000)) / 10000 << "\t|"<<"\t" << n << "\t|"<<"\t" << tail(a, e, n) << "\t|"  << endl;
			a += dx;
		}
		
	}
	double tail(double a, double e, int &n)
	{
		int k(1);
		double value(0);
		double elemRada(1);
		while (abs(elemRada) >=e)
		{
			value += elemRada;
			elemRada *= (2*k+1)/(a*a*(2*k+3));
			++k;
		}
		n = k;
		return value;
	}
	
	