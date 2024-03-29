//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int check(int mid,int n,vector<int> &stalls){
        int start = 0;
        int c = 0;
        
        for(int i=1;i<n;i++){
            if(stalls[i] - stalls[start] > mid){
                c++;
                start = i;
            } 
        }
        c++;
        
        return c;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        
        for(int i=0;i<n-1;i++){
            int diff = stalls[i+1] - stalls[i];
            low = min(low,diff);
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(check(mid,n,stalls) < k){
                high = mid-1;
            }
            
            else{
                low = mid+1;
            }
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends