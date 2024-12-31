#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm; 

static void reset_stack() {
        vm.stack_top = vm.stack;
}

void init_VM() {
        reset_stack();
}

void free_VM() {
}

void push(Value value) {
        *vm.stack_top = value;
        vm.stack_top++;
}

Value pop() {
        vm.stack_top--;
        return *vm.stack_top;
}

static InterpretResult run() {
        // #define READ_BYTE() (*vm.ip++)
        // #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
        for (;;) { /* wtf will change later */
#ifdef DEBUG_TRACE_EXECUTION
        printf("          ");
        for (Value *slot = vm.stack; slot < vm.stack_top; slot++) {
                printf("[ ");
                print_Value(*slot);
                printf(" ]");
        }
        printf("\n");
        disassemble_instruction(vm.chunk,(int)(vm.ip - vm.chunk->code));
#endif

                uint8_t instruction;
                switch (instruction = *vm.ip++) {
                        case OP_CONSTANT: {
                                Value constant = vm.chunk->constants.values[*vm.ip++];
                                push(constant);
                                break;
                        }
                        case OP_RETURN: {
                                print_Value(pop());
                                printf("\n");
                                return INTERPRET_OK;
                        }
                }
        }
}

InterpretResult interpret(Chunk* chunk) {
        vm.chunk = chunk;
        vm.ip = vm.chunk->code;
        return run();
}
