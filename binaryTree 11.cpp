//vertical order traversal
//find distance of nodes of a number line
//root at 0, left child= parent -1, right child= parent+1
//start printing from nodes with min to max distance (left to right on number line)
//nodes with same dist come under same vertical line


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

//solved using 2 parallel queues, 1 for level order traversal storing nodes, 2nd for corresponding dist
//can be solved using 1 queue using "queue< pair<Node,dist> >"
void verticalOrder(Node* root){
    if(!root)
        return;

    Node* curr;
    int parentDist;
    queue<Node*> que;
    queue<int> dist;
    map<int,vector<int>> umap;  //dist,list of Nodes at that vertical dist

    que.push(root);
    dist.push(0);
    while(!que.empty()){
        curr=que.front();
        parentDist=dist.front();
        que.pop();
        dist.pop();

        umap[parentDist].push_back(curr->data);

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
        for(auto y:x.second)
            cout<<y<<" ";
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

    cout << "Vertical order traversal is \n";
    verticalOrder(root);

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
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9
*/
