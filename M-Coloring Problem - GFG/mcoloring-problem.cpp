//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool isSafe(int node,vector<int> &color,bool graph[101][101],int n,int col){
        for(int k=0;k<n;k++){
            if( k != node && graph[k][node] == 1 && color[k] == col)
                return false;
        }
        return true;
    }
    
    bool solve(int node,bool graph[101][101],vector<int> &color, int m, int n){
        if(node == n)
            return true;
        
        for(int i=1;i<=m;i++){
            int col = i;
            if(isSafe(node,color,graph,n,col)){
                color[node] = col;
                if(solve(node+1,graph,color,m,n) == true)
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }

public:
   
    bool graphColoring(bool graph[101][101], int m, int n) {

        vector<int> color(n+1,0);
        return solve(0,graph,color,m,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends