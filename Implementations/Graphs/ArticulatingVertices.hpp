#ifndef ARTICULATINGVERTICES_H
#define ARTICULATINGVERTICES_H
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

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
        std::vector<int> entry_time;
        std::vector<int> exit_time;
        int time;

        std::vector<int> reachable_ancestor;
        std::vector<int> tree_out_degree;

        // Helper function to initialize the graph
        void initializeGraph(Graph *g, bool directed) {
            g->edges.resize(MAXV + 1, nullptr);
            g->degree.resize(MAXV + 1, 0);
            g->nVertices = 0;
            g->nEdges = 0;
            g->directed = directed;
            g->processed.resize(MAXV + 1, false);
            g->discovered.resize(MAXV + 1, false);
            g->parent.resize(MAXV + 1, -1);
            g->entry_time.resize(MAXV + 1, 0);
            g->exit_time.resize(MAXV + 1, 0);
            g->reachable_ancestor.resize(MAXV + 1); // Earliest reachable ancestor of v
            g->tree_out_degree.resize(MAXV + 1);    // DFS tree outdegree of v

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
                entry_time[i] = 0;
                exit_time[i] = 0;
            }
        }

        // Helper function for DFS
        void process_vertex_early(int v) {
            //std::cout << "Processing vertex early: " << v << "\n";
            //std::cout << "Vertex: " << v << " Entry time: " << time << "\n";
            reachable_ancestor[v] = v;
        }

        void process_edge(int x, int y) {
            //std::cout << "Processing edge: (" << x << ", " << y << ")\n";
            std::string edgeClass = edge_classification(x, y);

            if (edgeClass == "TREE") {
                tree_out_degree[x] = tree_out_degree[x] + 1;
            }

            if ((edgeClass == "BACK" && parent[x] != y) && (entry_time[y] < entry_time[reachable_ancestor[x]])) {
                reachable_ancestor[x] = y;
            }
            
            
        }

        void process_vertex_late(int v) {
            //std::cout << "Processing vertex late: " << v << "\n";
            //std::cout << "Vertex: " << v << " Exit time: " << time << "\n";
            bool root;          // Is parent[v] the root of the DFS tree?
            int time_v;         // Earliest reachable time for v
            int time_parent;    // EArliest reachable time for parent[v]

            // Test if v is the root
            if (parent[v] == -1) {
                if (tree_out_degree[v] > 1) {
                    std::cout << "Root articulation vertex: " << v << "\n";
                }
                return;
            }

            root = (parent[parent[v]] == -1);   // Is parent[v] the root?

            if (!root) {
                if (reachable_ancestor[v] == parent[v]) {
                    std::cout << "Parent articulation vertex: " << parent[v] << "\n";
                }

                if (reachable_ancestor[v] == v) {
                    std::cout << "Bridge articulation vertex: " << parent[v] << "\n";

                    // If v not a leaf?
                    if (tree_out_degree[v] > 0) {
                        std::cout << "Bridge articulation vertex: " << v << "\n";
                    }
                }
            }

            time_v = entry_time[reachable_ancestor[v]];
            time_parent = entry_time[reachable_ancestor[parent[v]]];

            if (time_v < time_parent) {
                reachable_ancestor[parent[v]] = reachable_ancestor[v];
            }

        }

        std::string edge_classification(int x, int y) {
            if (parent[y] == x) {
                return "TREE";
            }

            if (discovered[y] && !processed[y]) {
                return "BACK";
            }

            if (processed[y] && (entry_time[y] > entry_time[x])) {
                return "FORWARD";
            }

            if (processed[y] && (entry_time[y] < entry_time[x])) {
                return "CROSS";
            }

            std::cout << "Warning: Self Loop (" << x << ", " << y << ")\n";
            return "";
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

        // Function to perform DFS
        void dfs_recursive(Graph *g, int v) {
            if (time > MAXV) {
                return; // Allow for search termination
            }

            discovered[v] = true;
            process_vertex_early(v);
            time++;
            entry_time[v] = time;

            EdgeNode* p = g->edges[v];
            while (p != nullptr) {
                int y = p->y;

                if (!discovered[y]) {
                    parent[y] = v;
                    process_edge(v, y);
                    dfs_recursive(g, y);
                } else if ((!processed[y] && parent[v] != y) || g->directed) {
                    process_edge(v, y);
                }

                if (time > MAXV) {
                    return;
                }

                p = p->next;
            }

            time++;
            exit_time[v] = time;
            processed[v] = true;
            process_vertex_late(v);
        }

        void dfs(Graph* g, int startVertex) {
            initialize_search(g);
            dfs_recursive(g, startVertex);
        }

        void find_path(int start, int end) {
            if (start == end || end == -1) {
                std::cout << start;
            } else {
                find_path(start, parent[end]);
                std::cout << " -> " << end;
            }
        }
};

#endif