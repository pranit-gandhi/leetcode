class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& dp){
        if (dp[i][j]!=-1) return dp[i][j];

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int res = 0;
        for(int k=0; k<4; k++){
            int ni = i+dx[k], nj = j+dy[k];
            if (ni>=0 && ni<m && nj>=0 && nj<n
                && matrix[ni][nj]>matrix[i][j] ){
                    res = max(res, 1+dfs(ni, nj, matrix, m, n, dp));
                }
        }
        return dp[i][j] = res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res = max(res, 1+dfs(i, j, matrix, m, n, dp));
            }
        }
        return res;
    }
};