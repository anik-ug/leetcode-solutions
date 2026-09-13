/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;

        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxWidth=0;
        while(!q.empty()){
            int n = q.size();

            long long start = q.front().second;

            for(int i=0;i<n;i++){
                auto [curr,idx] = q.front();
                q.pop();

                idx -= start;

                if(i == n-1)
                    maxWidth = max(maxWidth,idx+1);
                
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right)
                    q.push({curr->right,2*idx+2});
            }            
        }
        return maxWidth;
    }
};