#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__
#pragma once

#include <string>
#include <iostream>

// Example of the template with one parameter
template < typename T >
class SharedPointer
{

	T* ptr;
	int *pCount;

public:

	SharedPointer(T* t)
	{
		ptr = t;
		pCount = new int();
		*pCount = 1;

		std::cout <<"SharedPointer(): pCount = " << *pCount << std::endl;

	}

	~SharedPointer()
	{
		(*pCount)--;
		if (0 == (*pCount)) { delete ptr; }

		std::cout <<"~SharedPointer(): pCount = " << *pCount << std::endl;

	}

	T& operator=(const SharedPointer& ptr);
	SharedPointer(const SharedPointer& ptr);
	T* operator->() { return ptr; }
	T& operator*() { return *ptr; }

	T* Get() { return ptr; }
	int GetCount() { return ptr; }
};

//________________________________________________________________________________________
template<class T>
T& SharedPointer<T>::operator=(const SharedPointer& ptr)
{
	this->ptr = ptr.ptr;
	(*(ptr.pCount))++;
	this->pCount = ptr.pCount;

	std::cout<<"Assignment operator"<< *(this->count) <<std::endl;

	return *this;
}

//________________________________________________________________________________________
template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer& ptr)
{
	this->ptr = ptr.ptr;
	(*(ptr.pCount))++;
	this->pCount = ptr.pCount;

	std::cout<<"Copy Constructor: pCount = "<< *(this->pCount) <<std::endl;
}

//________________________________________________________________________________________

// Example of the template with second template parameter
template < typename T, template<typename ARG> class ALLOC = std::allocator >
class SharedPointerAlloc
{
	ALLOC<T> ptr;
	int count;

public:

	SharedPointerAlloc(T* t, unsigned int size)
	{
		try
		{
			ptr.allocate(size, t);
			count = 1;

			std::cout << "SharedPointerAlloc(): count = " << count << std::endl;
			std::cout << "Max size = " << ptr.max_size()<< std::endl;
		}
		catch (std::bad_alloc& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	~SharedPointerAlloc()
	{
		count--;
		if (0 == count)
		{
//			ptr.destroy();
		}

		std::cout << "~SharedPointerAlloc(): count = " << count << std::endl;
	}
};

//________________________________________________________________________________________

#endif

