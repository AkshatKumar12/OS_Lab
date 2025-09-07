#include <stdio.h>
#include <stdlib.h>

typedef struct prcs
{
    int id, at, bt;

    int st, ct, wt, tat, rt;

} p;

int cmp(void *a, void *b)
{
    p *pa = (p *)a;
    p *pb = (p *)b;
    return (pa->at - pb->at);
}

int main()
{

    int n = 0;
    scanf("%d", &n);

    p arr[n];

    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        arr[i].id = i;
        arr[i].at = a;
        arr[i].bt = b;
    }

    int completed = 0;
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    qsort(arr, n, sizeof(p), cmp);
    int clock = 0;
    while (completed < n)
    {
        int idx = -1;
        int min_bt = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && arr[i].at <= clock)
            {
                if (arr[i].bt < min_bt)
                {
                    min_bt = arr[i].bt;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            clock++;
            continue;
        }
        arr[idx].st = clock;
        arr[idx].ct = clock + arr[idx].bt;
        arr[idx].tat = arr[idx].ct - arr[idx].at;
        arr[idx].wt = arr[idx].tat - arr[idx].bt;
        arr[idx].rt = arr[idx].st - arr[idx].at;

        clock = arr[idx].ct;
        vis[idx] = 1;
        completed++;
    }

    printf("ID  AT  BT  ST  CT  TAT RT  WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  %d  %d  %d  %d  %d  %d  %d \n", arr[i].id, arr[i].at, arr[i].bt, arr[i].st, arr[i].ct, arr[i].tat, arr[i].rt, arr[i].wt);
    }

    return 0;
}