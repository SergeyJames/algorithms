/**
* @brief wrappers over standard algorithms, to minimize code size, and make more readable
* @brief cross-platform one-file C++ header
*
* @author Sergey Masuryan
* Contact Telegram: @SergeyJamesM
*
*/
#pragma once
#ifndef experiments_algorithms_hpp
#define experiments_algorithms_hpp

#include <algorithm>

namespace wrp {

	/**
	 *	@brief        : сheck if container contains specific element
	 *	@required     :
	 *	@complexity   : at most last - first applications of the predicate
	 *	@return value :
	 *		false if the range [first, last) is empty, or no such element is found in range [first, last).
	 *		true  if the range [first, last) contains const Ty& Val.
	**/
	template<class Init, class Ty>
	inline bool contains(Init _begin, Init _end, const Ty& Val) noexcept {
		return (std::find(_begin, _end, Val) != _end);
	}


	/**
	 *	@brief        : сheck if container contains specific element
	 *	@required     :
 	 *	@complexity   : at most last - first applications of the predicate
	 *	@return value :
	 *		false if the range [first, last) is empty, or no such element is found in range [first, last).
	 *		true  if the range [first, last) contains const Ty& Val.
	**/
	template<class C, class Ty>
	inline bool contains(const C & c, const Ty& Val) noexcept	{
		return contains(std::begin(c), std::end(c), Val);
	}


	/**
	 *	@brief        : сheck if container contains specific element (use move semantic )
	 *	@required     :
	 *	@complexity   : At most last - first applications of the predicate
	 *	@return value :
	 *		false if the range [first, last) is empty, or no such element is found in range [first, last).
	 *		true  if the range [first, last) contains const Ty& Val.
	**/
	template<class C, class Ty>
	inline bool contains(const C & c, Ty&& Val) noexcept	{
		return contains(std::begin(c), std::end(c), std::forward<Ty>(Val));
	}


	/**
	 *  @brief        : 
	 *	@required     :
	 *	@complexity   : At most last - first applications of the predicate
	 *	@return value :
	 *		false if the range [first, last) is empty, or no such element predicate pred returns true in range [first, last).
	 *   	true  if the range [first, last) an element for which predicate pred returns true
	**/
	template<class Init, class Pr>
	inline bool contains_if(Init _begin, Init _end, Pr pred) noexcept {
		return (std::find_if(_begin, _end, pred) != _end);
	}

	/**
	 *  @brief        : 
	 *	@required     :
	 *	@complexity   : At most last - first applications of the predicate
	 *	@return value :
	 *		false if the range [first, last) is empty, or no such element predicate pred returns true in range [first, last).
	 *   	true  if the range [first, last) an element for which predicate pred returns true
	**/
	template<class C, class Pr>
	inline bool contains_if(const C & c, Pr pred) noexcept {
		return (std::find_if(std::begin(c), std::end(c), pred) != std::end(c));
	}


	
	/**
	 *	@brief        : 
	 *	@required     : unsorted dynamic contiguous sequence containers supporting 'Random Access Iterator' like  std::vector or std::deque
	 *	@complexity   : Amortized constant.
	 *	@return value : (void)
	 * 
	**/
	template<class C>
	inline void quik_remove_at(C & c, std::size_t idx) noexcept {
		if (idx < c.size()) {
			c[idx] = std::move(c.back());
			c.pop_back();
		}
	}


	/**
	 *	@required     : sorted container (class C)
	 *	@complexity   :
	 *		1-2) Logarithmic in the size of the container, O(log(size())).
	 *		3-4) Amortized constant if the insertion happens in the position just after the hint, logarithmic in the size of the container otherwise.(until C++11)
	 *		3-4) Amortized constant if the insertion happens in the position just before the hint, logarithmic in the size of the container otherwise. (since C++11)
	 *		5-6) O(N*log(size() + N)), where N is the number of elements to insert.
	 *		7)   Logarithmic in the size of the container, O(log(size())).
	 *		8)   Amortized constant if the insertion happens in the position just before the hint, logarithmic in the size of the container otherwise.
	 *	@return value : (void)
	**/
	template<class C, class T>
	inline void insert_sorted(C & c, const T& item) {
		c.insert(std::lower_bound(c.begin(), c.end(), item), item);
	}

	/**
	 *	@required     : sorted container (class C)
	 *	@complexity   :
	 *		1-2) Logarithmic in the size of the container, O(log(size())).
	 *		3-4) Amortized constant if the insertion happens in the position just after the hint, logarithmic in the size of the container otherwise.(until C++11)
	 *		3-4) Amortized constant if the insertion happens in the position just before the hint, logarithmic in the size of the container otherwise. (since C++11)
	 *		5-6) O(N*log(size() + N)), where N is the number of elements to insert.
	 *		7)   Logarithmic in the size of the container, O(log(size())).
	 *		8)   Amortized constant if the insertion happens in the position just before the hint, logarithmic in the size of the container otherwise.
	 *	@return value : (void)
	**/
	template<class C, class T>
	inline void insert_sorted(C & c, T&& item) {
		c.insert(std::lower_bound(c.begin(), c.end(), item), std::forward<T>(item));
	}


	/**
	 *	@since        :	C++14 (and higer).
	 * 	@complexity   :	For nonempty ranges, exactly std::distance(first,last) -1 applications of the corresponding predicate.
	 * 	@return value :	Forward iterator to the new end of the range
	 * 	@usage        :	Erase-remove idiom.
	**/
	template<class FwdIt>
	inline FwdIt remove_multi_wshitespaces(FwdIt begin, FwdIt end) noexcept {
		return std::unique(begin, end, [](const auto& a, const auto& b) {  return isspace(a) && isspace(b); });
	}	
	
} // !namespace wrp

#endif // !experiments_algorithms_hpp
