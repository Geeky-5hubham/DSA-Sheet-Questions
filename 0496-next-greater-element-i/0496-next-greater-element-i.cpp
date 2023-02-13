class Solution {
public:
    map<int,int> nge(vector<int> &nums2){
        int n = nums2.size();
        map<int,int> mp;
        
        stack<int> s;
        
        for(int i=n-1;i>=0;--i){
            int curr = nums2[i];
            while(!s.empty() && s.top() <= curr)
                s.pop();
            
            if(s.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = s.top();
            
            s.push(curr);
        }
        return mp;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> nge_map = nge(nums2);
        
        vector<int> ans(nums1.size());
        
        for(int i=0;i<nums1.size();i++){
            
            ans[i] = nge_map[nums1[i]];
        }
        return ans;
    }
};