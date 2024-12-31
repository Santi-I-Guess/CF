#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
        init_VM();

        Chunk chunk;
        init_Chunk(&chunk);

        int constant = add_constant(&chunk, 1.2);
        write_Chunk(&chunk, OP_CONSTANT, 123); /* 123 is an arbitrary line num */
        write_Chunk(&chunk, constant, 123);
        write_Chunk(&chunk, OP_NEGATE, 123);

        write_Chunk(&chunk, OP_RETURN, 123);

        disassemble_Chunk(&chunk, "test chunk");
        interpret(&chunk);
        free_VM();
        free_Chunk(&chunk);
        return 0;
}
