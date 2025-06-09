/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void explore(TreeNode* root, string prefix) {
        if (root == nullptr) {
            return;
        }
        prefix += to_string(root->val);
        
        if (root->right == nullptr && root->left == nullptr) {
            sum += bitset<32>(prefix).to_ulong();
        }
       
        explore(root->right, prefix);
        explore(root->left, prefix);
    }
    int sumRootToLeaf(TreeNode* root) {
        explore(root, "");
        return sum;
    }
};