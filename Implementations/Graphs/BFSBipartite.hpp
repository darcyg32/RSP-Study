#ifndef BFSBIPARTITE_H
#define BFSBIPARTITE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

#define MAXV 100

// Structure for the edge node
struct EdgeNode {
    int y;          // Adjacency Info
    int weight;     // Edge weight, if any
    EdgeNode* next; // Next edge in the list
};

// Structure for the graph
struct Graph {
    private:
        std::vector<EdgeNode*> edges;   // Adjacency Info
        std::vector<int> degree;        // Outdegree of each vertex
        int nVertices;                  // Number of vertices in the graph
        int nEdges;                     // Number of edges in the graph
        bool directed;                  // Is the graph directed?

        std::vector<bool> processed;
        std::vector<bool> discovered;
        std::vector<int> parent;
        int time;

        // Helper function to initialize the graph
        void initializeGraph(Graph* g, bool directed) {
            g->nVertices = 0;
            g->nEdges = 0;
            g->directed = directed;
            g->processed.resize(MAXV + 1, false);
            g->discovered.resize(MAXV + 1, false);
            g->parent.resize(MAXV + 1, -1);

            // Initialize degree and edges arrays
            for (int i = 1; i <= MAXV; i++) {
                g->degree[i] = 0;
                g->edges[i] = nullptr;
            }
        }

        // Helper function to insert an edge into the graph
        void insertEdge(Graph* g, int x, int y, bool directed) {
            // Allocate edge node storage
            EdgeNode* p = new EdgeNode();

            // Initialize edge node
            p->weight = 0;
            p->y = y;
            p->next = g->edges[x];

            // Insert the forward edge at the head of the list
            g->edges[x] = p;
            g->degree[x]++;

            if (!directed) {
                insertEdge(g, y, x, true);
            } else {
                // Increment the total number of edges
                g->nEdges++;
            }
            
        }

        void initialize_search(Graph* g) {
            time = 0;
            for (int i = 0; i <= g->nVertices; i++) {
                processed[i] = false;
                discovered[i] = false;
                parent[i] = -1;
            }
        }

    public:
        // Constructor
        Graph(bool isDirected) {
            nVertices = 0;
            nEdges = 0;
            directed = isDirected;
            edges.resize(MAXV + 1, nullptr);
            degree.resize(MAXV + 1, 0);
        }

        // Function to print the graph
        void printGraph(Graph *g) {
            EdgeNode* p;

            // Iterate through each vertex and print its adjacency list
            for (int i = 1; i <= g->nVertices; i++) {
                std::cout << i << ": ";
                p = g->edges[i];
                while (p != nullptr) {
                    std::cout << " " << p->y;
                    p = p->next;
                }
                std::cout << "\n";
            }
        }

        // Function to read the graph from input (Prone to error)
        void readGraph(Graph* g, bool directed, const std::string& filePath) {
            // Read graph information from a file
            std::ifstream inputFile(filePath);
            if (!inputFile.is_open()) {
                std::cerr << "Error opening file: " << filePath << "\n";
                return;
            }

            int m;      // Number of edges
            int x, y;   // Vertices in edge (x, y)
            
            initializeGraph(g, directed);

            // Read the number of vertices and edges from the file
            inputFile >> g->nVertices >> m;

            // Read each edge from the file and insert it into the graph
            for (int i = 1; i <= m; i++) {
                inputFile >> x >> y;
                insertEdge(g, x, y, directed);
            }

            inputFile.close();
        }

        bool isBipartite(Graph *g) {
            initialize_search(g);

            std::queue<int> q;
            int v, y;
            EdgeNode* p;

            // Initialize colour array (-1: not coloured, 0: colour 0, 1: colour 1)
            std::vector<int> colour(g->nVertices + 1, -1);

            for (int i = 1; i <= g->nVertices; i++) {
                if (!discovered[i]) {
                    q.push(i);
                    discovered[i] = true;
                    colour[i] = 0;

                    while (!q.empty()) {
                        // Dequeue a vertex from the front of the queue
                        v = q.front();
                        q.pop();

                        // Mark the current vertex as processed
                        processed[v] = true;

                        // Get the adjacency list of the current vertex
                        p = g->edges[v];

                        // Explore each neighbor of the current vertex
                        while (p != nullptr) {
                            // Get the neighbor vertex
                            y = p->y;

                            // Process the edge connecting the current vertex to its neighbor
                            if (!processed[y] || g->directed) {
                                if (!discovered[y]) {
                                    // Enqueue the neighbor vertex for further exploration
                                    q.push(y);

                                    // Mark the neighbor vertex as discovered
                                    discovered[y] = true;

                                    // Set the parent of the neighbor vertex to the current vertex
                                    parent[y] = v;

                                    // Assign the opposite colour to the neighbour
                                    colour[y] = 1 - colour[v];
                                } else if (colour[v] == colour[y]) {
                                    return false;
                                }
                            }

                            // Move to the next neighbor in the adjacency list
                            p = p->next;
                        }
                    }
                }
            }

            return true;
        }
};

#endif