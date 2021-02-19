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

void reverseLevelTraversal(Node* root){
    queue<Node*> que;
    stack<int> stk;
    Node* curr;

    que.push(root);
    while(!que.empty()){
        curr=que.front();
        que.pop();
        if(curr->right)
            que.push(curr->right);
        if(curr->left)
            que.push(curr->left);
        stk.push(curr->data);
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

}

int main(){
    int n,i,x;
    Node* root=NULL;
    cout<<"Enter no. of values:";
    cin>>n;
    for(i=0;i<n;++i){
        cin>>x;
        root=addNodeBST(root,x);
    }
    //inOrder(root);
    cout<<endl;
    reverseLevelTraversal(root);
    return 0;
}

/*
input data
7
50 30 20 40 70 60 80

              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80

*/
