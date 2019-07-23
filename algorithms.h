/**
* @brief wrappers over standard algorithms, to minimize code size, and make more readable
* @brief cross-platform one-file C++ header
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
#include <deque>

namespace wrp {

	/**
	*	Required     :
	*	Complexity   : At most last - first applications of the predicate
	*	Return value :
	*		false if the range [first, last) is empty, or no such element is found in range [first, last).
	*		true  if the range [first, last) contains const Ty& Val.
	*/
	template<class Init, class Ty>
	inline bool contains(Init begin, Init end, const Ty& Val) noexcept
	{
		return (std::find(begin, end, Val) != end);
	}

	/**
 	*  overloaded version of 'contains' function
 	*/
	template<class C, class Ty>
	inline bool contains(C & c, const Ty& Val) noexcept
	{
		return contains(std::begin(c), std::end(c), Val);
	}

	/**
	*	Required     :
	*	Complexity   : At most last - first applications of the predicate
	*	Return value :
	*		false if the range [first, last) is empty, or no such element predicate pred returns true in range [first, last).
	*   	true  if the range [first, last) an element for which predicate pred returns true
	*/
	template<class Init, class Pr>
	inline bool contains_if(Init begin, Init end, Pr pred) noexcept
	{
		return (std::find_if(begin, end, pred) != end);
	}
	
	/**
	*	Required     : unsorted dynamic contiguous sequence containers supporting 'Random Access Iterator' like  std::vector or std::deque
	*	Complexity   : Amortized constant.
	*	Return value : (none)
	*/
	template<class T>
	inline void quik_remove_at(T& v, std::size_t idx) noexcept
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

	/*
	*	Since        :	C++14 (and higer).
	*	Complexity   :	For nonempty ranges, exactly std::distance(first,last) -1 applications of the corresponding predicate.
	*	Return value :	Forward iterator to the new end of the range
	*	USage        :	Erase-remove idiom.
	*/
	template<class FwdIt>
	inline FwdIt remove_multi_wshitespace(FwdIt begin, FwdIt end) noexcept
	{
		return std::unique(begin, end, [](const auto& a, const auto& b) {  return isspace(a) && isspace(b); });
	}

	/*
	*	Complexity   :	Logarithmic
	*	Return value :	nums count, min val is 1
	*/
	inline int calc_nums_count(int a) noexcept
	{
		int n{ 1 };
		while ((a /= 10) > 0) ++n;
		return n; // NRVO optimization
	}
} // !namespace wrp

#endif // !experiments_algorithms_hpp
