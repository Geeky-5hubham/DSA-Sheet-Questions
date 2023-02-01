class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        if(intervals.size() == 0)
            return ans;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> curr = intervals[0];
        
        for(int i=1;i<intervals.size();i++){
           vector<int> temp = intervals[i];
            
            if(curr[1] < temp[0]){ // No overlapping
                ans.push_back(curr);
                curr = temp;
            }
            
            // overlapping
            else{
                curr[1] = max(curr[1],temp[1]);
            }
                
        }
        ans.push_back(curr);
        return ans;
    }
};