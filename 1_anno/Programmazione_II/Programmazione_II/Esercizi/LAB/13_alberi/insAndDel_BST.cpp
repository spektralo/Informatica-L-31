#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
};

class BST {
private:
    Node* root;
    int elementCount = 0;

    // Private recursive traversal methods
    void inOrderTraversal(Node* node) const;
    void preOrderTraversal(Node* node) const;
    void postOrderTraversal(Node* node) const;

    // Helper methods for deletion
    void deleteNode(Node* node);
    void transplant(Node* oldNode, Node* newNode);
    Node* findMin(Node* startNode);

public:
    BST() : root(nullptr) {}

    void insert(int value);

    // Public traversal methods
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;

    int height(Node* node) const;
    bool remove(int value);
    int findMin();

    friend ostream& operator<<(ostream& out, const BST& tree);
};


// Pre-order traversal: root -> left subtree -> right subtree
void BST::preOrderTraversal(Node* node) const {
    if (node != nullptr) {
        cout << node->value << "\t";
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
    }
}



// In-order traversal: left subtree -> root -> right subtree
void BST::inOrderTraversal(Node* node) const {
    if (node != nullptr) {
        inOrderTraversal(node->leftChild);
        cout << node->value << "\t";
        inOrderTraversal(node->rightChild);
    }
}

// Post-order traversal: left subtree -> right subtree -> root
void BST::postOrderTraversal(Node* node) const {
    if (node != nullptr) {
        postOrderTraversal(node->leftChild);
        postOrderTraversal(node->rightChild);
        cout << node->value << "\t";
    }
}



// Public version of pre-order traversal
void BST::preOrder() const {
    preOrderTraversal(root);
}

// Public version of in-order traversal
void BST::inOrder() const {
    inOrderTraversal(root);
}

// Public version of post-order traversal
void BST::postOrder() const {
    postOrderTraversal(root);
}



// Insert a new value into the tree
void BST::insert(int value) {
    Node* newNode = new Node{value, nullptr, nullptr, nullptr};
    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value < current->value)
            current = current->leftChild;
        else
            current = current->rightChild;
    }

    newNode->parent = parent;
    if (parent == nullptr) {
        root = newNode; // Tree was empty

    } else if (value < parent->value) {
        parent->leftChild = newNode;
        
    } else {
        parent->rightChild = newNode;
    }

    elementCount++;
}

// Helper function to print nodes at a specific level
void printLevel(Node* node, int level) {
    if (node == nullptr) {
        if (level == 0) cout << "_\t";
        return;
    }

    if (level == 0) {
        cout << node->value << "\t";

    } else if (level > 0) {
        printLevel(node->leftChild, level - 1);
        printLevel(node->rightChild, level - 1);
    }
}

// Calculate the height of the tree
int BST::height(Node* node) const {
    if (node == nullptr) return 0;

    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);

    return max(leftHeight, rightHeight) + 1;
}

// Overloaded operator to print the tree level by level
ostream& operator<<(ostream& out, const BST& tree) {
    int treeHeight = tree.height(tree.root);
    out << "Tree of height " << treeHeight << endl;
    for (int i = 0; i < treeHeight; i++) {
        printLevel(tree.root, i);
        out << endl;
    }
    return out;
}

// Helper method to replace a subtree with another
void BST::transplant(Node* oldNode, Node* newNode) {
    if (oldNode->parent == nullptr) {
        root = newNode;
    } else if (oldNode == oldNode->parent->leftChild) {
        oldNode->parent->leftChild = newNode;
    } else {
        oldNode->parent->rightChild = newNode;
    }
    if (newNode != nullptr) {
        newNode->parent = oldNode->parent;
    }
}

// Find the minimum node starting from a given node
Node* BST::findMin(Node* startNode) {
    while (startNode->leftChild != nullptr) {
        startNode = startNode->leftChild;
    }
    return startNode;
}

// Public method to find the minimum value in the tree
int BST::findMin() {
    Node* minNode = findMin(root);
    return minNode->value;
}

// Private method to delete a node
void BST::deleteNode(Node* targetNode) {
    if (targetNode->leftChild == nullptr) {
        transplant(targetNode, targetNode->rightChild);
    } 
    else if (targetNode->rightChild == nullptr) {
        transplant(targetNode, targetNode->leftChild);

    }

    else {
        Node* successor = findMin(targetNode->rightChild);

        if (successor->parent != targetNode) {
            transplant(successor, successor->rightChild);
            successor->rightChild = targetNode->rightChild;
            successor->rightChild->parent = successor;
        }

        transplant(targetNode, successor);
        successor->leftChild = targetNode->leftChild;
        successor->leftChild->parent = successor;
    }
    delete targetNode;
}

// Public method to delete a node by value
bool BST::remove(int value) {
    Node* current = root;

    // Find the node with the given value
    while (current != nullptr && current->value != value) {
        if (value < current->value)
            current = current->leftChild;
        else
            current = current->rightChild;
    }

    if (current == nullptr) return false; // Value not found

    deleteNode(current);
    return true;
}
