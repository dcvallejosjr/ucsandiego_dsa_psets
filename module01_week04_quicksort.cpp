#include <iostream>
#include <vector>
#include <cstdlib>


using std::vector;
using std::swap;


//prototypes:
void quicksort(vector<int> &a, int left, int right);
void partition(vector<int> &a, int left, int right, int &i, int &j);


//main
int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    
    quicksort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}


//implementation details. inspired from: https://www.tutorialspoint.com/3-way-quicksort-dutch-national-flag
void quicksort(vector<int> &a, int left, int right){
    //if there's only one or two elements to inspect, return
    if (right <= left) return;

    //randomize a[left] and a[right]
    int k = left + rand() % (right - left + 1); 
    int l = left + rand() % (right - left + 1);
    swap(a[left], a[k]);
    swap(a[right], a[l]);

    //call the partition function that will also determine the bounds of the next recursive call
    int i, j;
    partition(a, left, right, i, j); //calling this will assign value to i and j
    quicksort(a, left, i);
    quicksort(a, j, right);
}


void partition(vector<int> &a, int left, int right, int &i, int &j){
    //assign mid, pivot
    /*mid will serve as the index of the values as they are compared against pivot
    left will serve as the boundary of the sorted values less than pivot.
    right will serve as the boundary of the sorted values greather than pivot*/
    int mid = left; 
    int pivot = a[left];

    //partition the array and progressively sort from left to right and from right to left
    while (mid <= right){
        //three cases: arr[mid] < pivot, arr[mid] == pivot, arr[mid] > pivot
        if (a[mid] < pivot) swap(a[left++], a[mid++]); //put the value less than pivot to the left, then move mid and left +1 in the array 
        else if (a[mid] == pivot) mid++; //move mid +1 in the array
        else swap(a[mid], a[right--]); /*(arr[mid] > pivot), swap the value of a[mid] with the right-most value. 
                                        then, move the right-most value one step to the left. 
                                        this progressive puts value greater pivot to the right*/
    }

    i = left - 1; //becomes the next right on the next recursive call
    j = right; //becomes the next left whenever left = 0 is "exhausted" in the stack call
}
