#include <stdio.h>

#ifdef _OPENMP
#include <omp.h>
#endif

int main(void)
{
#pragma omp parallel
    {
#pragma omp task priority(20)
        {
            printf("I'm a task\n");
        }
    }
    return 0;
}
