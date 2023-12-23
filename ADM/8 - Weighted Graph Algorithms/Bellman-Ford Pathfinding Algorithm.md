#Chapter_8 
- An algorithm that computes [[8.3 - Shortest Paths|shortest paths]] from a single source vertex to all other vertices in a weighted directed graph.
- It is slower than Dijkstra's algorithm for the same problem, but more versatile, as it is capable of handling graphs in which some of the edge weights are negative numbers.

- Like Dijkstra's algorithm, Bellman-Ford proceeds by *relaxation*, in which approximations to the correct distance are replaced by better ones until they eventually reach the solution.
	- In both algorithms, the approximate distance to each vertex is always an overestimate to the true distance, and is replaced by the minimum of its old value and the length of a newly found path.

- While Dijkstra's algorithm uses a priority queue to greedily select the closest unprocessed vertex, and performs this this relaxation process on all of its outgoing edges, the Bellman-Ford algorithm simply relaxes *all* the edges, and does this $V-1$ times, where $V$ is the number of vertices in the graph.
	- In each of these repetitions, the number of vertices with correctly calculated distances grows, from which it follows that eventually all vertices will have their correct distances.



- Simply put, the algorithm initializes the distance to the source to 0 and all other nodes to infinity.
	- Then, for all edges, if the distance to the destination can be shorted by taking the edge, the distance is updated to the new lower value.

- The core of the algorithm is a loop that scans across all edges at every loop.
	- For every $i\leq V-1$, at the end of the $i$-th iteration, from any vertex *v*, following the predecessor trail recorded in *predecessor* yields a path that has a total weight that is at most $distance[v]$.
		- $distance[v]$ is a lower bound to the length of any path from source to *v* that uses at most *i* edges.

- Since the longest possible path without a cycle can be $V-1$ edges, the edges must be scanned $V-1$ times to ensure the shortest path has been found for all nodes.
	- A final scan of all the edges is performed, any if any distance is updated, then a path of length $V$ edges has been found which can only occur if at least one negative cycle exists in the path.

- The edge *(u, v)* that is found in step 3 must be reachable from a negative cycle, but it isn't necessarily part of the cycle itself, which is why it's necessary to follow the path of predecessors backwards until a cycle is detected.
	- The above pseudocode uses a boolean array `visited` to find a vertex on the cycle, but any *cycle finding* algorithm can be used to find a vertex on the cycle, such as [[7.8 - Depth-First Search|DFS]].

**Pseudocode:**
```
function BellmanFord(list vertices, list edges, vertex source) is
    // This implementation takes in a graph, represented as
    // lists of vertices (represented as integers [0..n-1]) and edges,
    // and fills two arrays (distance and predecessor) holding
    // the shortest path from the source to each vertex

    distance := list of size n
    predecessor := list of size n

    // Step 1: initialize graph
    for each vertex v in vertices do
        // Initialize the distance to all vertices to infinity
        distance[v] := inf
        // And having a null predecessor
        predecessor[v] := null

    // The distance from the source to itself is, of course, zero
    distance[source] := 0

    // Step 2: relax edges repeatedly
    repeat |V|−1 times:
        for each edge (u, v) with weight w in edges do
            if distance[u] + w < distance[v] then
                distance[v] := distance[u] + w
                predecessor[v] := u

    // Step 3: check for negative-weight cycles
    for each edge (u, v) with weight w in edges do
        if distance[u] + w < distance[v] then
            predecessor[v] := u
            // A negative cycle exists; find a vertex on the cycle
            visited := list of size n initialized with false
            visited[v] := true
            while not visited[u] do
                visited[u] := true
                u := predecessor[u]
            // u is a vertex in a negative cycle, find the cycle itself
            ncycle := [u]
            v := predecessor[u]
            while v != u do
                ncycle := concatenate([v], ncycle)
                v := predecessor[v]
            error "Graph contains a negative-weight cycle", ncycle

    return distance, predecessor

```

**C++:**
```C++
pair<vector<int>, vector<int>> bellmanFord(int n, const vector<Edge>& edges, int source) {
    vector<int> distance(n, inf);
    vector<int> predecessor(n, -1);

    // Step 1: initialize graph
    for (int v = 0; v < n; ++v) {
        distance[v] = inf;
        predecessor[v] = -1;
    }

    // The distance from the source to itself is zero
    distance[source] = 0;

    // Step 2: relax edges repeatedly
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (distance[u] != inf && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                predecessor[v] = u;
            }
        }
    }

    // Step 3: check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (distance[u] != inf && distance[u] + w < distance[v]) {
            // A negative cycle exists; find a vertex on the cycle
            vector<bool> visited(n, false);
            visited[v] = true;
            while (!visited[u]) {
                visited[u] = true;
                u = predecessor[u];
            }

            // u is a vertex in a negative cycle, find the cycle itself
            vector<int> ncycle = {u};
            v = predecessor[u];
            while (v != u) {
                ncycle.push_back(v);
                v = predecessor[v];
            }

            cout << "Graph contains a negative-weight cycle. Cycle vertices: ";
            for (int vertex : ncycle) {
                cout << vertex << " ";
            }
            cout << endl;

            // Returning an empty vector as an indication of a negative cycle
            return make_pair(vector<int>(), vector<int>());
        }
    }

    return make_pair(distance, predecessor);
}
```

- Bellman-Ford runs in $O(V*E)$ time.