class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int i = 0 , j = 0;
        
        int diff ;
        int ans = INT_MAX;
        while( j+k-1  < nums.size()){
            diff = nums[j+k-1] - nums[j];
            ans = min(diff,ans);
            j++;
            
        }
        return ans;
    }
};