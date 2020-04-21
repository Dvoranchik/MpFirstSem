#include "stdafx.h"
#include "Fun.h"

int indexOfBrakets(const char &str)
{
	int i = 0;
	char arr[] = "{}[]()<>";

	while (arr[i] != '\0')
	{
		if (str == arr[i])
			return i;
		++i;
	}
	return -1;
}
int Lenght(const char*str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return i;
}
bool Brakets(const char* arr)
{
	int *stack = new int[Lenght(arr)];
	int top = -1;
	
	for (int i = 0; arr[i] != '\0'; ++i)
	{
		int test = indexOfBrakets(arr[i]);
		if (test == -1)
			continue;
		if (test % 2 == 0)
			stack[++top] = test;
		else
		{
			if (top >= 0 && test - stack[top] == 1)
				--top;
			else
				return false;
		}
	}
	delete[] stack;
	return(top == -1);
}