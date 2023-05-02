//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool isPossible(vector<int>&v,int n,int k,int x)
    {
        int sum = 0, c = 0, mn = INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            sum += v[i];
            
            if(sum >= x && c < k){   
               mn = min(mn, sum);
               sum = 0;
               c++;
            }
        }
        
        mn = min(mn, sum);
        
        return c >= k && mn >= x;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
        int low = 0, high = 1e9, ans = 0;
         
        while(low <= high){
            int mid = low + (high - low)/2;
             
            if(isPossible(sweetness, N, K, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
         
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends
