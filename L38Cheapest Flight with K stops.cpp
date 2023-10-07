
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
          
          vector<pair<int,int> > adj[n];
          
          for(auto i : flights){
              adj[i[0]].push_back({i[1],i[2]});
              
          }
          
          
          queue<pair<pair<int,int>,int> >pq;
          vector<int> distance(n,INT_MAX);
          
          pq.push({{src,0},0});
          distance[src] = 0;
          int ans = INT_MAX;
          while(!pq.empty()){
              int node = pq.front().first.first;
              int dist = pq.front().first.second;
              int value = pq.front().second;
              
              pq.pop();
            
              
              if (value > K) continue;
              for(auto i : adj[node]){
                  int adjnode = i.first;
                  int adjdistance = i.second;
                  
                  if(adjdistance + dist < distance[adjnode] && value <= K ){
                      distance[adjnode] = adjdistance + dist;
                      pq.push({{adjnode,distance[adjnode]},value+1});
                  }
              
               }
              
          }
          if(distance[dst] == INT_MAX){
              return -1;
          }
          return distance[dst];
    }