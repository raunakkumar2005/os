#include <stdio.h>

int main()
{
    int awt = 0;
    int att = 0;
    int n, bt[20], wt[20], tt[20];

    printf("Enter the no. of processes : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter the burst time of %dth process : ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        tt[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        att = att + bt[i];
    }

    att /= n;
    awt /= n;

    printf("\nProcess\t\tBurst time\twaiting time\tturnaround time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
    }

    printf("Average waiting time = %d\n", awt);
    printf("Average turn around time = %d\n", att);

    return 0;
}
