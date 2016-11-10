#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__
#pragma once

#include <string>
#include <iostream>

template < typename T >
class SharedPointer
{

	T* ptr;
	int count;

public:

	SharedPointer(T* t)
	{
		ptr = t;
		count = 1;

		std::cout <<"SharedPointer(): count = " << count << std::endl;

	}

	~SharedPointer()
	{
		count--;
		if (0 == count) { delete ptr; }

		std::cout <<"~SharedPointer(): count = " << count << std::endl;

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
	ptr.count++;
	this->count = ptr.count;

	std::cout << "inside assignment operator\n";

	return *this;
}

//________________________________________________________________________________________
template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer& ptr)
{
	this->ptr = ptr.ptr;
	ptr.count++;
	this->count = ptr.count;

	std::cout << "inside copy constructor\n";
}

//________________________________________________________________________________________

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

	//T& operator=(const SharedPointerAlloc& ptr);
	//SharedPointerAlloc(const SharedPointerAlloc& ptr);
	//T* operator->() { return ptr; }
	//T& operator*() { return *ptr; }

	//T* Get() { return ptr; }
	//int GetCount() { return ptr; }
};

//________________________________________________________________________________________
//template<class T>
//T& SharedPointerAlloc<T>::operator=(const SharedPointerAlloc& ptr)
//{
//	this->ptr = ptr.ptr;
//	ptr.count++;
//	this->count = ptr.count;
//
//	std::cout << "inside assignment operator\n";
//
//	return *this;
//}

//________________________________________________________________________________________
//template<class T>
//SharedPointerAlloc<T>::SharedPointerAlloc(const SharedPointerAlloc& ptr)
//{
//	this->ptr = ptr.ptr;
//	ptr.count++;
//	this->count = ptr.count;
//
//	std::cout << "inside copy constructor\n";
//}

//________________________________________________________________________________________

#endif

