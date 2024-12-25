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
    int get_depth(TreeNode* root, int n = 0) {
        if (root == nullptr)
            return n;
        return max(get_depth(root->right, n + 1), get_depth(root->left, n + 1));
    }
    void extract(vector<int>& values, TreeNode* root, int level) {
        if (root == nullptr)
            return;
        cout<<values[level]<<" "<<root->val;
        values[level] = max(values[level], root->val);
        extract(values, root->right, level + 1);
        extract(values, root->left, level + 1);
    }
    vector<int> largestValues(TreeNode* root) {
       
        int x = get_depth(root);    // Declar e x before using it
        vector<int> values(x, INT_MIN);
        extract(values, root, 0);
        return values;
    }
};