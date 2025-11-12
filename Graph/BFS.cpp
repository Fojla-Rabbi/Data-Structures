#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N] = {false};

void bfs(int st, vector<int>* adj) {
    vis[st] = true;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr <<" ";
        for(auto i: adj[curr]) {
            if(vis[i] != true){
                vis[i] = true;
                q.push(i);
            }
        }
    }
}
int main(){
    int n, e; // nodes and edges
    cin >> n >> e;
 
    // Using adj list...(---> O(2e) space)
    vector<int> adj[n + 1]; // When graph is 1 based
    // There is n + 1 vectors starting from 0 to n
 
    // Now storing the edges (u ---> v)
    for(int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(6, adj);
    // Remember the 5 will be traversed from the shortest path (for 6)
    //-----The below graph-----
/*     1
      / \
    2     6
   / \   / \
  3   4 7   9
     /   \
    5-----8     */
 
 // 9 9
/*  1 2
    1 6
    2 3
    2 4
    6 7
    6 9
    4 5
    7 8
    5 8  */
 
}
