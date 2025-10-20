#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("fopen");
        return 1;
    }
    int c, blanks = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c == ' ') blanks++;
    }
    fclose(f);
    printf("Blanks: %d\n", blanks);
    return 0;
}
