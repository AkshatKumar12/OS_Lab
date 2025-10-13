#include <stdio.h>
#include <limits.h>

int isPresent(int pages[], int capacity, int key) {
    for (int i = 0; i < capacity; i++) {
        if (pages[i] == key)
            return 1;
    }
    return 0;
}

int findLRU(int lastUsed[], int capacity) {
    int min = lastUsed[0], pos = 0;
    for (int i = 1; i < capacity; i++) {
        if (lastUsed[i] < min) {
            min = lastUsed[i];
            pos = i;
        }
    }
    return pos;
}

int pageFaults(int pages[], int n, int capacity) {
    int frame[capacity];
    int lastUsed[capacity];
    int page_faults = 0;
    int time = 0;

  
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        lastUsed[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int current = pages[i];

     
        if (!isPresent(frame, capacity, current)) {
            int replaceIndex = -1;

         
            for (int j = 0; j < capacity; j++) {
                if (frame[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex == -1) {
                replaceIndex = findLRU(lastUsed, capacity);
            }

            frame[replaceIndex] = current;
            page_faults++;
        }

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == current)
                lastUsed[j] = ++time;
        }
    }

    return page_faults;
}

int main() {
    int n;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    int capacity;
    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    printf("Total Page Faults = %d\n", pageFaults(pages, n, capacity));

    return 0;
}
