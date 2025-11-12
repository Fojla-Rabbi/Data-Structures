#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N] = {false};
int level[N] = {0};
vector<int> level_order[N + 1];

void bfs(int st, vector<int>* adj) {
    vis[st] = true;
    level[st] = 0;
    level_order[0].push_back(st);
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr <<" ";
        for(auto i: adj[curr]) {
            if(vis[i] != true) {
                level[i] = level[curr] + 1;
                level_order[level[i]].push_back(i);
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
 
    vector<int> adj[n + 1];
    for(int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> level_order[n + 1];
    bfs(6, adj);
   
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
