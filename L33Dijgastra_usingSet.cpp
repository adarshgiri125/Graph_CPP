vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        set<pair<int,int> >st;
        vector<int> distance(V);
        for(int i = 0; i<V; i++) distance[i] = 1e9;
        
        distance[s] = 0;
        st.insert({0,s});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int weight = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto i : adj[node]){
                int adjWeight = i[1];
                int adjnode = i[0];
                 if( weight  + adjWeight < distance[adjnode]){
                     
                     if(distance[adjnode] != 1e9){
                         st.erase({distance[adjnode],adjnode});
                     }
                     
                    distance[adjnode] = weight + adjWeight;
                    st.insert({distance[adjnode],adjnode});
                }
            }
        }
        
        return distance;
        
        
    }