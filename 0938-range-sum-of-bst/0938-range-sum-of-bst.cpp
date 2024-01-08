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
    vector<int> s; 
    void search(TreeNode * r){
        if(r!=nullptr ){
            s.push_back(r->val);
        }
        if(r->left!=nullptr){
            search(r->left);
        }
        if(r->right!=nullptr){
            search(r->right);
            
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        s.clear();
        search(root);
        int res =0;
        if(!s.empty()){
            for(int i=0;i<s.size();i++){
                if(s[i]>=low && s[i]<=high) res+=s[i];
            }
        }
        return res;
    }
};