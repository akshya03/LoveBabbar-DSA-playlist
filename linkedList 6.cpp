//remove duplicates in sorted linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};

void addNode(Node **head, int x){
    Node *itr=*head;

    if(!itr)
        itr=new Node(x);
    while(itr->next){
        itr=itr->next;
    }

    itr->next=new Node(x);
    //return head;
}

void displayList(Node* head){
    Node *itr;
    itr=head;

    while(itr){
        cout<<itr->data<<" ";
        itr=itr->next;
    }
    cout<<endl;
}

int main(){
    Node *head=nullptr;

    int n,i,x;
    cout<<"Enter no. of elements, elements:";
    cin>>n;
    for(i=0;i<n;++i){
        cin>>x;
        //head=addNode(head,x);
        addNode(&head,x);
    }
    displayList(head);

    return 0;
}
