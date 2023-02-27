class Solution {
public:
    int getSum(int a, int b) {
        int p = max(a,b);
        int q = min(a,b);
        int x=q;
        while(x!=0){
          
            x = p%q;
            int divi = p/q;
            p = (-(~divi))*q;
            q = x;
        }
        return p;
    }
};