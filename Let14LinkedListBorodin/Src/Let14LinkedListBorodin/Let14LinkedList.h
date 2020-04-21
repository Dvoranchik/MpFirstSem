#pragma once
#include "Let14LinkedListBorodinApi.hpp"
#include "stdafx.h"
#include <list>

template<typename T>
struct ListNode
{
	ListNode * _next;
	ListNode* _prev;
	T _value;
	~ListNode()
	{
		_value.~T();
		_prev = nullptr;
		_next = nullptr;
	}
	ListNode(T value = T(), ListNode* prev = nullptr, ListNode* next = nullptr) :_value(value), _prev(prev), _next(next) {}
};

 template<typename T>
class LinkedList
{
public:
	 struct iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		iterator() 
		{
			_ptr = new ListNode<T>();
			_ptr->_value = T();
			_ptr->_next = _ptr;
			_ptr->_prev = _ptr;
		}
		~iterator() {}
		iterator(ListNode<T>* ptr) :_ptr(ptr) {}
		iterator(const iterator& other) :_ptr(other._ptr) {}
		
		T& operator*()
		{
			return _ptr->_value;
		}
		iterator& operator++()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		iterator& operator++(int)
		{
			iterator temp(*this);
			operator++();
			return temp;
		}
		iterator& operator--()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		iterator& operator--(int)
		{
			iterator temp(*this);
			operator--();
			return temp;
		}
		ListNode<T>& operator->()
		{
			return _ptr;
		}
		bool operator==(const iterator& other)
		{
			return _ptr == other._ptr;
		}
		bool operator!=(const iterator& other)
		{
			return _ptr != other._ptr;
		}
		ListNode<T>* _ptr;
	};


	LinkedList();
	LinkedList(const LinkedList& other);
	LinkedList( LinkedList&& other);

	~LinkedList();

	LinkedList& operator=(const LinkedList&& other);
	LinkedList& operator=(const LinkedList& other);

	iterator insert(iterator where, const T& value);
	void push_back(const T& value);
	void print();
	void push_front(const T& value);
	iterator remove(const T& value);
	iterator erase(iterator where);

	
	iterator begin();
	iterator end();


	void Clear(LinkedList& ob);
	bool empty();
private:
	int _size;
	ListNode<T>* _head;
};

template<typename T>
inline LinkedList<T>::LinkedList():_size(0)
{
	_head = new ListNode<T>();
	_head->_value = T();
	_head->_next = _head;
	_head->_prev = _head;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other):_size(other._size)
{
	_head = new ListNode<T>();
	ListNode<T>* temp1 = _head;
	ListNode<T>* temp2 = other._head;

	for (int i = 0; i < _size; ++i)
	{
		_head->_value = temp2->_value;
		_head->_next = new ListNode<T>();
		_head->_next->_prev = _head;
		_head = _head->_next;
		temp2 = temp2->_next;
	}
	_head->_value = temp2->_value;
	_head->_next = temp1;
	temp1->_prev = _head;

	_head = temp1;
}

template<typename T>
 LinkedList<T>::LinkedList(LinkedList&& other):_size(other._size)
{
	 if (this != &other)
	 {
		 _head = other._head;
		 _size = other._size;

		 other._head = nullptr;
		 other._size = 0;
	 }
	
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Clear(*this);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList && other)
{
	if (this != &other)
	{
		_head = other._head;
		_size = other._size;

		other._head = nullptr;
		other._size = 0;
	}

	return *this;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		this->~LinkedList();
		new (this) LinkedList(other);
	}

	return *this;
}

template<typename T>
void LinkedList<T>::Clear( LinkedList& ob)
{
	while (ob._size)
	{
		ListNode<T> *temp = ob._head;
		ob._head = ob._head->_next;

		 temp->~ListNode();

		--ob._size;
	}
	if(ob._head!=nullptr)
	ob._head->~ListNode();
	ob._head = nullptr;
}

template<typename T>
bool LinkedList<T>::empty()
{
	return _size == 0;
}

template<typename T>
inline typename LinkedList<T>::iterator LinkedList<T>::insert(iterator where, const T& value)
{
	ListNode<T>* temp = new ListNode<T>(value, where._ptr->_prev, where._ptr);
	where._ptr->_prev->_next = temp;
	where._ptr->_prev = temp;
	++_size;

	iterator it(temp);
	return it;
}

template<typename T>
inline void LinkedList<T>::push_back(const T& value)
{
	iterator temp(_head);
	insert(temp, value);
}

template<typename T>
inline void LinkedList<T>::print()
{
	ListNode<T>*temp = _head->_next;
	for (size_t i = 0; i < _size; ++i)
	{
		std::cout << temp->_value << std::endl;
		temp = temp->_next;
	}
}

template<typename T>
inline void LinkedList<T>::push_front(const T& value)
{
	iterator temp(_head->_next);
	insert(temp, value);
}

template<typename T>
inline typename LinkedList<T>::iterator LinkedList<T>::erase(iterator where)
{
	iterator temp(where._ptr);
	if (!_size)
		return where;

	temp= iterator(temp._ptr->_next);

	where._ptr->_prev->_next = where._ptr->_next;
	where._ptr->_next->_prev = where._ptr->_prev;
	--_size;

	return temp;
}

template<typename T>
inline typename LinkedList<T>::iterator LinkedList<T>::begin()
{
	return iterator(_head->_next);
}

template<typename T>
inline typename LinkedList<T>::iterator LinkedList<T>::end()
{
	return iterator(_head);
}

template<typename T>
inline typename  LinkedList<T>::iterator LinkedList<T>::remove(const T& value)
{
		iterator temp(_head->_next);
		for (size_t i = 0; i < _size; ++i)
		{
			if (temp._ptr->_value == value)
			{
				return erase(temp);
			}
			++temp;
		}
		throw std::logic_error("Not found!");
}
