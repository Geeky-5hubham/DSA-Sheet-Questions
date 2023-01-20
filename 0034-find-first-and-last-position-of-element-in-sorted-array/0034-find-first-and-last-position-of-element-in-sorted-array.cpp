class Solution {
    private:
    int firstOcc(vector<int>& nums, int target){
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid,res1 = -1;
        
        while(s <= e){
            mid = s +(e-s)/2;
            if(nums[mid] == target){
                res1 = mid;
                e = mid-1;
            }
            else if(nums[mid] > target)     e = mid-1;
            else    s = mid+1;
        }
        return res1;
    }
    
    int lastOcc(vector<int>& nums, int target){
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid,res2 = -1;
        
        while(s <= e){
            mid = s +(e-s)/2;
            if(nums[mid] == target){
                res2 = mid;
                s = mid+1;
            }
            else if(nums[mid] > target)     e = mid-1;
            else    s = mid+1;
        }
        return res2;
    }
    
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        vector<int> ans ;
        
        ans.push_back(firstOcc(nums,target));
        ans.push_back(lastOcc(nums,target));
        return ans;
    }
};