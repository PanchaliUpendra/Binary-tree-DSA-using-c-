#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int value)
    {
        val=value;
        left=NULL;
        right=NULL;
    }
};
void construct(struct Node* root){
    if(root==NULL) return ;
    if(root->left!=NULL){
        construct(root->left);
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        Node* t= root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    construct(root->right);
}

void printInorder(Node* root)
{
    if(root==NULL) return ;
    printInorder(root->left);
    cout<<root->val<<" ";
    printInorder(root->right);
}

int main()
{
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    construct(root);
    printInorder(root);


}