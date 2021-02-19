#include<stdio.h>
#include<stdlib.h>
typedef struct Tnode{
    char data;
    struct TNode *left,*right;
}Tnode;
Tnode* newNode(char data){
    Tnode* node =(Tnode *)malloc(sizeof(Tnode));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

Tnode* arrayToTree(char arr[],int start,int end){
    if(start<end){
        return NULL;
    }
    int mid=(start+end)/2;
    Tnode* root=newNode(arr[mid]);
    root->left=arrayToTree(arr,start,mid-1);
    root->right=arrayToTree(arr,mid+1,end);
    return root;
}

void preOrder(Tnode* node){
    if(!(node))
        return;
    printf("%c",node->data);
    preOrder(node->left);
    preOrder(node->right);

}

void reverseArray(char *arr,int start,int end){
    while(start<end){
        char x=arr[start];
        arr[start++]=arr[end];
        arr[end--]=x;

    }
}

void updateArray(char *arr,int n){
    int s;
    for(s=0;arr[s]!='\0';++s){
        reverseArray(arr,0,s-1);
        reverseArray(arr,0,n-1);
        reverseArray(arr,n,s-1);
    }
}

int main(){
    char arr[]="kjmrj*gvvnup";
    int n;
    for(n=0;arr[n]!='\0';++n);
    Tnode* root=arrayToTree(arr,0,n-1);
    preOrder(root);
    printf("-");

    updateArray(arr,4);
    root=arrayToTree(arr,0,n-2);
    preOrder(root);
    printf("-");

    updateArray(arr,2);
    root=arrayToTree(arr,0,n-1);
    preOrder(root);
    printf("-");

    updateArray(arr,1);
    root=arrayToTree(arr,0,n-3);
    preOrder(root);

    return 0;
}
