#include "BFSBipartite.hpp"
#include <iostream>

int main() {
    Graph myGraph(false);
    myGraph.readGraph(&myGraph, false, "BipartiteGraphInput.txt");
    myGraph.printGraph(&myGraph);

    if (myGraph.isBipartite(&myGraph)) {
        std::cout << "The graph is bipartite!\n";
    } else {
        std::cout << "The graph is not bipartite.\n";
    }
}