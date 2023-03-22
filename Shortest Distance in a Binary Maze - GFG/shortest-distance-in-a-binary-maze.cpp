//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first == destination.first && source.second == destination.second)
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n,vector<int> (m,1e9));
        
        dis[source.first][source.second] = 0;
        queue<vector<int>> q;    // {distance,row,col}
        q.push({0,source.first,source.second});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int distance = it[0];
            int r = it[1];
            int c = it[2];
            
            int delRow[4] = {-1,+1,0,0};
            int delCol[4] = {0,0,-1,+1};
            
            for(int i=0;i<4;i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                && grid[newRow][newCol] == 1 && distance + 1 < dis[newRow][newCol]){
                    
                    dis[newRow][newCol] = distance + 1;
                    
                    if(newRow == destination.first && newCol == destination.second)
                        return dis[newRow][newCol];
                        
                    q.push({distance+1,newRow,newCol});
                    
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends