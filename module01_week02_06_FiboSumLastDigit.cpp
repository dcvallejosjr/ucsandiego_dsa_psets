#include <iostream>

/*
* note: pisano period for mod(10)equals 60. this means that for fibonacci series mod(10),
* the remainders repeaat every interval 60. to calculate for the last digit, you only need to add
* the remainders
*/
const int PISANO_10 = 60;
int pisano10_sum_last_digit_array[PISANO_10] = { 0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3, 2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8,
                                                 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6, 1, 8, 0, 9, 0 };

int main()
{
    long long n = 0;
    long long test = 0;
    
    std::cin >> n;
    test = n % PISANO_10;  

    std::cout << pisano10_sum_last_digit_array[test];
}