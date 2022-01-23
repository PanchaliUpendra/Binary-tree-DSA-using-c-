///****Height Balanced Binary Tree ***///
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
bool isBalanced(struct Node* root, int *height)
{
    if(root==NULL) return true;
    int lh=0,rh=0;
    if(isBalanced(root->left,&lh)==false) return false;
    if(isBalanced(root->right,&rh)==false) return false;
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    {
        return true;
    }
    else{
        return false;
    }


}
int main()
{
    struct Node* root=new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    //root->left->left->left=new Node(6);
    int height=0;
    //checking the given tree is balanced or not
    if(isBalanced(root,&height)){
        cout<<"Balanced BINARY TREE\n";
    }
    else{
        cout<<"NOT a Balanced BINARY TREE\n";
    }
    return 0;
}