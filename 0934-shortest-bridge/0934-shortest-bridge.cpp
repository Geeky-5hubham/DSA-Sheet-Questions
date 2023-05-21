class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,int &c){
        int row = i;
        int col = j;
        
        vis[row][col] = c;
        
        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};
        
        for(int k=0;k<4;k++){
            int nrow = row + delRow[k];
            int ncol = col + delCol[k];
            
            
            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid.size() && vis[nrow][ncol] == 0
                && grid[nrow][ncol] == 1){
                
                
                dfs(nrow,ncol,grid,vis,c);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        int c = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    c++;
                    
                    dfs(i,j,grid,vis,c);
                    
                    
                }
            }
        }
        
        vector<pair<int,int>> ones,twos;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == 1)
                    ones.push_back({i,j});
                
                else if(vis[i][j] == 2)
                    twos.push_back({i,j});
            }
        }
        
        int ans = 1e9;
        
        for(auto it:ones){
            int r = it.first;
            int c = it.second;
            
            for(auto x:twos){
                int r2 = x.first;
                int c2 = x.second;
                
                int d = abs(r2-r) + abs(c2-c) - 1;
                
                ans = min(ans,d);
            }
        }

        return ans;
    }
};