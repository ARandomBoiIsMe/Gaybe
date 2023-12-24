#include <stdio.h>

#ifndef GENERAL_UTIL_H
#define GENERAL_UTIL_H

int isGayFile(char* filename);
char* readFileContents(FILE* file);
char* custom_strndup(char* s, int n);

#endif