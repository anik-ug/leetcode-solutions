class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > v;
        for(int j=0;j<numRows;j++){
            vector<int> a(j+1);
            v.push_back(a);
            for(int k=0;k<=j;k++){
                if(k==0||k==j)  
                    v[j][k]=1;
                else
                    v[j][k]=v[j-1][k]+v[j-1][k-1];

            }
        }
        return v;
    }
};