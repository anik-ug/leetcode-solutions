class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,path,result);
        return result;
    }
private:
    void backtrack(vector<int>& candidates, int target,int index,vector<int> &path,vector<vector<int>> &result){
        if(target==0){
            result.push_back(path);
            return;
        }
        if(target<0 || index>=candidates.size()){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i,path,result);
            path.pop_back();
        }
    }
};