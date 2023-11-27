#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Pushing elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);

    // Displaying the elements in the queue
    std::cout << "Elements in the queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << "\n";

    // Adding more elements
    myQueue.push(50);
    myQueue.push(60);

    // Displaying the front and back elements in the queue
    std::cout << "Front element in the queue: " << myQueue.front() << "\n";
    std::cout << "Back element in the queue: " << myQueue.back() << "\n";

    // Displaying the size of the queue
    std::cout << "Size of the queue: " << myQueue.size() << "\n";

    return 0;
}
