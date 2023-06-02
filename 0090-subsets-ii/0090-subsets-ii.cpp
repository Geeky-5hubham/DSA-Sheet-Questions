class Solution {
public:
    
    
    void f(int i,vector<int> &nums,vector<int> &temp,map<vector<int>,int> &mp){
        if(i == nums.size())
        {
            mp[temp]++;
            return;
        }
        
        temp.push_back(nums[i]);
        f(i+1,nums,temp,mp);
        
        temp.pop_back();
        f(i+1,nums,temp,mp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        map<vector<int>,int> mp;
        
        sort(nums.begin(),nums.end());
        
         f(0,nums,temp,mp);
        
        for(auto it:mp){
            ans.push_back(it.first);
        }
        
        
        
        return ans;
    }
};