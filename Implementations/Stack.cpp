#include "Stack.hpp"
#include <iostream>
using namespace std;

int main() {
    
    Stack<int> stack;

    stack.push(73);
    stack.push(3);
    stack.push(7);
    stack.push(713);
    stack.push(15);

    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }

    // Test peeking an empty stack
    cout << stack.peek() << " ";
    cout << "\n";

    return 0;
}