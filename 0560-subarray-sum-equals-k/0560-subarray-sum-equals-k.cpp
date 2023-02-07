class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        /*vector<int> pre;
        
        int sum = 0;
        pre.push_back(sum);
            
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            pre.push_back(sum);
        }
        */
        unordered_map<int,int> mp;   // SUM : Count of sum
        
        mp[0] = 1;  
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            
            sum += nums[i];
            
            if(mp.find(sum-k) != mp.end())
                count = count + mp.find(sum-k)->second;
            
            mp[sum]++;
      
        }
        return count;
    }
};