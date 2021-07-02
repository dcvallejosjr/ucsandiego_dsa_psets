#include <iostream>
#include <cstdint>
#include <cstdio>

const int MAX = 85;
int64_t fib_array[MAX];

int main()
{
    int n = 1;
    do 
    {
        std::cout << "Input nth fibonacci number:\n";
        std::cin  >> n;
        if (n < 1)
        {
            std::cout << "n must be counting number starting from 1. Max value supported is n = 85\n";
        }
    } while (n < 1);
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0) fib_array[i] = 0;
        else if (i == 1) fib_array[i] = 1;
        else fib_array[i] = fib_array[i-1] + fib_array[i-2];

        printf("n = %d,  fibonacci = %I64d \n", i+1, fib_array[i]);
    }

    return 0;
}