#include <iostream>
#include "Template.h"

//template<typename T, size_t s>
template<typename T>
ÑVector<T>& makeVector(const T & value, size_t s)
{
	ÑVector<T> v(s);

	v.fill(value);

	return v;
}


void main()
{
	const size_t size = 5;

	ÑVector<int> v = makeVector<int>( 7, size );

	int a = v[0];
}