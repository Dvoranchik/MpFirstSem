#include "stdafx.h"
#include "Fun.h"
int SubStrCount(const char* str, const char* substr)
{
	if (str == nullptr || substr == nullptr)
		return 0;
	else
	{
		int N = 0;
		int f = 0;
		int l1 = LenghtStr(str);
		int l2 = LenghtStr(substr);
	
				for (int i = 0; i < l1-l2+1; )
				{
					int j = 0;
					for (; j < l2; ++j,++i)
					{
						if (str[i] != substr[j])

							break;
					}

					if (j == l2)
					{
						++N;
					}
					else
					{
						i = i - j+1 ;
					}
				
				}
				return N;

			}

		}
		
		
	


int LenghtStr(const char* str)
{
	int N = 0;
	while (*str)
	{
		++N;      
		++str;
	}
	return N;
}