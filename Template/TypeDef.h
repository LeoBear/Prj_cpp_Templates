#ifndef __TYPE_DEF_H__
#define __TYPE_DEF_H__
#pragma once

#include <string>
#include <typeinfo>
#include <iostream>

template <typename T>
void fooRef(T const& ref)
{
	std::cout << "ref in fooRef(T const&): " << typeid(ref).name() << std::endl;
}

template <typename T>
void fooObj(T const obj)
{
	std::cout << "obj in fooObj(T const): " << typeid(obj).name() << std::endl;
}

template <typename T1, typename T2, typename T3>
void foo(T1 a, T2 b, T3 c)
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

#endif
