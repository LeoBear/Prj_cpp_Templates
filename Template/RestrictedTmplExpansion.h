#ifndef __RESTIRCTED_TEMPLATE_EXPANSION_H__
#define __RESTIRCTED_TEMPLATE_EXPANSION_H__
#pragma once

#include <string>
#include <iostream>

// Book: "C++ Templates: The Complete Guide" by David Vandevoorde & Nicolai M. Josuttis

class S
{

};

template <typename T>
class Wrapper
{
private:
	T object;

public:
	Wrapper(T obj) : object(obj)
	{
	}

	friend void f(Wrapper<T> const& a)
	{
	}
};

#endif
