#pragma once
#include "stdafx.h"
#include "Pz13BorodinApi.hpp"

template<typename T>
class Set
{
public:
	Set();
	Set(int capacity);
	Set(const Set<T>& other);

	~Set();

	Set& operator=(const Set<T>& other);
	Set operator+(Set<T>& other);
	Set operator*(Set<T>& other);
	Set operator-(Set<T>& other);
	T& operator[](int index);

	bool Find(const T& data);
	void Push(const T& data);
	void Delete(T data);
	int Capacity();
	int Size();
	template<typename T1,typename T2>
	T FindCriterion(T2 value,T1 functor);
	T Top();

	template<typename T>
	friend std::ostream& operator<<(std::ostream& stream, Set<T>& other);

private:
	T* _data;	
	int _capacity;
	int _size;
};

template<typename T>
Set<T>::Set() :_capacity(0), _size(0), _data(nullptr) {}

template<typename T>
Set<T>::Set(int capacity) : _capacity(capacity), _size(0)
{
	_data = new T[_capacity];
}

template<typename T>
Set<T>::Set(const Set<T>& other) :_size(other._size), _capacity(other._capacity)
{
	_data = new T[_capacity];
	for (int i = 0; i < _size; ++i)
	{
		_data[i] = other._data[i];
	}
}

template<typename T>
Set<T>::~Set()
{
	delete[] _data;
}

template<typename T>
Set<T>& Set<T>::operator=(const Set& other)
{
	if (this == &other)
		return *this;
	if (_data != nullptr)
		delete[] _data;
	_data = new T[_capacity];
	_size = other._size;
	_capacity = other._capacity;
	for (int i = 0; i < _size; ++i)
	{
		_data[i] = other._data[i];
	}
}

template<typename T>
template<typename T1, typename T2>
 T Set<T>::FindCriterion(T2 value, T1 functor)
{
	for (int i = 0; i < _size; ++i)
	{
		if (functor(_data[i], value))
			return _data[i];
	}
	throw std::domain_error("Return nothing");
}

template<typename T>
Set<T> Set<T>::operator+(Set<T>& other)
{
	if (this == &other)
		return *this;
	Set<T> sum(_size + other._size);
	for (int i = 0; i < _size; ++i)
	{
		sum.Push(_data[i]);
	}
	for (int i = 0; i < other._size; ++i)
	{
		sum.Push(other._data[i]);
	}
	return sum;
}

template<typename T>
Set<T> Set<T>::operator*(Set<T>& other)
{
	if (this == &other)
		return *this;
	Set<T> cross(_size);
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < other._size; ++j)
		{
			if (_data[i] == other._data[j])
				cross.Push(_data[i]);
		}
	}
	return cross;
}

template<typename T>
Set<T> Set<T>::operator-(Set<T>& other)
{
	Set<T> cross(*this);
	for (int i = 0; i < cross._size; ++i)
	{
		for (int j = 0; j < other._size; ++j)
		{
			if (cross._data[i] == other._data[j])
				cross.Delete(cross._data[i]);
		}
	}
	return cross;
}

template<typename T>
inline T& Set<T>::operator[](int index)
{
	return _data[index];
}

template<typename T>
bool Set<T>::Find(const T& data)
{
	for (int i = 0; i < _size; ++i)
	{
		if (data == _data[i])
			return true;
	}
	return false;
}

template<typename T>
void Set<T>::Push(const T& data)
{
	if (_size == _capacity)
		throw std::range_error("Stack is Full");
	if (Find(data) == 0)
		_data[_size++] = data;
}

template<typename T>
void Set<T>::Delete(T data)
{
	if (_size == 0)
		throw std::underflow_error("Stack is Empty");
	if (Find(data) != 0)
	{
		for (int i = 0; i < _size; ++i)
		{
			if (_data[i] == data)
				_data[i] = _data[_size - 1];
		}
		--_size;
	}
	else
		throw std::domain_error("Delete nothing");
}

template<typename T>
int Set<T>::Capacity()
{
	return _capacity;
}

template<typename T>
int Set<T>::Size()
{
	return _size;
}

template<typename T>
T Set<T>::Top()
{
	return _data[_size - 1];
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, Set<T>& other)
{
	for (size_t i = 0; i < other._size; ++i)
	{
		stream << other._data[i] <<" ";
	}
	return stream;
}

