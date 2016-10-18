#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#pragma once

template <class T>
class ÑVector
{
		size_t size;
		T* data;

	public:
		ÑVector();
		ÑVector(size_t s);
		~ÑVector();

		void fill(T value);
		unsigned int getSize();
		T& operator [](int);
};

template<class T>
ÑVector<T>::ÑVector()
{
	size = 0;
	data = NULL;
}

template<class T>
ÑVector<T>::ÑVector(size_t s)
{
	data = new T (s);
	size = s;
}

template<class T>
ÑVector<T>::~ÑVector()
{
	if (NULL != data)
	{
		delete data;
	}
}

template<class T>
void ÑVector<T>::fill(T value)
{
	if (NULL == data)
	{
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		data[i] = value;
	}
}

template<class T>
unsigned int ÑVector<T>::getSize()
{
	return size;
}

template<class T>
T & ÑVector<T>::operator[](int i)
{
	if (i <= size)
	{
		return data[i-1];
	}
}

#endif
