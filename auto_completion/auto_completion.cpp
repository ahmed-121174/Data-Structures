#include<iostream>
#include<string>
using namespace std;
class Node {
public:
    string word;
    int frequency;
    Node *left;
    Node *right;
    int height;
    Node(string word, int frequency) {
        this->word=word;
        this->frequency=frequency;
        left=NULL;
        right=NULL;
        height=1;
    }
};
class AVLTree {
public:
    Node* root;
    AVLTree() {
        root=NULL;
    }
    int getHeight(Node* node){
        if(node==NULL)
            return 0;
        return node->height;
    }
    int max(int a, int b){
        return (a>b)?a:b;
    }
    Node* rightRotate(Node* y){
        Node *x=y->left;
        Node *T2=x->right;
        x->right=y;
        y->left=T2;
        y->height=max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height=max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }
    Node *leftRotate(Node *x){
        Node *y=x->right;
        Node *T2=y->left;
        y->left=x;
        x->right=T2;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        return y;
    }
    int getBalance(Node* node) {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    Node* insertWord(Node* node, string word, int frequency) {
        if (node == NULL) {
            return new Node(word, frequency);
        }

        if (word < node->word)
            node->left = insertWord(node->left, word, frequency);
        else if (word > node->word)
            node->right = insertWord(node->right, word, frequency);
            node->frequency = frequency;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		int balance = getBalance(node);
        if (balance > 1 && word < node->left->word)
            return rightRotate(node);

        if (balance < -1 && word > node->right->word)
            return leftRotate(node);
        if (balance > 1 && word > node->left->word) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && word < node->right->word) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void search(Node* node,string prefix) {
        if(node==NULL)
            return;
        if(node->word.find(prefix)==0)
            cout<<node->word<<endl;
        if(node->left)
            search(node->left,prefix);
        if(node->right)
            search(node->right,prefix);
    }
};

int main() {
    AVLTree tree;
    tree.root=tree.insertWord(tree.root,"car",10);
    tree.root=tree.insertWord(tree.root,"cat",8);
    tree.root=tree.insertWord(tree.root,"calendar",5);
	tree.root=tree.insertWord(tree.root,"carrot",3);
	tree.root=tree.insertWord(tree.root,"ball",10);
    tree.root=tree.insertWord(tree.root,"baloon",8);
    tree.root=tree.insertWord(tree.root,"banu",5);
	tree.root=tree.insertWord(tree.root,"bacoot",3);
	
    string prefix;
    cout<<"Enter word: ";
    cin>>prefix;

    cout<<"Auto-completion suggestions:"<<endl;
    tree.search(tree.root,prefix);

    return 0;
}
