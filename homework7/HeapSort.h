#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

template <typename t>
void adjustHeap (std::vector<t>& arr, int end, int i)
{
    int parent = i;
    int max = parent;
    int l_child = 2 * i + 1;
    int r_child = 2 * i + 2;

    if (l_child <= end && arr[l_child] > arr[max])
        max = l_child;
    if (r_child <= end && arr[max] < arr[r_child])
        max = r_child;
    
    if (max != parent) {
        swap(arr[max], arr[parent]);
        adjustHeap (arr, end, max);
    }

}

template <typename t>
void Heapsort (std::vector<t>& arr, int len) {
    for (int i = len / 2 - 1; i >= 0; --i)
        adjustHeap(arr, len - 1, i);

    for (int n = len - 1; n > 0; n --){
        swap (arr[0], arr[n]);

        adjustHeap(arr, n - 1, 0);
    }
}