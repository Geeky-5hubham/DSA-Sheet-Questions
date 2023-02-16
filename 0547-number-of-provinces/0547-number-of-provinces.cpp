class Solution {
public:
    void dfs(int node,vector<int> adjLs[],vector<int> &vis,vector<int> &ans){
        
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it:adjLs[node]){
            if(vis[it] != 1)
                dfs(it,adjLs,vis,ans);
        }   
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();     // No of nodes
        vector<int> adjLs[n];    // Adjacency list
        
        // Converting adjacency matrix to adjacency list
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    //adjLs[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);   // Visited array
        vector<int> temp ;  // To Store the dfs Not needed for this question
        int cnt = 0;    // ans
        
        for(int i=0;i<n;i++){
            if(vis[i] == 0){   // No of times this will be executed are the number of isolated nodes(i.e., which are connected component of graph)
                cnt++;
                dfs(i,adjLs,vis,temp);
                
            }
        }
        
        return cnt;
    }
};