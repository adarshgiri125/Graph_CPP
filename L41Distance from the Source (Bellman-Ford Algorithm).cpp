class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        
        for(int i = 0; i<V-1; i++){
            for(auto j : edges){
                int u = j[0];
                int v = j[1];
                int w = j[2];
                
                if(distance[u] != 1e8 && distance[u] + w < distance[v] ){
                    distance[v] = distance[u] + w;
                }
            }
        }
        
        for(auto j : edges){
                int u = j[0];
                int v = j[1];
                int w = j[2];
                
                if(distance[u] != 1e8 && distance[u] + w < distance[v] ){
                    return {-1};
                }
            }
        
        
        
        return distance;
    }
    
    
    
};