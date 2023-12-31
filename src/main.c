#include <stdio.h>
#include <stdlib.h>
#include "include/general_util.h"
#include "include/lexer_util.h"
#include "include/lexer.h"

int main(int argc, char* argv[]) {
    // if (argc != 2) {
    //     printf("Usage: gaybe <file.gay>");
    //     return 1;
    // }

    char* filename = "../test.gay";
    if (isGayFile(filename) == 0) {
        printf("Invalid file: File must be gay.");
        return 1;
    }

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Invalid file: File does not exist.");
        return 1;
    }

    char* sourceCode = readFileContents(file);

    Token* tokens = tokenize(sourceCode);
    free(sourceCode);

    // Generate AST
    // Free token values
    // Free tokens

    for (int i = 0; tokens[i].type != END_OF_FILE; i++) {
        printf("Type: %d, Value: %s\n", tokens[i].type, tokens[i].value);
    }

    freeTokens(&tokens);
}