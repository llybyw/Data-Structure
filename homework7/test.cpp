#include "HeapSort.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;



vector<int> RandomQ (int n, int N) { 
    srand((int)time(0));
    vector<int> vAllIndices(N);
    vector<int> vAvailableIndices(n); 
    for(size_t i = 0; i < vAllIndices.size(); i++)
    {
        vAllIndices[i]=i;
    }
    for(size_t i = 0; i < vAvailableIndices.size(); i++)
    {
        int idx = random() % vAllIndices.size();
        vAvailableIndices[i] = vAllIndices[idx];
    }
    return vAvailableIndices;
}

template <typename t>
bool check(vector<t>& arr, int len) {
    for (int i = 1; i < len; i ++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}



int main() {
    int size = 1000000;
    int numsize = 100000000;
    int numsize1 = 1000;

    vector<int> Random = RandomQ(size, numsize);
    vector<int> Random_c = Random;
    cout << "testing the random\n";

    auto start1 = chrono::high_resolution_clock::now();
    make_heap(Random.begin(), Random.end());
    sort_heap(Random.begin(), Random.end());
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    cout << "sort_heap:" << duration1.count() << " \n";
    cout << "Sorting Correctness: " << (check(Random, size) ? "Passed" : "Failed") << "\n";

    auto start2 = chrono::high_resolution_clock::now();
    Heapsort(Random_c, size);
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    cout << "Heapsort:" << duration2.count() << " \n";
    cout << "Sorting Correctness: " << (check(Random_c, size) ? "Passed" : "Failed") << "\n";
    
    
    vector<int> orderedVec(size);
    for (int i = 0; i < size; ++i) {
        orderedVec[i] = i;
    }
    vector<int> orderedVec_c = orderedVec;
    cout << "testing the order\n";

    auto start3 = chrono::high_resolution_clock::now();
    make_heap(orderedVec.begin(), orderedVec.end());
    sort_heap(orderedVec.begin(), orderedVec.end());
    auto end3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);
    cout << "sort_heap:" << duration3.count() << " \n";
    cout << "Sorting Correctness: " << (check(orderedVec, size) ? "Passed" : "Failed") << "\n";

    auto start4 = chrono::high_resolution_clock::now();
    Heapsort(orderedVec_c, size);
    auto end4 = chrono::high_resolution_clock::now();
    auto duration4 = chrono::duration_cast<chrono::microseconds>(end4 - start4);
    cout << "Heapsort:" << duration4.count() << " \n";
    cout << "Sorting Correctness: " << (check(orderedVec_c, size) ? "Passed" : "Failed") << "\n";

    
    vector<int> reversedVec(size);
    for (int i = 0; i < size; ++i) {
        reversedVec[i] = size - i;
    }
    vector<int> reversedVec_c = reversedVec;
    cout << "testing the reversed\n";

    auto start5 = chrono::high_resolution_clock::now();
    make_heap(reversedVec.begin(), reversedVec.end());
    sort_heap(reversedVec.begin(), reversedVec.end());
    auto end5 = chrono::high_resolution_clock::now();
    auto duration5 = chrono::duration_cast<chrono::microseconds>(end5 - start5);
    cout << "sort_heap:" << duration5.count() << " \n";
    cout << "Sorting Correctness: " << (check(reversedVec, size) ? "Passed" : "Failed") << "\n";

    auto start6 = chrono::high_resolution_clock::now();
    Heapsort(reversedVec_c, size);
    auto end6 = chrono::high_resolution_clock::now();
    auto duration6 = chrono::duration_cast<chrono::microseconds>(end6 - start6);
    cout << "Heapsort:" << duration6.count() << " \n";
    cout << "Sorting Correctness: " << (check(reversedVec_c, size) ? "Passed" : "Failed") << "\n";

    vector<int> Random1 = RandomQ(size, numsize1);
    cout << "testing the random\n";
    vector<int> Random1_c = Random1;

    auto start7 = chrono::high_resolution_clock::now();
    make_heap(Random1.begin(), Random1.end());
    sort_heap(Random1.begin(), Random1.end());
    auto end7 = chrono::high_resolution_clock::now();
    auto duration7 = chrono::duration_cast<chrono::microseconds>(end7 - start7);
    cout << "sort_heap:" << duration7.count() << " \n";
    cout << "Sorting Correctness: " << (check(Random1, size) ? "Passed" : "Failed") << "\n";

    auto start8 = chrono::high_resolution_clock::now();
    Heapsort(Random1_c, size);
    auto end8 = chrono::high_resolution_clock::now();
    auto duration8 = chrono::duration_cast<chrono::microseconds>(end8 - start8);
    cout << "Heapsort:" << duration8.count() << " \n";
    cout << "Sorting Correctness: " << (check(Random1_c, size) ? "Passed" : "Failed") << "\n";

    return 0;
}