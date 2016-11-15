#ifndef __TYPE_DEF_H__
#define __TYPE_DEF_H__
#pragma once

#include <string>
#include <typeinfo>
#include <iostream>

// Example of the using typeid for clarification of the type for reference of the parameter
template <typename T>
void fooRef(T const& ref)
{
	std::cout << "ref in fooRef(T const&): " << typeid(ref).name() << std::endl;
}

// Example of the using typeid for clarification of the type for object parameter
template <typename T>
void fooObj(T const obj)
{
	std::cout << "obj in fooObj(T const): " << typeid(obj).name() << std::endl;
}
//________________________________________________________________________________________

// Example of the method where we can check how to identify different types of parameters
template <typename T1, typename T2, typename T3>
void fooTest(T1 a, T2 b, T3 c)
{
	std::cout << std::endl;

	std::cout << "a : " << typeid(a).raw_name() << std::endl;
	std::cout << "b : " << typeid(b).raw_name() << std::endl;
	std::cout << "c : " << typeid(c).raw_name() << std::endl;

	std::cout << std::endl;
	//std::cout <<"is_pointer T1 : "<< std::is_pointer<T1*>::value << std::endl;
	//std::cout << std::endl;

	std::cout << (std::is_pointer<T1>::value ? "pointer" : "not pointer") << ", value = " << a << "; type : " << typeid(a).name() << std::endl;
	std::cout << (std::is_pointer<T2>::value ? "pointer" : "not pointer") << ", value = " << b << "; type : " << typeid(b).name() << std::endl;
	std::cout << (std::is_pointer<T3>::value ? "pointer" : "not pointer") << ", value = " << c << "; type : " << typeid(c).name() << std::endl;
}
//________________________________________________________________________________________

// Example of the implementation of the identification of pointer or object
template <typename T>
bool isPtr(T obj)
{
	return false;		// return false because parameter of the method is not pointer
}

template <typename T>
bool isPtr(T* obj)
{
	return true;		// return true because parameter of the method is pointer
}

template <typename T>
T getValue(T obj)
{
	return obj;			// return object, without pointer dereference
}

template <typename T>
T getValue(T* obj)
{
	return *obj;		// return dereferenced pointer
}

// The method will be called at the end of call the variadic template
template <typename T>
void foo(T t)
{
	std::cout << (isPtr(t) ? "pointer" : "not pointer") << ", value = " << getValue(t) << "; type : " << typeid(t).name() << std::endl;
}

// Variadic template
template <typename T, typename... Rest>
void foo(T t, Rest... rest)
{
	std::cout << (isPtr(t) ? "pointer" : "not pointer") << ", value = " << getValue(t) << "; type : " << typeid(t).name() << std::endl;
	foo(rest...);
}
//________________________________________________________________________________________

// Example of the variadic template for SUM operation
template <typename T>
double sum(T t)
{
	return t;
}

template <typename T, typename... Rest>
double sum(T t, Rest... rest)
{
	return t + sum(rest...);
}
//________________________________________________________________________________________

#endif

