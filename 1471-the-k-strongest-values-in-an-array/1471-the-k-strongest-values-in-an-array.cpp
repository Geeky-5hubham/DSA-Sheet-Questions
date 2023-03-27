class Solution {
public:

    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int m = arr[(arr.size()-1)/2];
        int n = arr.size();
        int i=0,j = n-1;
        
        while(k--){
            if(m-arr[i] > arr[j]-m)
                i++;
            else j--;
        }
        arr.erase(begin(arr) + i, begin(arr) + j + 1);
        return arr;
    }
};