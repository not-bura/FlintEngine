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
		Array(T* pointer, ui4 length)
			: m_pointer(pointer)
			, m_length(length)
		{
		}

		Array(ui4 length)
			: m_pointer(static_cast<T*>(OSAllocator::Alloc(sizeof(T)* length)))
			, m_length(length)
		{
		}

		Array(const Array&) = delete;

		Array(Array&& other) noexcept
			: m_pointer(other.m_pointer)
			, m_length(other.m_length)
		{
			other.m_pointer = nullptr;
		}

		~Array()
		{
			if (m_pointer != nullptr)
			{
				OSAllocator::Free(m_pointer);
				m_pointer = nullptr;
			}
		}

		constexpr static Array<T> Empty() noexcept
		{
			return { nullptr, 0 };
		}

		constexpr T* Pointer() const noexcept
		{
			return m_pointer;
		}

		constexpr ui4 Length() const noexcept
		{
			return m_length;
		}

		template<typename TCast>
		constexpr Array<TCast> Move() noexcept
		{
			auto _result = Array<TCast>{ reinterpret_cast<TCast*>(m_pointer), m_length };
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
