class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return dp[i][j] = grid[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=INT_MAX;
        if(i<grid.size()-1){
            right = grid[i][j] + solve(i+1,j,grid);
        }
        int down=INT_MAX;
        if(j<grid[0].size()-1){
            down = grid[i][j] + solve(i,j+1,grid);
        }

        return dp[i][j] = min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
        
    }
};