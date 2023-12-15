#include <stdio.h>

int main()
{
    int n, np, mem_space[20], process_space[20], allocation[20];
    printf("enter the no. of blocks availabe : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("space in block %d : ", i + 1);
        scanf("%d", &mem_space[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Size of process %d : ", i + 1);
        scanf("%d", &process_space[i]);
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (mem_space[i] >= process_space[i])
        {
            allocation[j] = i + 1;
            j++;
            mem_space[i] -= process_space[i];
        }
    }

    printf("\nprocess No.\tprocess size\tblock_allocated\tspace available\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, process_space[i], allocation[i], mem_space[i]);
    }
    return 0;
}
