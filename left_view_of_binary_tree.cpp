#include<bits/stdc++.h>
using namespace std;
struct Node{
    int var;
    struct Node* left;
    struct Node* right;
    Node(int value)
    {
        var=value;
        left=NULL;
        right=NULL;
    }
};
void left_view(struct Node* root)
{
    if(root==NULL) return ;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            struct Node* node= q.front();
            q.pop();
            if(i==n-1) cout<<node->var<<" ";
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
    }
}
int main()
{
    struct Node* root =new Node(5);
    root->left=new Node(6);
    root->right=new Node(7);
    root->right->left=new Node(8);
    root->right->right= new Node(9);
    root->right->right->left=new Node(10);

    left_view(root);
    return 0;
}