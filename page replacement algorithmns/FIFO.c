#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct q{
    int *arr;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->arr = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int val) {
    if (q->size == q->capacity) {

        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}


bool finder(int val, bool *hashSet) {
    return hashSet[val];
}

int main() {
    int frames, n;
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of queries: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the array of pages: ");
    int maxPage = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > maxPage) maxPage = arr[i];
    }

    bool *hashSet = (bool*)calloc(maxPage + 1, sizeof(bool)); 
    Queue* q = createQueue(frames);

    int hit = 0, miss = 0;

    printf("\nProcessing......\n");
    for (int i = 0; i < n; i++) {
        int page = arr[i];
        if (finder(page, hashSet)) {
            hit++;
        } else {
            miss++;
            if (q->size == frames) {
                int oldPage = q->arr[q->front];
                hashSet[oldPage] = false;
            }
            enqueue(q, page);
            hashSet[page] = true;
        }
    }

    printf("\nNumber of hits: %d", hit);
    printf("\nNumber of misses: %d\n", miss);

    free(arr);
    free(hashSet);
    free(q->arr);
    free(q);
    return 0;
}
