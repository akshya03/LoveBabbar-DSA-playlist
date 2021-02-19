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

int heightIterative(Node* root){
    if(!root)
        return 0;

    Node* curr;
    queue<Node*> que;
    int lvl=1;
    que.push(root);
    que.push(NULL);

    while(que.size()>1){
        curr=que.front();
        que.pop();
        if(!curr){
            //cout<<endl;
            ++lvl;
            que.push(NULL);
            continue;
        }
        //cout<<curr->data<<" ";
        if(curr->left)
            que.push(curr->left);
        if(curr->right)
            que.push(curr->right);
    }
    return lvl;
}

int heightRecursive(Node* root){
    if(!root)
        return 0;

    int left,right;
    left=heightRecursive(root->left);
    right=heightRecursive(root->right);
    return max(left,right)+1;
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
    inOrder(root);

    cout<<endl;
    cout<<heightRecursive(root)<<endl;
    cout<<heightIterative(root)<<endl;
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
