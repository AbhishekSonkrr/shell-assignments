#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int c, lines = 0, words = 0, chars = 0, inword = 0;
    while ((c = getchar()) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) {
            if (inword) { words++; inword = 0; }
        } else inword = 1;
    }
    if (inword) words++;
    printf("Lines: %d Words: %d Characters: %d\n", lines, words, chars);
    return 0;
}
