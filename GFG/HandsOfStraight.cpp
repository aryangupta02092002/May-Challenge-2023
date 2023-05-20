//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        map<int,int> m;
        for(auto i : hand) {
            m[i]++;
        }
        
        int count = 0;
        int num = -1;
        
        while(1){
            int num = m.begin()->first;
            count = 0;
            
            while(count < groupSize){
                if(m.find(num) == m.end()) 
                    return false;
                m[num]--;
                if(m[num] == 0) {
                    m.erase(num);
                }
                num++;
                count++;
            }
            if(m.size() == 0) 
                break;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
