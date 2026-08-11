class Solution {
    public String longestPalindrome(String s) {
        int start=0;
        int maxLen=0;
        for(int i=0;i<s.length();i++){
            
            int len1 = expand(s,i,i);
            int len2 = expand(s,i,i+1);

            int len  = Math.max(len1,len2);
            if(len > maxLen) {
                maxLen = len;
                start = i - (len-1)/2;
            }
        }
        return s.substring(start,start+maxLen);
    }
    private int expand(String str,int l,int r){
        while(l>=0 && r<str.length() && str.charAt(l)==str.charAt(r)){
            l--;
            r++;
        }
        return r-l-1;
    }
}
