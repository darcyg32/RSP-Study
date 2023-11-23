#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

int main() {
    BinaryTree tree;

    // Insert some values into the tree
    tree.insert(8);
    tree.insert(1);
    tree.insert(84);
    tree.insert(115);
    tree.insert(45);
    tree.insert(3);
    tree.insert(12);
    tree.insert(88);
    tree.insert(11);
    tree.insert(17);
    tree.insert(19);

    // Delete some values
    tree.remove(12);
    tree.remove(19);

    cout << "Find Min: " << tree.findMin() << "\n";
    
    cout << "Find Max: " << tree.findMax() << "\n";

    // Perform in-order traversal
    cout << "In-order traversal: ";
    tree.inOrder();
    cout << "\n";

    // Perform pre-order traversal
    cout << "Pre-order traversal: ";
    tree.preOrder();
    cout << "\n";

    // Perform post-order traversal
    cout << "Post-order traversal: ";
    tree.postOrder();
    cout << "\n";

}