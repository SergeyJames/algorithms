/**
* @brief wrappers over standard algorithms, to minimize code size, and make more readable
* @brief cross-platform one-file C++ header
*
* @author Sergey Masuryan
* Contact Telegram: @SergeyJames
*
*/
#pragma once
namespace wrp {

	/**
	 *	@required      : Forward iterator
	 *	@complexity    : At most last - first applications of the predicate
	 *	@return value  : bool
	**/
	template<typename Init>
	inline bool operator!=(Init _beg, Init _end) noexcept {
		return _beg != _end; 
	}
	
} // !namespace wrp
