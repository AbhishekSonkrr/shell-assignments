#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void cat_file(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) { perror(path); return; }
    char buf[4096];
    ssize_t n;
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        if (write(1, buf, n) != n) { perror("write"); break; }
    }
    if (n < 0) perror("read");
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // read from stdin and copy to stdout
        char buf[4096]; ssize_t n;
        while ((n = read(0, buf, sizeof(buf))) > 0) {
            if (write(1, buf, n) != n) { perror("write"); break; }
        }
        if (n < 0) perror("read");
    } else {
        for (int i = 1; i < argc; ++i) cat_file(argv[i]);
    }
    return 0;
}
