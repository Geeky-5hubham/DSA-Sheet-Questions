class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if(nums.size() == 1)    return nums[0];
        
        int count = 0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1]){
                count++;
                
                if(count+1 > nums.size()/2) return nums[i];
            }
            
            else    count = 0;
        }
        return -1;
    }
};