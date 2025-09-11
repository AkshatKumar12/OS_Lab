#include <stdio.h>
#include <stdlib.h>

typedef struct prcs
{
    int id;
    int at, bt;

    int rt, wt, tat, ct, st;
} p;

int cmp( void *a,  void *b)
{
     p *pa = ( p *)a;
     p *pb = ( p *)b;
    return (pa->at - pb->at);
}
int main()
{
    int n = 0;
    printf("Enter the number of preocesses: ");
    scanf("%d", &n);
    p arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for the %dth process :", i + 1); // INPUT
        int a, b;
        scanf("%d %d", &a, &b);
        arr[i].id = i;
        arr[i].at = a;
        arr[i].bt = b;

        arr[i].rt = arr[i].wt = arr[i].tat = arr[i].ct = arr[i].st = 0;
    }

    qsort(arr, n, sizeof(p), cmp); // SORTED

    int time_ellapsed = 0; // TIME ELLAPSED SO FAR.

    for (int i = 0; i < n; i++)
    {
        if (time_ellapsed < arr[i].at){
            time_ellapsed = arr[i].at;      // IDLE TIME
        }

        arr[i].st = time_ellapsed;
        time_ellapsed += arr[i].bt;
        arr[i].ct = time_ellapsed;

        arr[i].rt = arr[i].st - arr[i].at;
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
    }

    printf("ID  AT  BT  ST  CT  TAT RT  WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  %d  %d  %d  %d  %d  %d  %d \n", arr[i].id, arr[i].at, arr[i].bt, arr[i].st,arr[i].ct, arr[i].tat, arr[i].rt, arr[i].wt);
    }

    return 0;
}