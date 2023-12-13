class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
           int m = mat.size();
    int n = mat[0].size();
    int specialCount = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1) {
                
                bool rowCheck = true;
                for (int col = 0; col < n; ++col) {
                    if (col != j && mat[i][col] != 0) {
                        rowCheck = false;
                        break;
                    }
                }

     
                bool colCheck = true;
                for (int row = 0; row < m; ++row) {
                    if (row != i && mat[row][j] != 0) {
                        colCheck = false;
                        break;
                    }
                }

                if (rowCheck && colCheck) {
                    specialCount++;
                }
            }
        }
    }

    return specialCount;
}
    
};