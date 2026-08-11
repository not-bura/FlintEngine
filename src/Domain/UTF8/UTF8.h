#pragma once

#include "Domain/Type.h"
#include <Windows.h>

namespace FlintEngine
{
	struct UTF8Char
	{
	private:
		const char8_t* m_pointer;

	public:
		UTF8Char(const char8_t* value);

		ui1 GetSize() const;

		static ui1 Size(const char* source);
		static ui1 Size(const char8_t* source);
	};

	struct UTF8FixedChar
	{
	private:
		ui4 m_value;
	};

	struct UTF8Memory
	{
	private:
		const char8_t* m_pointer;
		const ui4 m_length;

	public:
		UTF8Memory(const char* source);
		UTF8Memory(const char8_t* source);
		UTF8Memory(const char* source, ui4 length);
		UTF8Memory(const char8_t* source, ui4 length);

		const UTF8Char operator [] (const int index) const;
		const UTF8Char operator [] (const ui1 index) const;
		const UTF8Char operator [] (const ui2 index) const;
		const UTF8Char operator [] (const ui4 index) const;
		const UTF8Char operator [] (const ui8& index) const;

		operator LPCSTR () const noexcept;

		//char8_t* begin() noexcept;
		//char8_t* end() noexcept;
		const char8_t* begin() const noexcept;
		const char8_t* end() const noexcept;
	};

	struct UTF8String
	{
	private:
		const char8_t* m_pointer;
		const ui4 m_length;

	public:
		struct Iterator
		{
		private:
			const char8_t* m_pointer;

		public:
			Iterator(const char8_t* pointer)
				: m_pointer(pointer)
			{
			}

			const UTF8Char operator * () const
			{
				return UTF8Char{ this->m_pointer };
			}

			Iterator& operator ++ ()
			{
				ui1 _size = UTF8Char::Size(this->m_pointer);
				this->m_pointer += _size;
				return *this;
			}

			bool operator != (const Iterator& other) const
			{
				return m_pointer != other.m_pointer;
			}
		};

		UTF8String(const char* source);
		UTF8String(const char8_t* source);
		UTF8String(const char* source, ui4 length);
		UTF8String(const char8_t* source, ui4 length);

		const UTF8Char operator [] (const int index) const;
		const UTF8Char operator [] (const ui1 index) const;
		const UTF8Char operator [] (const ui2 index) const;
		const UTF8Char operator [] (const ui4 index) const;
		const UTF8Char operator [] (const ui8& index) const;

		operator LPCSTR () const noexcept;

		UTF8Memory ToMemory();

		Iterator begin() const noexcept
		{
			return Iterator{ m_pointer };
		}

		Iterator end() const noexcept
		{
			return Iterator{ m_pointer };
		}
	};

	class UTF8StringBuilder
	{
	private:
		char8_t* m_buffer;

	public:
		UTF8StringBuilder(ui4 capacity);
		UTF8StringBuilder(char* buffer, ui4 length);
		UTF8StringBuilder(char8_t* buffer, ui4 length);

		UTF8StringBuilder& Append(const ui1 source);
		UTF8StringBuilder& Append(const ui2 source);
		UTF8StringBuilder& Append(const ui4 source);
		UTF8StringBuilder& Append(const ui8& source);

		UTF8StringBuilder& Append(const si1 source);
		UTF8StringBuilder& Append(const si2 source);
		UTF8StringBuilder& Append(const si4 source);
		UTF8StringBuilder& Append(const si8& source);

		UTF8StringBuilder& Append(const sf4 source);
		UTF8StringBuilder& Append(const sf8& source);

		UTF8StringBuilder& Append(const char source);
		UTF8StringBuilder& Append(const char8_t source);

		UTF8StringBuilder& Append(const UTF8String& source);

		UTF8StringBuilder& AppendLine(const UTF8String& source);
		UTF8StringBuilder& AppendLine();
	};
}
