class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        // Chheck for top right left down
        int delRow[] = {0,0,-1,+1};
        int delCol[] = {-1,+1,0,0};
        
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
              && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,board);
            }
        }
             
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // Traversing first and last row
        for(int j=0;j<m;j++){
            
            // first row
            if(vis[0][j] == 0 && board[0][j] == 'O'){
                dfs(0,j,vis,board);
            }
            
            // last row
            if(vis[n-1][j] == 0 && board[n-1][j] == 'O'){
                dfs(n-1,j,vis,board);
            }
        }
        
        // Traversing first and last column
        for(int i=0;i<n;i++){
            
            // first row
            if(vis[i][0] == 0 && board[i][0] == 'O'){
                dfs(i,0,vis,board);
            }
            
            // last row
            if(vis[i][m-1] == 0 && board[i][m-1] == 'O'){
                dfs(i,m-1,vis,board);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};