#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

int main() {
    BinaryTree<int> tree;

    // Insert some values into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Find Min: " << tree.findMin() << "\n";
    
    cout << "Find Max: " << tree.findMax() << "\n";

    // Perform in-order traversal
    cout << "In-order traversal: ";
    tree.inOrder();

    // Perform pre-order traversal
    cout << "Pre-order traversal: ";
    tree.preOrder();

    // Perform post-order traversal
    cout << "Post-order traversal: ";
    tree.postOrder();

}