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
    TreeNode* helper(vector<int>& preorder,int s,int e){
        if(s>e)return NULL;
        TreeNode* root = new TreeNode(preorder[s]);
        int i=s+1;
        while(i<preorder.size() && preorder[i]<root->val){
            i++;
        }
        root->left = helper(preorder,s+1,i-1);
        root->right = helper(preorder,i,e);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return helper(preorder,0,preorder.size()-1);
    }
};