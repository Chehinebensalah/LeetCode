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
    void search(TreeNode * r){
        if(r==nullptr){
            return;
        }
        v.push_back(r->val);
        if(r->right!=nullptr) search(r->right); 
        if(r->left!=nullptr) search(r->left);
    } 
    TreeNode* increasingBST(TreeNode* r) {
        search(r);
        sort(v.begin(),v.end());
        int n = v.size(); 
        if(n==0) return new TreeNode();

        TreeNode* nr = new TreeNode(v[0]);
        TreeNode* res = nr;
        int i = 1;
        while(i<n){
            nr->right = new TreeNode(v[i]);
            nr = nr->right; 
            i++;
        }
        return res; 
    }
};