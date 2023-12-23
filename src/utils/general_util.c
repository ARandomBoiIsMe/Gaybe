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