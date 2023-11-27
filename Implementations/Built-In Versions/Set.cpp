#include <iostream>
#include <set>

int main() {
    std::set<int> binaryTree;

    // Insert elements into the binary tree
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(70);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(60);
    binaryTree.insert(80);

    // Print the elements of the binary tree
    std::cout << "Binary Tree elements:";
    for (const auto &element : binaryTree) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    // Check if an element is present in the binary tree
    int searchElement = 40;
    auto searchResult = binaryTree.find(searchElement);
    if (searchResult != binaryTree.end()) {
        std::cout << searchElement << " is present in the binary tree." << std::endl;
    } else {
        std::cout << searchElement << " is not present in the binary tree." << std::endl;
    }

    // Erase an element from the binary tree
    int eraseElement = 30;
    binaryTree.erase(eraseElement);

    // Print the elements of the modified binary tree
    std::cout << "Modified Binary Tree elements:";
    for (const auto &element : binaryTree) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    // Get the size of the binary tree
    std::cout << "Size of the binary tree: " << binaryTree.size() << std::endl;

    // Check if the binary tree is empty
    std::cout << "Is the binary tree empty? " << (binaryTree.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
