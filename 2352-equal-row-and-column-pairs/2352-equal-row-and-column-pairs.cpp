class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        
        map<vector<int>,int> mp;
        
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
            mp[temp]++;
        }
        
        int ans = 0;
        
        for(int j=0;j<n;j++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                temp.push_back(grid[i][j]);
            }
            
            if(mp[temp])
                ans += mp[temp];
        }
        
        return ans;
    }
};