#include "UTF8.h"
#include <Domain/Type.h>

using namespace FlintEngine;

namespace
{
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

UTF8Memory::UTF8Memory(const char* source)
	: m_pointer(reinterpret_cast<const char8_t*>(source))
	, m_length(LengthInternal(reinterpret_cast<const char8_t*>(source)))
{
}

UTF8Memory::UTF8Memory(const char8_t* source)
	: m_pointer(source)
	, m_length(LengthInternal(source))
{
}

UTF8Memory::UTF8Memory(const char* source, ui4 length)
	: m_pointer(reinterpret_cast<const char8_t*>(source))
	, m_length(length)
{
}

UTF8Memory::UTF8Memory(const char8_t* source, ui4 length)
	: m_pointer(source)
	, m_length(length)
{
}

const UTF8Char UTF8Memory::operator [] (const int index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8Memory::operator [] (const ui1 index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8Memory::operator [] (const ui2 index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8Memory::operator [] (const ui4 index) const
{
	return UTF8Char{ m_pointer + index };
}

const UTF8Char UTF8Memory::operator [] (const ui8& index) const
{
	return UTF8Char{ m_pointer + index };
}

UTF8Memory::operator LPCSTR() const noexcept
{
	return (LPCSTR)m_pointer;
}


//char8_t* UTF8Memory::begin() noexcept
//{
//	return m_pointer;
//}
//
//char8_t* UTF8Memory::end() noexcept
//{
//	return m_pointer + m_length;
//}

const char8_t* UTF8Memory::begin() const noexcept
{
	return m_pointer;
}

const char8_t* UTF8Memory::end() const noexcept
{
	return m_pointer + m_length;
}
