#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f) { perror("fopen"); return 1; }
    int c, lines = 0, words = 0, chars = 0, inword = 0;
    while ((c = fgetc(f)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) {
            if (inword) { words++; inword = 0; }
        } else inword = 1;
    }
    if (inword) words++;
    fclose(f);
    printf("Lines: %d Words: %d Characters: %d\n", lines, words, chars);
    return 0;
}
