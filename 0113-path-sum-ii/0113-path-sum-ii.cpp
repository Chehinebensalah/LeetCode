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
    vector<vector<int>> s;
    
    void dfs( TreeNode * r ,int ts,vector<int> v){

        if(r->right==nullptr && r->left==nullptr){
            if(ts-r->val==0){
                v.push_back(r->val);
                s.push_back(v);
                return;
            }
        }
            v.push_back(r->val);
            if(r->right!=nullptr){
                dfs(r->right,ts-r->val,v);
            }
            if(r->left!=nullptr){
                dfs(r->left,ts-r->val,v);
            }
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if( root==nullptr){
            return {};
        }
        vector<int> v;
        dfs(root,targetSum,v);
        return s;
    }
};