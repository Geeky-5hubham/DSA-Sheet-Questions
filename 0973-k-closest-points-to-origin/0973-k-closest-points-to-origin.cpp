class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector <int>> ans;
        
        vector<pair<int,vector<int>>> temp;
        
        for(auto i:points){
            int dist = i[0]*i[0]+i[1]*i[1];
            temp.push_back({dist,i});
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<k;i++){
            vector<int> v = temp[i].second;
            ans.push_back(v);
        }
       
        return ans;
        
    }
};