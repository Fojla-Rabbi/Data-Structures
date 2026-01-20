#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node {
public:
    Node* next[26];
    // 1 Node contains 26 Node type pointers(next) that
    // can point to a new Node
    bool flag;
    Node() {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        flag = false;
    }
};

class Trie {
public:
    Node* root = new Node();
    // O(L)  [here L is the length of the word]
    void insert(string word) {
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) {
                Node* newnode = new Node();
                cur->next[idx] = newnode;
                // NULL chara onno kauke point kortese mane 
                // oikhane index er equvalent ch ache
                cur = cur->next[idx];
            }
            else cur = cur->next[idx];
        }
        cur->flag = true;
    }

    // O(L)
    bool search(string word) {
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] != NULL) {
                cur = cur->next[idx];
            }
            else return false;
            // v has next reference but d doesn't ("hard");
        }
        return cur->flag; // For prefix search, just use "return true;"
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    t.insert("harvard");
    t.insert("yoyo");
    t.insert("kuet");
    cout << t.search("harvard") << '\n';
    cout << t.search("hard") << '\n';

    return 0;
}

