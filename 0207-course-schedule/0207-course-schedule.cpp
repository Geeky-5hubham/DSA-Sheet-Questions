class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &path_vis,vector<vector<int>> &adj){
        vis[node] = 1;
        path_vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,path_vis,adj) == true){
                    return true;
                }
            }
            
            //if the node has been previously visited and on the same path
            else if(path_vis[it] == 1){
                return true;
            }
        }
        
        path_vis[node] = 0;
        return false;
        
    }
    

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        vector<vector<int>> adj(n);
        
        for(auto it:prerequisites){
            int u = it[0]; // course u is dependent on course v
            int v = it[1]; // course v should be completed before taking course u
        
            adj[v].push_back(u);
        }
        
        vector<int> vis(n,0),path_vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,path_vis,adj) == true)
                    return false;
            }
        }
        
        return true;
    }
};