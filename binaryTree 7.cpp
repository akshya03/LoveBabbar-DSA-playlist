//preorder iterative
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
void preOrder(Node *root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void preorderIterative(Node *root){
    stack<Node *> stk;
    Node *curr=root;

    while(curr || !stk.empty()){
        if(curr){
            cout<<curr->data<<" ";
            stk.push(curr);
            curr=curr->left;
        }
        else{
            curr=stk.top();
            stk.pop();
            curr=curr->right;
        }
    }
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    preOrder(root);
    cout<<endl;
    preorderIterative(root);
    return 0;
}

//ans: 1 2 4 3 5 7 8 6
