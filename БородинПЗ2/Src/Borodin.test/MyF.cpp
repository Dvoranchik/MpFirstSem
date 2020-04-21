
#include "stdafx.h"
#include "MyF.h"


void Inf(double *arr, int n, const char*filename)
{
	std::ifstream inpFile(filename);
	for (int i = 0; i < n; ++i)
		inpFile >> arr[i];
}
void Outf(double *arr, int count, const char *filename)
{
	std::ofstream outFile(filename);
	for (int i = 0; i < count; ++i)
		outFile << arr[i] << ' ';
	outFile <<std::endl;
	
}
size_t IndexOfMaxElement(double *arr, size_t size)
{
	size_t indMax = 0;	

	for (size_t i = 1; i < size; ++i)
	{
		if (*(arr + i) > *(arr + indMax))	
			indMax = i;
	}

	return indMax;

}

size_t Summa(double *arr, size_t size)
{
	double Summa=0;
	double z = IndexOfMaxElement( arr, size);
	for (size_t i = 0; i < z; ++i)
	{
		if (arr[i] > 0 )
			Summa += arr[i];
	}
	return Summa;
}


void Honesty(double *arr, int n)
{
	int k = 0;
	int j = n-1;
	double *a = new double[n];
	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
		{
			a[j] = arr[i];
			--j;
		}
		else
		{
			a[k] = arr[i];
			++k;
		}
	}

	for (int i = 0; i < n; ++i)
		arr[i] = a[i];
	delete[] a;
}
bool Equal(double *arr, double*ar2, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] != ar2[i])
			return false;
	}
	return true;
}
int Matrix(int**matr, int n)
{
	int N = 0;
	
	for (int j = 0; j < n; ++j)
	{
		
		for (int i = 0; i < n; ++i)
		{
			bool ok = 1;
			int value = matr[i][j];
			if (i > 0 && value > matr[i - 1][j])
				ok = 0;
			if (j > 0 && value > matr[i][j - 1]) 
				ok = 0;
			if (i < n - 1 && value >matr[i + 1][j]) 
				ok = 0;
			if (j<n - 1 && value>matr[i][j + 1])
				ok = 0;
			if (ok != 0)
				++N;
		}
		
	}
	return N;
 }
