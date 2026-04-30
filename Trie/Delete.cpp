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

    void insert(string word) {
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

    bool search(string word) {
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) return false;
            cur = cur->next[idx];
        }
        return cur->is_end;
    }   

    bool is_empty(Node* node) {
        for(int i = 0; i < 26; i++) {
            if(node->next[i] != NULL) return false;
        }
        return true;
    }

    Node* erase_util(Node* cur, string word, int wo_idx) {
        // if(cur = NULL) return NULL; (for invalid case)
        // Base case (end of a word)
        if(wo_idx == word.size()) {
            if(cur->is_end) cur->is_end = false;

            if(is_empty(cur)) {
                delete cur;
                cur = NULL;
            }
            return cur;
        }

        int idx = word[wo_idx] - 'a';
        cur->next[idx] = erase_util(cur->next[idx], word, wo_idx + 1);

        if(is_empty(cur) && cur->is_end == false) {
            delete cur;
            cur = NULL;
        }
        return cur;
    }

    void del(string word) {
        root = erase_util(root, word, 0); 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    t.insert("yo");
    t.insert("yoyo");
    t.insert("yoyoyo");

    return 0;
}
