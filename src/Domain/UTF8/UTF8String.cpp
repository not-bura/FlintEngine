#include "UTF8.h"
#include "Domain/Type.h"
#include <Windows.h>

using namespace FlintEngine;

namespace
{
	static ui4 CountInternal(const char8_t* source)
	{
		ui4 _count = 0;
		ui4 _index = 0;

		while (source[_index] != '\0')
		{
			++_count;
			const auto _pointer = source + _index;

			_index += UTF8Char::Size(_pointer);
		}

		return _count;
	}

	static ui4 LengthInternal(const char8_t* source)
	{
		ui4 _index = 0;

		while (source[_index] != '\0')
		{
			const auto _pointer = source + _index;

			_index += UTF8Char::Size(_pointer);
		}

		return _index;
	}
}

UTF8String::UTF8String(const char* source)
	: m_pointer(reinterpret_cast<const char8_t*>(source))
	, m_length(LengthInternal(reinterpret_cast<const char8_t*>(source)))
{
}

UTF8String::UTF8String(const char8_t* source)
	: m_pointer(source)
	, m_length(LengthInternal(source))
{
}

UTF8String::UTF8String(const char* source, ui4 length)
	: m_pointer(reinterpret_cast<const char8_t*>(source))
	, m_length(length)
{
}

UTF8String::UTF8String(const char8_t* source, ui4 length)
	: m_pointer(source)
	, m_length(length)
{
}

const UTF8Char UTF8String::operator [] (const int index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8String::operator [] (const ui1 index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8String::operator [] (const ui2 index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8String::operator [] (const ui4 index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8String::operator [] (const ui8& index) const
{
	return UTF8Char{ m_pointer + index };
}

UTF8String::operator LPCSTR() const noexcept
{
	return (LPCSTR)m_pointer;
}
