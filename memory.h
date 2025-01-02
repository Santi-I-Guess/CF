
#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

/* GROW CAPACITY, GROW_ARRAY, FREE_ARRAY */

void *reallocate(void *pointer, size_t old_size, size_t new_size);

#endif

