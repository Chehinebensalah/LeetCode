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
    map<int,vector<int>> c ; 
    int m=-1;
    
    void explore(TreeNode* r,int depth){
        if(r->right==nullptr && r->left==nullptr){
            m=max(m,depth);
            c[depth].push_back(r->val);
            return;
        }
        if(r->right!=nullptr){
            explore(r->right,depth+1);
        }
        if(r->left!=nullptr){
            explore(r->left,depth+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);
        explore(root,0);
        int res=0;
        for(int i=0;i<c[m].size();i++){
            res+=c[m][i];
        }
        return res;
    }
};