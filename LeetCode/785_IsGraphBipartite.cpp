class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int> colors(sz, 0);
        queue<int> q;
        
        for(int i=0; i<sz; i++){
            if(colors[i]){
                continue;
            }
            colors[i] = 1;
            q.push(i);
            
            while(!q.empty()){
                int tmp = q.front();    q.pop();
                
                for(auto neighbor : graph[tmp]){
                    if(!colors[neighbor]){
                        colors[neighbor] = -colors[tmp];
                        q.push(neighbor);
                    }
                    else if(colors[neighbor] == colors[tmp]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
