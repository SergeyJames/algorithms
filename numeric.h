/**
* @brief wrappers over standard algorithms, to minimize code size, and make more readable
* @brief cross-platform one-file C++ header
*
* @author Sergey Masuryan
* Contact Telegram: @SergeyJamesM
*
*/
#pragma once
#ifndef experiments_numeric_h
#define experiments_numeric_h 1
#include <numeric>

namespace wrp {
	
    /**
     *  @brief        : calculate average value in the range [first,last) (container c) using operator+()
     * 	@required     : InputIt must meet the requirements of LegacyInputIterator.
     * 	@complexity   : At most last - first applications of the predicate
     * 	@return value : average value (default is float) 
    **/
	template<class C, class T = float>
	inline constexpr T average(const C & c, T v = 0.0f) noexcept {
		return (c.empty() ? 0.0 : std::accumulate(c.cbegin(), c.cend(), 0) / static_cast<T>(c.size()));
	}

    /**
     *  @brief        : calculate nums count (only signed integral types, and not more than INT64_MAX)
     *  @complexity   :	Logarithmic
     * 	@return value :	nums count, min val is 1 
    **/
	inline constexpr unsigned short calc_nums_count(int64_t a) noexcept {
		short n{ 1 };
		while ( (a /= 10) > 0 ) ++n;
		return n; // NRVO optimization
	}


} // !namespace wrp

#endif // !experiments_numeric_h
