#include "UTF8.h"
#include "Domain/Type.h"

using namespace FlintEngine;

namespace
{
	[[nodiscard]] constexpr static ui1 LengthInternal(const char8_t head) noexcept
	{
		// 上位4ビットで表現される全16パターンに対するバイト数のテーブル
		// ニブル(4bit)毎にレスポンスを詰めた64bit整数
		// パターン:
		//  0x0~0x7 (0000~0111) -> 1byte (ASCII)
		//  0x8~0xB (1000~1011) -> 1byte (無効な先頭バイト/後続バイト。1として扱うかエラー判定)
		//  0xC~0xD (1100~1101) -> 2bytes
		//  0xE     (1110)      -> 3bytes
		//  0xF     (1111)      -> 4bytes

		// 64bit値の中に各ニブルごとの長さを格納 (4bit × 16 = 64bit)
		// インデックス:  F E D C  B A 9 8  7 6 5 4  3 2 1 0
		// バイト長:     4 3 2 2  1 1 1 1  1 1 1 1  1 1 1 1
		constexpr ui8 LENGTH_TABLE = 0x4322'1111'1111'1111ULL;

		const ui1 byte = static_cast<ui1>(head);
		const ui1 nibble = byte >> 4; // 上位4ビットを取得 (0~15)

		// ニブルに応じて4ビットシフトし、0xFでマスク
		return (LENGTH_TABLE >> (nibble * 4)) & 0x0F;
	}
}

UTF8Char::UTF8Char(const char8_t* value)
	: m_pointer(value)
{
}

ui1 UTF8Char::GetSize() const
{
	return LengthInternal(m_pointer[0]);
}

ui1 UTF8Char::Size(const char* source)
{
	return LengthInternal(static_cast<char8_t>(source[0]));
}

ui1 UTF8Char::Size(const char8_t* source)
{
	return LengthInternal(source[0]);
}
