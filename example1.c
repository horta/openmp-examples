#include <stdio.h>

#ifdef _OPENMP
#include <omp.h>
#endif

int main(void)
{
#pragma omp parallel
    {
        printf("I'm a task\n");
    }
    return 0;
}
