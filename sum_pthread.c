#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

int sum = 0;
int n;

void *sum_n(void *arg)
{
    int thread_id = *(int *)arg;
    int start = thread_id * (n / MAX_THREADS) + 1;
    int end = (thread_id + 1) * (n / MAX_THREADS);
    int local_sum = 0;
    for (int i = start; i <= end; i++)
    {
        local_sum += i;
    }
    sum += local_sum;
    return NULL;
}

int main()
{
    printf("Enter the value of n: ");
    scanf("%d", &n);

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum_n, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of first %d natural numbers is %d.\n", n, sum);
    return 0;
}
