//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job &a,Job &b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++){
            int deadl = arr[i].dead;
            maxi = max(maxi,deadl);
        }
        
        vector<int> deadline(maxi+1,-1);
        
        int ans = 0,cnt = 0;
        
        for(int i=0;i<n;i++){
            int currid = arr[i].id;
            int currdead = arr[i].dead;
            int currprofit = arr[i].profit;
            
            for(int j=currdead;j>0;j--){
                if(deadline[j] == -1 ){
                    deadline[j] = currid;
                    ans += currprofit;
                    cnt++;
                    break;
                }
            }
        }
        
        vector<int> res;
        res.push_back(cnt);
        res.push_back(ans);
        
        return res;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends