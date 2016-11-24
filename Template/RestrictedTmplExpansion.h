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

	// The "explicit" makes a conversion constructor to non-conversion constructor.
	// as result we cannot call "S s1;	f(s1);"
	// If remove "explicit" then Wrapper(T obj)  will be as conversion constructor.
	explicit Wrapper(T obj) : object(obj)
	{
	}

	friend void f(Wrapper<T> const& a)
	{
	}

	friend bool f(Wrapper<T> const& a, Wrapper<T> const& b)
	{
		return true;
	}

};

#endif
