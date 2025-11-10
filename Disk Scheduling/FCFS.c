#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d",&n);

    printf("Enter the entries: ");
    int arr[n];
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int look_ups = 0;
    for(int i = 0;i<n-1;i++)
    {
        look_ups += abs(arr[i] - arr[i+1]);
    }
    printf("The number of look-ups is: %d\n",look_ups);
return 0;
}