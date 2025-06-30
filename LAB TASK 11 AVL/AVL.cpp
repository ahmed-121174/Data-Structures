#include<iostream>
using namespace std;

class node
{
	private:
		int data;
		node *left;
		node *right;
	public:
		node(int data)
		{
			this->data=data;
			left=nullptr;
			right=nullptr;
		}
		friend class avl;
		friend int main();
};
class avl
{
	public:
		node *left(node *A)
		{
			node *B=A->right;
			node *trees=B->left;
			B->left=A;
			A->right=trees;
			return B;
		}
		node *right(node *B)
		{
			node *A=B->left;
			node *trees=A->right;
			A->right=B;
			B->left=trees;
			return A;
		}
		node *rot_rl(node *root)
		{
			root->right=right(root->right);
			return left(root);
		}
		node *rot_lr(node *root)
		{
			root->left=left(root->left);
			return right(root);
		}
		void preorder(node *root)
		{
			if(root!=nullptr)
			{
				cout<<root->data<<" ";
				preorder(root->left);
				preorder(root->right);
			}
		}
};

int main()
{
	avl t;
//	rl
	node *rl=new node(1);
	rl->right=new node(3);
	rl->right->left=new node(2);
	cout<<"before rl rotate: ";
	t.preorder(rl);
	cout<<endl;
	rl=t.rot_rl(rl);
	cout<<"after rl rotate: ";
	t.preorder(rl);
	cout<<endl;
//  lr
	node *lr=new node(3);
	lr->left=new node(1);
	lr->left->right=new node(2);
	cout<<"before lr rotate: ";
	t.preorder(lr);
	cout<<endl;
	lr=t.rot_lr(lr);
	cout<<"after lr rotate: ";
	t.preorder(lr);
	cout<<endl;
	return 0;
}