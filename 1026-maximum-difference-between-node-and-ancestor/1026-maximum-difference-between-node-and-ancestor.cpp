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
    int mdiff=-1;
    void solve(TreeNode* r , int mx, int mn){
        if(r==nullptr){
            return;
        }
        mx=max(mx,r->val);
        mn=min(mn,r->val);
        mdiff = max(mdiff,mx-mn);
        if(r->right!=nullptr){
            solve(r->right,mx,mn);
        }
        if(r->left!=nullptr){
            solve(r->left,mx,mn);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,0,100005);
        return mdiff;
    }
};