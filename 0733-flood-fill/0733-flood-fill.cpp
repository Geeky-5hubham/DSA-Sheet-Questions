class Solution {
private:
    void dfs(int row,int col,int iniColor,int color,vector<vector<int>> &ans,vector<vector<int>>& image){
        
        int n = image.size();
        int m = image[0].size();
        
        ans[row][col] = color;  // Assigned new color
        
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,-1,0,+1};
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i]; // neighbour row
            int ncol = col + delcol[i];
            
            
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m 
               && ans[nrow][ncol] != color && ans[nrow][ncol] == iniColor){
                dfs(nrow,ncol,iniColor,color,ans,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];   // Initial color
        
        int row = sr;
        int col = sc;
        
        dfs(row,col,iniColor,color,ans,image);
        
        return ans;
    }
};