#include <stdlib.h>
#include <string.h>
#include "dynamic_token_array.h"
#include "lexer_util.h"

void initializeTokenArray(DynamicTokenArray* array, int size) {
    array->array = malloc(size * sizeof(Token));
    array->size = size;
    array->used = 0;
}

void insertToken(DynamicTokenArray* array, Token* token) {
    // Double total array size and allocate more memory to array
    if (array->used == array->size) {
        array->size *= 2;
        array->array = realloc(array->array, array->size * sizeof(Token));
    }

    // Dereferences and adds element to array, then increases used count
    array->array[array->used] = *token;
    array->used++;
}

void freeTokenArray(DynamicTokenArray* array) {
    free(array->array);
    array->size = 0;
    array->used = 0;
}