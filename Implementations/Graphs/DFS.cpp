#include "DFS.hpp"
#include <iostream>

int main() {
    Graph myGraph(false);
    myGraph.readGraph(&myGraph, false, "DFSGraphInput.txt");

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Graph Details:\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    myGraph.printGraph(&myGraph);

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Cycles in Graph:\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    // DFS to find cycles
    myGraph.dfs(&myGraph, 1);
}