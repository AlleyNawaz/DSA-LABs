#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char val)
{
    Node* n = new Node();
    n->data = val;
    n->left = n->right = NULL;
    return n;
}


// Task 2: Implement Tree Traversals
// Inorder Traversal (Left, Root, Right)
// Visits left subtree, then root, then right subtree
void inorder(Node* root)
{
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
// Visits root first, then left subtree, then right subtree
void preorder(Node* root)
{
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
// Visits left subtree, then right subtree, then root
void postorder(Node* root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// Task 3: Search for an Element
// Recursively searches for a given key in the binary tree
// Returns true if found, otherwise false
bool search(Node* root, char key)
{
    if (!root) return false;
    if (root->data == key) return true;

    return search(root->left, key) || search(root->right, key);
}

// Task 4: Calculate Height of Tree
// Calculates height of binary tree using recursion
// Height = number of edges in longest path from root to leaf
int height(Node* root)
{
    if (!root) return -1;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

// Task 5 (Advanced): Count Leaf Nodes and Total Nodes
// Counts total number of nodes in the tree
int countNodes(Node* root)
{
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Counts number of leaf nodes (nodes with no children)
int countLeaves(Node* root)
{
    if (!root) return 0;

    // if node has no children → leaf node
    if (!root->left && !root->right)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

// Bonus Task
void levelOrder(Node* root)
{
    if (!root) return;

    Node* arr[100];   // manual queue
    int front = 0, rear = 0;

    arr[rear++] = root;

    while (front < rear)
    {
        Node* temp = arr[front++];
        cout << temp->data << " ";

        if (temp->left)
            arr[rear++] = temp->left;

        if (temp->right)
            arr[rear++] = temp->right;
    }
}

// Task 6
// Structure for threaded binary tree node
struct TNode
{
    char data;
    TNode *left, *right;
    bool lThread, rThread;
};

TNode* createTNode(char val)
{
    TNode* n = new TNode();
    n->data = val;
    n->left = n->right = NULL;
    n->lThread = n->rThread = true;
    return n;
}

// Inserts a node into threaded binary tree (BST style)
TNode* insertTBT(TNode* root, char key)
{
    if (!root)
        return createTNode(key);

    TNode* parent = NULL;
    TNode* curr = root;

    // find position to insert
    while (curr)
    {
        if (key == curr->data)
            return root;

        parent = curr;

        if (key < curr->data)
        {
            if (!curr->lThread)
                curr = curr->left;
            else break;
        }
        else
        {
            if (!curr->rThread)
                curr = curr->right;
            else break;
        }
    }

    TNode* newNode = createTNode(key);

    // insert as left child
    if (key < parent->data)
    {
        newNode->left = parent->left;
        newNode->right = parent;

        parent->lThread = false;
        parent->left = newNode;
    }
    else // insert as right child
    {
        newNode->left = parent;
        newNode->right = parent->right;

        parent->rThread = false;
        parent->right = newNode;
    }

    return root;
}

// Inorder traversal of threaded binary tree without recursion or stack
void inorderTBT(TNode* root)
{
    if (!root) return;

    TNode* curr = root;

    while (!curr->lThread)
        curr = curr->left;

    while (curr)
    {
        cout << curr->data << " ";

        if (curr->rThread)
            curr = curr->right;
        else
        {
            curr = curr->right;
            while (curr && !curr->lThread)
                curr = curr->left;
        }
    }
}

int main()
{
    // Task 1: Build a Static Binary Tree
    Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');

    root->left->left = createNode('D');
    root->left->right = createNode('E');

    root->right->left = createNode('F');
    root->right->right = createNode('G');

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n\nSearch E: " << (search(root, 'E') ? "Found" : "Not Found");
    cout << "\nSearch X: " << (search(root, 'X') ? "Found" : "Not Found");

    cout << "\n\nHeight: " << height(root);

    cout << "\nTotal Nodes: " << countNodes(root);
    cout << "\nLeaf Nodes: " << countLeaves(root);

    cout << "\n\nLevel Order: ";
    levelOrder(root);

    TNode* troot = NULL;

    troot = insertTBT(troot, 'D');
    troot = insertTBT(troot, 'B');
    troot = insertTBT(troot, 'F');
    troot = insertTBT(troot, 'A');
    troot = insertTBT(troot, 'C');
    troot = insertTBT(troot, 'E');
    troot = insertTBT(troot, 'G');

    cout << "\n\nThreaded Tree Inorder: ";
    inorderTBT(troot);

    return 0;
}