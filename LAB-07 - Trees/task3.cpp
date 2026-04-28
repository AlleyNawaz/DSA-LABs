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

bool search(Node* root, int key) {
    if (root == NULL) return false;

    if (root->data == key) return true;

    return search(root->left, key) || search(root->right, key);
}

int main() {
    Node* root = createTree();

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Element Found\n";
    else
        cout << "Element Not Found\n";

    return 0;
}