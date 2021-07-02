#include <iostream>
#include <vector>
#include <cmath>
#include <valarray>
#include <algorithm>

using std::vector;

//create struct Item
struct Item {
    double value, weight;
    double  val_per_weight;
};


//prototypes
double get_optimal_value(int capacity, vector<Item> Items, int items_number);
bool reverse_comp(const Item& a, const Item& b);


//main
int main() {
    int n;
    int capacity;

    std::cin >> n >> capacity;
    vector<Item> Items(n);

    for (int i = 0; i < n; i++) {
        std::cin >> Items[i].value >> Items[i].weight;
        Items[i].val_per_weight = Items[i].value / Items[i].weight;
    }

    double optimal_value = get_optimal_value(capacity, Items, n);

    std::cout.precision(10);
    std::cout << "\n" << optimal_value << std::endl;
    return 0;
}


//compare values. from: https://stackoverflow.com/questions/4892680/sorting-a-vector-of-structs
bool reverse_comp(const Item& a, const Item& b){
    return a.val_per_weight > b.val_per_weight;
}


//get_optimal_value
double get_optimal_value(int capacity, vector<Item> Items, int items_number) {
    double value = 0.0;

    //for more info: https://www.cplusplus.com/reference/algorithm/sort/
    std::sort(Items.begin(), Items.end(), reverse_comp); 
    
    //while the knapsack isn't full just take as much of the most to the least valuable
    int i = 0;
    while (capacity != 0.0 && i < items_number){
        if (Items[i].weight < capacity){
            value = value + Items[i].value;
            capacity = capacity - Items[i].weight;
        }
        else{
            value = value + Items[i].val_per_weight * capacity;
            capacity = 0.0;
        }
        //std::cout << capacity << " " << value <<  " " << (i < items_number) << "\n";
        i++;
    }

    return value;
}