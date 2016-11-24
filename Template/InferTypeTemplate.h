#ifndef __INFER_TYPE_TEMPLATE_H__
#define __INFER_TYPE_TEMPLATE_H__
#pragma once

#include <string>
#include <iostream>
#include <type_traits>

template <typename T>
bool isRef(T& obj)
{
	return true;
}

template <typename T>
bool isURef(T&& obj)
{
	return true;
}

//________________________________________________________________________________________
template <typename T>
void foo1(T& param)
{
	if (std::is_const<T>::value) { std::cout << "const "; }

	std::cout << typeid(T).name();

	if (isRef(param)) { std::cout << " &"; }

	std::cout << std::endl;
}

//________________________________________________________________________________________
template <typename T>
void foo2(const T& param)
{
	if (std::is_const<T>::value) { std::cout << "const "; }

	std::cout << typeid(T).name();

	//if (std::is_lvalue_reference<T>::value) { std::cout << " &"; }
	if (isRef(param)) { std::cout << " &"; }

	std::cout << std::endl;
}

//________________________________________________________________________________________
template <typename T>
void foo3(T&& param)
{
	if (std::is_const<T>::value) { std::cout << "const "; }

	std::cout << typeid(T).name();

	//if (std::is_lvalue_reference<T>::value) { std::cout << " &"; }
	//if (std::is_rvalue_reference<T>::value) { std::cout << " &"; }

//	std::cout << std::is_rvalue_reference<int&&>::value << '\n';				??? why here is OK

	if (isRef(param)) { std::cout << " &"; }
	if (isURef(param)) { std::cout << " &&"; }

	std::cout << std::endl;
}
//________________________________________________________________________________________

template <typename T>
void foo4(T param)
{
	if (std::is_const<T>::value) { std::cout << "const "; }

	std::cout << typeid(T).name();

	if (isRef(param)) { std::cout << " &"; }
	if (isURef(param)) { std::cout << " &&"; }

	std::cout << std::endl;
}
//________________________________________________________________________________________

#endif
