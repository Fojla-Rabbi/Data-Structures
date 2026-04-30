#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    Node* next[26];
    int cnt;
    bool is_end;

    Node() {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        cnt = 0;
        is_end = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) {
                cur->next[idx] = new Node();
            }
            cur = cur->next[idx];
            cur->cnt++;
        }
        cur->is_end = true;
    }

    bool search(string word) { // O(L)
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) return false;
            cur = cur->next[idx];
        }
        return cur->is_end;
    }   

    int prefix_count(string prefix) {
        Node* cur = root;
        for(auto ch : prefix) {
            int idx = ch - 'a';
            cur = cur->next[idx];
        }
        return cur->cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    t.insert("yo");
    t.insert("yoyo");
    t.insert("yoyoyo");
    cout << t.prefix_count("yo");

    return 0;
}
