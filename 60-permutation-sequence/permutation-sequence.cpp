class Solution {
public:
    void permutation(vector<int>& v,int n,int k,vector<int>& fact,string& ans){
        if(n==1){
            ans+=to_string(v.back());
            return;
        }

        int index = (k/fact[n-1]);

        if(k % fact[n-1] == 0)
            index--;

        ans+=to_string(v[index]);
        v.erase(v.begin()+index);
        k-=fact[n-1]*index;

        permutation(v,n-1,k,fact,ans);
    }
    string getPermutation(int n, int k) {
        vector<int> fact = {1,1,2,6,24,120,720,5040,40320,362880};
        string ans;
        vector<int>v;
        for(int i=1;i<=n;i++) v.emplace_back(i);
        permutation(v,n,k,fact,ans);
        return ans;
    }
};