#pragma once

#include "Domain/Type.h"
#include "Infrastructure/Allocator/OSAllocator.h"

namespace FlintEngine
{
	template<typename T>
	class List
	{
	private:
		T* m_pointer;
		ui4 m_capacity;
		ui4 m_count;

	public:
		List(ui4 capacity)
			: m_pointer(static_cast<T*>(OSAllocator::Alloc(sizeof(T) * capacity)))
			, m_capacity(capacity)
			, m_count(0)
		{
		}

		~List()
		{
			OSAllocator::Free(m_pointer);
		}

		constexpr ui4 Capacity() const noexcept
		{
			return m_capacity;
		}

		constexpr ui4 Count() const noexcept
		{
			return m_count;
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
			return m_pointer + m_count;
		}

		constexpr const T* begin() const noexcept
		{
			return m_pointer;
		}

		constexpr const T* end() const noexcept
		{
			return m_pointer + m_count;
		}

		void Add(const T& value)
		{
			m_pointer[m_count] = value;
			++m_count;
		}
	};
}
