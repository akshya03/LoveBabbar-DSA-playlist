//detect loop in a linked list
//floyd method to detect cycle

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

bool detectLoop(Node *head){
    Node* itr1,*itr2;

    itr1=itr2=head;

    while(itr1 && itr2 && itr2->next){
        itr1=itr1->next;
        itr2=itr2->next->next;
        if(itr1==itr2)
            return 1;
    }
    return 0;
}

Node* addNode(Node* head, int x){
    Node *itr=head;

    if(!head)
        return new Node(x);
    while(itr->next){
        itr=itr->next;
    }

    itr->next=new Node(x);
    return head;
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

int main()
{
    /* Start with the empty list */
    Node* head = nullptr;

    int arr[]={20,4,15,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;++i){
        head=addNode(head,arr[i]);
    }
    displayList(head);
    head->next->next->next->next = head;

    cout<<"Loop exists:"<<detectLoop(head);

    return 0;
}


