class Solution {
private:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &map,vector<int> &ds,int n){
        
        // Base Case
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(map[i] == 0){
                map[i] = 1;
                ds.push_back(nums[i]);
                solve(nums,ans,map,ds,n);
                ds.pop_back();
                map[i] = 0;
            }
        }
            
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        vector<int> ds;
        vector<int> map(n,0);
        solve(nums,ans,map,ds,n);
        
        return ans;
        
    }
};