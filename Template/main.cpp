
#include <vector>
#include <string>
#include <iostream>

#include "TypeDef.h"
#include "Template.h"
#include "SortTracer.h"
#include "TupleVariadic.h"
#include "ShallowChecks.h"
#include "SharedPointer.h"
#include "InferTypeTemplate.h"
#include "RestrictedTmplExpansion.h"

//___Example 1___
template<typename T>
inline ÑVector<T> const& makeVector(T const& value, const size_t s)
{
	ÑVector<T> v(s);

	v.fill(value);

	return v;
}

//___Example 2___
//Client clientObject;

void main()
{
	//___Example 1: Template method uses template class ÑVector<...> ___
	//const size_t size = 5;
	//ÑVector<int> v = makeVector<int>( 7, size );
	//int a = v[2];

	//___Example 2: Verification of the instantiation of templates during compilation ___
	//shell(clientObject);

	//___Example 3: Verifies tracer for std::sort algorithm ___
	//TrcStdSort();

	//___Example 4: Several examples of the variadic methods which determine pointer or object ___
	//fooRef("hello");
	//fooObj("hello");

	//int * a = new int(5);
	//double b = 10.0;
	//std::string c = "bla bla";

	//foo(a, b, c);
	//fooTest(a, b, c);

	//double res1 = sum(1, 1, 1, 1, 1);
	//double res2 = sum(2, 2, 2.2, 2.1, 2.0);

	//___Example 5: ___
	//SharedPointer<int> p1 = new int(5);
	//{
	//	SharedPointer<int> p2 = p1;
	//}

	//SharedPointerAlloc<int> pAlloc( new int(5), 4 );

	//___Example 6: ___
	//S s1;
	//Wrapper<S> w(s1);

	//f(w);
	//f(s1);

	//___Example 7: ___ Example of template instantiation
	//      int   x = 2;
	//const int  cx = x;
	//const int& rx = x;

	//foo1(x);
	//foo1(cx);
	//foo1(rx);

	//std::cout << std::endl;

	//foo2(x);
	//foo2(cx);
	//foo2(rx);

	//std::cout << std::endl;

	//foo3(x);
	//foo3(cx);
	//foo3(rx);
	//foo3(28);

	//std::cout << std::endl;

	//foo4(x);
	//foo4(cx);
	//foo4(rx);
	//foo4(28);

	//std::cout << std::endl;

	//___Example 8: ___ Variadic Template Class

	//std::string s = "Hello";
	//std::vector<int> v = { 1,22,3,4,5 };
	//auto x = make_tuple(s, v, 1.2);
}