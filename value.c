#include <stdio.h>

#include "memory.h"
#include "value.h"

void init_ValueArray(ValueArray *array) {
        array->capacity = 0;
        array->count = 0;
        array->values = NULL;
}

void free_ValueArray(ValueArray *array) {
        int old_capacity = sizeof(Value) * array->capacity;
        reallocate(array->values, old_capacity, 0);
        init_ValueArray(array);
}

void write_ValueArray(ValueArray *array, Value value) {
        if (array->capacity == array->count) {
                int old_capacity = array->capacity;
                array->capacity = (old_capacity < 8) ? 8 : 2 * old_capacity;
                array->values = (Value*)reallocate(array->values, old_capacity,
                                                   array->capacity);
        }
        array->values[array->count] = value;
        array->count++;
}

void print_Value(Value value) {
        printf("%g", value);
}
