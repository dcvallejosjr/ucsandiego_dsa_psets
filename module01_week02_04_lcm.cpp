#include <iostream>
#include <cstdint>


int64_t gcd(int64_t a, int64_t b) {    
    if (b == 0) return a;

    int64_t a_prime = a % b;
     
    return gcd(b, a_prime);
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
        
    std::cout << (a*b)/gcd(a, b) << std::endl;
    return 0;
}
