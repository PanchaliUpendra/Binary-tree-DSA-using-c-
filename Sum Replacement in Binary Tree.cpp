///******SUM REPLACEMENT IN BINARY TREE********////
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
void SumReplace(struct Node* root)
{
    if(root==NULL) return ;
    SumReplace(root->left);
    SumReplace(root->right);
    if(root->left!=NULL) root->val+=root->left->val;
    if(root->right!=NULL) root->val+=root->right->val;
}
void PrintPreorder(struct Node* root)
{
    if(root==NULL) return;
    cout<<root->val<<ends;
    PrintPreorder(root->left);
    PrintPreorder(root->right);

}
int main()
{
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left= new Node(6);
    root->right->right=new Node(7);
    //print thr preorder before sum replacement
    PrintPreorder(root);
    SumReplace(root);//calling sum replacement
    cout<<"\n";
    PrintPreorder(root);//printing the tree after sum replace
    return 0;
}