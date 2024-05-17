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
    int nbnode =0,c=0;
    void deleteTarget(TreeNode* &root, int target){
        if(root == nullptr) return;
        nbnode++;
        deleteTarget(root->right,target);
        deleteTarget(root->left,target);
        if(root->val ==target && root->right==nullptr && root->left==nullptr){
            c++;
            root = nullptr;
            return;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* &root, int target) {
        TreeNode* res = root ; 
        deleteTarget(root,target);
        if(nbnode ==c ) return nullptr;
        return res;
    }
};