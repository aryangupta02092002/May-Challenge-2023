//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&ranges, int q, vector<int>queries){
        //Write your code here
        sort(ranges.begin(),ranges.end());
        
        vector<vector<int>> r;
        r.push_back({ranges[0][0],ranges[0][1]});
        
        for(int i=1; i<n; i++){
            int a = ranges[i][0];
            int b = ranges[i][1];
            if(r.back()[1]>=a){
                r.back()[1] = max(r.back()[1],b);
            }
            else{
                r.push_back({ranges[i][0],ranges[i][1]});
            }
        }
        
        vector<int> v;
        
        for(int i=0; i<q; i++){
            
            int e = queries[i];
            int c = 0;
            while(c < r.size() and e != 0 ){
                
                int p =  (r[c][1] - r[c][0] );
                if(e > (p+1)){
                    e = e - (p+1);
                }
                else{
                    int ans = r[c][0] + e - 1;
                    v.push_back(ans);
                    break;
                }
               
                c++;
            }
            
            if(c == r.size()){
                v.push_back(-1);
            }
            
        }
        
        return v;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
