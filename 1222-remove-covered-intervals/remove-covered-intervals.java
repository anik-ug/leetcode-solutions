class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;
        
        boolean[] covered = new boolean[n];
        Arrays.sort(intervals,(a,b)->{
            if(a[0]==b[0])return Integer.compare(b[1],a[1]);

            return Integer.compare(a[0],b[0]); 
            });
        for(int i=0;i<n;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            for(int j=i+1;j<n;j++){
                
                int c = intervals[j][0];
                int d = intervals[j][1];
                if(a <= c && d <= b){
                    covered[j]=true;
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