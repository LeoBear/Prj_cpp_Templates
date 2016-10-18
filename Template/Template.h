#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#pragma once

template <class T>
class �Vector
{
		size_t size;
		T* data;

	public:
		�Vector();
		�Vector(size_t s);
		~�Vector();

		void fill(T value);
		unsigned int getSize();
		T& operator [](int);
};

template<class T>
�Vector<T>::�Vector()
{
	size = 0;
	data = NULL;
}

template<class T>
�Vector<T>::�Vector(size_t s)
{
	data = new T (s);
	size = s;
}

template<class T>
�Vector<T>::~�Vector()
{
	if (NULL != data)
	{
		delete data;
	}
}

template<class T>
void �Vector<T>::fill(T value)
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
unsigned int �Vector<T>::getSize()
{
	return size;
}

template<class T>
T & �Vector<T>::operator[](int i)
{
	if (i <= size)
	{
		return data[i-1];
	}
}

#endif
