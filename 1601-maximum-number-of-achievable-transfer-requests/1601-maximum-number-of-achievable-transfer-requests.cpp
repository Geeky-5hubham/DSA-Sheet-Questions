class Solution {
public:
    int ans = 0;
    
    void f(int ind,int count,vector<vector<int>>& requests,vector<int> &in){
        if(ind == requests.size()){
            int x = 0;
            for(auto it:in){
                if(it == 0)     x++;
            }
            
            if(x == in.size()){
                ans = max(ans,count);
            }
            
            return;      
        }
        
        int from = requests[ind][0];
        int to = requests[ind][1];
        // Consider
        in[from]--;
        in[to]++;
        f(ind+1,count+1,requests,in);
        
        in[from]++;
        in[to]--;
        
        // Not consider
        f(ind+1,count,requests,in);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> in(n,0);
        int count = 0;
        
        f(0,count,requests,in);
        return ans;
    }
};