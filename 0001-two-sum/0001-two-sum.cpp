class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int curr = nums[i];
            int diff = target - curr;
            
             if(mp.find(diff) == mp.end()){
                  mp[curr] = i;
             }
             else{
                 ans.push_back(mp[diff]);
                 ans.push_back(i);
                 return ans;
             }
        }
        return ans;
  
    }
};