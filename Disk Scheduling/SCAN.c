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

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    printf("\nSCAN Disk Scheduling Order (starting at 0):\n");
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            printf("%d -> ", requests[i]);
            total_movement += abs(requests[i] - head);
            head = requests[i];
        }
    }

    if (head != disk_size) {
        total_movement += abs(disk_size - head);
        head = disk_size;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (requests[i] < head) {
            printf("%d -> ", requests[i]);
            total_movement += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("\n\nTotal head movement = %d\n", total_movement);
    return 0;
}
