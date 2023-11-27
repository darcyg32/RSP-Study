#include "PriorityQueue.hpp"
#include <iostream>
using namespace std;

int main() {
    PriorityQueue<int> pq;

    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);

    std::cout << "PriorityQueue size: " << pq.size() << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}