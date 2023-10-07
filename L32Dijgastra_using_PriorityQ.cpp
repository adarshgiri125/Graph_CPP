    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
        vector<int> distance(V);
        for(int i = 0; i<V; i++) distance[i] = 1e9;
        
        distance[s] = 0;
        pq.push({s,0});
        
        while(!pq.empty()){
            int node = pq.top().first;
            int d = pq.top().second;
            pq.pop();
            
            for(auto i : adj[node]){
                int adjWeight = i[1];
                int adjnode = i[0];
                 if( d  + adjWeight < distance[adjnode]){
                    distance[adjnode] = d + adjWeight;
                    pq.push({adjnode,distance[adjnode]});
                }
            }
        }
        
        return distance;
        
        
    }