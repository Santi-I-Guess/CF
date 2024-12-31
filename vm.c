#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm; 

void init_VM() {
}

void free_VM() {
}

static InterpretResult run() {
        // #define READ_BYTE() (*vm.ip++)
        // #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
        for (;;) { /* wtf will change later */
#ifdef DEBUG_TRACE_EXECUTION
        disassemble_instruction(vm.chunk,(int)(vm.ip - vm.chunk->code));
#endif

                uint8_t instruction;
                switch (instruction = *vm.ip++) {
                        case OP_CONSTANT: {
                                Value constant = vm.chunk->constants.values[*vm.ip++];
                                print_Value(constant);
                                printf("\n");
                                break;
                        }
                        case OP_RETURN: {
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
