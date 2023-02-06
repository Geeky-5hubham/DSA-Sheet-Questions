class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> temp;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                
                if(binary_search(nums2.begin(),nums2.end(),nums1[i]) == true)
                    temp.insert(nums1[i]);
                
            }
        }
        
        for(auto i:temp)
            ans.push_back(i);
        
        return ans;
    }
};