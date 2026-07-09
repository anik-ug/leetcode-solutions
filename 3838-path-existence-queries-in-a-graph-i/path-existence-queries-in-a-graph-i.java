class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int m = queries.length;
        boolean[] result = new boolean[m];

        int[] g = new int[n];
        
        g[0] = 0;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] > maxDiff)
                cnt++;
            g[i] = cnt;
        }

        for(int i=0;i<m;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(v==u)result[i]= true;
            else if(g[u]==g[v]){
                result[i] = true;
            }
            else{
                result[i] = false;
            }
        }
        return result;
    }
}