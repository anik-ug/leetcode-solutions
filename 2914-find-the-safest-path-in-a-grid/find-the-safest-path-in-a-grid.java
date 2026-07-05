class Solution {
    int[][] dir = {{0,1},{1,0},{0,-1},{-1,0}};
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        Queue<int[]> q = new ArrayDeque<>();

        int[][] dist = new int[n][n];

        // Initially mark all cells as unvisited
        for(int i=0;i<n;i++){
            Arrays.fill(dist[i],-1);
        }
        // Step 1:
        // Put every thief into queue
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid.get(i).get(j)==1){
                    q.offer(new int[]{i,j});
                    dist[i][j]=0;
                }
            }
        }
        
        // Step 2:
        // Multi-source BFS
        while(!q.isEmpty()){
            int[] curr = q.poll();

            int x = curr[0];
            int y = curr[1];

            for(int[] d:dir){
                int r = x+d[0];
                int c = y+d[1];

                if(r<0||c<0||r>=n||c>=n)
                    continue;
                
                if(dist[r][c] != -1)
                    continue;
                
                dist[r][c] = dist[x][y] + 1;
                q.offer(new int[]{r,c});
            }
        }

        // Step 3:
        // Max Heap
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->b[0]-a[0]);

        boolean[][] vis = new boolean[n][n];

        pq.offer(new int[] {dist[0][0],0,0});

        vis[0][0] = true;

        while(!pq.isEmpty()){
            int[] curr = pq.poll();

            int safe = curr[0];
            int x = curr[1];
            int y = curr[2];

            if(x == n-1 && y == n-1){
                return safe;
            } 
            for(int[] d:dir){

                int r=x+d[0];
                int c=y+d[1];

                if(r<0||c<0||r>=n||c>=n)
                    continue;

                if(vis[r][c])
                    continue;

                vis[r][c]=true;

                int newSafe=Math.min(safe,
                                     dist[r][c]);

                pq.offer(new int[]{
                        newSafe,
                        r,
                        c
                });
            }
        }
        return 0;
    }
}