class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0,sum2 = 0;
        
        for(auto i:nums){
            mp[i]++;
        }    
        
        for(auto x:nums){
            if(mp[x] != 1)  return x;
        }
        
        return -1;
    }
};