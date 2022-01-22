//WAP to print the ******POST_ORDER_OF_THE_TREE*******///

 #include<iostream>
 using namespace std;
 struct node{
     int var;
     struct node* left;
     struct node* right;
     node(int value)
     {
         var=value;
         left=NULL;
         right=NULL;
     }
 };
 void postorder(struct node* head){
     if(head==NULL) return;
     postorder(head->left);
     postorder(head->right);
     cout<<head->var<<ends;
 }
 
 int main()
 {
     struct node* root= new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->right->left=new node(6);
     root->right->right=new node(7);
     postorder(root);
     return 0;
 }
 
