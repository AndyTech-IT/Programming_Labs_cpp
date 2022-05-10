#pragma once
#include "Main.h"

#if LR == 7

template <typename T>
class SetArray
{
protected:
	T* _set;
	USHORT _size;

protected:
	bool Contains(const T item) const
	{
		for (int i = 0; i < _size; i++)
		{
			if (_set[i] == item)
				return true;
		}
		return false;
	}
	void Clear()
	{
		if (_set)
		{
			delete[] _set;
		}
		_set = NULL;
		_size = 0;
	}

protected:
	void Add(const T item)
	{
		if (_size == 0)
		{
			_set = new T[1]{ item };
			_size = 1;
			return;
		}

		if (Contains(item))
			return;

		T* temp = new T[_size + 1];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = _set[i];
		}
		temp[_size] = item;

		delete[] _set;
		_set = temp;
		_size++;
	}
	void Remove(const T item)
	{
		if (_size == 0)
			return;

		if (Contains(item) == false)
		{
			return;
		}

		if (_size == 1)
		{
			delete[] _set;
			_set = NULL;
			_size = 0;
		}

		T* temp = new T[_size - 1];
		for (int i = 0, j = 0; i < _size; i++)
		{
			if (_set[i] == item)
				continue;

			temp[j++] = _set[i];
		}

		delete[] _set;
		_set = temp;
		_size--;
	}
	void Union(const SetArray<T> set)
	{
		int count = set;
		for (int i = 0; i < count; i++)
		{
			Add(set._set[i]);
		}
	}
	void Crossing(const SetArray<T> set)
	{
		for (int i = 0; i < _size;)
		{
			if (set.Contains(_set[i]) == false)
			{
				Remove(_set[i]);
			}
			else
				i++;
		}
	}

public:
	SetArray()
	{
		_set = NULL;
		_size = 0;
	}

	SetArray(const T first) : SetArray<T>()
	{
		Add(first);
	}

	SetArray(const SetArray<T>& copy) : SetArray<T>()
	{
		int count = copy;
		for (int i = 0; i < count; i++)
			Add(copy._set[i]);
	}

	SetArray(const SetArray<T>* copy)
	{
		int count = copy->_size;
		for (int i = 0; i < count; i++)
			Add(copy->_set[i]);
	}

public:
	SetArray<T>& operator =(T value)
	{
		Clear();
		Add(value);
		return *this;
	}
	SetArray<T>& operator =(SetArray<T> set)
	{
		Clear();
		Union(set);
		return *this;
	}
	T* operator [](USHORT index) const
	{
		if (index >= _size)
			return NULL;

		return &_set[index];
	}
	operator int() const
	{
		return _size;
	}

public:
	SetArray<T> operator +(T value)
	{
		SetArray<T> temp(this);
		temp.Add(value);
		return temp;
	}
	SetArray<T> operator -(T value)
	{
		SetArray<T> temp(this);
		temp.Remove(value);
		return temp;
	}

	SetArray<T>& operator +=(T value)
	{
		Add(value);
		return *this;
	}

	SetArray<T>& operator -=(T value)
	{
		Remove(value);
		return *this;
	}

public:
	SetArray<T> operator +(SetArray<T> set)
	{
		SetArray<T> temp(this);
		temp.Union(set);
		return temp;
	}
	SetArray<T> operator -(SetArray<T> set)
	{
		SetArray<T> temp(this);
		temp.Crossing(set);
		return temp;
	}

	SetArray<T>& operator +=(SetArray<T> set)
	{
		Union(set);
		return *this;
	}

	SetArray<T>& operator -=(SetArray<T> set)
	{
		Crossing(set);
		return *this;
	}
};

#endif