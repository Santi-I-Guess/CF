#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

void* reallocate(void* pointer, size_t old_size, size_t new_size);

#endif
