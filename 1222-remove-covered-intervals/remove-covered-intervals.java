class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;
        
        boolean[] covered = new boolean[n];

        Arrays.sort(intervals,(a,b)->{
            if(a[0]==b[0])return Integer.compare(a[1],b[1]);

            return Integer.compare(b[0],a[0]); 
            });
        for(int i=0;i<n-1;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            for(int j=i+1;j<n;j++){
                
                int c = intervals[j][0];
                int d = intervals[j][1];
                if(c <= a && b <= d){
                    covered[i]=true;
                }
                
            }
        }
        int ans = 0;

        for(boolean x : covered){

            if(!x)
                ans++;
        }
        return ans;
    }
}