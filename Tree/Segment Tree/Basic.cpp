// build --> O(n) (because we need to create all the nodes, which is approximately 4*n)
// update --> O(log n)
// query --> O(log n)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll a[N];
ll seg[4 * N];

// low and high e sheraaaa
void build(int idx, int low, int high) {
    if(low == high) {
        seg[idx] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * idx, low, mid);
    build(2 * idx + 1, mid + 1, high);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int query(int idx, int low, int high, int l, int r) {
    if(low >= l && high <= r) return seg[idx];
    else if(high < l || low > r) return 0;
    
    int mid = (low + high) / 2;
    ll left_child = query(2 * idx, low, mid, l, r);
    ll right_child = query(2 * idx + 1, mid + 1, high, l, r);

    return left_child + right_child;
}

void update(int idx, int low, int high, int i, int val) {
    if(low == high) {
        seg[idx] = val;
        return;
    }

    int mid = (low + high) / 2;
    if(i <= mid) update(2 * idx, low, mid, i, val);
    else  update(2 * idx + 1, mid + 1, high, i, val);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    for(int i = 1; i < 4 * n; i++) cout << seg[i] << " ";

    update(1, 1, n, 1, 100);
    for(int i = 1; i < 4 * n; i++) cout << seg[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
