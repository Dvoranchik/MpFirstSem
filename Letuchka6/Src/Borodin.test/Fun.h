#pragma once

int SubStrCount(const char*, const char*);
template<typename T> int SubStrCount(const T* str,const T* substr)
{
	int N = 0;
	int f = 0;
	int l1 = LenghtStr<T>(str);
	int l2 = LenghtStr<T>(substr);
	for (int i = 0; i < l1 - l2 + 1; )
	{
		int j = 0;
		for (; j < l2; ++j, ++i)
		{
			if (str[i] != substr[j])

				break;
		}

		if (j == l2)
		{
			++N;
		}
			i = i - j + 1;
	}
	return N;
}
template<typename T> int LenghtStr(const T*str)
{
	int N = 0;
	while (*str)
	{
		++N;
		++str;
	}
	return N;
 }
int LenghtStr(const char*);