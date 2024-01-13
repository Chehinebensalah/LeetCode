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
    int c=0;
    void solve(TreeNode* r){
        c++;
        if(r==nullptr){
            return ; 
        }
        if(r->right!=nullptr){
            solve(r->right);
        }
        if(r->left!=nullptr){
            solve(r->left);
        }
    }
    
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        solve(root);
        return c;
    }
};