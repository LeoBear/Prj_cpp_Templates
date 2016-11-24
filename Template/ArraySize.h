#ifndef __ARRAY_SIZE_H__
#define __ARRAY_SIZE_H__

#pragma once

// Return numbers of elements in array in time of compilation

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&array)[N]) noexcept
{
	return N;
}

#endif
