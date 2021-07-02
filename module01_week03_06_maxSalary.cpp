#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;


int switcheroo (int a, int b){
    if (b == -1) return a;

    std::stringstream ret1;
    std::stringstream ret2;
    string result1;
    string result2;

    ret2 << b;
    ret2 << a;
    ret2 >> result2;
    //std::cout << "result2: " << result2 <<"\n";
    
    ret1 << a;
    ret1 << b;
    ret1 >> result1;
    //std::cout << "result1: " << result1 <<"\n";
    
    if (result1 >= result2) return a;
    return b;
}


string largest_number(vector<int> a) {
    //write your code here
    std::stringstream ret;
    int test = a.size() + 1; /*interesting bug found
                            if you don't do this  before the while loop, the array size will lack one 
                            if you enter the values in an ascending order
                            e.g.: input n = 3, values = {2, 7, 9}*/

    while (a.size() != 0){
        int maxDigit = -1;
        for (size_t i = 0; i < a.size(); i++){
            //std::cout << "comparing: " << a[i] << " " << maxDigit << "\n";
            maxDigit = switcheroo(a[i], maxDigit);
            //std::cout << "picked: " << maxDigit << "\n";
            //int *trigger = &a[i];
            //test = *trigger;
        }

        //std::cout << "current maxDigit: " << maxDigit << "\n";
        ret << maxDigit;
        auto it = std::find(a.begin(), a.end(), maxDigit);
        a.erase(it);
    }

    string result; //NOTE: ret is a stringsteam, while result is a string
    ret >> result; //more here: https://www.javatpoint.com/cpp-int-to-string
    return result;
}


int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
        }
    std::cout << largest_number(a);
}
