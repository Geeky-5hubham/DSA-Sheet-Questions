class Solution {
private:
    bool dfs(int node,int col,vector<int> &color,vector<vector<int>>& graph){
        color[node] = col;
        
       /* queue<pair<int,bool>> q; // {node,color}
        q.push(0,color);
        
        while(!q.empty()){
            
            int node = q.front().first;
            bool color = q.front().second;
            vis[node] = 1;
            q.pop();
            
            
            for(auto it:graph[node]){
                if(!vis[it]){
                    q.push({it,!color});
                }
            }
            */
        
        for(auto it:graph[node]){
            
            if(color[it] == -1){
                if(dfs(it,!col,color,graph) == false)
                    return false;
            }
                
            else if(color[it] == col)
                return false;    
        }
        return true;
    }
    

public:
    // graph is bipartite if we can color adjacent element with different colour and complete graph with only 2 color
    // A linear graph is always bipartite
    // Cyclic graph with even no. of nodes in cycles are bipartite whereas those having odd no of nodes in cycle are not bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n,-1);
       
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph) == false)
                    return false;         
            }     
        }
        
        return true;
        
    }
};