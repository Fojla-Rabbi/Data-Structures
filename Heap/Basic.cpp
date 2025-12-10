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

void insert(int val) {
    heap.push_back(val);
    int i = heap.size() - 1;
    while(i > 0) {
        int par = (i - 1) / 2;
        if(heap[par] < heap[i]) {
            swap(heap[par], heap[i]);
            i = par;
        }
        else break;
    }

}

void delete_root() {
    int n = heap.size();
    heap[0] = heap[n - 1];
    heap.pop_back();
    heapify(0, n - 1);

}

void print_heap() {
    for(int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
}

int main() {

    //for(int i = 0; i < n; i++) cin >> heap[i];
    insert(100);
    insert(50);
    insert(20);
    insert(200);
    print_heap();
    delete_root();
    cout << '\n';
    print_heap();
   
    return 0;
}
