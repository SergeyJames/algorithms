/**
* @brief wrappers over standard algorithms, to minimize code size, and make more readable
* @brief cross-platform one-file C++ header
*
* @author Sergey Masuryan
* Contact Telegram: @SergeyJamesM
*
*/
# pragma once
#ifndef experiments_compare_h
#define experiments_compare_h

namespace wrp {

	/**
	 *	@required     : Forward iterator
	 *	@complexity   : At most last - first applications of the predicate
     *  @return value : bool
     **/
	template<typename Init>
	inline bool operator!=(Init _beg, Init _end) {
    	return _beg != _end; 
	}
    
} // !namespace wrp

#endif // !experiments_compare_h
