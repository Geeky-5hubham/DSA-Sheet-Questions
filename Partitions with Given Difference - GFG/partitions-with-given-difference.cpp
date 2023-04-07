//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int mod = (int)(1e9+7);
    /*int f(int i,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(i == 0){
            if(arr[0] == 0 && target == 0)      return 2;
            if(target == 0 || target == arr[0])     return 1;
            return 0;
        }
        if(dp[i][target] != -1)
            return dp[i][target];
        
        int notTake = f(i-1,target,arr,dp);
        
        int take = 0;
        if(arr[i] <= target)
            take = f(i-1,target-arr[i],arr,dp);
            
        return dp[i][target] = (take + notTake) % mod;
    }*/
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(auto it:arr)
            sum += it;
            
        if((sum + d)%2 == 1)
            return 0;
        else{
            int target = (d+sum)/2;
            vector<vector<int>> dp(n,vector<int> (target+1,0));
            
            if(arr[0] == 0)    
                dp[0][0] = 2;
            
            else    
                dp[0][0] = 1;
            
            if(arr[0] != 0 && arr[0] <= target)    
                dp[0][arr[0]] = 1;
                
            for(int i=1;i<n;i++){
                for(int t=0;t<=target;t++){
                    
                    int notTake = dp[i-1][t];
        
                    int take = 0;
                    if(arr[i] <= t)
                        take = dp[i-1][t-arr[i]];
                        
                    dp[i][t] = (take + notTake) % mod;
                    
                }
            }
            
            
            return dp[n-1][target];
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/wheelfab-1680611378.svg