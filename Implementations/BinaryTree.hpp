#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>


// Can add searching, deletion/balancing
template <typename T>
class BinaryTree {
    private:
        class Node {
            public:
                T item;
                Node* parent;
                Node* left;
                Node* right;

                // Constructor
                Node(T x) : item(x), parent(nullptr), left(nullptr), right(nullptr) {}
        };

        Node* root;

        // Helper function for insertion
        Node* insert(Node* currNode, T x) {
            if (currNode == nullptr) {
                return new Node(x);
            }

            if (x < currNode->item) {
                currNode->left = insert(currNode->left, x);
            } else if (x > currNode->item) {
                currNode->right = insert(currNode->right, x);
            }

            return currNode;
        }

        // Helper function for In-order Traversal
        void inOrder(const Node* currNode) const {
            if (currNode != nullptr) {
                inOrder(currNode->left);
                std::cout << currNode->item << " ";
                inOrder(currNode->right);
            }
        }

        // Helper function for Pre-order Traversal
        void preOrder(const Node* currNode) const {
            if (currNode != nullptr) {
                std::cout << currNode->item << " ";
                preOrder(currNode->left);
                preOrder(currNode->right);
            }
        }

        // Helper function for Post-order Traversal
        void postOrder(const Node* currNode) const {
            if (currNode != nullptr) {
                postOrder(currNode->left);
                postOrder(currNode->right);
                std::cout << currNode->item << " ";
            }
        }

        // Helper function to delete all nodes
        void destroyTree(Node* currNode) {
            if (currNode != nullptr) {
                destroyTree(currNode->left);
                destroyTree(currNode->right);
                delete currNode;
            }
        }

    public:
        // Contructor
        BinaryTree() : root(nullptr) {}

        // Destructor
        ~BinaryTree() {
            destroyTree(root);
        }

        // Function to insert a value
        void insert(T x) {
            root = insert(root, x);
        }

        // Function to find the min value
        T findMin() {
            Node* min = root;

            if (root == nullptr) {
                std::cout << "Error: Tree is Empty.\n";
                return -1;
            }

            while (min->left != nullptr) {
                min = min->left;
            }

            return min->item;
        }

        // Function to find the max value
        T findMax() {
            Node* max = root;

            if (root == nullptr) {
                std::cout << "Error: Tree is Empty.\n";
                return -1;
            }

            while (max->right != nullptr) {
                max = max->right;
            }

            return max->item;
        }

        // In-order Traversal
        void inOrder() const {
            inOrder(root);
            std::cout << "\n";
        }

        // Pre-order Traversal
        void preOrder() const {
            preOrder(root);
            std::cout << "\n";
        }

        // Post-order Traversal
        void postOrder() const {
            postOrder(root);
            std::cout << "\n";
        }

};

#endif