#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>


using std::vector;


vector<unsigned long int> optimal_summands(unsigned long int n) {
    vector<unsigned long int> summands;
    
    //write your code here
    //most basic case
    if (n < 2){
        summands.push_back(n);
        return summands;
    }

    /*this was first formulated in excel. i don't know why the <=0.5 works. some maths genius explanation must exist
    largely based on the math found here: https://stackoverflow.com/questions/54608210/different-summands-problem-greedy-alogrithm
    */
    long double k = sqrt(8*n + 1)/2;
    long double k_checker = fmod(k, trunc(k));

    unsigned long int subtrahend;
    if (k_checker <= 0.5) subtrahend = floor(k);   
    else subtrahend = floor(k) + 1;

    //i also don't know how this works. it's just a pattern i found in excel.
    unsigned long int exception = subtrahend*(subtrahend+1)/2 - n; 

    while (subtrahend > 0){
        n = n - subtrahend;

        if (subtrahend != exception){                           //case 0 split the value of the exception
            if (n > 0) summands.push_back(subtrahend);          //case 1
            else if (n < 0) n = n + subtrahend;                 //case 2
            else summands.push_back(subtrahend);                //case 3
        }
        else n = n + subtrahend;
        
        subtrahend--;
    }
    return summands;
}


int main() {
    unsigned long int n;
    std::cin >> n;
    vector<unsigned long int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
