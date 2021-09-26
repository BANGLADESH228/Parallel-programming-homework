#include <omp.h>
#include <iostream>

#define N 6
#define M 8

void getRandomArray(int mas[N][M])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            mas[i][j] = rand() % 10;
        }
    }
}

int main()
{
    int min = 0, max = 0;
    int d[N][M];

    getRandomArray(d);

#   pragma omp parallel for shared(d, min, max)
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (d[i][j] > max)
            #pragma omp critical
            {
                max = d[i][j];
            }
            #pragma omp critical
            if (d[i][j] < min)
            {
                min = d[i][j];
            }
        }
    }

    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;

    return 0;
}