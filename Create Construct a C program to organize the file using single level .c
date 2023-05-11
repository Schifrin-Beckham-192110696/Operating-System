#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char *file_name;
    char *destination_dir;
    char destination_path[256];

    if (argc != 3) {
        printf("Usage: %s <file_name> <destination_dir>\n", argv[0]);
        return 1;
    }

    file_name = argv[1];
    destination_dir = argv[2];

    struct stat st;
    if (stat(destination_dir, &st) == -1) {
        printf("Error: destination directory does not exist\n");
        return 1;
    }

    if (!S_ISDIR(st.st_mode)) {
        printf("Error: destination is not a directory\n");
        return 1;
    }

    snprintf(destination_path, sizeof(destination_path), "%s/%s", destination_dir, file_name);

    if (rename(file_name, destination_path) != 0) {
        printf("Error: failed to move file\n");
        return 1;
    }

    printf("File moved to destination directory\n");

    return 0;
}
