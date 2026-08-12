class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m>n)return -1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack.substr(i,needle.size())== needle){
                return i;
            }
        }
        return -1;
    }
};