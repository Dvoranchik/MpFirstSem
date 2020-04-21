#include "stdafx.h"
#include "Fun.h"
int* String_inst(char* str)
{
	int len = 0;
	for (; str[len] != 0; ++len);

	int* nums = NULL;
	int numsc = 0;
	char buff[11];
	int pos = 0;
	bool ended = true;

	for (int i = 0; i == 0 || str[i - 1] != 0; ++i) 
	{
		if (str[i] >= '0' && str[i] <= '9') 
		{
			if (ended)
			{
				ended = false;
				pos = 0;
			}
			buff[pos++] = str[i];
			buff[pos] = 0;
		}
		else
		{
			if (ended) continue;
			ended = true;
			int temp = 0, mul = 1;
			while (pos--)
 {
				temp += mul * (buff[pos] - '0');
				mul *= 10;
			}
			nums = (int*)realloc(nums, sizeof(int)*(numsc + 1));
			nums[numsc++] = temp;
		}
	}

	return nums;
}

char* Filter_words(char* str, char chr, int count)
{
	int len = 0;
	for (; str[len] != 0; ++len);

	char* words = (char*)calloc(len + 1, sizeof(char));
	int words_pos = 0;
	char word[100];
	int word_pos = 0;
	bool word_ended = true;

	for (int i = 0; i == 0 || str[i - 1]; ++i)
	{
		if (str[i] == 0 || str[i] == ' ' || str[i] == ',') 
		{
			if (!word_ended)
			{
				word_ended = true;
				int c = 0;
				for (int j = 0; j<word_pos; ++j)
					c += (word[j] == chr);
				if (c >= count) 
				{
					for (int j = 0; j<word_pos; ++j)
						words[words_pos++] = word[j];
					words[words_pos++] = ' ';
				}
			}
		}
		else 
		{
			if (word_ended)
			{
				word_pos = 0;
				word_ended = false;
			}
			word[word_pos++] = str[i];
		}
	}

	return words;
}

char* Uppercase(char* str) 
{
	int len = 0;
	for (; str[len] != 0; ++len);

	char* words = (char*)calloc(len + 1, sizeof(char));
	bool word_ended = true;

	for (int i = 0; i<len; ++i) 
	{
		words[i] = str[i];
		if (str[i] == 0 || str[i] == ' ' || str[i] == ',')
		{
			word_ended = true;
		}
		else {
			if (word_ended) {
				word_ended = false;
				if (str[i] >= 'a') words[i] = str[i] - ('a' - 'A');
			}
		}
	}

	return words;
}
