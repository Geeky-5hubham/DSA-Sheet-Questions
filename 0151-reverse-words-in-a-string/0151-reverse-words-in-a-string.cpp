class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        
        
        
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            
            else if(s[i] == ' '){
                if(temp.size() > 0){
                    v.push_back(temp);
                    temp = "";
                }
            }
        }
        
        if(temp.size() > 0)
            v.push_back(temp);
        
        string ans = "";
        
        reverse(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++){
            ans += v[i];
            ans += ' ';
        }
        
        ans.erase(ans.begin()+ans.size()-1);
        
        return ans;
    }
};