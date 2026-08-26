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
    unordered_map<int,int> map;
    int index = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            map[inorder[i]] = i;

        index = postorder.size()-1;
        return solve(postorder,0,postorder.size()-1);
    }

    TreeNode* solve(vector<int>& postorder,int start,int end){
        if(start>end)return nullptr;
        int rootVal = postorder[index--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];
        root->right =solve(postorder,mid+1,end);
        root->left = solve(postorder,start,mid-1);
        
        return root;
    }
};