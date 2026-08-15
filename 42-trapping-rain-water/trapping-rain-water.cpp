class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        int max_l=0,max_r=0;
        int total = 0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<max_l){
                    total += (max_l-height[l]);
                }else{
                    max_l = height[l];
                }
                l++;
            }else{
                if(height[r]<max_r){
                    total += (max_r-height[r]);
                }else{
                    max_r = height[r];
                }
                r--;
            }
        }
        return total;

    }
};