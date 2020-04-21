#include "stdafx.h"
#include "Time.h"
Time::Time(int hours,int minutes)
{
	if (hours >= 24 || minutes>=60)
		throw std::logic_error("Many times");
	_hours = hours;
	_minutes = minutes;
}

Time& Time::operator=(const Time &other)
{
	if (this == &other)
		return *this;
	_minutes = other._minutes;
	_hours = other._hours;
	return *this;
}

Time::Time(const Time& other):_minutes(other._minutes),_hours(other._hours){}

void Time::SetTime(int hours,int minutes)
{
	if (hours >= 24 || minutes >= 60)
		throw std::logic_error("Many times");
	_minutes = minutes;
	_hours = hours;
}

int Time::GetMinutes()
{
	return _minutes;
}

int Time::GetHours()
{
	return _hours;
}

IPair* Time::Load(std::ifstream & stream)
{
	int hours;
	int minutes;
	stream >> hours >> minutes;
	return new Time(hours, minutes);
}

void Time::Save(std::ostream & stream)
{
	stream << "Time " << _hours << " " << _minutes << std::endl;
}

 Time Time::operator+(const Time& other)
{
	 Time ob;
	 ob._hours = other._hours + _hours;
	 ob._minutes = other._minutes + _minutes;
	 ob._hours += ob._minutes / 60;
	 ob._minutes %= 60;
	 ob._hours %= 24;

	 return ob;
}

 Time Time::operator*(const Time & other)
{
	 Time ob;
	 ob._hours = other._hours *_hours;
	 ob._minutes = other._minutes *_minutes;
	 ob._hours+=ob._minutes/60;
	 ob._minutes %= 60;
	 ob._hours %= 24;
	 
	 return ob;
}

 std::istream& Time::Input(std::istream& stream)
 {
	 stream >> _hours >> _minutes;
	 return stream;
 }

std::ostream& Time::Output(std::ostream& stream)
 {
	stream << _hours <<" "<< _minutes << std::endl;
	return stream;
 }

