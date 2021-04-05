//check if tree is bst
//tree=bst when ALL (not just immediate child) nodes of left are small and right are large
// Node > max(left subtree)
// Node < min(right subtree)
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left,right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

bool isBST(Node* root){
    if
}
