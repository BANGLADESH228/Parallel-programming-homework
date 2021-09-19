#include <iostream>
#include <numeric>
#include <omp.h>

#define N 10

void getRandomArray(int mas[])
{
	for (int i = 0; i < N; ++i)
	{
		mas[i] = rand() % 10;
	}
}

void getResult(int result1, int result2) 
{
	if (result1 > result2) 
	{
		std::cout << "Result1 > Result2" << std::endl;
	}
	else if (result1 < result2)
	{
		std::cout << "Result1 < Result2" << std::endl;
	}
	else 
	{
		std::cout << "Result1 = Result2" << std::endl;
	}
}

int main()
{
	int a[N], b[N], var1 = 0, var2 = 0;

	getRandomArray(a);
	getRandomArray(b);

	#pragma omp parallel for reduction(+: var1) 
	for (int i = 0; i < N; ++i) 
	{
		var1 += a[i];
	}

	auto res1 = var1 / N;
	std::cout << "Result number 1 = " << res1 << std::endl;

	#pragma omp parallel for reduction(+: var2) 
	for (int i = 0; i < N; ++i)
	{
		var2 += b[i];
	}

	auto res2 = var2 / N;
	std::cout << "Result number 2 = " << res2 << std::endl;

	getResult(res1, res2);

	return 0;
}

