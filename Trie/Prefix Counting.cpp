#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node {
public:
    Node* next[26];
    bool flag;
    int prefix_cnt;
    Node() {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        flag = false;
        prefix_cnt = 0;
    }
};

class Trie {
public:
    Node* root = new Node();

    void insert(string word) {
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) {
                Node* newnode = new Node();
                cur->next[idx] = newnode;

                cur = cur->next[idx];
            }
            else cur = cur->next[idx];
            cur->prefix_cnt++;
        }
        cur->flag = true;
    }
    
    int count_prefix(string prefix) {
        Node* cur = root;
        for(auto ch: prefix) {
            int idx = ch - 'a';
            if(cur->next[idx] != NULL) {
                cur = cur->next[idx];
            }
            else return 0;
        }
        return cur->prefix_cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    t.insert("harvard");
    t.insert("yoyo");
    t.insert("kuetx");
    t.insert("kuety");
    t.insert("kuatz");

    cout << t.count_prefix("kue");

    return 0;
}
