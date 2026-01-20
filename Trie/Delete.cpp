#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node {
public:
    Node* next[26];
    bool flag;
public:
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
        for(auto ch : word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) {
                Node* newnode = new Node();
                cur->next[idx] = newnode;
            }
            cur = cur->next[idx];
        }
        cur->flag = true;
    }

    void dfs(Node* cur, string &word) {
        if(cur->flag) {
            cout << word << '\n';
        }

        for(int i = 0; i < 26; i++) {
            if(cur->next[i] != NULL) {
                word.push_back(i + 'a');
                dfs(cur->next[i], word);
                word.pop_back();
            }
        }
    }

    bool is_empty(Node* node) {
        for(int i = 0; i < 26; i++) {
            if(node->next[i] != NULL) return false;
        }
        return true;
    }

    Node* erase_util(Node* cur, string word, int depth) {
        // if(cur = NULL) return NULL; (for invalid case)

        if(depth == word.size()) {
            if(cur->flag) cur->flag = false;

            if(is_empty(cur)) {
                delete cur;
                cur = NULL;
            }
            return cur;
        }

        int idx = word[depth] - 'a';
        cur->next[idx] = erase_util(cur->next[idx], word, depth + 1);

        if(is_empty(cur) && cur->flag == false) {
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
    t.insert("harvard");
    t.insert("hard");
    t.insert("kuetx");
    t.insert("kuety");
    t.insert("kuatz");
    string s = "";
    t.dfs(t.root, s);
    t.del("hard");
    string p = "";
    t.dfs(t.root, p);


    return 0;
}
