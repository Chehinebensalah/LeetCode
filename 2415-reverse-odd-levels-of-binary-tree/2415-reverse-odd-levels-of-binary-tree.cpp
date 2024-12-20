class Solution {
public:
    void reverse(TreeNode* left, TreeNode* right, int level) {
        if (left == nullptr || right == nullptr)
            return;
        if (level % 2 == 0) {
            int x = right->val;
            right->val = left->val;
            left->val = x;
        }
        reverse(right->left,left->right,level+1);
        reverse(right->right,left->left,level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 0);
        return root;
    }
};
