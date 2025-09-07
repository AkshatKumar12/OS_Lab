#include <stdio.h>
#include <stdlib.h>

typedef struct prcs
{
    int id, arrivaltime, bursttime;

    int st, ct, wt, tat, rt, remainingtime;

} p;

int cmp(void *a, void *b)
{
    p *pa = (p *)a;
    p *pb = (p *)b;
    return (pa->arrivaltime - pb->arrivaltime);
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
        arr[i].arrivaltime = a;
        arr[i].bursttime = b;
        arr[i].remainingtime = b;
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
        int idx = -1;   // currnet candidate process
        int mintime = 100000007;    // current least time(INT_MAX) 
        for (int i = 0; i < n; i++)
        {
            if(arr[i].arrivaltime <= clock && arr[i].remainingtime >0)
            {
                if(arr[i].remainingtime < mintime)
                {
                    idx = i;
                    mintime = arr[i].remainingtime;
                }
            }
        }

        if(idx == -1){  // CPU IDLE
            clock++;
            continue;
        }

        // process coming for the first time
        if(arr[idx].bursttime == arr[idx].remainingtime)
        {
            arr[idx].st = clock;
        }

        arr[idx].remainingtime -- ; // executed for one cycle
        clock++;


        if(arr[idx].remainingtime == 0) // this process has completed its execution and so we can calculate rest all parameters
        {
            arr[idx].ct = clock;
            arr[idx].rt = arr[idx].st - arr[idx].arrivaltime;
            arr[idx].tat = arr[idx].ct - arr[idx].arrivaltime;
            arr[idx].wt = arr[idx].tat - arr[idx].bursttime;
        }
    }

    printf("ID  AT  bursttime  ST  CT  TAT RT  WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  %d  %d  %d  %d  %d  %d  %d \n", arr[i].id, arr[i].arrivaltime, arr[i].bursttime, arr[i].st, arr[i].ct, arr[i].tat, arr[i].rt, arr[i].wt);
    }

    return 0;
}