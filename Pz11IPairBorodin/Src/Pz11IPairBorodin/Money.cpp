#include "stdafx.h"
#include "Money.h"

Money::Money(int rubles, int pennies)
{
	if (pennies >= 100)
		throw std::logic_error("A lot of money");
	_rubles = rubles;
	_pennies = pennies;
}

Money::Money(const Money& other):_rubles(other._rubles),_pennies(other._pennies){}

Money& Money::operator=(const Money& other)
{
	if (this == &other)
		return *this;
	_rubles = other._rubles;
	_pennies = other._pennies;
	return *this;
}

int Money::GetRubles() const
{
	return _rubles;
}

int Money::GetPennies() const
{
	return _pennies;
}

void Money::SetMoney(int rubles, int pennies) 
{
	if (pennies >= 100)
		throw std::logic_error("A lot of money");
	_rubles = rubles;
	_pennies = pennies;
}

void Money::Save(std::ostream & stream)
{
	stream << "Money " << _rubles << " " << _pennies << std::endl;
}

 Money Money::operator+(const Money& other)
{
	 Money ob;
	 ob._pennies = other._pennies + _pennies;
	 ob._rubles = other._rubles + _rubles;
	 ob._rubles += ob._pennies / 100;
	 ob._pennies %=  100;
	 return ob;
}

Money Money::operator*(const Money& other)
 {
	Money ob;
	 ob._pennies = other._pennies * _pennies;
	 ob._rubles = other._rubles * _rubles;
	 ob._rubles += ob._pennies / 100;
	 ob._pennies %=  100;
	 return ob;
 }
 std::istream & Money::Input(std::istream& stream)
{
	 stream >> _rubles >> _pennies;
	 return stream;
}

 std::ostream& Money::Output(std::ostream& stream)
{
	 stream << _rubles << " " << _pennies;
	 return stream;
}

IPair* Money::Load(std::ifstream& stream)
{
	int rubles;
	int pennies;
	stream >> rubles >> pennies;
	return new Money(rubles, pennies);
}

