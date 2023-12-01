#include "ConnectedComponents.hpp"
#include <iostream>

int main() {
    Graph myGraph(false);

    myGraph.readGraph(&myGraph, false, "CCGraphInput.txt");
    myGraph.printGraph(&myGraph);
    std::cout << "\n";
    myGraph.connectedComponents(&myGraph);

    return 0;
}