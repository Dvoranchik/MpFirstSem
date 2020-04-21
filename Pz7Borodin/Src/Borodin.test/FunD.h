#include "Header.h"
#include "stdafx.h"

#define TEMPLATE_SWAP_FIRST_AND_LAST(Type)\
void bubblesort_##Type(Type *a, int n)\
{\
	int j, k;\
	do{ \
		k = 0;\
		for(j=1;j<n;++j)\
			if (a[j - 1] > a[j])\
			{\
				Type T = a[j - 1];\
				a[j - 1] = a[j];\
				a[j] = T;\
				k = j;\
			}\
		n = k;\
	}while (n);\
}


template<typename T>
void Modify(T* arr, int len)
{
	T sum = 0;
	for (int i = 0; i < len; sum += arr[i++]);
	for (int i = 0; i < len; ++i)
		if (arr[i] == 0)
			arr[i] = sum / len;
}

template<typename T>
T max(T* arr, int len)
{
	T max = arr[0];
	for (int i = 1; i < len; ++i)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

template<>
char* max<char*>(char** arr, int len)
{
	char* max = arr[0];
	for (int i = 1; i < len; ++i)
		if (strcmp(arr[i], max) > 0)
			max = arr[i];
	return max;

}

template<typename T>
T sum(T* arr, int len)
{
	T s = arr[0];
	for (int i = 1; i < len; s += arr[i++]);
	return s;
}

template<>
inline char* sum(char** arr, int len)
{
	int size = 0;
	for (int i = 0; i < len; ++i)
		size += strlen(arr[i]);
	char* mas = new char[size+1 ];
	int p = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; arr[i][j]; ++j)
			mas[p++] = arr[i][j];
	}
	mas[p] = 0;
	return mas;
}

template<typename T>
T* extend(T* arr, int len)
{
	T * mas = new T[len + 2];
	for (int i = 0; i < len; ++i)
		mas[i] = arr[i];
	mas[len] = max(arr, len);
	mas[len + 1] = sum(arr, len);
	return mas;
	
}
