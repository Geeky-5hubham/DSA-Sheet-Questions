class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // We will use BFS as it travel all direction at same speed(level wise)
        queue<vector<int> > q; // {row,col,time}
        int vis[n][m];
        
        int cntfresh = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    vis[i][j] = 2;
                }
                else
                    vis[i][j] = 0;
                
                if(grid[i][j] == 1)
                    cntfresh++;
            }
        }
        
        int time = 0;
        int cnt = 0;
        
        while(!q.empty()){
            int row = q.front()[0];
            int col = q.front()[1];
            int t = q.front()[2];
            
            time = t;
            q.pop();
            
            int delRow[] = {-1,+1,0,0};
            int delCol[] = {0,0,-1,+1};
            
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m  
                  && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({nrow,ncol,t+1});
                    cnt++;
                }
            }
            
        }
        
        if(cnt != cntfresh)
            return -1;
        
        return time;
            
    }
};