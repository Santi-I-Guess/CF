#include <stdio.h>

#include "memory.h"
#include "value.h"

void init_varray(ValueArray *array) {
        array->capacity = 0;
        array->count = 0;
        array->values = NULL;
}

void free_varray(ValueArray *array) {
        reallocate(array->values, sizeof(Value) * array->capacity, 0);
        init_varray(array);

}

void write_varray(ValueArray *array, Value value) {
        if (array->capacity == array->count) {
                int old_capacity = array->capacity;
                array->capacity = (old_capacity < 8) ? 8 : old_capacity * 2;
                array->values = (Value*)reallocate(array->values,
                                                   sizeof(Value) * old_capacity,
                                                   sizeof(Value) * array->capacity);
        }
        array->values[array->count] = value;
        array->count++;
}

void print_value(Value value) {
        printf("%g", value);
}
