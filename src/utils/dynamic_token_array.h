#include "lexer_util.h"

#ifndef DYNAMIC_TOKEN_ARRAY_H
#define DYNAMIC_TOKEN_ARRAY_H

typedef struct
{
    Token* array;
    int size;
    int used;
} DynamicTokenArray;

void initializeTokenArray(DynamicTokenArray* array, int size);
void insertToken(DynamicTokenArray* array, Token* token);
void freeTokenArray(DynamicTokenArray* array);

#endif