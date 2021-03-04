//inorder iterative
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

void inorder(Node* root){
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderIterative(Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr || !s.empty())
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;

    } /* end of while */
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    inorder(root);
    cout<<endl;
    inorderIterative(root);

    return 0;
}
//ans:4 2 1 7 5 8 3 6
