#pragma once
#include "stdafx.h"

template<typename IterType, typename T, typename PredType = std::less<int>>
IterType BinarySearch(IterType begin, IterType end, T value, PredType pred = PredType())
{
		int size = distance(begin, end);
		advance(begin, size / 2);
		IterType stor(begin);
		if (!pred(*stor, value)&&!pred(value,*stor))
		{
			return stor;
		}
		while (distance(stor, end) != 1)
		{
			size = distance(stor, end);
			if (pred(value,*stor))
			{
				advance(stor, -size / 2);
				advance(end, -size / 2);
				if (*stor == value)
					return stor;
			}
			else
			{
				advance(stor, size / 2);
				if (*stor == value)
				{
					return stor;
				}
			}
		}
		return end;
}

template<typename IterType, typename T, typename PredType = std::less<int>>
IterType RecursiveBinarySearch(IterType begin, IterType end, T value, PredType pred = PredType())
{
	int size = distance(begin, end);
	IterType storage(begin);
	IterType result;
	advance(storage, size / 2);
	if (!pred(*storage, value) && !pred(value, *storage))
	{
		return storage;
	}
	if (size / 2 == 0)
		return end;
	if (pred(value, *storage))
	{
		result = RecursiveBinarySearch(begin, storage, value, pred);
	}
	else
	{
		result = RecursiveBinarySearch(storage, end, value, pred);
	}
	if (storage == result)
		return end;
	return result;
}

