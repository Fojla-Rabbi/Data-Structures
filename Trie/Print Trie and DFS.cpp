#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node {
public:
    Node* next[26];
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
        }
        cur->flag = true;
    }

    // For print purpose
    // O(T)  [here T = total number of characters stored in the trie]
    void dfs(Node* cur, string &word) {
        if(cur->flag) {
            cout << word << '\n';
            // return; 
            // you cannot do that!!, think for "kuet", "kuetp" 
            // The Node that contains p has flag = true for t
        }

        for(int i = 0; i < 26; i++) {
            if(cur->next[i] != NULL) {
                word.push_back(i + 'a');
                dfs(cur->next[i], word);
                word.pop_back();
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    t.insert("harvard");
    t.insert("yoyo");
    t.insert("kuet");
    t.insert("kuep");
    // cout << t.search("harvard") << '\n';
    // cout << t.search("hard") << '\n';
    string word = "";
    t.dfs(t.root, word);

    return 0;
}
