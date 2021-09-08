#include <iostream>
#include <algorithm>
#include <omp.h>

#define THREADS_NUM 2
#define N 10

int main(int argc, char* argv[])
{
    int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int b[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    #pragma omp parallel num_threads(THREADS_NUM)
    {
        if (omp_get_thread_num() == 0)
            std::cout << "Min element: " 
            << *std::min_element(a, a + N) << std::endl;
        else
            std::cout << "Max element: " 
            <<  *std::max_element(b, b + N) << std::endl;
    }

    return 0;
}