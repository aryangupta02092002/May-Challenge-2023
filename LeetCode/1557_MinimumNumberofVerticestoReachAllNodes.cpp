class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> inorder(n+1, 0);
        for(auto edge : edges){
            inorder[edge[1]]++;
        }
        for(int i=0; i<n; i++){
            if(inorder[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
