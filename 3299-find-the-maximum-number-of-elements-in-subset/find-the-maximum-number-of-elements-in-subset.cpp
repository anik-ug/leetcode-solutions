class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long,int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            int cnt = freq[1];
            ans = max(ans, (cnt % 2 == 0) ? cnt - 1 : cnt);
        }

        for (auto it : freq) {

            long long start = it.first;

            if (start == 1)
                continue;

            long long cur = start;
            int len = 0;

            while (freq.count(cur) && freq[cur] >= 2) {

                len += 2;

                cur = cur * cur;
            }

            if (freq.count(cur)== 1)
                len++;
            else
                len--;         

            ans = max(ans, len);
        }

        return ans;
    }
};