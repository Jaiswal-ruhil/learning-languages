/*Program 14
Design, develop, and execute a program in C++ to create a class called BIN_TREE that represents a Binary Tree, with member functions to perform inorder, preorder and postorder traversals.Create a BIN_TREE object and demonstrate the traversals.
*/

#include<iostream>
using namespace std;
struct dlist{
  int info;
  struct dlist *left,*right;
};

typedef struct dlist node;
node *root;

class bin_tree{
public:
  void gettree();
  void inorder(node *);
  void preorder(node *);
  void postorder(node *);
};

void bin_tree::gettree(){
  node *newnode;
  node *prev=NULL;
  int n;
  cout<<"enter the number of elements\n";
  cin>>n;
  cout<<"the elements are\n";
  while(--n){
    newnode=new node;
    cin>>newnode->info;
    newnode->left=newnode->right=NULL;
    if(root==NULL){
      root=newnode;
	  continue;
    }
    for(node *temp=root; temp ;){
      prev=temp;
      temp=(newnode->info < temp->info)?temp->left:temp->right;
    }
    if(newnode->info < prev->info)
      prev->left=newnode;
    else
      prev->right=newnode;
  }
}

void bin_tree::inorder(node *temp){
  if(temp){
    inorder(temp->left);
    cout<<"\t"<<temp->info;
    inorder(temp->right);
  }
}

void bin_tree::preorder(node *temp){
  if(temp){
    cout<<"\t"<<temp->info;
    preorder(temp->left);
    preorder(temp->right);
  }
}

void bin_tree::postorder(node *temp){
  if(temp){
    postorder(temp->left);
    postorder(temp->right);
    cout<<"\t"<<temp->info;
  }
}

main(){
  bin_tree t1;
  t1.gettree();
  cout<<"\npreorder\t";
  t1.preorder(root);
  cout<<"\ninorder\t\t";
  t1.inorder(root);
  cout<<"\npostorder\t";
  t1.postorder(root);
  cout<<endl;
  return 0;
}
