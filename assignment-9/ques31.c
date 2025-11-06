#include <stdio.h>    /* printf, fprintf, perror */
#include <stdlib.h>   /* exit codes, not strictly required here */
#include <sys/stat.h> /* struct stat, stat() */
#include <utime.h>    /* struct utimbuf, utime() */

/* Simple program: copy access and modification times from source -> target */
int main(int argc, char *argv[]) {
    /* argc should be 3: program name, source_file, target_file */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file target_file\n", argv[0]);
        return 1; /* non-zero indicates error */
    }

    /* filenames from command line */
    const char *src = argv[1];
    const char *dst = argv[2];

    /* get metadata of source file */
    struct stat sb;
    if (stat(src, &sb) != 0) {
        /* stat failed (e.g., file doesn't exist or permission denied) */
        perror("stat(source)");
        return 1;
    }

    /* prepare utimbuf with access and modification times from source */
    struct utimbuf times;
    times.actime  = sb.st_atime;  /* last access time (time_t) */
    times.modtime = sb.st_mtime;  /* last modification time (time_t) */

    /* apply timestamps to target file */
    if (utime(dst, &times) != 0) {
        /* utime failed (e.g., target doesn't exist or no permission) */
        perror("utime(target)");
        return 1;
    }

    /* success message */
    printf("\nTimestamps of '%s' updated to match '%s'.\n", dst, src);
    return 0; /* success */
}