class Solution {
    // Euclidean Algorithm
    public int GCD(int a,int b){
        if(b==0){
            return a;
        }
        return GCD(b,a%b);
    }
    public int findGCD(int[] nums) {
        int n = nums.length;
        int a = nums[0];
        int b = nums[0];
        for(int i=1;i<n;i++){
            a = Math.min(a,nums[i]);
            b = Math.max(b,nums[i]);
        }
        
        return GCD(a,b);
    }
}