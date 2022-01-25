#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int value)
    {
        val=value;
        left=NULL;
        right=NULL;
    }
};

Node* FindLca(Node* root,int n1,int n2)
{
    if(root==NULL) return NULL;
    if(root->val==n1||root->val==n2) return root;
    Node* left= FindLca(root->left,n1,n2);
    Node* right=FindLca(root->right,n1,n2);
    if(left!=NULL and right!=NULL) return root;
    if(left==NULL and right==NULL) return NULL;
    if(left!=NULL) return FindLca(root->left,n1,n2);
    return FindLca(root->right,n1,n2);
}
int main()
{
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right= new Node(3);
    root->right->left= new Node(4);
    root->right->right= new Node(5);
    root->right->right->right= new Node(6);
    int n1=4,n2=6;
    Node* lca=FindLca(root,n1,n2);
    cout<<"the Lca of the given tree is : "<<lca->val;

    return 0;
}