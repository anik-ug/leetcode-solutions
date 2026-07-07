class Solution {
    public long sumAndMultiply(int n) {
        int m = n;
        String ans="";
        int sum = 0;
        while(m>0){
            if(m%10 != 0){
                ans+=String.valueOf(m%10);
                sum+=m%10;
            }
            m/=10;
        }
        if(ans.length() == 0)
            return 0;
        String rev = new StringBuilder(ans).reverse().toString();
        long x = Long.parseLong(rev);
        x*=sum;
        return x;

    }
}