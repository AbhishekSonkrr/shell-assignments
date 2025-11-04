#include <stdio.h>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <target_file>\n", argv[0]);
        return 1;
    }

    struct stat src_stat;
    if (stat(argv[1], &src_stat) != 0) {
        perror("stat");
        return 1;
    }

    struct utimbuf new_times;
    new_times.actime = src_stat.st_atime;
    new_times.modtime = src_stat.st_mtime;

    if (utime(argv[2], &new_times) != 0) {
        perror("utime");
        return 1;
    }

    printf("Timestamps updated successfully.\n");
    return 0;
}