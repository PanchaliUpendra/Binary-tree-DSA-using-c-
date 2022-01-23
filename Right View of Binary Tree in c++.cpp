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
void printRightView(struct Node* root)
{
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* node= q.front();
            q.pop();
            if(i==n-1) cout<<node->val<<" ";
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
    }
}
int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->left->left=new Node(7);
    root->right->right=new Node(6);

    printRightView(root);
    return 0;

}