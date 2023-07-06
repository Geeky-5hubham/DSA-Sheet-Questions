class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,int sRow,int sCol,int c,int cnt){
        
        if(i < 0 || j < 0  || i >= grid.size() || j >= grid[0].size())
            return 0;
        
        if(grid[i][j] == -1)
            return 0;
        
        if(i == sRow && j == sCol){
            cnt--;
            if(c == cnt)    return 1;
            else return 0;
        }
        
        
        grid[i][j] = -1;
        
        int left = f(i,j-1,grid,sRow,sCol,c,cnt+1);
        int right = f(i,j+1,grid,sRow,sCol,c,cnt+1);
        int up = f(i-1,j,grid,sRow,sCol,c,cnt+1);
        int down = f(i+1,j,grid,sRow,sCol,c,cnt+1);
        
        grid[i][j] = 0;
        
        return left+right+down+up;
        
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,-2));
        
        int sRow,sCol,eRow,eCol;
        
        int c = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] == 1){
                    sRow = i;
                    sCol = j;
                }
                
                if(grid[i][j] == 2){
                    eRow = i;
                    eCol = j;
                }
                
                if(grid[i][j] == 0){
                    c++;
                }
            }
        }
        
        
        return f(eRow,eCol,grid,sRow,sCol,c,0);
    }
};