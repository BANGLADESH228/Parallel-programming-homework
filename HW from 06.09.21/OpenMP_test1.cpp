#include <iostream>
#include <omp.h>

#define THREAD_NUM 8

int main() 
{
    int id = 1;

    #pragma omp parallel num_threads(THREAD_NUM)
    {
        std::cout << "id: " << id++ << " " << "Thread number: "
            << omp_get_thread_num() << " " << "Hello, world!" << std::endl;
    }

    return 0;
}

