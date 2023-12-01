#include "BFSShortestPath.hpp"
#include <iostream>

int main() {

    Graph myGraph(false);
    myGraph.readGraph(&myGraph, false, "SPGraphInput.txt");

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i != j) {
                std::cout << "Shortest path from " << i << " to " << j << ": ";
                myGraph.findPath(&myGraph, i, j);
                std::cout << "\n";
            }
        }
        std::cout << "\n";
    }
    
    return 0;
}