class Solution {
private:
   void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
      // mark it visited
      vis[row][col] = 1; 
      queue<pair<int,int>> q;
      // push the node in queue
      q.push({row, col}); 
      int n = grid.size(); 
      int m = grid[0].size(); 
      
      // until the queue becomes empty
      while(!q.empty()) {
          int row = q.front().first; 
          int col = q.front().second; 
          q.pop(); 
          
          // traverse in the neighbours and mark them if its a land 
          for(int i=-1;i<=1;i++)
          {
              int newr = row+i;
              int newc = col+i;
              
              // New row is inside the grid & is not visited & is Land
              if(newr>=0 && newr<n && !vis[newr][col] && grid[newr][col]=='1')
              {
                  vis[newr][col] =true;
                  q.push({newr,col});
              }
              //  New col is inside the grid & is not visited & is Land
               if(newc>=0 && newc<m && !vis[row][newc] && grid[row][newc]=='1')
              {
                  vis[row][newc] =true;
                  q.push({row,newc});
              }
          }
      }
  }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0)) ;    //visitedMatrix;
        
        int cnt = 0;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};