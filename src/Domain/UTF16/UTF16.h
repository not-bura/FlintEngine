#pragma once

#include "Domain/Type.h"

struct UTF16Char
{
private:
	ui2 m_value;

public:
	UTF16Char(const ui2 source);
	operator ui2() const;
};


