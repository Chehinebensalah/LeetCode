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
    vector<long long int> v;
    int depth = -1;
    void getmaxdepth(TreeNode* root, int l = 0) {
        if (root == nullptr)
            return;
        depth = max(depth, l);
        getmaxdepth(root->right, l + 1);
        getmaxdepth(root->left, l + 1);
    }
    void search(TreeNode* root, int l = 0) {
        if (root == nullptr)
            return;
        v[l] += root->val;
        search(root->right, l + 1);
        search(root->left, l + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        getmaxdepth(root);
        v.resize(depth+1, 0);
        search(root);
        if (k > v.size()) {
            return -1;
        }
        sort(v.begin(), v.end());
        
        return v[v.size()-k];
    }
};