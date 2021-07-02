#include <iostream>
#include <cstdint>


//get pisano period: code taken from https://www.codegrepper.com/code-examples/whatever/how+to+calculate+pisano+period
int64_t get_pisano_period(int64_t m) {
    int64_t a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            //std::cout << "Pisano period is: " << i + 1;
            return i + 1;
    }
}


int64_t get_fibonacci_huge(int64_t n, int64_t m) {
    int64_t pisano_period = get_pisano_period(m);
    std::cout << "Pisano period is:" << pisano_period << "\n";
    n = n % pisano_period;

    if (n <= 1) return n;

    int64_t previous = 0;
    int64_t current = 1;

    /*guides:
    * https://www.youtube.com/watch?v=Nu-lW-Ifyec
    * https://www.geeksforgeeks.org/fibonacci-number-modulo-m-and-pisano-period/
    */
    for (int64_t i = 0; i < n - 1; i++) {
        std::cout << "i = " << i << ", previous = " << previous << ", current = " << current << "\n";
        int64_t tmp_previous = previous%m;
        previous = current%m;
        current = (tmp_previous + current)%m;
        /*if ((i + 1) % 100 == 0)
            std::cout << current << "\n";
          */  
    }

    return current;
}


int main() {
    int64_t n, m;
    std::cin >> n >> m;
    //int64_t pisano_period = get_pisano_period(m);
    //std::cout << "Pisano period is:" << pisano_period << "\n";
    std::cout << get_fibonacci_huge(n, m) << '\n';
}