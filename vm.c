#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm; 

static void reset_stack() {
        vm.stack_top = vm.stack;
}

void init_vm() {
        reset_stack();
}

void free_vm() {
}

void push(Value value) {
        *vm.stack_top = value;
        vm.stack_top++;
}

Value pop() {
        vm.stack_top--;
        return *vm.stack_top;
}

InterpretResult interpret(Chunk *chunk) {
        vm.chunk = chunk;
        vm.ip = vm.chunk->code;
        return run();
}

/* actually runs the bytecode */
static InterpretResult run() {
/* #define READ_BYTE() (*vm.ip++) */
/* #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()]) */
/* #define BINARY_OP(op) */

        while (1) {
#ifdef DEBUG_TRACE_EXECUTION
        disassemble_instruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
        printf("          ");
        for (Value *slot = vm.stack; slot < vm.stack_top; slot++) {
                printf("[ ");
                print_value(*slot);
                printf(" ]");
        }
        printf("\n");
#endif
                uint8_t instruction;
                switch (instruction = *vm.ip++) {
                        case OP_CONSTANT: {
                                Value constant = vm.chunk->constants.values[*vm.ip++];
                                push(constant);
                                break;
                        }
                        case OP_ADD: {
                                Value b = pop();
                                Value a = pop();
                                push(a + b);
                                break;
                        }
                        case OP_SUBTRACT: {
                                Value b = pop();
                                Value a = pop();
                                push(a - b);
                                break;
                        }
                        case OP_MULTIPLY: {
                                Value b = pop();
                                Value a = pop();
                                push(a * b);
                                break;
                        }
                        case OP_DIVIDE: {
                                Value b = pop();
                                Value a = pop();
                                push(a / b);

                        }
                        case OP_NEGATE: {
                                push(-pop());
                                break;
                        }
                        case OP_RETURN: {
                                print_value(pop());
                                printf("\n");
                                return INTERPRET_OK;
                        }
                }
        }

}
