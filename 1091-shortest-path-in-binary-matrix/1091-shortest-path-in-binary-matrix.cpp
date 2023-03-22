class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1)
            return -1;
        
        if(n == 1)
            return 1;
        
        vector<vector<int>> dis(n,vector<int> (n,1e9));
        queue<vector<int>> q;   // {distance,row,col}
        q.push({0,0,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it[0];
            int r = it[1];
            int c = it[2];
            
            int delRow[8] = {0,0,-1,1,1,1,-1,-1};
            int delCol[8] = {1,-1,0,0,1,-1,-1,1};
            
            for(int i=0;i<8;i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist + 1 < dis[nr][nc])
                {
                    dis[nr][nc] = dist + 1;
                    if(nr == n-1 && nc == n-1)
                        return dist + 1 + 1;
                    q.push({dist+1,nr,nc});
                }
            }
        }
        return -1;
    }
};