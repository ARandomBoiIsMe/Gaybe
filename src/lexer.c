#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils/lexer_util.h"
#include "utils/dynamic_token_array.h"
#include "lexer.h"

// Define Tokenize function, which returns a list of Tokens
Token* tokenize(char* sourceCode) {
    DynamicTokenArray tokens;
    initializeTokenArray(&tokens, 50);

    int codeLength = strlen(sourceCode);

    int cursor = 0;
    while (cursor <= codeLength) {
        // Skip whitespace
        if (isspace(sourceCode[cursor])) {
            cursor++;
            continue;
        }
    }
}