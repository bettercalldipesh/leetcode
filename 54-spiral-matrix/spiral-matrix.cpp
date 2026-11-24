class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int left = 0, top = 0, right = n-1, bottom = m-1;

        while(top <= bottom && left <= right){
            //Traversal from Left to Right
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //Traversal from Top to Bottom
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

           if(top <= bottom){
             // Traversal from Right to Left
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left <= right){
                // Traversal from Bottom to Top
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }

        return ans;
    }
};