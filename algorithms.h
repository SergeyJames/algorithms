/**
* @brief wrappers over standard algorithms, to minimize code size, and make more readable 
*
* @author Sergey Masuryan
* Contact Telegram: @SergeyJamesM
*
*/
#ifndef experiments_algorithms_hpp
#define experiments_algorithms_hpp

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <algorithm>
#include <cstddef>
#include <vector>

/**
*	Required     : 
*	Complexity   : At most last - first applications of the predicate
*	Return value :
*	false if the range [first, last) is empty, or no such element is found in range [first, last).
*   true  if the range [first, last) contains const Ty& Val.
*/
template<class Init, class Ty>
inline bool contains(Init begin, Init end, const Ty& Val)
{
	return (std::find(begin, end, Val) != end);
}


/**
*	Required     : unsorted std::vector<T>,
*	Complexity   : Amortized constant.
*	Return value : (none)
*/
template<class T>
inline void quik_remove_at(std::vector<T>& v, std::size_t idx)
{
	if (idx < v.size()) {
		v[idx] = std::move(v.back());
		v.pop_back();
	}
}


/**
*	Required     : sorted container (class C)
*	Complexity   :
			1-2) Logarithmic in the size of the container, O(log(size())).
			3-4) Amortized constant if the insertion happens in the position just after the hint, logarithmic in the size of the container otherwise.(until C++11)
			3-4) Amortized constant if the insertion happens in the position just before the hint, logarithmic in the size of the container otherwise. (since C++11)
			5-6) O(N*log(size() + N)), where N is the number of elements to insert.
			7)   Logarithmic in the size of the container, O(log(size())).
			8)   Amortized constant if the insertion happens in the position just before the hint, logarithmic in the size of the container otherwise.
*	Return value : (none)
*/
template<class C, class T>
inline void insert_sorted(C & c, const T& item)
{
	c.insert(std::lower_bound(c.begin(), c.end(), item), item);
}



#endif // !experiments_algorithms_hpp

