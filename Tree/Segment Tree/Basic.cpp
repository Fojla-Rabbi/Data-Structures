// build --> O(n) (because we need to create all the nodes, which is approximately 4*n)
// update --> O(log n)
// query --> O(log n)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
int arr[N], seg[4*N];
void build(int ind, int low, int high) {
    if(low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid  = (low + high) / 2;
    build(2*ind + 1, low, mid);
    build(2*ind + 2, mid + 1, high);
    seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]); // Backtracking
}
void update_val(int ind, int low, int high, int node, int val) {
    if(low == high) {
        seg[ind] += val; // Say you are told to increase the value by val;
        arr[low] += val; // Just formality
        return;
    }
    int mid  = (low + high) / 2;
    if(node <= mid && node >= low) update_val(2*ind + 1, low, mid, node, val);
    else update_val(2*ind + 2, mid + 1, high, node, val);

    seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]); // Backtracking
}
int query(int ind, int low, int high, int l, int r) {
    if(low >= l && high <= r) {
        return seg[ind];
    }
    if(low > r || high < l) return INT_MIN;
    int mid = (low + high) / 2;
    int left = query(2*ind + 1, low, mid, l, r);
    int right = query(2*ind + 2, mid + 1, high, l, r);
    return max(left, right);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {

    }
    return 0;

}
