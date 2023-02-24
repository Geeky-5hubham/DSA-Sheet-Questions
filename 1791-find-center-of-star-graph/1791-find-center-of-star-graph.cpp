class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+2];
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=1;i<=n+1;i++){
            vector<int> temp = adj[i];
            if(temp.size() == n)
                return i;
        }
        return -1;
    }
};