class Solution {
public:
    // Ans depends on number of nodes not values coz all numbersa are in increasing order and distinct  Ans for i(th) node= left sub tree Ans * right sub tree Ans = Ans(i-1)*Ans(n-i)
    
    int solve_Tabulation(int n){
        vector<int> dp(n+1);
        
        dp[0] = dp[1] = 1;

        // i -> no. of nodes
        for(int i=2;i<=n;i++){
           // j -> root node
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        
        return dp[n];
        
    }
    
    int solve_memoisation(int n,vector<int> &dp){
        
        if(n <=1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += solve_memoisation(i-1,dp)*solve_memoisation(n-i,dp);
        }
        
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve_Tabulation(n);
    }
};