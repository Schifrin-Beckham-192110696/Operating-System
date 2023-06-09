#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pattern> <file>\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];
    char *file = argv[2];

    FILE *fp = fopen(file, "r");
    if (!fp) {
        printf("Error: Unable to open file %s\n", file);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
