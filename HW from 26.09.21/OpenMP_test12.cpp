#include <iostream>
#include <omp.h>
#include <chrono>
#include <thread>

int main()
{
    #pragma omp parallel num_threads(8)
    {
        std::this_thread::sleep_for(std::chrono
            ::milliseconds(100 * (8 - omp_get_thread_num())));
        std::cout << "Hello, World!" << " " << "Thread number: "
            << omp_get_thread_num() << std::endl;
    }

    return 0;
}
