#include <iostream>
#include "Template.h"
#include "ShallowChecks.h"

//___Example 1___//
//template<typename T, size_t s>
template<typename T>
inline �Vector<T> const& makeVector(T const& value, const size_t s)
{
	�Vector<T> v(s);

	v.fill(value);

	return v;
}

//___Example 2___//
Client clientObject;

void main()
{
	const size_t size = 5;
	�Vector<int> v = makeVector<int>( 7, size );
	int a = v[2];

//	shell(clientObject);

}