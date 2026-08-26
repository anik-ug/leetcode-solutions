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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        deque<TreeNode*>q;
        q.push_front(root);
        while(q.size()){
            int n = q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop_front();
                v.push_back(top->val);
                if(top->left)q.push_back(top->left);
                if(top->right)q.push_back(top->right);
            }
            ans.push_back(v);
            n = q.size();
            if(n==0)return ans;
            vector<int>v1;
            for(int i=0;i<n;i++){
                TreeNode* top = q.back();
                q.pop_back();
                v1.push_back(top->val);
                
                if(top->right)q.push_front(top->right);
                if(top->left)q.push_front(top->left);
            }
            ans.push_back(v1);
        }
        return ans;
    }
};