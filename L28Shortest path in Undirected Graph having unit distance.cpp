vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
    vector<int> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> distance(N, 1e9);
        queue<int> q;
        q.push(src);
        distance[src] = 0;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
    
            for (auto i : adj[node]) {
                if (distance[node] + 1 < distance[i]) {
                    distance[i] = distance[node] + 1;
                    q.push(i);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (distance[i] == 1e9) {
                distance[i] = -1;
            }
        }
    
        return distance;
    }