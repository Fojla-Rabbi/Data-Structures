#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> heap;

// Percolate down
void heapify(int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    if(right < n && heap[right] > heap[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(heap[i], heap[largest]);
        i = largest;
        heapify(i, n);
    }

}

void build_heap() {
    int n = heap.size();
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(i, n);
    }
}


void delete_root() {
    int n = heap.size();
    heap[0] = heap[n - 1];
    heap.pop_back();
    heapify(0, n - 1);

}

// This one is not memory efficient
// void heap_sort() {
//     while(!heap.empty()) {
//         cout << heap[0] << " ";
//         delete_root();
//     }
// }

void heap_sort() {
    build_heap();
    int n = heap.size();
    for(int i = n - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapify(0, i);
    }
}

void print_heap() {
    for(int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << '\n';
}

int main() {

    //for(int i = 0; i < n; i++) cin >> heap[i];
    heap = {10, 20, 15, 50, 30, 40};
    print_heap();
    heap_sort();
    print_heap();

  
    return 0;
}
