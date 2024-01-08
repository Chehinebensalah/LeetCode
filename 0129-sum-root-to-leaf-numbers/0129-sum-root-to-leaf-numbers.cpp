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
    int c =0;
    void getnumbers(TreeNode* root,vector<string>& s,string curr){
        if(root->left == nullptr && root->right == nullptr){
            curr+=to_string(root->val);
            s.push_back(curr);
            return;
        }
        string next = curr + to_string(root->val);
        if(root->left!=nullptr){
            getnumbers(root->left,s,next);
        }
        if(root->right!=nullptr){
            getnumbers(root->right,s,next);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        vector<string> s; 
        getnumbers(root,s,"");
        int n = s.size(),sum=0;
        if(n==0){
            return 0;
        }
        for(int i=0;i<s.size();i++){
            sum+=stoi(s[i]);
        }
        return sum;
    }
};