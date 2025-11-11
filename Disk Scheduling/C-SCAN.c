#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    int head = 0; 
    int disk_size = 199; 
    int total_movement = 0;

    printf("\n\nTotal head movement = %d\n", total_movement);
    return 0;
}
