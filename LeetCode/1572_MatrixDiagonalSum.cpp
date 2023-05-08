class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int j = mat.size()-1;
        int mid = mat.size()/2;

        for(int i=0; i<mat.size(); i++)
        {
            sum += (i==mid && mat.size()%2 != 0 ? 0 : mat[i][i]);
            sum += mat[j][i];
            j--;
        }
        return sum;
    }
};
