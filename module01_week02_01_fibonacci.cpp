#include <iostream>
#include <cstdint>
#include <cstdio>


int64_t fibonacci(int n)
{
    if (n <= 1) return n;
    else return int64_t(fibonacci(n - 1)) + fibonacci(n - 2);
}

int main()
{
    int n = 0;
    do
    {
        std::cout << "input nth fibonacci number:\n";
        std::cin >> n;
    } while (n < 1);


    for (int i = 1; i < n + 1; i++)
    {
        int64_t result = fibonacci(i - 1);
        printf("n = %d, fibonacci = %I64d\n", i, result);
    }
    return 0;
}