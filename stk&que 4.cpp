//find middle element of stack
// push,pop,find_middle,delete_middle in O(1)
//possible using Doubly
//push always at top (head) of stk

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next,*prev;
    Node(int x){
        data=x;
        next=prev=NULL;
    }
};

class Stk{
    Node *head,*tail,*middle;
    int c;

    public:
    Stk(){
        head=tail=middle=NULL;
        c=0;
    }
    void displayForward(){
        Node *itr=head;
        cout<<"Forward traversal: ";
        while(itr){
            cout<<itr->data<<" ";
            itr=itr->next;
        }
        cout<<endl;
    }

    void displayReverse(){
        Node *itr=tail;
        cout<<"Reverse traversal: ";
        while(itr){
            cout<<itr->data<<" ";
            itr=itr->prev;
        }
        cout<<endl;
    }

    void push(int x){
        Node* temp=new Node(x);
        //++c;
        if(!head){
            head=tail=temp;
            ++c;
        }
        else{
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
        if(c/2==(c+1)/2)
            middle=middle->next;
            ++c;
    }

    int pop(){
        if(c==0)
            return -1;

        int x=head->data;
        --c;
        if(head==tail){
            head=tail=NULL;
            return x;
        }

        Node* temp=head->next;
        delete head;
        temp->prev=NULL;
        head=temp;
        return x;
    }

    int findMiddle(){
        if(!middle)
            return -1;
        return middle->data;
    }

};

int main(){
    Stk stk;
    int i,n,x;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>x;
        stk.push(x);
    }
    stk.displayForward();
    //stk.displayReverse();
    cout<<"Middle: "<<stk.findMiddle()<<endl;
    return 0;
}
