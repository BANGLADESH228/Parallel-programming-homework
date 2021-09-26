#include <iostream>
#include <omp.h>

#define N 30

void getRandomArray(int mas[N])
{
    for (int i = 0; i < N; ++i)
    {
        mas[i] = rand() % 100;
    }
}

int main()
{
    int a[N], max = 0;

    getRandomArray(a);

    #pragma omp parallel for firstprivate(a) shared(max) num_threads(4)
    for (int i = 0; i < N; ++i)
    {
        if (a[i] % 7 == 0)
        {
            #pragma omp critical
            if (a[i] > max)
            {
                max = a[i];
            }
        }
    }

    std::cout << "Maximum multiple of 7: " << max << std::endl;

    return 0;
}