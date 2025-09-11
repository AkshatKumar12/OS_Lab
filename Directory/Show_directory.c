#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *dir;

    // Open current directory (.)
    d = opendir(".");
    if (d == NULL) {
        perror("opendir");
        return 1;
    }

    printf("Contents of current directory:\n");
    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }

    closedir(d);
    return 0;
}
