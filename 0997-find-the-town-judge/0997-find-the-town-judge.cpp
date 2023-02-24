class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n+1];
        
        for(auto it:trust){
            adj[it[0]].push_back(it[1]);
        }
        int x = 0;
        
        for(int i=1;i<=n;i++){
            vector<int> temp = adj[i];
            if(temp.size() == 0 )
                x = i;
        }
        
        if(x != 0){
           vector<int> inDegree(n+1,0);
            
           for(auto it:adj){
               for(auto x:it){
                   inDegree[x]++;
               }
           }
            
           if(inDegree[x] == n-1)
               return x;
            return -1;
        }
        
        else
            return -1;
        
    }
};