/**
* @brief cross-platform one-file C++ header
* @author Sergey Masuryan
* Contact Telegram: @SergeyJames
*/



#pragma once

#include <chrono>
#include <iostream>
#include <typeindex>

namespace wrp {

	/**
	 * Durations - days, weeks, months and years are not supported, due to the inappropriateness.
	*/
	template<class _duration>
	const char* chronoDurationPrettyName() {
		const std::size_t dur = typeid(_duration).hash_code();
		if(dur == typeid(std::chrono::nanoseconds).hash_code()) {
			return "nanoseconds";
		}
		else if (dur == typeid(std::chrono::microseconds).hash_code()) {
			return "microseconds";
		}
		else if (dur == typeid(std::chrono::milliseconds).hash_code()) {
			return "milliseconds";
		}
		else if (dur == typeid(std::chrono::seconds).hash_code()) {
			return "seconds";
		}
		else if (dur == typeid(std::chrono::minutes).hash_code()) {
			return "minutes";
		}
		else if (dur == typeid(std::chrono::hours).hash_code()) {
			return "hours";
		}
		return "Unknown or not supported duration.";
	}

	/**
	 * 
	 * 
	 * 
	**/
	template<class _duration = std::chrono::milliseconds>
	class ScopedTimer {
	public:
		explicit ScopedTimer(bool printOnExit = false, const char* tag = nullptr) noexcept
			: m_start{ std::chrono::high_resolution_clock::now() },
			  m_printOnExit{ printOnExit },
			  m_tag{ tag }
		{}
		
		virtual ~ScopedTimer() noexcept {
			const auto end = std::chrono::high_resolution_clock::now();
			const std::string theMessage = m_tag ? std::string{ "The " } + m_tag + " elapsed: " : "Elapsed: ";

			if (m_printOnExit) {
				std::cout <<
				theMessage <<
				std::chrono::duration_cast<_duration>(end - m_start).count() <<
				" " <<
				chronoDurationPrettyName<_duration>() << std::endl;
			}
		}

		size_t getCurDuration() const noexcept {
			return std::chrono::duration_cast<_duration>(std::chrono::high_resolution_clock::now() - m_start).count();
		}
	
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
		const bool m_printOnExit;
		const char* m_tag{ nullptr };

		ScopedTimer(ScopedTimer&&) = delete;
		ScopedTimer(const ScopedTimer&) = delete;
		ScopedTimer& operator=(ScopedTimer&&) = delete;
		ScopedTimer& operator=(const ScopedTimer&) = delete;
	};
} // ! namespace wrp

