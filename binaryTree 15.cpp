//check if tree is balanced or not
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

bool isBalanced()

int main()
{
    // Create binary tree shown in above figure
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    if(isBalanced(root))
        cout<<"It is balanced";
    else
        cout<<"Not balanced";


    return 0;
}

/*
           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9
Output:
