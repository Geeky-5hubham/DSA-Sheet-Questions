//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long int lenOfLongIncSubArr(long int arr[], long int n) {
        long long int ans = 1;
        long long int res = LONG_MIN;
        //long long int n = .size();
        long long int curr = arr[0];
        
        if(n==1)    return 1;
        
        for(int i=1;i<n;i++){
            
            if(arr[i] > curr){
                ans++;
                res = max(ans,res);
                curr = arr[i];
            }
            else{
                curr = arr[i];
                ans = 1;
                res = max(ans,res);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        long int arr[n], i;
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        Solution obj;
        cout << obj.lenOfLongIncSubArr(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends