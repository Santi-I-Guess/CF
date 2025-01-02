#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

void *reallocate(void *pointer, size_t old_size, size_t new_size) {
        if (new_size == 0) {
                if (pointer == NULL) {
                        fprintf(stderr, "realloc tried to free a NULL ptr\n");
                        fprintf(stderr, "\told size: %lu\n", old_size);
                } else {
                        free(pointer);
                }
                return NULL;
        }

        void *result;
        if (pointer == NULL) {
                result = malloc(new_size);
        } else {
                result = realloc(pointer, new_size);
        }

        if (result == NULL) {
                fprintf(stderr, "memory.c failed\n");
                exit(1);
        }
        return result;
}

