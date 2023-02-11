class Solution {
public:
    // Ans depends on number of nodes not values coz all numbersa are in increasing order and distinct  Ans for i(th) node= left sub tree Ans * right sub tree Ans = Ans(i-1)*Ans(n-i)
    
    int numTrees(int n) {
        if(n <= 1)
            return 1;
        
        int ans = 0;
        
        // consider i as root node
        for(int i=1;i<=n;i++){
            ans += numTrees(i-1)*numTrees(n-i);
        }
        
        return ans;
    }
};