//diameter of tree
//time complexity for naive approach=nh
//h= lg n for balanced tree, n for unbalanced tree
//time complexity for better approach=n

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

Node* addNodeBST(Node* root,int x){
    if(!root)
        return new Node(x);
    if(x<root->data)
        root->left=addNodeBST(root->left,x);
    else if(x>root->data)
        root->right=addNodeBST(root->right,x);
    return root;
}

void inOrder(Node* root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int height(Node* root){
    if(!root)
        return 0;
    int left,right;
    left=height(root->left);
    right=height(root->right);
    return max(left,right)+1;
}

int diameter(Node* root){
    if(!root)
        return 0;

    int diameterRoot,diameterLeft,diameterRight;

    diameterRoot = height(root->left)+height(root->right)+1;
    diameterLeft = diameter(root->left);
    diameterRight = diameter(root->right);

    return max(diameterRoot, max(diameterLeft,diameterRight));

}

int main(){
    int n,i,x;
    Node* root=NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<diameter(root);
    return 0;
}

/*
input data
7 50 30 20 40 70 60 80

              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80

*/
