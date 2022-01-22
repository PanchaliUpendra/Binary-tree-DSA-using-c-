//****CONSTRUCTING THE TREE BY USING POSTORDER AND INORDER*******//


 #include<bits/stdc++.h>
 using namespace std;
 struct Node{
     int var;
     struct Node* left;
     struct Node* right;
     Node(int value){
         var=value;
         left=NULL;
         right=NULL;
     }
 };
 int search(int inorder[],int start,int end, int curr)
 {
     for(int i=0;i<=end;i++)
     {
         if(inorder[i]==curr)return i;
     }
     return -1;
 }
 Node* buildTree(int postorder[],int inorder[],int start, int end){
     static int idx=4;
     if(start>end){
         return NULL;
     }
     int curr=postorder[idx];
     idx--;
     Node* node=new Node(curr);
     if(start==end){
         return node;
     }
     int pos=search(inorder,start,end,curr);
     node->right=buildTree(postorder,inorder,pos+1,end);
     node->left=buildTree(postorder,inorder,start,pos-1);
     
     return node;

 }
 void inorderprint(Node* root){
     if(root==NULL){
         return ;
     }
     inorderprint(root->left);
     cout<<root->var<<ends;
     inorderprint(root->right);
 }
 int main()
 {
     int postorder[]={4,2,5,3,1};
     int inorder[]={4,2,1,5,3};
     Node* root=buildTree(postorder,inorder,0,4);
     inorderprint(root);

     return 0;
 }
 