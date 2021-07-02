#include <iostream>
#include <cstdint>


int64_t gcd_naive(int64_t a, int64_t b) {
    /*std::cout << "recursion count: " << recurs_count << "\n"
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";*/
    if (b == 0) return a;

    int64_t a_prime = a % b;
    
    return gcd_naive(b, a_prime);
}


int main() {
    int64_t a, b;
    int64_t c = 0;

    std::cin >> a >> b;

    if (b > a)
    {
        c = a;
        a = b;
        b = c;
    }
        
    std::cout << gcd_naive(a, b) << std::endl;
    return 0;
}