#include <stdio.h>

int main()
{
    int block_size[] = {100, 200, 300, 500};
    int process_size[] = {50, 100, 150, 250};
    int best_fit = -1;
    int allocation[20];

    for (int i; i < 20; i++)
    {
        allocation[i] = -1;
    }
    int j = 0;
    for (int i = 0; i < 4; i++)
    {
        if (block_size[i] >= process_size[i])
        {
            if (best_fit == -1)
            {
                best_fit = j + 1;
            }
            else if (block_size[best_fit] >= process_size[best_fit])
            {
                best_fit = j + 1;
            }
        }
        j++;

        if (best_fit == -1)
        {
            allocation[i] = best_fit;
            block_size[best_fit] -= process_size[i];
        }
    }

    return 0;
}
