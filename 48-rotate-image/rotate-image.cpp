class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

//For Transpose of the matrix
        for(int i=0; i < n; i++){
            for(int j=i+1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

// For Reversing the Array
        for(int i=0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};