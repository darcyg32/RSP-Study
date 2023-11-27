#include <iostream>
#include <stack>

int main() {
    // Creating a stack of integers
    std::stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Displaying the top element of the stack
    std::cout << "Top element of the stack: " << myStack.top() << std::endl;

    // Displaying the size of the stack
    std::cout << "Size of the stack: " << myStack.size() << std::endl;

    // Popping elements from the stack
    std::cout << "Popping elements from the stack:" << std::endl;
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // Check if the stack is empty after popping
    if (myStack.empty()) {
        std::cout << "The stack is empty." << std::endl;
    } else {
        std::cout << "The stack is not empty." << std::endl;
    }

    return 0;
}