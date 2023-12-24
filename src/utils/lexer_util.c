#include <string.h>
#include <stdlib.h>
#include "../include/lexer_util.h"

int isKeyword(char** word) {
    char* keywords[] = {"if", "while", "output", "input"};

    for (int i = 0; i < 2; i++) {
        if (strcmp(*word, keywords[i]) == 0) {
            return 1;
        }
    }
    
    return 0;
}

void insertToken(Token** tokens, Token* token, int* tokenCount) {
    *tokens = realloc(*tokens, (*tokenCount + 1) * sizeof(Token));
    (*tokens)[*tokenCount] = *token;
    (*tokenCount)++;
}

char peek(char** source) {
    if (*(*source + 1) != '\0') {
        return *(*source + 1);
    }

    return '\0';
}