//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfsCheck(int node,vector<int> adj[],int vis[],int path_vis[]){
        vis[node] = 1;
        path_vis[node] = 1;
        
        for(auto it:adj[node]){
            // If Not visited
            if(!vis[it]){
                if(dfsCheck(it,adj,vis,path_vis) == true)
                    return true;
            }
            // Visited and path visited
            else if(path_vis[it] == 1)
                return true;
        }
        path_vis[node] = 0;
        return false;
        
    }
  
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int path_vis[V] = {0};
        
        // For Connected Componenets
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,path_vis) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends