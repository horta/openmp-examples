#include <math.h>
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <omp.h>

#define NUMBER 20

static long fibbonacci(long n);

inline void elapsed_sleep(double seconds)
{
#ifdef _WIN32
    Sleep((DWORD)(seconds * 1000));
#else
    usleep((useconds_t)(seconds * 1000 * 1000));
#endif
}

int main(int argc, char* argv[])
{
    if (omp_get_max_task_priority() != 100) {
        printf("Please, enter `export OMP_MAX_TASK_PRIORITY=100` before-hand.\n");
        return 1;
    }

    /* if (argc < 2) { */
    /*     printf("Usage: %s NUM_THREADS\n", argv[0]); */
    /*     return 1; */
    /* } */

    /* int num_threads = atoi(argv[1]); */
    /* omp_set_num_threads(num_threads); */

#pragma omp        parallel default(none)
    {
#pragma omp single nowait
        {
#pragma omp task priority(50)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 50 has finished (%ld).\n", val);
            }

#pragma omp task priority(10)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 10 has finished (%ld).\n", val);
            }

#pragma omp task priority(100)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 100 has finished (%ld).\n", val);
            }

#pragma omp task priority(0)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 0 has finished (%ld).\n", val);
            }

#pragma omp task priority(5)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 5 has finished (%ld).\n", val);
            }

#pragma omp task priority(80)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 80 has finished (%ld).\n", val);
            }

#pragma omp task priority(25)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 25 has finished (%ld).\n", val);
            }

#pragma omp task priority(15)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 15 has finished (%ld).\n", val);
            }

#pragma omp task priority(35)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 35 has finished (%ld).\n", val);
            }

#pragma omp task priority(31)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 31 has finished (%ld).\n", val);
            }

#pragma omp task priority(32)
            {
                long val = fibbonacci(NUMBER);
                printf("Thread with priority 32 has finished (%ld).\n", val);
            }
        }
    }
    return 0;
}

static long fibbonacci(long n)
{
    elapsed_sleep(0.001);
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return (fibbonacci(n - 1) + fibbonacci(n - 2));
    }
}
