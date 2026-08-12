class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){

            // Skip duplicate i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j=i+1;j<n-2;j++){

                // Skip duplicate j
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int first=j+1,last=n-1;
                while(first<last){
                    long long sum = (long long)nums[i]+nums[j]+nums[first]+nums[last];
                    if(sum==target){
                        total.push_back({nums[i],nums[j],nums[first],nums[last]});
                        first++;
                        last--;

                        // Skip duplicates
                        while(first < last &&
                              nums[first] == nums[first - 1])
                            first++;

                        while(first < last &&
                              nums[last] == nums[last + 1])
                            last--;

                    }else if(sum<target){
                        first++;
                    }else{
                        last--;
                    }
                }
            }
        }
        return total;
    }
};