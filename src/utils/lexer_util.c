#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/general_util.h"
#include "../include/lexer_util.h"

void skipWhitespace(char** source) {
    while (**source != '\0' && isspace(**source)) {
        (*source)++;
    }
}

Token generateIdentifierOrKeywordToken(char** source) {
    char* startOfTokenValue = *source;

    while (**source != '\0' && (isalnum(**source) || **source == '_')) {
        (*source)++;
    }

    char* value = custom_strndup(startOfTokenValue, *source - startOfTokenValue);
    TokenType type = isKeyword(&value) == 1 ? KEYWORD : IDENTIFIER;

    return (Token){value, type};
}

Token generateStringLiteralToken(char** source) {
    (*source)++; // Skips over opening quote

    // Retrieves string content
    char* startOfTokenValue = *source;

    while (**source != '\0' && **source != '\"') {
        (*source)++;
    }

    char* value = custom_strndup(startOfTokenValue, *source - startOfTokenValue);

    (*source)++; // Skips over closing quote

    return (Token){value, STRING_LITERAL};
}

Token generateIntegerLiteralToken(char** source) {
    char* startOfTokenValue = *source;

    while (**source != '\0' && isdigit(**source)) {
        (*source)++;
    }

    char* value = custom_strndup(startOfTokenValue, *source - startOfTokenValue);

    return (Token){value, INTEGER_LITERAL};
}

Token generateOperatorToken(char** source, char* value, TokenType type) {
    // Moves past operator
    int length = strlen(value);
    (*source) += length;

    return (Token){value, type};
}

Token generateSymbolToken(char** source, char* value, TokenType type) {
    // Moves past symbol
    (*source)++;

    return (Token){value, type};
}

int isKeyword(char** word) {
    char* keywords[] = {"if", "while", "output", "input", "str", "int", "bool", 
                        "char", "var", "true", "false"};

    for (int i = 0; i < 11; i++) {
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