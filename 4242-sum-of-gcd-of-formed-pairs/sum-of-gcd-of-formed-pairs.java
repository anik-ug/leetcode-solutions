class Solution {
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] prefixGcd = new int[n];
        int mx = nums[0];
        prefixGcd[0]=nums[0];
        for(int i=1;i<n;i++){
            mx = Math.max(nums[i],mx);
            prefixGcd[i] = gcd(nums[i],mx);
        }
        Arrays.sort(prefixGcd);
        int l=0;
        int r=n-1;
        long sum = 0;
        while(l<r){
            sum+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
     }
}