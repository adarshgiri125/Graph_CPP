 int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        queue<pair<int,int> > pq;
        vector<int> steps(100000, 1e9);
        
        pq.push({start,0});
        steps[start] = 0;
        
        while(!pq.empty()){
            
           int node =  pq.front().first;
           int step = pq.front().second;
           pq.pop();
           
           
           
           for(int i = 0; i<n; i++){
            int newnode = (node * arr[i]) % 100000;
                if(step + 1 < steps[newnode]){
                    steps[newnode] = step + 1;
                    if(newnode == end)
                    return step + 1;
                
                    pq.push({newnode,step + 1});
                }
                
            
          } 
        }
        if(start == end){
            return 0;
        }
        return -1;
        
    }