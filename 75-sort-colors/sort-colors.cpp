class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int hi=n-1,lo=0,mid=0;

        while(mid<=hi){
            if(nums[mid]==2){
                swap(nums[mid],nums[hi]);
                hi--;
            }else if(nums[mid]==0){
                swap(nums[mid],nums[lo]);
                mid++;
                lo++;
            }else if(nums[mid]==1){
                mid++;
            }

        }
        
    }
};