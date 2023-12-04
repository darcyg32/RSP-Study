#include "ArticulatingVertices.hpp"
#include <iostream>

int main() {
    Graph myGraph(false);
    myGraph.readGraph(&myGraph, false, "DFSGraphInput.txt");

    myGraph.dfs(&myGraph, 1);
}