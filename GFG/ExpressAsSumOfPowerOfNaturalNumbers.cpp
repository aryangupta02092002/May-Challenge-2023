//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int helper(int num , int tar , int x,vector<vector<int>> &dp){
        if(tar == 0) return 1;
        if(tar<0) return 0;
        if(pow(num,x)>tar) return 0;
        
        if(dp[num][tar]!=-1) return dp[num][tar];
        
        
        int pick = 0;
        if(tar-pow(num,x)>=0){
         pick = helper(num+1 , tar-pow(num,x), x,dp);
        }
        int notpick = helper(num+1, tar, x, dp);
        return dp[num][tar]=(pick + notpick) % (int)(1e9 + 7);
    }
    int numOfWays(int n, int x)
    {   vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return helper(1,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends
