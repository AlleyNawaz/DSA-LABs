#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string val) {
        data = val;
        left = right = NULL;
    }
};

Node* findLCA(Node* root, const string& emp1, const string& emp2) {
    if (root == NULL)
        return NULL;

    if (root->data == emp1 || root->data == emp2)
        return root;

    Node* leftLCA = findLCA(root->left, emp1, emp2);
    Node* rightLCA = findLCA(root->right, emp1, emp2);

    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {

    Node* root = new Node("Alice");

    root->left = new Node("Bob");
    root->right = new Node("Carol");

    root->left->left = new Node("Dave");
    root->left->right = new Node("Eva");

    root->right->left = new Node("Frank");
    root->right->right = new Node("Grace");

    Node* lca1 = findLCA(root, "Eva", "Frank");
    cout << "LCA of Eva and Frank: " << lca1->data << endl;

    Node* lca2 = findLCA(root, "Dave", "Eva");
    cout << "LCA of Dave and Eva: " << lca2->data << endl;

    return 0;
}