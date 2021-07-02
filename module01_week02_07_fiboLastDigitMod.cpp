/*
* note: pisano period for mod(10)equals 60. this means that for fibonacci series mod(10),
* the remainders repeaat every interval 60. to calculate for the last digit, you only need to add
* the remainders
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

const int PISANO_10 = 60;
int pisano10_sum_last_digit_array[PISANO_10] = { 0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 
                                                 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9,  6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 
                                                 9, 3, 2, 5, 7, 2, 9, 1 };

int sum_builder(long long lim) {
    int start = 0;
    for (int i = 0; i < lim + 1; i++)
    {
        start = start + pisano10_sum_last_digit_array[i];
    }
    return start;
}

int main()
{
    long long m, n = 0;
    long long from, to = 0;

    std::cin >> m >> n;
    from = m % PISANO_10; 
    to = n % PISANO_10;

    std::cout << abs(sum_builder(to) - sum_builder(from-1))%10;
}