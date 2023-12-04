#include "BFSShortestPath.hpp"
#include <iostream>

int main() {

    Graph myGraph(true);
    myGraph.readGraph(&myGraph, true, "BFSShortestPathGraphInput.txt");
    myGraph.printGraph(&myGraph);

    /*
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (i != j) {
                std::cout << "Shortest path from " << i << " to " << j << ": ";
                myGraph.findPath(&myGraph, i, j);
                std::cout << "\n";
            }
        }
        std::cout << "\n";
    }
    */
    
    return 0;
}