class Solution {
public:
    void dfs(string src, string dest, map<string, vector<pair<string, double>>> &m, set<string> s, double &res, double tmp){
        if(s.find(src) != s.end()){
            return;
        }
        else{
            s.insert(src);
            if(src == dest){
                res = tmp;
                return;
            }
            else{
                for(auto x : m[src]){
                    dfs(x.first, dest, m, s, res, tmp*x.second);
                }
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>> > m;
        vector<double> ans;
    
        for(int i=0; i<equations.size(); i++){
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        for(int i=0; i<queries.size(); i++){
            string src = queries[i][0];
            string dest = queries[i][1];
            
            set<string> vis;
            double res = -1.0;
            if(m.find(src) != m.end()){
                dfs(src, dest, m, vis, res, 1.0);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
