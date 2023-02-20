class Solution {
private:
    pair<int,int> fun(int n){
         int i = 0;
 
        while(pow(2,i) < n){
            i++;
        }
        
        int hi = pow(2,i);
        int lo = pow(2,--i);
        
        return make_pair(lo,hi);
    }
    
public:
    int minOperations(int n) {
        int ans = 0;
        
    
        
        while(n != 0){
            pair<int,int> p = fun(n);
            int lo = p.first;
            int hi = p.second;
            
           int diff1 = n-lo;
           int diff2 = hi-n;
            ans++;
            
           if(diff1 < diff2){
               n = diff1;
           }
            
            else{
                n = diff2;
            }
        }
        
        return ans;
    }
};