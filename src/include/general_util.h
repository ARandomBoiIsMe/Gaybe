#include <stdio.h>
#include "lexer_util.h"

#ifndef GENERAL_UTIL_H
#define GENERAL_UTIL_H

int isGayFile(char* filename);
char* readFileContents(FILE* file);
char* custom_strndup(char* s, int n);
void freeTokens(Token** tokens); // To be implemented

#endif