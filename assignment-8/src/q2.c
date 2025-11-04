#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    off_t file_size;
    char ch;

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

    file_size = lseek(src_fd, 0, SEEK_END);

    for (off_t i = file_size - 1; i >= 0; i--) {
        if (lseek(src_fd, i, SEEK_SET) == -1) {
            perror("Error seeking in source file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
        if (read(src_fd, &ch, 1) != 1) {
            perror("Error reading source file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
        if (write(dest_fd, &ch, 1) != 1) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }
    close(src_fd);
    close(dest_fd);
    printf("File \"%s\" reversed successfully into \"%s\"\n", argv[1], argv[2]);
    return 0;
}