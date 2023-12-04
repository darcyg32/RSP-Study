#include "DFSDirected.hpp"
#include <iostream>

int main() {
    Graph myGraph(true);
    myGraph.readGraph(&myGraph, true, "DFSDirectedInput.txt");

    myGraph.topsort(&myGraph);
}