class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        
        int half = n/2;
        
        vector<int> val;
        
        for(auto it:mp)
            val.push_back(it.second);
        
        sort(val.begin(),val.end());
        
        int ans = 0;
        int sum = 0;
        int i = val.size()-1;
        
        while(true){
            sum += val[i];
            ans++;
            if(sum >= half)
                break;
            --i;
        }
        return ans;
    }
};