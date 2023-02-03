class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e5;
        
        int sum = 0;
        
        int i=0,j=0;
        int x = INT_MIN;
        
        while(j<nums.size()){
            sum += nums[j];
            
            if(j-i+1 == k){
                x = max(x,sum);
                sum = sum - nums[i];
                i++;
                j++;
            }
            
            else{
                j++;
            }
        }
        
        return x/double(k);
    }
};