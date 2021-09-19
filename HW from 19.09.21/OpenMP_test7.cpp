#include <iostream>
#include <omp.h>

#define N 12

int main()
{
    int a[N], b[N], c[N];

    #pragma omp parallel for schedule(static, 10) num_threads(3)
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i * 100;
        std::cout << "a[i]: " << a[i] << ", " << "b[i]: " << b[i] << ", " 
            << "Thread num: " << omp_get_thread_num() << ", " 
            << "Number threads: " << omp_get_num_threads() << std::endl;
    }

    std::cout << std::endl;

    #pragma omp parallel for schedule(dynamic, 10) num_threads(4)
    for (int i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
        std::cout << "c[i]: " << c[i] << ", " << "Thread num: " << 
            omp_get_thread_num() << ", " << "Number threads: " 
            << omp_get_num_threads() << std::endl;
    }

    return 0;
}