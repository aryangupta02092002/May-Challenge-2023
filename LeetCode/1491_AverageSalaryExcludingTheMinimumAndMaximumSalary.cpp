class Solution {
public:
    double average(vector<int>& s) {
        double sum = 0;
        int mn = 1e9, mx = 0;
        for(int i=0; i<s.size(); i++){
            mn = min(mn, s[i]);
            mx = max(mx, s[i]);
            sum += s[i];
        }
        sum = sum - mn - mx;
        double avg = sum/(s.size()-2);
        return avg;
    }
};
