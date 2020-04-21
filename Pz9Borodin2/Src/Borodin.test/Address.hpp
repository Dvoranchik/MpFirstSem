#pragma once
#include "stdafx.h"
#ifndef ADDRESS_HPP
#define ADDRESS_HPP

class Address
{
public:
	Address();
	Address(const Address &ob);
	~Address();

	void setCountry(const char* str);
	void setTown(const char*str);
	void setStreet(const char* str);
	void setNumber(const char* str);
	void setName(const char *str);
	void setAddress(void);

	Address* Find(const char* parametr, const char* name, Address* const &mas, int count, int &n, bool(*comp)(const Address & ,const char*));

	Address& operator = (Address& right);
	bool operator ==(Address& right);
	
	char* getCountry(void) const;
	char* getTown(void) const;
	char* getStreet(void) const;
	char* getNumber(void) const;
	char* getAddress(void) const;
	const char* getName(void) const;

	friend bool CompCountry(const Address  &a, const char* country);
private:
	char* _Country;
	char* _Town;
	char* _Street;
	char* _Number;
	char* _Address;
	char* _Name;

};
bool CompCountry(const Address  &a, const char* country);
#endif
