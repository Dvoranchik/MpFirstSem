#include "stdafx.h"
#include "StopWords.h"

StopWords::StopWords(const char* fileName)
{
	std::ifstream inFile(fileName);
	std::string str;
	while (getline(inFile, str))
	{
		_data.push_back(str);
	}
}
