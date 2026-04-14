#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    Node* next[26];
    bool is_end;

    Node() {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        is_end = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {  // O(L)  [here L is the length of the word]
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) {
                cur->next[idx] = new Node();
            }
            cur = cur->next[idx];
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
    
    // DFS to print all words
    void dfs(Node* cur, string &path) {
        if(cur->is_end) {
            cout << path << '\n';
        }

        for(int i = 0; i < 26; i++) {
            if(cur->next[i] != NULL) {
                char ch = 'a' + i;
                path.push_back(ch);
                dfs(cur->next[i], path);
                path.pop_back(); // backtrack
            }
        }
    }

    void print_trie() {
        string path = "";
        dfs(root, path);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    t.insert("yo");
    t.insert("yoyo");
    t.insert("kuet");
    t.print_trie();

    return 0;
}
