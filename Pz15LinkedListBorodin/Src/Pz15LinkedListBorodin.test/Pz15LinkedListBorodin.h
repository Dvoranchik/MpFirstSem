#pragma once
#include "stdafx.h"

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
	struct const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		const_iterator()
		{
			_ptr = new ListNode<T>();
			_ptr->_value = T();
			_ptr->_next = _ptr;
			_ptr->_prev = _ptr;
		}
		~const_iterator() {  }
		const_iterator(ListNode<T>* ptr) :_ptr(ptr) {}
		const T& operator*() const
		{
			return _ptr->_value;
		}
		const_iterator& operator=(const const_iterator& other)
		{
			_ptr = other._ptr;
		}
		const_iterator& operator++()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		const_iterator& operator++(int)
		{
			const_iterator temp(*this);
			operator++();
			return temp;
		}
		const_iterator& operator--()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		const_iterator& operator--(int)
		{
			const_iterator temp(*this);
			operator--();
			return temp;
		}
		ListNode<T>& operator->() const
		{
			return _ptr;
		}
		bool operator==(const const_iterator& other) const
		{
			return _ptr == other._ptr;
		}
		bool operator!=(const const_iterator& other) const
		{
			return _ptr != other._ptr;
		}
		ListNode<T>* _ptr;
	};

	struct const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		const_reverse_iterator()
		{
			_ptr = new ListNode<T>();
			_ptr->_value = T();
			_ptr->_next = _ptr;
			_ptr->_prev = _ptr;
		}
		~const_reverse_iterator() {}
		const_reverse_iterator(ListNode<T>* ptr) :_ptr(ptr) {}
		const_reverse_iterator(const const_reverse_iterator& other) :_ptr(other._ptr) {}

		const T& operator*() const
		{
			return _ptr->_value;
		}

		const_reverse_iterator& operator++()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		const_reverse_iterator& operator++(int)
		{
			const_iterator temp(*this);
			operator++();
			return temp;
		}
		const_reverse_iterator& operator--()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		const_reverse_iterator& operator--(int)
		{
			iterator temp(*this);
			operator--();
			return temp;
		}
		ListNode<T>& operator->() const
		{
			return _ptr;
		}
		bool operator==(const const_reverse_iterator& other) const
		{
			return _ptr == other._ptr;
		}
		bool operator!=(const const_reverse_iterator& other) const
		{
			return _ptr != other._ptr;
		}

		ListNode<T>* _ptr;
	};

	struct reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		reverse_iterator()
		{
			_ptr = new ListNode<T>();
			_ptr->_value = T();
			_ptr->_next = _ptr;
			_ptr->_prev = _ptr;
		}
		~reverse_iterator() {}
		reverse_iterator(ListNode<T>* ptr) :_ptr(ptr) {}
		reverse_iterator(const reverse_iterator& other) :_ptr(other._ptr) {}

		T& operator*() const
		{
			return _ptr->_value;
		}

		reverse_iterator& operator++()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		reverse_iterator& operator++(int)
		{
			reverse_iterator temp(*this);
			operator++();
			return temp;
		}
		reverse_iterator& operator--()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		reverse_iterator& operator--(int)
		{
			reverse_iterator temp(*this);
			operator--();
			return temp;
		}
		ListNode<T>& operator->() const
		{
			return _ptr;
		}
		bool operator==(const reverse_iterator& other) const
		{
			return _ptr == other._ptr;
		}
		bool operator!=(const reverse_iterator& other) const
		{
			return _ptr != other._ptr;
		}

		ListNode<T>* _ptr;
	};

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
		bool operator==(const iterator& other) const
		{
			return _ptr == other._ptr;
		}
		bool operator!=(const iterator& other) const
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

	void push_back(const T& value);
	void push_front(const T& value);

	bool empty();

	const_iterator begin() const;
	const_iterator end() const;

	iterator insert(iterator where, const T& value);
	iterator remove(const T& value);
	iterator erase(iterator where);
	iterator begin();
	iterator end();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

private:
	int _size;
	ListNode<T>* _head;
};

template<typename T>
inline LinkedList<T>::LinkedList() :_size(0)
{
	_head = new ListNode<T>();
	_head->_value = T();
	_head->_next = _head;
	_head->_prev = _head;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other) :_size(other._size)
{
	_head = new ListNode<T>();
	ListNode<T>* temp1 = _head;
	ListNode<T>* temp2 = other._head;
	_head->_value = temp2->_value;
	for (int i = 0; i < _size; ++i)
	{
		temp2 = temp2->_next;
		_head->_next = new ListNode<T>(temp2->_value,_head);
		_head = _head->_next;
	}
	_head->_next = temp1;
	temp1->_prev = _head;

	_head = temp1;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList&& other) :_size(other._size)
{
		_head = other._head;

		other._head = nullptr;
		other._size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	while (_size)
	{
		ListNode<T> *temp = _head;
		_head = _head->_next;

		temp->~ListNode();

		--_size;
	}
	if (_head != nullptr)
		_head->~ListNode();
	_head = nullptr;
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

	temp = iterator(temp._ptr->_next);

	where._ptr->_prev->_next = where._ptr->_next;
	where._ptr->_next->_prev = where._ptr->_prev;
	--_size;

	return temp;
}

template<typename T>
inline typename LinkedList<T>::const_iterator LinkedList<T>::begin() const
{
	return const_iterator(_head->_next);
}

template<typename T>
inline typename LinkedList<T>::const_iterator LinkedList<T>::end() const
{
	return const_iterator(_head);
}

template<typename T>
inline typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin()
{
	return reverse_iterator(_head->_prev);
}

template<typename T>
inline typename LinkedList<T>::reverse_iterator LinkedList<T>::rend()
{
	return reverse_iterator(_head);
}

template<typename T>
inline typename LinkedList<T>::const_reverse_iterator LinkedList<T>::rbegin() const
{
	return const_reverse_iterator(_head->_prev);
}

template<typename T>
inline typename LinkedList<T>::const_reverse_iterator LinkedList<T>::rend() const
{
	return const_reverse_iterator(_head);
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
	throw std::domain_error("Not found!");
}