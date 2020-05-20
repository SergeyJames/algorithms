/**
* @brief some utilities collection from famous c++ experts
* @brief cross-platform one-file C++ header
*
* @author Sergey Masuryan
* Contact Telegram: @SergeyJames
*
*/
#pragma once
#ifndef utils_utils_hpp
#define utils_utils_hpp

namespace wrp {

	/** @copyright ©  : @herbsutter
	 *	@brief        : сheck if First (type _Derived) is Derived Of Second (type _Base)
	 *	@required     :
	 *	@usage        : 
	 *          class parent {};
	 *          class child : public parent {};
	 *
	 *          isFirstDerivedOfSecond<parent, child__>::getResult(); //< false
	 *          isFirstDerivedOfSecond<child, parent>::getResult();   //< true
	 *          
	**/
	template<typename _Derived, typename _Base>
	class isFirstDerivedOfSecond {
		class No { };
		class Yes { No no[2]{}; };
		static constexpr Yes Test(_Base*);
		static constexpr No Test(...);
	public:
		static constexpr bool getResult() noexcept { 
			return sizeof(Test(static_cast<_Derived*>(0))) == sizeof(Yes);
		}
	};
} // ! namespace wrp

#endif // ! utils_utils_hpp
