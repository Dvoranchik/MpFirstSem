#include "stdafx.h"
#include "Sings.h"

Sings::Sings()
{
	char sep[] = ",.'/?:;=+-_)({}[]&*^%$#@! ~|\t\n\"";
	int len = strlen(sep);
	for (size_t i = 0; i < len; ++i)
	{
		_table[(unsigned char) sep[i]] = true;
	}
}

bool Sings::IsSings(const char& elem) const
{
	return _table[(unsigned char)elem];
}


bool PredicatPair::operator()(const std::pair<int,std::string>& data, const std::pair<int, std::string>& value) const
{
	return data.first > value.first;
}

bool ErrorWords::operator()(const std::string& data) 
{
	return data == _value;;
}
