#include <stdio.h>
#include <stdlib.h>

int frames, n;

int finder(int val, int ram[]) {
    for (int i = 0; i < frames; i++) {  // add a set to go from O(n)  --> O(1), but will need O(log n) to remmove element.
        if (ram[i] == val) {
            return 1;
        }
    }
    return 0;
}

void process(int val, int ram[]) {
    for (int i = 0; i < frames - 1; i++) {      // replace by queue to go from O(n)  --> O(1)
        ram[i] = ram[i + 1];
    }
    ram[frames - 1] = val;
}

int main() {
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of queries: ");
    scanf("%d", &n);

    int arr[n], ram[frames];

    for (int i = 0; i < frames; i++)
        ram[i] = -1;

    printf("Enter the array of pages: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Processing......\n");
    int hit = 0, miss = 0;

    for (int i = 0; i < n; i++) {       // add above fixes to go from O(n^2) to O(nlogn)
        if (finder(arr[i], ram)) {
            hit++;
        } else {
            process(arr[i], ram);
            miss++;
        }
    }

    printf("\nNumber of hits: %d", hit);
    printf("\nNumber of misses: %d\n", miss);

    return 0;
}
