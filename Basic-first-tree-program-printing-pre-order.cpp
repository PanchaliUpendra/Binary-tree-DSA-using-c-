//*****BASIC-FIRST-TREE-PROGRAM******PRINTING PRE-ORDER ELEMENTS OF THE TREE**//

#include<bits/stdc++.h>
using namespace std;
struct node{
    int var;
    struct node* left;
    struct node* right;
    node(int value){
        var=value;
        left=NULL;
        right=NULL;
    }
};
void print(struct node* head)
{
    if(head==NULL) return;
    cout<<head->var<<ends;
    print(head->left);
    print(head->right);

}
int main()
{
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    cout<<"print the pre-order tree\n";
    print(root);
    return 0;
}