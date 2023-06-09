class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int c = 1;
        for(int j=1;j<nums.size();j++){
            if(nums[i] == nums[j]){
                c++;
                if(c <= 2){
                    i++;
                    nums[i] = nums[j];
                }
               
            }
            
            else if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                c = 1;
            }
        }
        
        return i+1;
    }
};