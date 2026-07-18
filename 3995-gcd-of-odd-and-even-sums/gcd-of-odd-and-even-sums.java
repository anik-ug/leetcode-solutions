class Solution {
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,b%a);
    }
    public int gcdOfOddEvenSums(int n) {
        if(n==1)return 1;
        int o = 0;
        int e = 0;
        for(int i=1;i<=n;i++){
            o+=i;
            e+=(i+1);
        }
        return gcd(o,e);
    }
}