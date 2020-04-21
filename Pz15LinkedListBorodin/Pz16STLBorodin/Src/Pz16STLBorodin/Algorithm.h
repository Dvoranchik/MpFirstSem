#pragma once
#include "stdafx.h"

template< typename IterType,typename T>
T Multy(IterType begin, IterType end)
{
	int multy = 1;
	for (auto it = begin; it != end; ++it)
	{
		if (*it % 4 == 0)
			multy *= *it;
	}
	return multy;
}

template<> inline
std::string Multy<char**,std::string>(char** begin,char**end)
{
	int size = std::distance(begin, end);
	std::string storage;
	while(begin!=end)
	{
		if (strlen(*begin) == 4)
			storage += *begin;
		++begin;
	}
	if (storage.empty())
		throw std::domain_error("Do not find");
	return storage;
}

template<typename IterType,typename T, typename PredType>
void Sort(IterType begin, IterType end, PredType pred)
{
	int counter = 0;
	std::vector<T> ls;
	for (auto i = begin+1; i != end; ++i)
	{
		for (auto j = i; j !=begin && pred(*(j-1),*j); --j)
		{
			counter++;
			std::swap(*(j-1), *j);
		}
	}
}

template<typename IterType, typename T1,typename T2, typename PredType>
std::list<T1> Find(IterType begin, IterType end, PredType pred, T2 value)
{
	std::list<T1> ls;
	for (auto i = begin; i != end; ++i)
	{
		if (pred(*i, value))
			ls.push_back(*i);
	}
	if (ls.empty())
		throw std::domain_error("Do not find");
	return ls;
}

template<typename IterType,typename Type, typename T, typename PredType>
Type LinaryFind(IterType begin, IterType end,  T value, PredType pred)
{
	for (auto i = begin; i != end; ++i)
	{
		if (pred(*i, value))
			return *i;
	}
	throw std::domain_error("Do not find");
}

template<typename IterType, typename T,typename Type, typename PredType, typename PredCuality>
Type BinarySearch(IterType begin, IterType end, T value, PredType pred,PredCuality predicate)
{
	auto size = distance(begin, end);
	advance(begin, size / 2);
	IterType stor(begin);
	if (predicate(*stor, value))
	{
		return *stor;
	}
	while (distance(stor, end) != 1)
	{
		size = distance(stor, end);
		if (pred(*stor, value))
		{
			advance(stor, -size / 2);
			advance(end, -size / 2);
			if (predicate(*stor, value))
				return *stor;
		}
		else
		{
			advance(stor, size / 2);
			if (predicate(*stor, value))
			{
				return *stor;
			}
		}
	}
	throw std::domain_error("Error of Search");
}

template<typename IterType, typename T1, typename T2, typename PredType>
std::list<T1> QuantityFind(IterType begin, IterType end, PredType pred, T2 value,int amount)
{
	std::list<T1> ls;
	for (auto i = begin; ls.size()<amount && i!= end; ++i)
	{
		if (pred(*i, value))
			ls.push_back(*i);
	}
	if (ls.empty())
		throw std::domain_error("Do not find");
	return ls;
}