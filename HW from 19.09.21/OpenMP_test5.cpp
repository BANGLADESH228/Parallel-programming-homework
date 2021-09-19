#include <iostream>
#include <omp.h>
#include <limits.h>

#define N 6
#define M 8

void getRandomArray(int mas[N][M])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            mas[i][j] = rand() % 100;
        }
    }
}

void getSection1(int mas[N][M])
{
    int sum = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            sum += mas[i][j];
        }
    }

    auto average = sum / (N * M);
    std::cout << "Task 1: " << average << ", " << "Thread num: " 
        << omp_get_thread_num() << std::endl;
}

void getSection2(int mas[N][M])
{
    int min = 0;
    int max = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mas[i][j] > max)
            {
                max = mas[i][j];
            }

            else 
            {
                min = mas[i][j];
            }
        }
    }

    std::cout << "Task 2: " << "Min: " << min << " " << "Max: " << max << ", " 
        << "Thread num: " << omp_get_thread_num() << std::endl;
}

void getSection3(int mas[N][M])
{
    int k = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (mas[i][j] % 3 == 0)
            {
                k++;
            }
        }
    }

    std::cout << "Task 3: " << k << ", " << "Thread num: "
        << omp_get_thread_num() << std::endl;
}

int main()
{
    int d[N][M];
    getRandomArray(d);

    #pragma omp parallel sections 
    {
        #pragma omp section
        {
            getSection1(d);
        }

        #pragma omp section
        {
            getSection2(d);
        }

        #pragma omp section
        {    
            getSection3(d);
        }
    }

    return 0;
}