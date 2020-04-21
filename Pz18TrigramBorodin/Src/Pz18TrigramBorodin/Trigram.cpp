#include "stdafx.h"
#include "Trigram.h"
#include "Delimiters.h"

char* FileRead(const char* fileName)
{
	FILE* file = fopen(fileName, "r");

	if (file == NULL)
		return nullptr;

	fseek(file, 0, SEEK_END);
	long lSize = ftell(file);
	rewind(file);

	char * buffer = new char[lSize];
	if (buffer == NULL)
		return nullptr;

	int result = fread(buffer, 1, lSize, file);

	buffer[lSize] = '\0';

	fclose(file);
	return buffer;
}

bool Trigram::IsSigns(const char& value)
{
	static Delimiters sgn;
	return sgn.IsSings(value);
}

std::wstring Trigram::ReadFileToMultiByte(const char* fileName)
{
	setlocale(LC_ALL, "ru");
	std::string text = FileRead(fileName);
	text += ' ';
	IsTextUnicode(text.c_str(), text.size(), NULL);
	{
		text.erase(text.begin(), text.begin() + 3);
	}
	std::wstring buf(text.size(),0);
	MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, text.c_str(), text.size(), const_cast<wchar_t*>(buf.data()), text.size());
	
	return buf;
}

std::pair<std::unordered_map<std::wstring, int>, std::unordered_map<std::wstring, int>> Trigram::TrigramList(std::string fileName)
{
	std::wstring storage = ReadFileToMultiByte(fileName.c_str());
	int i = 0;
	std::wstring strru;
	std::wstring streu;
	std::pair<std::unordered_map<std::wstring, int>, std::unordered_map<std::wstring, int>> twoLang;
	std::unordered_map<std::wstring, int> preresultru;
	std::unordered_map<std::wstring, int> preresulteu;
	while (storage[i] != '\0')
	{
		
		if (strru.size() != 3)
		{
			if (storage[i] >= L'à' && storage[i] <= L'ÿ')
			{
				if (streu.size() != 3)
					streu.clear();
				strru += storage[i];
			}
			else
			{
				if (IsSigns(storage[i]))
					if (!strru.empty() && strru.back() != ' ')
						strru += ' ';
			}
		}
		else
		{
			preresultru[strru]++;
			strru.erase(strru.begin());
			if (streu.empty())
				continue;
		}
		if (streu.size() != 3)
		{
			if (storage[i] >= L'a' && storage[i] <= L'z')
			{
				if (strru.size() != 3)
					strru.clear();
				streu += storage[i];
			}
			else
			{
				if (IsSigns(storage[i]))
					if (!streu.empty() && streu.back() != ' ')
						streu += ' ';
			}
		}
		else
		{
			preresulteu[streu]++;
			streu.erase(streu.begin());
			if (strru.empty())
				continue;
		}
		++i;
	}
	twoLang.first = preresultru;
	twoLang.second = preresulteu;
	return twoLang;
}


std::pair<int, int> Trigram::Sum(std::pair<std::unordered_map<std::wstring, int>, std::unordered_map<std::wstring, int>> res)
{
	std::pair<int, int> Sum;
	for (auto i = res.first.begin(); i != res.first.end(); ++i)
		Sum.first += i->second;
	for (auto j = res.second.begin(); j != res.second.end(); ++j)
		Sum.second += j->second;

	return Sum;
}

void Trigram::StaticToFile(std::pair<std::multimap<double, std::wstring>, std::multimap<double, std::wstring>> res, std::string fileName, int procent)
{
		
		std::wofstream Fout(fileName);
		Fout.imbue(std::locale("rus_rus.866"));
		int ru = procent * _sumRU / 100;
		int eu = procent * _sumEU / 100;
		auto ir = res.first.rbegin();
		auto ie = res.second.rbegin();
		advance(ir, ru);
		advance(ie, eu);
		for (auto it = res.first.rbegin(); it != ir; ++it)
			WideCharToMultiByte(CP_UTF8,0,it->second.c_str(),-1,NULL,0,NULL,NULL);
		Fout << "Ru Words:" << std::endl;
		for (auto i = res.first.rbegin(); i != ir; ++i)
			Fout << i->first << '%' << '\t' << i->second << std::endl;
		Fout << std::endl;
		Fout << "Eu Words:" << std::endl;
		for (auto j = res.second.rbegin(); j != ie; ++j)
			Fout << j->first << '%' << '\t' << j->second << std::endl;
		Fout.close();
}

std::pair<std::multimap<double, std::wstring>, std::multimap<double, std::wstring>> Trigram::Statistic(std::string fileName)
{
	std::pair<std::unordered_map<std::wstring, int>, std::unordered_map<std::wstring, int>> preres = TrigramList(fileName);
	std::pair<std::multimap<double, std::wstring>, std::multimap<double, std::wstring>> result;
	_sumRU = Sum(preres).first;
	_sumEU = Sum(preres).second;
	for (auto i = preres.first.begin(); i != preres.first.end(); ++i)
	{
		result.first.emplace(100 * (double)i->second / _sumRU, i->first);
	}

	for (auto j = preres.second.begin(); j != preres.second.end(); ++j)
	{
		result.second.emplace(100 * (double)j->second / _sumEU, j->first);
	}
	return result;
}