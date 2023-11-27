#include <iostream>
#include <list>     // Doubly linked list template, provides constant time insertions and removals from both beginning and end, and linear time operations in the middle.
#include <algorithm>

int main() {
    // Create an empty list of integers
    std::list<int> myList;

    // Push elements to the back of the list using push_back
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Push elements to the front of the list using push_front
    myList.push_front(5);
    myList.push_front(15);

    // Print the elements of the list using an iterator
    std::cout << "Elements of the list: ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Access the first and last element using front() and back()
    std::cout << "First element: " << myList.front() << std::endl;
    std::cout << "Last element: " << myList.back() << std::endl;

    // Insert an element at a specific position using insert()
    auto it = std::find(myList.begin(), myList.end(), 20);
    if (it != myList.end()) {
        myList.insert(it, 25);
    }

    // Remove an element at a specific position using erase()
    it = std::find(myList.begin(), myList.end(), 15);
    if (it != myList.end()) {
        myList.erase(it);
    }

    // Remove elements from the back using pop_back
    myList.pop_back();

    // Remove elements from the front using pop_front
    myList.pop_front();

    // Print the updated elements of the list
    std::cout << "Updated elements of the list: ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Check if the list is empty using empty()
    if (myList.empty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }

    // Get the size of the list using size()
    std::cout << "Size of the list: " << myList.size() << std::endl;

    // Clear all elements from the list using clear()
    myList.clear();

    // Check if the list is empty after clearing
    if (myList.empty()) {
        std::cout << "The list is empty after clearing." << std::endl;
    } else {
        std::cout << "The list is not empty after clearing." << std::endl;
    }

    return 0;
}