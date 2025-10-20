#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[1] : ".";
    DIR *d = opendir(path);
    if (!d) { perror(path); return 1; }
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(d);
    return 0;
}
