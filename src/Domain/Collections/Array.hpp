#pragma once

#include "Domain/Type.h"
#include "Infrastructure/Allocator/OSAllocator.h"

namespace FlintEngine
{
	template<typename T>
	class Array
	{
	private:
		T* m_pointer;
		ui4 m_length;

	public:
		Array(ui4 length)
			: m_pointer(static_cast<T*>(OSAllocator::Alloc(sizeof(T)* length)))
			, m_length(length)
		{
		}

		~Array()
		{
			OSAllocator::Free(m_pointer);
		}

		constexpr ui4 Length() const noexcept
		{
			return m_length;
		}

		constexpr T& operator [] (ui4 index)
		{

			return m_pointer[index];
		}

		constexpr const T& operator [] (ui4 index) const
		{
			return m_pointer[index];
		}

		constexpr T* begin() noexcept
		{
			return m_pointer;
		}

		constexpr T* end() noexcept
		{
			return m_pointer + m_length;
		}

		constexpr const T* begin() const noexcept
		{
			return m_pointer;
		}

		constexpr const T* end() const noexcept
		{
			return m_pointer + m_length;
		}
	};
}
