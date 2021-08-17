#include <iostream>
#include <vector>

using namespace std;
using std::vector;

unsigned long optimal_weight(unsigned long W, vector<unsigned long> w);


int main() {
    int n, W;
    std::cin >> W >> n;
    vector<unsigned long> w(n);
    
    for (size_t i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    std::cout << optimal_weight(W, w) << '\n';
}


unsigned long optimal_weight(unsigned long W, vector<unsigned long> w){
    //write your code here
    // W = weight capacity of the knapsack
    // w = vector of the weight of each item
    unsigned long num_items = w.size();
    unsigned long dyn_arr [num_items + 1][W + 1];

    for (size_t i = 0; i <= num_items; i++) dyn_arr[i][0] = 0;
    for (size_t j = 0; j <= W; j++) dyn_arr[0][j] = 0;

    for (size_t i = 1; i <= num_items; i++){
        for (size_t j = 1; j <= W; j++){
            unsigned long deflt = dyn_arr[i - 1][j]; //select the value to the top of the current cell, means by default you take the previous best solution for current weight j
            dyn_arr[i][j] = deflt;

            if (j >= w[i - 1]) {
                unsigned long value = dyn_arr[i - 1][j - w[i - 1]] + w[i - 1];
                dyn_arr[i][j] = max(deflt, value);
            }
        }
    }
 
    // for (size_t i = 0; i <= num_items; i++){
    //     for (size_t j = 0; j <= W; j++){
    //         std::cout << dyn_arr[i][j] << " ";
    //     }
    //     std::cout << endl;
    // }

    return dyn_arr[num_items][W];
}