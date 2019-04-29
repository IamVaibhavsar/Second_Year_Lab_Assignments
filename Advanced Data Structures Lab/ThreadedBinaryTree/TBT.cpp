/*Convert given binary tree into threaded binary tree. Analyze time and space complexity of the
algorithm.*/


#include<iostream>
using namespace std;

class node {
	public :
		int data;
		int lth,rth;
		node *right,*left;
};

class TBT {
	
		
	public :node * root,* head;
		TBT() {
		head = new node;
		head->right = head;
		head->left = head;
		head->lth = 1;
		head->rth = 0;
		root = NULL;
		}
		void create();
		void preorder();
		//void inorder();
		//node * inorderSucc(node *);
};


 // 

void TBT :: create() {
	node *temp,*curr;
	char ch;
	do {
		curr = new node;
		cout<<"\n Enter the data : ";
		cin>>curr->data;
		curr->right = NULL;
		curr->left = NULL;
		curr->lth = 1;
		curr->rth = 1;

		if(root == NULL) 
		{
			root = curr;
			root->right = head;
			root->left = head;
			head->left = root;
			head->lth = 0;			
		} else 
		{
			temp = root;
			while(1) 
			{
				if(curr->data < temp->data) 
				{
					if(temp->lth == 1) 
					{
					curr->left = temp->left;
					curr->right = temp;
					temp->lth = 0;
					temp->left = curr;	
					break;	
					} 
					else 
					{
						temp = temp->left;
					}	
				} 
					else 
					{
					if(temp->rth == 1) 
					{
					curr->right = temp->right;
					curr->left = temp;
					temp->rth = 0;
					temp->right = curr;
					break;
					} 
					else 
					{
						temp = temp->right;		
					}
				}
			}				
		}
		cout<<"\n Do you want to continue (Y/N) :  ";
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');	
}

void TBT :: preorder() {
node * temp;
int flag = 0;
temp = root;
	while(temp != head) 
	{
		if(flag == 0)
			cout<<temp->data<< "  ";
		if(temp->lth == 0 && flag == 0) {
			temp = temp->left;
		} 
		else if( temp->rth == 0){
			temp = temp->right;
			flag = 0;
		} else {
			temp = temp->right;
			flag = 1;
		}
	}
} 


/*void TBT :: inorder() {
	node* temp;
	temp = head;
	do{
		temp = inorderSucc(temp);
		if(temp!= head)
			cout<<temp->data<<" ";
	}while(temp != head);
}

/*node * TBT :: inorderSucc(node * temp) {
	node * p;
	p = temp->right;
	if(temp->rth == 0) {
		while(p->lth == 0) {
			p = p->left;
		}
	}
	return p;
	
}*/



int main() 
{
	TBT t;
	cout<<"\n Create a binary tree : ";
	t.create();
	cout<<"\n Preorder traversal is : ";
	t.preorder();
	//cout<<"\n Inorder traversal is : ";
	//t.inorder();
return 0;
}













