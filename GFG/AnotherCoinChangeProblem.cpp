//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  private:
    bool caldp(int idx, int k, int tr, vector<int>&coin, vector<vector<int>>&dp)
    {
        if(tr == 0){
           return (k == 0);
        }
        
        if(idx == 0){
            return (tr/coin[idx] == k && tr%coin[idx] == 0);
        }
        
        if(dp[tr][k] != -1){
            return dp[tr][k];
        }
        
        bool nttk = caldp(idx-1, k, tr, coin, dp);
        bool ttk = false;
        
        if(tr >= coin[idx]){
            ttk = caldp(idx, k-1, tr - coin[idx], coin, dp);
        }
        return dp[tr][k] = (ttk || nttk);
    }
  public:
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
       vector<vector<int>>dp(target + 1, (vector<int>(k+1, -1)));
       return caldp(n-1, k, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends
