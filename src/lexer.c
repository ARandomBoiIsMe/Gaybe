#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/lexer.h"
#include "include/general_util.h"
#include "include/lexer_util.h"

Token* tokenize(char* source) {
    Token* tokens = NULL;
    int tokenCount = 0;

    while (*source != '\0') {
        // Skips whitespace
        if (isspace(*source)) {
            source++;
            continue;
        }

        // Handles keywords and identifiers
        if (isalpha(*source) || *source == '_') {
            char* startOfTokenValue = source;

            while (isalnum(*source) || *source == '_') {
                source++;
            }

            char* value = custom_strndup(startOfTokenValue, source - startOfTokenValue);
            TokenType type = isKeyword(&value) == 1 ? KEYWORD : IDENTIFIER;

            Token token = {value, type};
            insertToken(&tokens, &token, &tokenCount);

            continue;
        }

        else {
            printf("%c", *source);
            source++;
            continue;
        }
    }

    Token token = {"", END_OF_FILE};
    insertToken(&tokens, &token, &tokenCount);

    return tokens;
}