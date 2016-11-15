#ifndef __SHALLOW_CHECKS_H__
#define __SHALLOW_CHECKS_H__
#pragma once

template <typename T>
inline void ignore(T const&)
{
}
//________________________________________________________________________________________

// Example shows confusing sequence (clear()->core()->middle()->shell()) of the template methods.
// Such sequence show hot to check parameters during instantiation of templates
// Book: "C++ Templates: The Complete Guide" by David Vandevoorde & Nicolai M. Josuttis

template <typename T>
void clear(T const& p)
{
	*p = 0;
}
//________________________________________________________________________________________

template <typename T>
void core(T const& p)
{
	clear(p);
}
//________________________________________________________________________________________

template <typename T>
void middle(typename T::Index p)
{
	core(p);
}
//________________________________________________________________________________________

template <typename T>
void shell(T const& env)
{
	class ShallowChecks		// the class verifies that specifying type T::Index cannot be pointer
	{
		void deref(T::Index ptr)
		{
			ignore(*ptr);
		}
	};

	typename T::Index i;
	middle<T>(i);
}
//________________________________________________________________________________________

class Client
{
	public:
		typedef int Index;
};

#endif
