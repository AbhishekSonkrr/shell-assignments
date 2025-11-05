#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void check_permission(mode_t mode, uid_t file_uid, gid_t file_gid, uid_t current_uid, gid_t current_gid) {
    if (current_uid == file_uid) {
        printf("Owner has: ");
        if (mode & S_IRUSR) printf("Read ");
        if (mode & S_IWUSR) printf("Write ");
        if (mode & S_IXUSR) printf("Execute ");
        printf("permissions\n");
    } else if (current_gid == file_gid) {
        printf("Group has: ");
        if (mode & S_IRGRP) printf("Read ");
        if (mode & S_IWGRP) printf("Write ");
        if (mode & S_IXGRP) printf("Execute ");
        printf("permissions\n");
    } else {
        printf("Others have: ");
        if (mode & S_IROTH) printf("Read ");
        if (mode & S_IWOTH) printf("Write ");
        if (mode & S_IXOTH) printf("Execute ");
        printf("permissions\n");
    }
}

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
    uid_t current_uid = getuid();
    gid_t current_gid = getgid();
    printf("File: %s\n", argv[1]);
    printf("Owner UID: %d, Group GID: %d\n", filestat.st_uid, filestat.st_gid);
    check_permission(filestat.st_mode, filestat.st_uid, filestat.st_gid, current_uid, current_gid);
    return 0;
}