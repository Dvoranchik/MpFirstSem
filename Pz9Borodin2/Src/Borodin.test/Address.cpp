#include "stdafx.h"
#include "Address.hpp"


Address::Address()
	:_Name(new char[1]{ '\0' }),
	_Country(new char[1]{ '\0'}),
	_Town(new char[1]{ '\0' }),
	_Street(new char[1]{ '\0' }),
	_Address(new char[1]{ '\0' }),
	_Number(new char[1]{ '\0' })
{
}


Address::Address(const Address & ob)
{
	size_t lenght = strlen(ob._Name) + 1;
	_Name = new char[lenght];
	strcpy_s(_Name, lenght, ob._Name);

	lenght = strlen(ob._Country) + 1;
	_Country = new char[lenght];
	strcpy_s(_Country, lenght, ob._Country);


	lenght = strlen(ob._Town) + 1;
	_Town = new char[lenght];
	strcpy_s(_Town, lenght, ob._Town);


	lenght = strlen(ob._Street) + 1;
	_Street = new char[lenght];
	strcpy_s(_Street, lenght, ob._Street);


	lenght = strlen(ob._Number) + 1;
	_Number = new char[lenght];
	strcpy_s(_Number, lenght, ob._Number);


	lenght = strlen(ob._Address) + 1;
	_Address = new char[lenght];
	strcpy_s(_Address, lenght, ob._Address);
		
}

Address& Address::operator = (Address& right)
{
	if (this == &right) return *this;
	delete[] this->_Address;
	delete[] this->_Country;
	delete[] this->_Name;
	delete[] this->_Number;
	delete[] this->_Street;
	delete[] _Town;

	size_t lenght = strlen(right._Address)+1;
	this->_Address = new char[lenght];
	strcpy_s(this->_Address, lenght, right._Address);

	lenght = strlen(right._Country) + 1;
	this->_Country = new char[lenght];
	strcpy_s(this->_Country, lenght, right._Country);

	lenght = strlen(right._Name) + 1;
	this->_Name = new char[lenght];
	strcpy_s(this->_Name, lenght, right._Name);

	lenght = strlen(right._Number) + 1;
	this->_Number = new char[lenght];
	strcpy_s(this->_Number, lenght, right._Number);

	lenght = strlen(right._Street) + 1;
	this->_Street = new char[lenght];
	strcpy_s(this->_Street, lenght, right._Street);
	
	
	lenght = strlen(right._Town) + 1;
	this->_Town = new char[lenght];
	strcpy_s(this->_Town, lenght, right._Town);

	return *this; //Возврат ссылки на обЪект
}

bool Address::operator == (Address& right)
{
	return !strcmp(this->_Country, right._Country) && !strcmp(this->_Town, right._Town);
}

Address::~Address()
{
	delete[] _Name;
	delete[] _Number;
	delete[] _Country;
	delete[] _Town;
	delete[] _Address;
	delete[] _Street;
}

bool CompCountry( const Address  &a, const char* country)
{
	return(!strcmp(a._Country, country));

}
Address* Address::Find(const char *parametr, const char* name, Address* const &mas, int count, int& n, bool (*comp)(const Address & ,const char*))
{
	
	Address *result = nullptr;
	{
		int resultCount = 0;
		for (int i = 0; i < count; ++i)
		{
			if (comp(mas[i],name))
				++resultCount;
		}
		n = resultCount;
		result = new Address[resultCount];
	
		for(int i=0; i< count && resultCount!=0; ++i)
		{
			if (comp(mas[i], name))
			{
				result[resultCount - 1] = mas[i];
				--resultCount;
			}
		}
	}
	return result;
}


void Address::setCountry(const char* str)
{
	if (!str)
		return;

	delete[] _Country;

	_Country = new char[strlen(str) + 1];
	strcpy_s(_Country, strlen(str) + 1, str);
}

void Address::setName(const char* str)
{
	if (!str)
		return;

	delete[] _Name;

	_Name = new char[strlen(str) + 1];
	strcpy_s(_Name, strlen(str) + 1, str);
}

void Address::setTown(const char* str)
{
	if (!str)
		return;

	delete[] _Town;

	_Town = new char[strlen(str) + 1];
	strcpy_s(_Town, strlen(str) + 1, str);
}

void Address::setStreet(const char* str)
{
	if (!str)
		return;

	delete[] _Street;

	_Street = new char[strlen(str) + 1];
	strcpy_s(_Street, strlen(str) + 1, str);
}

void Address::setNumber(const char* str)
{
	if (!str)
		return;

	delete[] _Number;

	_Number = new char[strlen(str) + 1];
	strcpy_s(_Number, strlen(str) + 1, str);
}

void Address::setAddress(void)
{
	delete[] _Address;

	size_t lenghtName = strlen(_Name);
	size_t lenghtStreet = strlen(_Street);
	size_t lenghtTown = strlen(_Town);
	size_t lenghtCountry = strlen(_Country);
	size_t lenghtNumber = strlen(_Number);
	size_t lenght = lenghtName + lenghtStreet + lenghtTown + lenghtCountry + lenghtNumber +5;


	_Address = new char[lenght + 1]{ 0 };

	strcpy_s(_Address, lenghtCountry + 1, _Country);


	_Address[lenghtCountry] = ' ';

	strcpy_s(_Address + lenghtCountry + 1, lenghtTown + 1, _Town);
	_Address[lenghtCountry + lenghtTown + 1] = ' ';

	strcpy_s(_Address + lenghtCountry + lenghtTown + 2, lenghtStreet + 1, _Street);
	_Address[lenghtCountry + lenghtTown + lenghtStreet + 2] = ' ';

	strcpy_s(_Address + lenghtCountry + lenghtTown + lenghtStreet + 3, lenghtStreet + 1, _Number);
	_Address[lenghtCountry + lenghtTown + lenghtStreet + +lenghtNumber + 3] = ' ';

	strcpy_s(_Address + lenghtCountry + lenghtTown + lenghtStreet + lenghtNumber + 4, lenghtName + 1, _Name);

	_Address[lenghtName + lenghtCountry + lenghtNumber + lenghtTown + lenghtStreet + 5] = '\0';
}

char* Address::getCountry(void) const
{
	return _Country;
}
char* Address::getTown(void) const
{
	return _Town;
}
char* Address::getStreet(void) const
{
	return _Street;
}
const char* Address::getName(void) const
{
	return _Name;
}
char* Address::getNumber(void) const
{
	return _Number;
}
char* Address::getAddress(void) const
{
	return _Address;
}
