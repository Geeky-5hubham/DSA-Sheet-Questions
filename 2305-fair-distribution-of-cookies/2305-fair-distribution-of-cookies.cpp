class Solution {
public:
    int ans = INT_MAX;
    
    void f(int ind,vector<int> &count,vector<int> &cookies){
        if(ind == cookies.size()){
            int maxi = 0;
            for(auto it:count)  maxi = max(it,maxi);
            ans = min(ans,maxi);
            return;
        }
        
        for(int i=0;i<count.size();i++){
            count[i] += cookies[ind];
            f(ind+1,count,cookies);
            count[i] -= cookies[ind];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> count(k,0);
        
        f(0,count,cookies);
        return ans;
    }
};