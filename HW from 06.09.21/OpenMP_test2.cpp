#include <iostream>
#include <omp.h>

int main()
{
    int threads_num = 3;

    std::cout << "Parallel:";
    #pragma omp parallel num_threads(threads_num) if (threads_num > 2)
    {
        std::cout << "thread number: " << omp_get_thread_num() 
            << " threads: " << omp_get_num_threads() << std::endl;
    }
    
    threads_num = 1; 

    std::cout << "Not in parallel: ";
    #pragma omp parallel num_threads(threads_num) if (threads_num > 2)
    {
        std::cout << "thread number: " << omp_get_thread_num() 
            << " threads: " << omp_get_num_threads() << std::endl;
    }

    return 0;
}
