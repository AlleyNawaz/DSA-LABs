#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* createTree() {
    int val;
    cout << "Enter value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);

    cout << "Enter left of " << val << endl;
    root->left = createTree();

    cout << "Enter right of " << val << endl;
    root->right = createTree();

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = createTree();

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}