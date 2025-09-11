#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Listing files using execlp():\n");
    execlp("ls", "ls", "-l", NULL);

    // This line is reached only if execlp() fails
    perror("execlp failed");
    return 1;
}
