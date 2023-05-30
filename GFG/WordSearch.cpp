//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i, int j, int ptr, vector<vector<int>> &vis, vector<vector<char>>& board, string word){
        if(ptr == word.length()) 
            return true;
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0) 
            return false;
        if(board[i][j] == word[ptr] && !vis[i][j]){
            vis[i][j] = 1;
            ptr++;
            if(dfs(i+1, j, ptr, vis, board, word)) 
                return true;
            if(dfs(i-1, j, ptr, vis, board, word)) 
                return true;
            if(dfs(i, j+1, ptr, vis, board, word)) 
                return true;
            if(dfs(i, j-1, ptr, vis, board, word)) 
                return true;
            vis[i][j] = 0;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        if (n == 0 || m == 0) 
            return false;
            
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> vis(n, vector<int> (m, 0));
                    vis[i][j] = 1;
                    int ptr = 1;
                    if(word.length() == 1) 
                        return true;
                    if(dfs(i+1, j, ptr, vis, board, word)) 
                        return true;
                    if(dfs(i-1, j, ptr, vis, board, word)) 
                        return true;
                    if(dfs(i, j+1, ptr, vis, board, word)) 
                        return true;
                    if(dfs(i, j-1, ptr, vis, board, word)) 
                        return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
