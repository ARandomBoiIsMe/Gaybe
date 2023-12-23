#include <string.h>
#include <stdlib.h>

int isKeyword(char* word) {
    char* keywords[] = {"if", "while", "output", "input"};

    for (int i = 0; i < 2; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    
    return 0;
}

// Got this from Stack Overflow.
// strndup isn't part of the custom C library, so I had to get another implementation.
char* custom_strndup(char *s, int n) {
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