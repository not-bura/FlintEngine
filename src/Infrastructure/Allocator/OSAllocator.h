#pragma once

#include "Domain/Type.h"

class OSAllocator
{
public:
	static void* Alloc(const size size);
	static void Free(void* pointer);
};
