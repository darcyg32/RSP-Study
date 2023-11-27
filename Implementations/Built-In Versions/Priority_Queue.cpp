#include <iostream>
#include <queue>

int main() {
    // Create a priority queue of integers
    std::priority_queue<int> pq;

    // Push elements onto the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    std::cout << "Priority Queue elements: ";
    while (!pq.empty()) {
        // Print the top element
        std::cout << pq.top() << " ";

        // Pop the top element
        pq.pop();
    }

    std::cout << "\n";

    return 0;
}
