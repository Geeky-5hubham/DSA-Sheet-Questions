class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        
        int x;
        
        for(int i=citations.size()-1;i>=0;i--){
            x = citations.size()-i;
            if(citations[i] >= x)    
                continue;
            
            else
                return x-1;
        }
        
        return citations.size();
    }
};