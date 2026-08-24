class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>s;
        int ans=0;
        for(int i=0;i<=n;i++){
            int t = (i==n) ? -1 : heights[i];
            while(!s.empty() && t<=heights[s.top()]){
               int a=s.top();
               s.pop();
               int r=(!s.empty()?s.top():-1);
               int temp=(i-r-1)*heights[a];
               ans=max(ans,temp);
            }
            s.push(i);
        }
        return ans;
    }
};