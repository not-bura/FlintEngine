#include "OSAllocator.h"
#include <Domain/Type.h>
#include <malloc.h>

void* OSAllocator::Alloc(const size size)
{
	return malloc(size);
}

void OSAllocator::Free(void* pointer)
{
	free(pointer);
}
