class Solution {
public:
    vector<int> DJ(int src,vector<vector<int>>& edges,int n){
        // Constructing adjacency list
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            
                adj[it[0]].push_back({it[1],it[2]});
                adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        vector<int> dis(n,1e9);
        dis[src] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // {dist,node}
        pq.push({0,src});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            
            for(auto i:adj[node]){
                int adjNode = i.first;
                int edgeW = i.second;
                
                if(dist + edgeW < dis[adjNode]){
                    dis[adjNode] = dist + edgeW;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }
        return dis;
        
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance;
        
        for(int src=0;src<n;src++){
            vector<int> dis = DJ(src,edges,n);
            distance.push_back(dis);
            dis.clear();
        }
        
        int count = n;
        int ans = -1;
        
        for(int i=0;i<n;i++){
            int c = 0;
            for(int j=0;j<n;j++){
                if(distance[i][j] <= distanceThreshold){
                    c++;
                }
            }
            
            if(c <= count){
                count = c;
                ans = i;
            }
        }
        return ans;
    }
};