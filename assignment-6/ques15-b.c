#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int c;
    int lines = 0, words = 0, chars = 0;
    int inword = 0;
    printf("Enter text (Ctrl+D to end):\n");
    while ((c = getchar()) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) {
            if (inword) { words++; inword = 0; }
        } else {
            inword = 1;
        }
    }
    if (inword) words++;
    printf("Lines: %d Words: %d Characters: %d\n", lines, words, chars);
    return 0;
}
