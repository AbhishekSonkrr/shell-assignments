#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_perms(mode_t m) {
    printf( (m & S_IRUSR) ? "r" : "-" );
    printf( (m & S_IWUSR) ? "w" : "-" );
    printf( (m & S_IXUSR) ? "x" : "-" );
    printf( (m & S_IRGRP) ? "r" : "-" );
    printf( (m & S_IWGRP) ? "w" : "-" );
    printf( (m & S_IXGRP) ? "x" : "-" );
    printf( (m & S_IROTH) ? "r" : "-" );
    printf( (m & S_IWOTH) ? "w" : "-" );
    printf( (m & S_IXOTH) ? "x" : "-" );
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file...\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        struct stat sb;
        if (stat(argv[i], &sb) != 0) { perror(argv[i]); continue; }
        printf("File: %s\n", argv[i]);
        printf("Type: ");
        if (S_ISREG(sb.st_mode)) printf("regular file\n");
        else if (S_ISDIR(sb.st_mode)) printf("directory\n");
        else if (S_ISLNK(sb.st_mode)) printf("symbolic link\n");
        else printf("other\n");
        printf("Links: %ld\n", (long)sb.st_nlink);
        printf("Last access: %s", ctime(&sb.st_atime));
        printf("Permissions: "); print_perms(sb.st_mode); printf("\n\n");
    }
    return 0;
}
