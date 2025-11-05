#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void) {
    for (int i = 0; i < 20; i++) {
        const char* msg = strerror(i);
        if (strcmp(msg, "Unknown error") != 0) {
            printf("Error %d: %s\n", i, msg);
        }
    }
    return 0;
}