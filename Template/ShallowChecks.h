#ifndef __SHALLOW_CHECKS_H__
#define __SHALLOW_CHECKS_H__
#pragma once

template <typename T>
inline void ignore(T const&)
{
}

template <typename T>
void clear(T const& p)
{
	*p = 0;
}

template <typename T>
void core(T const& p)
{
	clear(p);
}

template <typename T>
void middle(typename T::Index p)
{
	core(p);
}

template <typename T>
void shell(T const& env)
{
	class ShallowChecks
	{
		void deref(T::Index ptr)
		{
			ignore(*ptr);
		}
	};

	typename T::Index i;
	middle<T>(i);
}

class Client
{
	public:
		typedef int Index;
};

#endif
