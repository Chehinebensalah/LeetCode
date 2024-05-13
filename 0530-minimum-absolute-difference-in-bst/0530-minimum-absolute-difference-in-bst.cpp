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
    vector<int> v;
    void traverseAndFill(TreeNode* r){
        if(r==nullptr) return; 
        
        v.push_back(r->val);
        traverseAndFill(r->right);
        traverseAndFill(r->left);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        traverseAndFill(root);
        if(v.size()==1){ 
            return v[0];
        }
        sort(v.begin(),v.end());
        int res=1e8,n=v.size();
        for(int i=1;i<n;i++){
            res = min(res, v[i]-v[i-1]);
        }
        return res;
    }
};