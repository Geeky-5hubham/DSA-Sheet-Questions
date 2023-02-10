class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int i=0,j=nums.size()-1;
        int mid;
        
        if(nums[i] > target)    return 0;
        if(nums[j] < target)    return j+1;
        
        while(i<=j){    
            mid = i+(j-i)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                j = mid-1;
            else
                i = mid+1;
        }
        return i;   //After termination of loop i will have index at which target is to inserted
    }
};