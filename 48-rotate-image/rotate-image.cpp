class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> newmatrix = matrix;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                newmatrix[j][n-1-i] = matrix[i][j];
            }
        }

        matrix = newmatrix;
    }
};