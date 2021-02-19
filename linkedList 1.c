#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* newNode(int x){
    Node* temp=(Node *)malloc(sizeof(Node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}

Node* addNode(Node* root,int x){
    Node *itr,*temp;
    temp=newNode(x);
    itr=root;
    if(!root)
        return temp;
    while(itr->next)
        itr=itr->next;
    itr->next=temp;
    return root;
}

void displayList(Node *root){
    Node* itr=root;
    printf("Display List:");
    while(itr){
        printf("%d ",itr->data);
        itr=itr->next;
    }
    printf("\n");
}

void reverseIterative(Node **root){
    Node *current,*prv,*nxt;
    current=*root;
    if(!(current) || !(current->next))
        return;

    prv=NULL;
    while(current){
        nxt=current->next;
        current->next=prv;
        prv=current;
        current=nxt;
    }
    *root=prv;
}

int main(){
    int n,i,x;
    scanf("%d",&n);
    Node* head=NULL;
    for(i=0;i<n;++i){
        scanf("%d",&x);
        head=addNode(head,x);
    }
    displayList(head);
    //reverseIterative(&head);

    displayList(head);


    return 0;
}
