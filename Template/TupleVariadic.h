#ifndef __TUPLE_VARIADIC_H__
#define __TUPLE_VARIADIC_H__
#pragma once

#include <string>
#include <iostream>

// Helper type traits
template<typename T>
struct add_reference
{
	typedef T &type;
}; 
//________________________________________________________________________________________

template<typename T>
struct add_const_reference
{
	typedef T const &type;
};
//________________________________________________________________________________________

template <typename... Tail>
class CTuple
{
};
//________________________________________________________________________________________

template <class Head, class... Tail>
class CTuple<Head, Tail...> : private CTuple<Tail...>
{
private:
	typedef CTuple<Tail...> inherited;

protected:
	Head m_head;
	
public:

	CTuple()
	{
	}

	// Создаем кортеж по независимым аргументам:
	CTuple( typename add_const_reference<Head>::type v, typename add_const_reference<Tail>::type... vtail ) : m_head( v ), inherited( vtail... )
	{
	}

	// Создаем кортеж по другому кортежу:
	template<typename... VValues>
	CTuple( const CTuple<VValues...>& other ) : m_head( other.head() ), inherited( other.tail() )
	{
	}

	// Присваивание
	template<typename... VValues>
	CTuple& operator=( const CTuple<VValues...>& other )
	{
		m_head = other.head();
		tail() = other.tail();
		return *this;
	}

	typename add_reference<Head>::type       head()       { return m_head; }
	typename add_reference<const Head>::type head() const { return m_head; }

	      inherited& tail()       { return *this; }
	const inherited& tail() const { return *this; }
};
//________________________________________________________________________________________

template<class... Types>
CTuple<Types...> make_tuple(Types&&... t)
{
	return CTuple<Types...>(t...);
}


#endif

