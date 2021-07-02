#include <iostream>

int get_change(int m) {
    int tens = 0;
    int fives = 0;
    int ones = 0;
    int placeholder = 0;

    tens = m / 10;
    placeholder = m - tens * 10;
    
    fives = placeholder / 5;
    placeholder = placeholder - fives * 5;

    ones = placeholder;

    return tens + fives + ones;
}


int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}