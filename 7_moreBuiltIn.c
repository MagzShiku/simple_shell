#include "main.h"

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int mjCopyFl(const char* source_file, const char* destination_file) {
    FILE *source, *destination;
    int ch;

    source = fopen(source_file, "r");
    if (source == NULL) {
        fprintf(stderr, "Error: Failed to open source file\n");
        return -1;
    }

    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        fprintf(stderr, "Error: Failed to open destination file\n");
        fclose(source);
        return -1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully\n");
    return 0;
}

int mjListDir(const char* directory) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(directory);
    if (dir == NULL) {
        fprintf(stderr, "Error: Failed to open directory\n");
        return -1;
    }

    printf("Directory listing:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}

void mjPrintFile(const char* file_path) {
    FILE *file;
    int ch;

    file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        return;
    }

    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void helpMeHere() {
    printf("Help message:\n");
    printf("This is the help message. Replace this with your own help instructions.\n");
}

