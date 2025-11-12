#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*left;
    Node*right;
public:
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
/* THIS FUNCTION CANNOT HANDLE THE CASE "when root=NULL"
   When the original root is NULL, then passing that root
   cannot make any changes in that main root, (think it)*/
// Only for that, we need to change the return type. Like Node* insert(...)
void insert(Node*root, int val){
    Node*newnode=new Node(val);   
    // if(root==NULL){
    //     root=newnode;
    //     return root;
    // }
    Node*curr=root;
    Node*parent=root;
    while(curr!=NULL){
        parent=curr;
        if(val<curr->data) curr=curr->left;
        else curr=curr->right; 
    }
    // To keep track of parent Node is mandatory here
    // "curr=newnode" cannot insert val to the tree
    // because curr becomes NULL, then it looses connection
    if(val<parent->data) parent->left=newnode;
    else parent->right=newnode;    
}
void in_order(Node*curr){
       if(curr==NULL) return;
       in_order(curr->left);
       cout<<curr->data<<" ";
       in_order(curr->right);
}
int main(){
    // If initially root is NULL,
    // then write "root=insert(root,100);"
    Node*root=new Node(100);
    insert(root,20);
    insert(root,500);
    insert(root,10);
    insert(root,30);
    in_order(root);
}
