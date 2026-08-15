class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prev_great(n);
        vector<int> next_great(n);
        prev_great[0]=-1;
        next_great[n-1]=-1;
        int max=height[0];
        for(int i=1;i<n;i++){
            prev_great[i]=max;
             if(max<height[i]){
                max=height[i];
             }
        }
        max=height[n-1];
        for(int i=n-2;i>=0;i--){
            next_great[i]=max;
            if(max<height[i]){
                max=height[i];
            }
        }
        vector<int> crr(n);
        int output=0;
        for(int i=0;i<n;i++){
            crr[i]=min(prev_great[i],next_great[i]);
            if(height[i]<crr[i]){
                output=output+(crr[i]-height[i]);
            }

        }
        return output;
    }
};