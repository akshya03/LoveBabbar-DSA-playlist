//left view of a tree = 1st element of each lvl in level order traversal
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

vector<int> leftView(Node *root){
    bool f=true;
    vector<int> ans;
    if(!root)
        return ans;

    Node *curr;
    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    while(que.size()>1){
        curr=que.front();
        que.pop();
        if(!curr){
            que.push(NULL);
            f=true; //take next element in ans
            continue;
        }
        if(f){  //flag true means this is 1st element of this lvl
            ans.push_back(curr->data);
            f=false;
        }
        if(curr->left)
            que.push(curr->left);
        if(curr->right)
            que.push(curr->right);
    }
    return ans;
}
