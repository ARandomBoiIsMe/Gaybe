#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/general_util.h"

int isGayFile(char* filename) {
    char* dot = strrchr(filename, '.');

    // Is there a dot? Is it the only character in the file?
    if (!dot || strcmp(dot, filename) == 0) {
        return 0;
    }

    char* extension = dot + 1; // Gets next substring after found character
    if (strcmp(extension, "gay") == 0) {
        return 1;
    }

    return 0;
}

char* readFileContents(FILE* file) {
    int fileLength;

    fseek(file, 0, SEEK_END); // Moves to the end of the file
    fileLength = ftell(file); // Gets current position of file cursor
    fseek(file, 0, SEEK_SET); // Moves back to the begininng of the file

    char* fileContent = malloc(fileLength + 1);
    if (fileContent == NULL) {
        printf("Error while reading file.");
        return fileContent;
    }

    // Reads bytes from file until end of file is reached
    fread(fileContent, 1, fileLength, file);
    fclose(file);

    fileContent[fileLength] = '\0';

    return fileContent;
}

// Got this from Stack Overflow.
// strndup isn't part of the custom C library, so I had to get another implementation.
char* custom_strndup(char* s, int n) {
    char *p;
    int n1;

    for (n1 = 0; n1 < n && s[n1] != '\0'; n1++)
        continue;

    p = malloc(n1 + 1);
    if (p != NULL) {
        memcpy(p, s, n1);
        p[n1] = '\0';
    }

    return p;
}

void freeTokens(Token** tokens) {
    // Frees memory from dynamically-generated values
    for (int i = 0; (*tokens)[i].type != END_OF_FILE; i++) {
        if (
            (*tokens)[i].type == IDENTIFIER || (*tokens)[i].type == KEYWORD ||
            (*tokens)[i].type == STRING_LITERAL || (*tokens)[i].type == INTEGER_LITERAL
        ) {
            free((*tokens)[i].value);
        }
    }

    // Frees memory from tokens (obv)
    free(*tokens);
}