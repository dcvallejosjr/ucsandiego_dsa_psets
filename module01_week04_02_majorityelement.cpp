#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>


using std::vector;

//prototypes
int get_majority_element(vector<long int> &a, long int size);


int main() {
    long int n;

    //this block creates the election vector
    std::cin >> n; 
    vector<long int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << get_majority_element(a, a.size()) << '\n';
}


int get_majority_element(vector<long int> &a, long int size){
    if (size < 3) return 0;
    //sort the election vector
    std::sort (a.begin(), a.end());
    long int n = size;
    
    //this block populates the element-address map of the election vector, using the vector a
    std::map<long int, long int> results;
    long int search_size = n - 1;
    long int vote_count = 0;
    for (size_t i = 0; i <= search_size; i++){
        vote_count++;
        //if (i == search_size) break;
        if (a[i] != a[i + 1]){
            results.insert({a[i], vote_count});
            vote_count = 0; 
        }
        //std::cout << results.size() << "\n";
    }
    //handled outside the for loop to avoid out-of-bounds errors
    if (a[search_size] == a[search_size - 1]) results.insert({a[search_size], vote_count});
    else results.insert({a[search_size], 1});
    //std::cout << results.size() << "\n";

    //find the max value from the map. taken from: https://stackoverflow.com/questions/9370945/c-help-finding-the-max-value-in-a-map/9371137
    std::map<long int, long int>::iterator best = std::max_element(results.begin(), results.end(),
        [] (const std::pair<long int, long int> &a, const std::pair<long int, long int> &b)
        -> bool {return a.second < b.second;});
    
    std::cout << "highest number of vote: " << best->second << "\n";
    //check if best holds a majority
    if (best->second > n/2) return 1;
    else return 0;
}