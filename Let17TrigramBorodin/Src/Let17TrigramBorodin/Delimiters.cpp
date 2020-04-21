#include "stdafx.h"
#include "Delimiters.h"

Delimiters::Delimiters()
{
	char sep[] = ",.'/?:;=+-_)({}[]&*^%$#@!~1234567890 |\t\n\"";
	size_t len = strlen(sep);
	for (size_t i = 0; i < len; ++i)
	{
		_table[(unsigned char)sep[i]] = true;
	}
}

 bool Delimiters::IsSings(const char & elem) const
{
	return _table[(unsigned char)elem];
}


