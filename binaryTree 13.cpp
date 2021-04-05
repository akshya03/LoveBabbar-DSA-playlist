//similar to vertical traversal
// only diff is that only last dist is taken

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

void bottomView(Node* root){
    if(!root)
        return;

    Node* curr;
    int parentDist;
    queue<Node*> que;
    queue<int> dist;
    map<int,int> umap;  //dist,list of Nodes at that vertical dist

    que.push(root);
    dist.push(0);
    while(!que.empty()){
        curr=que.front();
        parentDist=dist.front();
        que.pop();
        dist.pop();

        //if(umap.find(parentDist) == umap.end())
        //    umap[parentDist].push_back(curr->data);
        umap[parentDist]=curr->data;

        if(curr->left){
            que.push(curr->left);
            dist.push(parentDist-1);
        }
        if(curr->right){
            que.push(curr->right);
            dist.push(parentDist+1);
        }
    }

    for(auto x:umap){

            cout<<x.second<<" ";
        cout<<endl;
    }
}


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

    cout << "Bottom view is \n";
    bottomView(root);

    return 0;
}

/*
           1
        /    \
       2      3
      / \    / \
     4   5  6   7   #nodes at same lvl with same horizontal distance: take the last node at that lvl(of same dist( as they overwrite each other
             \   \
              8   9
Output:
The output of print this tree vertically will be:
4
2
6
8
7
9
*/
