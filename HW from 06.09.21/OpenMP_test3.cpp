#include <iostream>
#include <omp.h>

void task1(int a, int b) 
{
    std::cout << "Before parralel (a): " << a
        << " Before parallel (b): " << b << std::endl;

    #pragma omp parallel num_threads(2) private(a) firstprivate(b) 
    {
        a += omp_get_thread_num();
        b += omp_get_thread_num();

        std::cout << "Parralel (a): " << a
            << " Parallel (b): " << b << std::endl;
    }

    std::cout << "After parralel (a): " << a
        << " After parallel (b): " << b << std::endl;
}

void task2(int a, int b) 
{
    std::cout << "Before parralel (a): " << a
        << " Before parallel (b): " << b << std::endl;

    #pragma omp parallel num_threads(4) shared(a) private(b) 
    {
        a -= omp_get_thread_num();
        b -= omp_get_thread_num();

        std::cout << "Parralel (a): " << a
            << " Parallel (b): " << b << std::endl;
    }

    std::cout << "After parralel (a): " << a
        << " After parallel (b): " << b << std::endl;
}

int main()
{
    int a = 2, b = 4;
    task1(a, b);
    task2(a, b);

    return 0;
}
