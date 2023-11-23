#include "LinkedList.hpp"
#include <iostream>
using namespace std;

int main() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    // Create an instance of the Linked List
    LinkedList<int> LL;

    // Add some items
    LL.insert(5);
    LL.insert(8);
    LL.insert(88);
    LL.insert(2);
    LL.insert(1);
    cout << "\n";

    // Search for an element that exists
    LL.search(2);
    cout << "\n";

    // Search for an element that doesn't exist
    LL.search(10);
    cout << "\n";

    // Print List
    LL.printList();
    cout << "\n";

    // Delete a node at head
    LL.deleteNode(1);
    cout << "\n";

    // Delete a different node
    LL.deleteNode(88);
    cout << "\n";

    // Delete a node that doesn't exist
    LL.deleteNode(1);
    cout << "\n";

    // Print List
    LL.printList();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    return 0;
}