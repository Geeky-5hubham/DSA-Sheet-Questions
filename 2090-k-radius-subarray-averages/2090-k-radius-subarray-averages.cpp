class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> ans(n,-1);
        
        if(2*k+1 > n)
            return ans;
        
        int i = 0;
        int j = 0;
        long long int sum = 0;
        
        while(j < n){
            sum += nums[j];
            
            if(j-i+1 == 2*k+1){
                int avg = sum/(j-i+1);
                ans[(i+j)/2] = avg;
                sum = sum - nums[i];
                i++;
                j++;
            } 
            
            else{
                j++;
            }
        }
        
        return ans;
    }
};