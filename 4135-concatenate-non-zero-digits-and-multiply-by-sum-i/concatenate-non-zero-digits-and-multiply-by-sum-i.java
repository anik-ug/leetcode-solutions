class Solution {
    public long sumAndMultiply(int n) {
        int m = n;
        StringBuilder sb = new StringBuilder();
        int sum = 0;
        while(m>0){
            if(m%10 != 0){
                sb.append(m % 10);
                sum+=m%10;
            }
            m/=10;
        }
        if(sb.length() == 0)
            return 0;
        String rev = sb.reverse().toString();
        long x = Long.parseLong(rev);
        x*=sum;
        return x;

    }
}