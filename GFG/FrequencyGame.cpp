//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int> u;
        int mn = INT_MAX;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++) {
            u[arr[i]]++;
        }
        
        for(auto it : u){
            mn = min(mn, it.second);
        }
        for(auto it : u){
            if(it.second == mn){
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
