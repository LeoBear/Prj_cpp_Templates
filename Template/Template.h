#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#pragma once

// Example of the template class with one parameter
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
//________________________________________________________________________________________

template<class T>
ÑVector<T>::ÑVector()
{
	size = 0;
	data = nullptr;
}
//________________________________________________________________________________________

template<class T>
ÑVector<T>::ÑVector(size_t s)
{
//	data = new T(s);
	data = new T[s];
	size = s;
}
//________________________________________________________________________________________

template<class T>
ÑVector<T>::~ÑVector()
{
	if (nullptr != data)
	{
		delete data;
	}
}
//________________________________________________________________________________________

template<class T>
void ÑVector<T>::fill(T value)
{
	if (nullptr == data)
	{
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		data[i] = value;
	}
}
//________________________________________________________________________________________

template<class T>
unsigned int ÑVector<T>::getSize()
{
	return size;
}
//________________________________________________________________________________________

template<class T>
T & ÑVector<T>::operator[](int i)
{
	if (i <= size)
	{
		return data[i-1];
	}
}

#endif
