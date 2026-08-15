class Solution {
public:
    
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        int count = 0;
        int other=0;
        count = n/3;
        other = n%3;
        if(other == 2){
            return (other)*pow(3,count);
        }
        return (other+3)*pow(3,count-1);
    }
};