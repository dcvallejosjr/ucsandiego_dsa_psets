#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using std::vector;

//prototypes
long int search(const vector<unsigned long int> &search_in, unsigned long int search_for, long int low, long int high);


int main() {
    long int n, m;

    //this block creates and sorts the search_in vector
    std::cin >> n; 
    vector<unsigned long int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    //std::sort (a.begin(), a.end());
    
    //this block creates and sorts the search_for vector, then creates a set from the elements of that vector
    std::cin >> m;
    vector<unsigned long int> b(m);
    for (size_t i = 0; i < b.size(); i++) {
        std::cin >> b[i];
    }
    std::set<unsigned long int> d(b.begin(), b.end());

    //this block populates the element-address map of the search_in vector, using the set d
    std::map<unsigned long int, long int> results;
    long int search_size = a.size() - 1;
    for (auto it = d.begin(); it != d.end(); ++it){
        unsigned long int e = *it;
        results.insert({e, search(a, e, 0, search_size)});
    }
    
    //this block prints out the address of the elements of the search_for vector, as they are found in the search_in vector
    for (size_t i = 0; i < m; i++){
        std::cout<< results[b[i]] << " ";
    }
}


long int search(const vector<unsigned long int> &search_in, unsigned long int search_for, long int low, long int high){
    long int mid = (high + low)/2;

    //base case 0: the number you are looking for is less than min(search_in) or greater than max(search_in)
    if (search_for < search_in[low] || search_for > search_in[high]) return -1;
    
    //base case 1: number you are looking for is equal to the middle element in the vector
    if (search_for == search_in[mid]) return mid;

    //base case 2: you are left looking at just one element. if not match, return -1
    if ((high == low) && (search_for != search_in[mid])) return -1;

    //number you are looking for is less than the middle element in the vector
    if (search_for < search_in[mid]) return search(search_in, search_for, low, mid); 
    
    //number you are looking for is more than the middle element in the vector
    if (search_for > search_in[mid]) return search(search_in, search_for, mid + 1, high);
}   