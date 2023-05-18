class Solution {
public:
    int kthFactor(int n, int k) {
        int c = 0;
        
        for(int i=1;i*i<n;i++){
            if(n%i == 0){
                --k;
                if(k == 0)
                    return i;
            }
        }
        
        for(int i=(int)pow(n,0.5);i>=1;i--){
            if(n%i == 0){
                --k;
                if(k == 0)
                    return n/i;
            }
            
        }
        return -1;
  
    }
};