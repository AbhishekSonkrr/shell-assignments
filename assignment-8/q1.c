#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    ssize_t nread;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sourcefile> <destinationfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening/creating destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    while ((nread = read(src_fd, buffer, BUF_SIZE)) > 0) {
        if (write(dest_fd, buffer, nread) != nread) {
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }
    if (nread < 0) {
        perror("Error reading source file");
    }
    close(src_fd);
    close(dest_fd);
    printf("File copied successfully from \"%s\" to \"%s\"\n", argv[1], argv[2]);
    return 0;
}