#include "stdafx.h"
#include "Let18MaxSubStr.h"

MaxSubStr::MaxSubStr(std::string file1, std::string file2)
{
	std::ifstream f1Open(file1);
	std::ifstream f2Open(file2);
	std::string storage;
	while (std::getline(f1Open, storage))
	{
		_file1 += storage;
	}
	while (std::getline(f2Open, storage))
	{
		_file2 += storage;
	}
}

std::string MaxSubStr::FindSubStr()
{
	int size = 0;
	if (_file1.size() > _file2.size())
		size = _file2.size();
	else
		size = _file1.size();
	int *diag = new int[size + 1]{ 0 };

	int res[3]{0};
	int prevres = 0;
	for (size_t k = 1; k <size; ++k)
	{
		for (size_t i=k, j = 1; i<size+1 && j < size+1; ++i, ++j)
		{
			if (_file1[i - 1] == _file2[j - 1])
			{
				diag[j] = diag[j - 1] + 1;
				if (diag[j] > res[2])
				{
					res[2] = diag[j];
					res[1] = j;
					res[0] = i;
				}
			}
		}
		if (res[2] > prevres)
		{
			size = size - (res[2] - prevres);
			prevres = res[2];
		}
	}
	for (size_t i = 0; i < size+1; i++)
	{
		diag[i] = 0;
	}
	for (size_t k = 2; k <size; ++k)
	{
		for (size_t j = k, i = 1; i<size+1 && j < size+1; ++i, ++j)
		{
			if (_file1[i - 1] == _file2[j - 1])
			{
				diag[i] = diag[i - 1] + 1;
				if (diag[i] > res[2])
				{
					res[2] = diag[i];
					res[1] = j;
					res[0] = i;
				}
			}
		}
		if (res[2] > prevres)
		{
			size = size - (res[2] - prevres);
			prevres = res[2];
		}
	}
	delete[] diag;
	std::string result;
	int z = res[1] - res[2];
	for (size_t i = 0; i < res[2]; ++i)
	{
		result.push_back(_file2[z++]);
	}
	return result;
}
