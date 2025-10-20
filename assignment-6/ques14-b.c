#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }
    char buf[4096];
    ssize_t n;
    int blanks = 0;
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        for (ssize_t i = 0; i < n; ++i) if (buf[i] == ' ') blanks++;
    }
    if (n < 0) { perror("read"); close(fd); return 1; }
    close(fd);
    printf("Blanks: %d\n", blanks);
    return 0;
}
