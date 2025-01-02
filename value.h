#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;

/* constant pool */
typedef struct {
        int capacity;
        int count;
        Value *values;
} ValueArray;

void init_varray(ValueArray *array);
void write_varray(ValueArray *array, Value value);
void free_varray(ValueArray *array);
void print_value(Value value);

#endif
