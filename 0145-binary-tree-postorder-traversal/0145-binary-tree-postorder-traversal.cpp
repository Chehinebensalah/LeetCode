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
    vector<int> v ; 
    void search(TreeNode* root){
        if(root==nullptr) return; 
        v.push_back(root->val); 
        search(root->right); 
        search(root->left); 
    }
    vector<int> postorderTraversal(TreeNode* root) {
        search(root); 
        reverse(v.begin(),v.end()); 
        return v;
    }
};