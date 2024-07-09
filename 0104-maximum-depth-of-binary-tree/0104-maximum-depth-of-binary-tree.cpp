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
    int mxh=-1;
    void calculateDepth(TreeNode* root,int h=0){
        if(root==nullptr){
            return ;
        }
        mxh=max(mxh,h+1);
        calculateDepth(root->left,h+1);
        calculateDepth(root->right,h+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        calculateDepth(root);
        return mxh;
    }
};