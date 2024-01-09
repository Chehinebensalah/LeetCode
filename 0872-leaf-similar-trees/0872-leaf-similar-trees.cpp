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
    vector<int> s,s1;
    void getleaf(TreeNode * root,vector<int>& s){
        if(root->right==nullptr && root->left==nullptr){
            s.push_back(root->val);
            return ; 
        }
        if(root->right!=nullptr){
            getleaf(root->right,s);
        }
        if(root->left!=nullptr){
            getleaf(root->left,s);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);
        getleaf(root1,s);
        getleaf(root2,s1);
        if(s.size()!=s1.size()){
            return false;
        }
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=s1[i]){
                return false;
            }
        }
        return true;
    }
};