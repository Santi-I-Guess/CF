#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

/* runs the chunks of code */
/* moral of the story: dereferences are faster than look-ups */
typedef struct {
        Chunk *chunk;
        uint8_t *ip; /* instruction pointer / program counter */
        Value stack[256];
        Value *stack_top;
} VM;

typedef enum {
        INTERPRET_OK,
        INTERPRET_COMPILE_ERROR,
        INTERPRET_RUNTIME_ERROR
} InterpretResult;

static void reset_stack();
void init_vm();
void free_vm();
InterpretResult interpret(Chunk *chunk);
static InterpretResult run();
void push(Value value);
Value pop();

#endif
