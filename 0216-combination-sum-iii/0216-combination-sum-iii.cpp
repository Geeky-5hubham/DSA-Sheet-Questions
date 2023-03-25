class Solution {
public:
    void solve(int index,int target,vector<int>& candidates,vector<int> &ds,vector<vector<int>> &ans,int k){
        int n = candidates.size();
        
        if(target == 0)
        {
            if(ds.size() == k)  ans.push_back(ds);
            return;
        }
        
        for(int i=index;i<n;i++){
            if(i > index && candidates[i] == candidates[i-1]) continue; // if not first element
            if(candidates[i] > target)  break;
            
            ds.push_back(candidates[i]);
            solve(i+1,target - candidates[i],candidates,ds,ans,k);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0,n,v,ds,ans,k);
        return ans;
    }
};