#include <stdio.h>
#include "utils/general_util.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: gaybe <file.gay>");
        return 1;
    }

    char* filename = argv[1];
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
    printf(sourceCode);
}