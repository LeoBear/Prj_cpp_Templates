#ifndef __SMART_POINTER_TEMPLATE_TEMPLATE_PARAMETER_H__
#define __SMART_POINTER_TEMPLATE_TEMPLATE_PARAMETER_H__
#pragma once

#include <string>
#include <iostream>

template <class T>
struct NoChecking
{
	static void Check(T*)
	{
		std::cout << "NoChecking::Check()" << std::endl;
	}
};
//________________________________________________________________________________________

template <class T>
struct EnforceNotNull
{
	class NullPointerException : public std::exception {};
	static void Check(T* ptr)
	{
		std::cout << "EnforceNotNull::Check()" << std::endl;

		if (!ptr)
		{
			throw NullPointerException();
		}
	}
};
//________________________________________________________________________________________

template <class T>
struct EncureNotNull
{
	static void Check(T*& ptr)
	{
		std::cout << "EncureNotNull::Check()" << std::endl;

		if (!ptr)
		{
//			ptr = GetDefaultValue();
		}
	}
};
//________________________________________________________________________________________

template
<
	class T,
	template<class> class CheckingPolicy,
	template<class> class ThreadingModel
>
class SmartPtr : public CheckingPolicy<T>,
                 public ThreadingModel<SmartPtr>
{
	T* point;

	//T* operator()
	//{
	//	typename ThreadingModel<SmartPtr>::Lock guard(*this);
	//	CheckingPolicy<T>::Check(point);
	//	return point;
	//}
};
#endif
