#include <math.h>
#include <stdio.h>

#include <omp.h>

#define NUMBER 47
#define NITERS 10000000000

static int fibbonacci(int n);

int main(void)
{
    printf("MAX_PRIORITY: %d\n", omp_get_max_task_priority());
#pragma omp parallel
    {
#pragma omp single
        {
            /* priority(50) final(1) */
#pragma omp task
            {
                /* fibbonacci(NUMBER); */
                printf("Thread num: %d\n", omp_get_thread_num());
                for (size_t i = 0; i < NITERS; ++i) {
                    if (i % 1000000000 == 0)
                        printf("Thread num: %d\n", omp_get_thread_num());
                }
                printf("Thread with priority 50 has finished.\n");
            }

            /* #pragma omp task priority(10) final(1) */
            /*             { */
            /*                 fibbonacci(NUMBER); */
            /*                 printf("Thread with priority 10 has finished.\n"); */
            /*             } */

            /* #pragma omp task priority(100) final(1) */
            /*             { */
            /*                 fibbonacci(NUMBER); */
            /*                 printf("Thread with priority 100 has finished.\n"); */
            /*             } */
        }
    }
    return 0;
}

static int fibbonacci(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return (fibbonacci(n - 1) + fibbonacci(n - 2));
    }
}
