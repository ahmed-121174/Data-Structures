#include <iostream>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

TreeNode* inorderSuccessor(TreeNode* root, int key, TreeNode* successor = nullptr) {
    if (!root) return successor;

    if (key < root->key) {
        successor = root;
        return inorderSuccessor(root->left, key, successor);
    } else if (key > root->key) {
        return inorderSuccessor(root->right, key, successor);
    } else {
        if (root->right) {
            TreeNode* temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }
            return temp;
        }
    }

    return successor;
}

int main() {
    // Constructing a sample BST
    TreeNode* root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(12);
    root->right->right = new TreeNode(25);
    root->right->left = new TreeNode(16);

    // Finding inorder successor
    int key = 25;
    TreeNode* result = inorderSuccessor(root, key);
    if (result) {
        cout << "Inorder successor of " << key << " is " << result->key << std::endl;
    } else {
        cout << "No inorder successor found for " << key << std::endl;
    }

    // Free allocated memory (not handling full tree deletion for brevity)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
