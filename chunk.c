#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void init_chunk(Chunk* chunk) {
        chunk->count = 0;
        chunk->capacity = 0;
        chunk->code = NULL;
        init_ValueArray(&chunk->constants);
}

void free_chunk(Chunk *chunk) {
        int old_capacity = sizeof(uint8_t) * chunk->capacity;
        reallocate(chunk->code, old_capacity, 0);
        free_ValueArray(&chunk->constants);
        init_chunk(chunk);
}

void write_chunk(Chunk *chunk, uint8_t byte) {
        if (chunk->capacity == chunk->count) {
                int old_capacity = chunk->capacity;
                chunk->capacity = (old_capacity < 8) ? 8 : 2 * old_capacity;
                chunk->code = (uint8_t*)reallocate(chunk->code, old_capacity,
                                                   chunk->capacity);
        }
        chunk->code[chunk->count] = byte;
        chunk->count++;
}

int add_constant(Chunk *chunk, Value value) {
        write_ValueArray(&chunk->constants, value);
        return chunk->constants.count - 1;
}
