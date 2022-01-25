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
Node* FindLca(Node* root,int n1,int n2)
{
    if(root==NULL) return NULL;
    if(root->val==n1 || root->val==n2) return root;
    Node* left=FindLca(root->left,n1,n2);
    Node* right=FindLca(root->right,n1,n2);
    if(left!=NULL and right!=NULL) return root;
    if(left==NULL and right==NULL) return NULL;
    if(left!=NULL) return FindLca(root->left,n1,n2);
    return FindLca(root->right,n1,n2);
}
int Distance(Node* root,int x,int dist)
{
    if(root==NULL) return -1;
    if(root->val==x) return dist;
    int left=Distance(root->left,x,dist+1);
    if(left!=-1) return dist;
    return Distance(root->right,x,dist+1);
    
}
int FindTheDistanc(Node* root,int n1, int n2)
{
    if(root==NULL) return 0;
    Node* lca=FindLca(root,n1,n2);
    int d1=Distance(root,n1,0);
    int d2=Distance(root,n2,0);
    return d1+d2;

}
int main()
{
    struct Node* root=new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->right->left= new Node(4);
    root->right->right=new Node(5);
    root->right->right->right=new Node(6);
    int n1=2,n2=6;
    int d=FindTheDistanc(root,n1,n2);
    cout<<"distance: "<< d;
    
    return 0;
}