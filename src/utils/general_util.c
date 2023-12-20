#include <string.h>
#include <stdio.h>
#include "general_util.h"

int isGayFile(char* filename) {
    char extension[5] = ".";

    int length = strlen(filename);

    for (int i = 0; i < length; i++) {
        // Locates start of file extension
        if (filename[i] != '.') {
            continue;
        }

        // Appends the file extension type to the initial '.' of the array
        for (int j = 1; j <= 3; j++) {
            extension[j] = filename[i + j];
        }

        break;
    }

    // Ending character
    extension[4] = '\0';

    if (strcmp(extension, ".gay") == 0) {
        return 1;
    }

    return 0;
}