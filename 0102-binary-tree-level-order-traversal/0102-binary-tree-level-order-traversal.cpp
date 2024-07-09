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
    unordered_map<int,vector<int>> mp;

    void explore(TreeNode* root ,int lv=0){
        if(root==nullptr){
            return ;
        }
        mp[lv].push_back(root->val);
        explore(root->left,lv+1);
        explore(root->right,lv+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        explore(root);
        vector<vector<int>> res(mp.size()); 
        for(auto a : mp){
            for(auto aa : a.second){
                res[a.first].push_back(aa);
            }
        }
        return res; 
    }
};