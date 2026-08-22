class Solution {
public:
    int solve(int m, int n,int i,int j,vector<vector<int>>&dp){
        // Reached destination
        int right=0,down=0;
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // Move right
        if(j < n - 1) {
           right = solve(m, n, i, j + 1, dp);
        }

        // Move down
        if(i < m - 1) {
            down = solve(m, n, i + 1, j, dp);
        }

        return dp[i][j] = right+down;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,(vector<int>(n,-1)));
        return solve(m,n,0,0,dp);
    }
};