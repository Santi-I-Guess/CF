#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

typedef struct {
        Chunk *chunk;
        uint8_t *ip; /* instruction pointer */
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

void init_VM();
void free_VM();
InterpretResult interpret(Chunk* chunk);

#endif

