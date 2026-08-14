// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int>path;
//         sort(candidates.begin(),candidates.end());
//         backtrack(candidates,target,0,path,result);
//         return result;
//     }
// private:
//     void backtrack(vector<int>& candidates, int target,int index,vector<int>&path,vector<vector<int>>& result){
//         if(target==0){
//             result.push_back(path);
//             return;
//         }
//         if(index>=candidates.size() || target<0)
//             return;
        
//         for(int i=index;i<candidates.size();i++){
//             if(i > index && candidates[i] == candidates[i - 1])
//                 continue;

//             if(index>=candidates.size() || candidates[i]>target)
//                 break;

//             path.push_back(candidates[i]);
//             backtrack(candidates,target-candidates[i],i,path,result);
//             path.pop_back();

//         }
//     }
// };
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, path, result);

        return result;
    }

private:
    void backtrack(vector<int>& candidates,
                   int target,
                   int index,
                   vector<int>& path,
                   vector<vector<int>>& result) {

        if(target == 0) {
            result.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            // Skip duplicates at same recursion level
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, no point going further
            if(candidates[i] > target)
                break;

            path.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      path,
                      result);

            path.pop_back();
        }
    }
};