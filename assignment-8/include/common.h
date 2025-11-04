#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

void handle_error(const char *msg);
void print_permissions(mode_t mode);
void check_permission(mode_t mode, uid_t file_uid, gid_t file_gid, uid_t current_uid, gid_t current_gid);

#endif // COMMON_H