class Solution {
public:
    int dp[105][105];
    int solve(int i,int j,vector<int>& cuts){
        if(j-i <= 1)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans = INT_MAX;

        for(int k=i+1;k<j;k++){
            int cost =cuts[j]-cuts[i]+solve(i,k,cuts)+solve(k,j,cuts);

            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));

        return solve(0,cuts.size()-1,cuts);
    }
};