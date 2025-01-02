#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm; 

void init_vm() {
}

void free_vm() {
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

        while (1) {
#ifdef DEBUG_TRACE_EXECUTION
        disassemble_instruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
                uint8_t instruction;
                switch (instruction = *vm.ip++) {
                        case OP_CONSTANT: {
                                Value constant = vm.chunk->constants.values[*vm.ip++];
                                print_value(constant);
                                printf("\n");
                                break;
                        }
                        case OP_RETURN: {
                                return INTERPRET_OK;
                        }
                }
        }

}
