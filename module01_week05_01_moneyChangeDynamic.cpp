#include <iostream>
#include <vector>
#include <map>

using namespace std;
using std::vector;
using std::map;

int get_change(int m, vector<int> denom);

int main() {
    int m;
    std::cin >> m;

    vector<int> denom = {1, 3, 4};

    std::cout << get_change(m, denom) << '\n';
}


int get_change(int m, vector<int> denom) {
    //write your code here
    std::map <int, int> change;

    //create map with keys from 0 to m with placeholder m+1
    change.insert({0, 0});
    for (int i = 1; i <= m; i++){
        change.insert({i, m+1});
    }

    //check each denomination for each key in the map
    //explanation here: https://www.youtube.com/watch?v=jgiZlGzXMBw
    int size = denom.size();
    for (int i = 1; i <= m; i++){
        int best = change[i];
        for (size_t j = 0; j < size; j++){
            int update = i - denom[j];
            if (update >= 0){
                if (best > change[update] + 1){
                    best = change[update] + 1;
                    change[i] = best;
                }
                
            }
        }
    }
    /*test
    for (size_t i = 0; i <= m; i++){
        std::cout << "amount: " << i << "; change: " << change[i] << endl;
    }*/
    return change[m];
}