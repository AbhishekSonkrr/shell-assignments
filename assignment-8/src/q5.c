#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat filestat;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (stat(argv[1], &filestat) < 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    printf("File: %s\n", argv[1]);
    printf("Permission bits (octal): %04o\n", filestat.st_mode & 07777);
    printf("Set-user-ID (S_ISUID): %s\n", (filestat.st_mode & S_ISUID) ? "SET" : "NOT SET");
    printf("Set-group-ID (S_ISGID): %s\n", (filestat.st_mode & S_ISGID) ? "SET" : "NOT SET");
    printf("Sticky Bit (S_ISVTX): %s\n", (filestat.st_mode & S_ISVTX) ? "SET" : "NOT SET");

    printf("\nOwner permissions:\n");
    printf("Read (S_IRUSR): %s\n", (filestat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Write (S_IWUSR): %s\n", (filestat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Execute (S_IXUSR): %s\n", (filestat.st_mode & S_IXUSR) ? "Yes" : "No");

    printf("\nGroup permissions:\n");
    printf("Read (S_IRGRP): %s\n", (filestat.st_mode & S_IRGRP) ? "Yes" : "No");
    printf("Write (S_IWGRP): %s\n", (filestat.st_mode & S_IWGRP) ? "Yes" : "No");
    printf("Execute (S_IXGRP): %s\n", (filestat.st_mode & S_IXGRP) ? "Yes" : "No");

    printf("\nOther permissions:\n");
    printf("Read (S_IROTH): %s\n", (filestat.st_mode & S_IROTH) ? "Yes" : "No");
    printf("Write (S_IWOTH): %s\n", (filestat.st_mode & S_IWOTH) ? "Yes" : "No");
    printf("Execute (S_IXOTH): %s\n", (filestat.st_mode & S_IXOTH) ? "Yes" : "No");

    return 0;
}