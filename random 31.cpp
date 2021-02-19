/*
Given a binary tree and a linked list from "leaf to node".Find and print path from "root to leaf".
eg:
          1
       /    \
      2       2
    /  \    /   \
   4    5   6     8
        /
      8
Given Linked List:8->5->2->1
Output: LRL (top to bottom)
*/
#include<bits/stdc++.h>
using namespace std;

struct NodeTree{
    int data;
    struct NodeTree *left,*right;
    NodeTree(int x){
        data=x;
        left=right=NULL;
    }
};

struct NodeLL{
    int data;
    struct NodeLL *next;
    NodeLL(int x){
        data=x;
        next=NULL;
    }
};

NodeLL* addLinkedListNode(NodeLL* head,int x){
    NodeLL *itr,*temp;
    itr=head;
    temp=new NodeLL(x);
    if(!itr)
        return temp;
    while(itr->next)
        itr=itr->next;
    itr->next=temp;
    return head;
}


void displayLinkedList(NodeLL* head){
    if(!head)
        return;
    while(!head->next){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void inOrder(NodeTree* root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
void levelOrder1Queue(NodeTree* root){
    cout<<"Line by Line using 1 queue: ";
    queue<NodeTree*> que;
    que.push(root);
    que.push(NULL);

    while(que.size()>1){
        NodeTree* temp=que.front();
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

void displayResult(string &ans){

    cout<<"Solution found: "<<ans<<endl;
}

bool isValid(NodeTree* root,vector<int> &arr,int pos){
    if(root && root->data==arr[pos])
        return true;
    return false;
}

bool helper(NodeTree* root,vector<int> &arr,string &ans,int pos){
    if(pos==arr.size()-1){
        displayResult(ans);
        return true;
    }

    if(isValid(root->left,arr,pos+1)){
        ans.push_back('L');
        helper(root->left,arr,ans,pos+1);
        ans.pop_back();
    }
    if(isValid(root->right,arr,pos+1)){
        ans.push_back('R');
        helper(root->right,arr,ans,pos+1);
        ans.pop_back();
    }
    return false;
}


void solve(NodeTree* root,NodeLL* head){
    vector<int> arr;
    NodeLL* itr=head;
    if(!root){
        cout<<"Empty tree";
        return;
    }
    if(!head){
        cout<<"Empty Linked List";
        return;
    }

    while(itr){
        arr.push_back(itr->data);
        itr=itr->next;
    }
    reverse(arr.begin(),arr.end());
    cout<<"\nInput LinkedList: ";
    for(int i=0;i<arr.size();++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    if(root->data!=arr[0]){
        cout<<"Root not equal to 1st element in LL\n";
        return;
    }
    string ans;
    if(helper(root,arr,ans,0)==false)
        cout<<"Ans not found";
}



int main(){
    int n,i,x;
    NodeTree* root=NULL;
    NodeLL *head=NULL;
    cout<<"Enter no. of nodes in LL:";
    cin>>n;
    for(i=0;i<n;++i){
        cin>>x;
        head=addLinkedListNode(head,x);
    }
    root=new NodeTree(1);
    root->left=new NodeTree(2);
    root->left->left=new NodeTree(4);
    root->left->right=new NodeTree(5);
    root->left->right->left=new NodeTree(8);
    root->right=new NodeTree(2);
    root->right->left=new NodeTree(6);
    root->right->right=new NodeTree(8);
    //levelOrder1Queue(root);
    inOrder(root);

    solve(root,head);
    return 0;
}
//4
 //8 5 2 1
