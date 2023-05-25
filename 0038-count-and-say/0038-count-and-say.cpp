class Solution {
public:
    vector<pair<int,int>> f1(string s){
        vector<pair<int,int>> res;
        int c = 1;
        
        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1]){
                c++;
            }
            
            else{
                res.push_back({s[i-1]-'0',c});
                c = 1;
            }
        }
        res.push_back({s[s.size()-1]-'0',c});
        return res;
    }
    
    string f2(vector<pair<int,int>> v){
        string ans = "";
        
        for(int i=0;i<v.size();i++){
            
            ans += to_string(v[i].second);
            ans += to_string(v[i].first);
         }
        
        return ans;
    }
    
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string curr = to_string(1);
        
        int cnt = 0;
        
        while(cnt < n-1){
            vector<pair<int,int>> temp = f1(curr);
            curr = f2(temp);
            cnt++;
        }
        
        return curr;
    }
};