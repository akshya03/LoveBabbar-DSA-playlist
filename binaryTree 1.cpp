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

void preOrder(Node *root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void levelOrder1Queue(Node* root){
    cout<<"Line by Line using 1 queue: ";
    queue<Node*> que;
    que.push(root);
    que.push(NULL);

    while(que.size()>1){
        Node* temp=que.front();
        que.pop();
        if(temp==NULL){
            que.push(NULL);
            cout<<endl;
            continue;
        }
        cout<<temp->data<<" ";

        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
    }
    cout<<endl;
}

void levelOrder2Queues(Node *root){
    cout<<"Using 2 queues: ";
    queue<Node*> q1,q2;
    Node* curr;

    q1.push(root);

    while( (!q1.empty()) || (!q2.empty()) ){

        while(!q1.empty()){
            curr=q1.front();
            cout<<curr->data<<" ";
            q1.pop();
        if(curr->left)
            q2.push(curr->left);
        if(curr->right)
            q2.push(curr->right);
        }
        cout<<endl;
        while(!q2.empty()){
            curr=q2.front();
            cout<<curr->data<<" ";
            q2.pop();
        if(curr->left)
            q1.push(curr->left);
        if(curr->right)
            q1.push(curr->right);
        }
        cout<<endl;
    }

}

void levelOrderTraversal(Node *root){
    cout<<"Level order traversal: ";
    queue<Node*> que;
    que.push(root);
    while(!(que.empty())){
        Node* temp=que.front();
        cout<<temp->data<<" ";
        que.pop();
        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
    }
    cout<<endl;
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
    levelOrderTraversal(root);
    levelOrder2Queues(root);
    levelOrder1Queue(root);
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
