//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        int mod = 100000;
        // There will be at max (0-9999) {think it of as node}
        vector<int> dis(100000,1e9);
        dis[start] = 0;
        
        queue<pair<int,int>> q; // {distance,node}
        q.push({0,start});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int steps = it.first;
            int node = it.second;
            
            for(auto i:arr){
                int num = (i*node)%mod;
                
                if(steps + 1 < dis[num]){
                    dis[num] = steps + 1;
                    if(num == end)  return steps + 1;
                    q.push({steps+1,num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends