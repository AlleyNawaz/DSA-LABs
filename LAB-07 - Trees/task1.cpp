#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* createTree() {
    int value;
    cout << "Enter value (-1 for NULL): ";
    cin >> value;

    if (value == -1) return NULL;

    Node* root = new Node(value);

    cout << "Enter left of " << value << endl;
    root->left = createTree();

    cout << "Enter right of " << value << endl;
    root->right = createTree();

    return root;
}

int main() {
    cout << "Create Binary Tree" << endl;

    Node* root = createTree();

    cout << "\nTree created successfully!" << endl;

    return 0;
}