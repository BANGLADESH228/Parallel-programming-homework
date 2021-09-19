#include <iostream>
#include <omp.h>

#define N 1000

void getRandomArray(int mas[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mas[i][j] = rand() % 10;
		}
	}
}

void getRandomArray(int mas[N])
{
    for (int i = 0; i < N; ++i)
    {
        mas[i] = rand() % 10;
    }
}

void getResult(int matrix[N][N], int vec[N], int vec_res[N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            vec_res[i] += matrix[i][j] * vec[j];
        }
    }
}

int main()
{
    static int matrix[N][N], vec[N], vec_res[N];

    getRandomArray(matrix);
    getRandomArray(vec);

    double start = omp_get_wtime();

    getResult(matrix, vec, vec_res);

    double end = omp_get_wtime();
    std::cout << "Time without parallel: " << end - start << std::endl;

    ///////////////////////////////////////////////////////////////////

    start = omp_get_wtime();

    #pragma omp parallel num_threads(8)
    {
        getResult(matrix, vec, vec_res);
    }

    end = omp_get_wtime();
    std::cout << "Time with parallel: " << end - start << std::endl;

    return 0;
}

