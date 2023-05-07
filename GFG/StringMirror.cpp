//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int n = str.size();
        string temp;
        temp += str[0];
        
        for(int i = 1; i < n; i++) {
            if(str[i] < str[i - 1]){
                temp += str[i];
            }
            else if(str[i] > str[i - 1]){
                break;
            }
            else{
                if(str[i] == temp[0]){
                    break;
                }
                else{
                    temp += str[i];
                }
            }
        }
        
        string rev = temp;
        reverse(rev.begin(), rev.end());
        
        return temp + rev;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends
