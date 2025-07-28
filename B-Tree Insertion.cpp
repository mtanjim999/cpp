#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

Node* insert(Node* root, int data) {
    // Standard BST insertion
    if (root == nullptr)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        // Equal keys not allowed, do nothing
        return root;

    // Update height of this ancestor node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor to check whether this node became unbalanced
    int balance = getBalance(root);

    // If unbalanced, then 4 cases

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the unchanged node pointer
    return root;
}

// Find tree height for printing purposes
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// A helper struct to hold node with its role label
struct NodeInfo {
    Node* node;
    string role;
    NodeInfo(Node* n, string r) : node(n), role(r) {}
};

// Print tree top-down with labels
void printTreeTopDown(Node* root) {
    if (!root) return;
    int h = height(root);
    queue<NodeInfo> q;
    q.push(NodeInfo(root, "root"));

    int level = 0;
    int maxWidth = pow(2, h) - 1;

    while (!q.empty() && level < h) {
        int levelNodes = q.size();

        // Calculate spacing for nodes at current level
        int spaceBetween = maxWidth / (levelNodes + 1);

        vector<string> lineNodes;
        vector<NodeInfo> nextLevel;

        for (int i = 0; i < levelNodes; ++i) {
            NodeInfo ni = q.front(); q.pop();

            if (ni.node)
                lineNodes.push_back(to_string(ni.node->data) + " (" + ni.role + ")");
            else
                lineNodes.push_back(" ");

            // Enqueue children for next level
            if (ni.node) {
                nextLevel.push_back(NodeInfo(ni.node->left, "left"));
                nextLevel.push_back(NodeInfo(ni.node->right, "right"));
            } else {
                // For null nodes, push placeholders to keep structure
                nextLevel.push_back(NodeInfo(nullptr, ""));
                nextLevel.push_back(NodeInfo(nullptr, ""));
            }
        }

        // Print the current level with spacing
        int pos = spaceBetween;
        for (auto &val : lineNodes) {
            int leftSpaces = pos - (val.length() / 2);
            for (int s = 0; s < leftSpaces; s++) cout << " ";
            cout << val;
            pos += spaceBetween;
        }
        cout << "\n";

        // Add next level nodes to queue
        for (auto &ni : nextLevel) {
            q.push(ni);
        }

        maxWidth /= 2;
        level++;
    }
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nAVL Tree (top-down with labels):\n";
    printTreeTopDown(root);

    return 0;
}

