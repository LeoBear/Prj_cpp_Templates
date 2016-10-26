
#include <iostream>

#include "TypeDef.h"
#include "Template.h"
#include "SortTracer.h"
#include "ShallowChecks.h"

//___Example 1___
//template<typename T, size_t s>
template<typename T>
inline ÑVector<T> const& makeVector(T const& value, const size_t s)
{
	ÑVector<T> v(s);

	v.fill(value);

	return v;
}

//___Example 2___
Client clientObject;

void main()
{
	//___Example 1___
//	const size_t size = 5;
//	ÑVector<int> v = makeVector<int>( 7, size );
//	int a = v[2];

	//___Example 2___
//		shell(clientObject);

	//___Example 3___
//	TrcStdSort();

	//___Example 4___
	fooRef("hello");
	fooObj("hello");

	int * a = new int(5);
	double b = 10.0;
	std::string c = "bla bla";
	foo(a, b, c);
}