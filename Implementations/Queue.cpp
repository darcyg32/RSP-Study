#include "Queue.hpp"
#include <iostream>
using namespace std;
int main() {
    // Testing the queue
    Queue<int> myQueue;

    myQueue.enqueue(73);
    myQueue.enqueue(3);
    myQueue.enqueue(7);
    myQueue.enqueue(713);
    myQueue.enqueue(15);

    while (!myQueue.isEmpty()) {
        cout << myQueue.peek() << " ";
        myQueue.dequeue();
    }

    // Test peeking an empty stack
    cout << myQueue.peek() << " ";
    cout << "\n";

    return 0;
}