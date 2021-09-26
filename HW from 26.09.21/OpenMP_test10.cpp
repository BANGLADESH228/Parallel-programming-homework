#include <omp.h>>
#include <iostream>

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
    int a[N], count = 0;;

    getRandomArray(a);

    #pragma omp parallel for shared(a, count)
    for (int i = 0; i < N; ++i)
    {
        if (a[i] % 9 == 0)
        {
            #pragma omp atomic
            count += 1;
        }
    }

    std::cout << "Number of multiples of 9: " << count << std::endl;

    return 0;
}