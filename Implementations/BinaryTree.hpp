#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

// Tree node
struct Node {
    int value; // Data
    int height; // Height of current node
    struct Node *leftChild; // Pointer to node's left child
    struct Node *rightChild; // Pointer to node's right child

    // Constructor
    Node(int x) : value(x), height(1), leftChild(nullptr), rightChild(nullptr) {}
};

class BinaryTree {
    private:
        // Helper Getter functions
        int getHeight(Node *N) { // Get height of tree
            if (N == nullptr) {
                return 0;
            }
            return N->height;
        }
        
        int getBalance(Node *N) { // Get balance-factor of node N
            if (N == nullptr) {
                return 0;
            }
            return getHeight(N->leftChild) - getHeight(N->rightChild);
        }

        // Helper update height function
        void updateHeight(Node *N) {
            if (N == nullptr) {
                return;
            }
            N->height = std::max(getHeight(N->leftChild), getHeight(N->rightChild)) + 1;
        }

        // Remove function
        Node* remove(Node* root, int value) {
            // Base case: If tree/subtree is empty, return nullptr
            if (root == nullptr) {
                return root;
            }

            // Search for node to delete
            if (value < root->value) {
                root->leftChild = remove(root->leftChild, value);
            } else if (value > root->value) {
                root->rightChild = remove(root->rightChild, value);
            } else { // When the node with given value is found
                // Case 1: Node with one or no children. Swap node with child node and delete original node. No need for rebalancing
                if (root->leftChild == nullptr) {
                    Node* temp = root->rightChild;
                    delete root;
                    return temp;
                } else if (root->rightChild == nullptr) {
                    Node* temp = root->leftChild;
                    delete root;
                    return temp;
                }

                // Case 2: Node with two children. May need rebalancing
                Node* temp = maxValueNode(root->leftChild); // Find in-order successor
                root->value = temp->value; // Copy the successor's data to this node
                root->leftChild = remove(root->leftChild, temp->value); // Delete the successor
            }

            // Update height
            updateHeight(root);

            // Return balanced tree
            root = balance(root);
            return root;
        }

        // Balance functions
        Node *rightRotate(Node *y) { // Right-rotate subtree with root y
            Node *x = y->leftChild;
            Node *T2 = x->rightChild;

            // Perform rotation
            x->rightChild = y;
            y->leftChild = T2;

            // Update heights
            updateHeight(y);
            updateHeight(x);

            // Return new root
            return x;
        }

        Node *leftRotate(Node *x) { // Left-rotate subtree with root x
            Node *y = x->rightChild;
            Node *T2 = y->leftChild;

            // Perform rotation
            y->leftChild = x;
            x->rightChild = T2;

            // Update heights
            updateHeight(x);
            updateHeight(y);

            // Return new root
            return y;
        }

        // Helper function to find the max value node from a given node (used during rebalancing)
        Node* maxValueNode(Node* node) {
            Node* current = node;
            while (current->rightChild != nullptr) {
                current = current->rightChild;
            }
            return current;
        }

        // Helper function to find the min value node from a given node
        Node* minValueNode(Node* node) {
            Node* current = node;
            while (current->leftChild != nullptr) {
                current = current->leftChild;
            }
            return current;
        }

        // Helper balancing function
        Node* balance(Node* node) { // Perform AVL balancing after insertion/deletion
            int balance = getBalance(node);

            // If node not balanced:

            // Left Left Case
            if (balance > 1 && getBalance(node->leftChild) >= 0) {
                return rightRotate(node);
            }

            // Left Right Case
            if (balance > 1 && getBalance(node->leftChild) < 0) {
                node->leftChild = leftRotate(node->leftChild);
                return rightRotate(node);
            }

            // Right Right Case
            if (balance < -1 && getBalance(node->rightChild) <= 0) {
                return leftRotate(node);
            }

            // Right Left Case
            if (balance < -1 && getBalance(node->rightChild) > 0) {
                node->rightChild = rightRotate(node->rightChild);
                return leftRotate(node);
            }

            // Else
            return node;
        }

        // Helper insertion function
        Node* insert(Node* node, int value) { // Insert value into subtree with root N, returns new root of subtree
            // 1. Perform normal BST insertion
            if (node == nullptr) { // Base case: If current node is empty, insert new node here
                return new Node(value);
            }
            if (value < node->value) { // If current node isn't empty, and the value of the node to be inserted is less than the value of the current node, traverse to left subtree
                node->leftChild = insert(node->leftChild, value);
            }
            else if (value > node->value) { // If current node isn't empty, and the value of the node to be inserted is greater than the value of the current node, traverse to right subtree
                node->rightChild = insert(node->rightChild, value);
            }
            else { // Else, if value of node to be inserted is already in tree, don't insert anything, return root of original tree.
                return node;
            }

            // 2. Update height of the inserted node
            updateHeight(node);

            // 3. Return balanced tree
            node = balance(node);
            return node;
            
        }

        // Printer helper functions
        void inOrder(Node *root) { // Print in-order traversal of tree
            if (root != nullptr) {
                inOrder(root->leftChild);
                std::cout << root->value << " ";
                inOrder(root->rightChild);
            }
        }

        void preOrder(Node *root) { // Print pre-order traversal of tree
            if (root != nullptr) {
                std::cout << root->value << " ";
                preOrder(root->leftChild);
                preOrder(root->rightChild);
            }
        }

        void postOrder(Node *root) { // Print post-order traversal of tree
            if (root != nullptr) {
                postOrder(root->leftChild);
                postOrder(root->rightChild);
                std::cout << root->value << " ";
            }
        }

    public:
        Node* root; // Pointer to root node of the AVL tree

        // Constructor
        BinaryTree() {
            root = nullptr;
        }

        // Public insert function
        void insert(int value) {
            root = insert(root, value);
        }

        // Public remove function
        void remove(int value) {
            root = remove(root, value);
        }

        // Public find max function
        int findMax() {
            return maxValueNode(root)->value;
        }

        // Public find min function
        int findMin() {
            return minValueNode(root)->value;
        }

        // Printers
        void inOrder() { // Print in-order traversal of tree
            inOrder(root);
        }

        void preOrder() { // Print pre-order traversal of tree
            preOrder(root);
        }

        void postOrder() { // Print post-order traversal of tree
            postOrder(root);
        }
};

#endif