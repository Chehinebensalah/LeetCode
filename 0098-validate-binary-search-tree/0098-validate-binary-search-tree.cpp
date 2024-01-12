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
    
    bool search(TreeNode* r,long min , long max){
      if(r==nullptr) 
          return true;
      
      if(r->val >= max || r->val <= min)
            return false;
      
       return search(r->right,r->val,max) && search(r->left,min,r->val); 
       
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;

        return search(root,LONG_MIN,LONG_MAX);
    }
};