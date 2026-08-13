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
		List(T* pointer, ui4 capacity, ui4 count)
			: m_pointer(pointer)
			, m_capacity(capacity)
			, m_count(count)
		{
		}

		List(ui4 capacity)
			: m_pointer(static_cast<T*>(OSAllocator::Alloc(sizeof(T) * capacity)))
			, m_capacity(capacity)
			, m_count(0)
		{
		}

		List(const List&) = delete;

		List(List&& other) noexcept
			: m_pointer(other.m_pointer)
			, m_capacity(other.m_capacity)
			, m_count(other.m_count)
		{
			other.m_pointer = nullptr;
		}

		~List()
		{
			if (m_pointer != nullptr)
			{
				OSAllocator::Free(m_pointer);
				m_pointer = nullptr;
			}
		}

		constexpr static List<T> Empty() noexcept
		{
			return { nullptr, 0, 0 };
		}

		constexpr T* Pointer() const noexcept
		{
			return m_pointer;
		}

		constexpr ui4 Capacity() const noexcept
		{
			return m_capacity;
		}

		constexpr ui4 Count() const noexcept
		{
			return m_count;
		}

		template<typename TCast>
		constexpr List<TCast> Move() noexcept
		{
			auto _result = List<TCast>{ reinterpret_cast<TCast*>(m_pointer), m_capacity, m_count };
			m_pointer = nullptr;
			return _result;
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
