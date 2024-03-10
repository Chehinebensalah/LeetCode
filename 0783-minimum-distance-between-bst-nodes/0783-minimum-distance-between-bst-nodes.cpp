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
    priority_queue<int,vector<int>, greater<int>> pq;
    void search(TreeNode* r){
        if(r==nullptr) return ; 
        pq.push(r->val);
        if(r->right!=nullptr) search(r->right) ;
        if(r->left!=nullptr) search(r->left) ;
    }
    int minDiffInBST(TreeNode* r) {
        search(r);
        int MIN =1e7, m1 =pq.top();
        pq.pop();
        while(!pq.empty()){
            MIN = min(MIN,pq.top()-m1);
            m1 = pq.top();
            pq.pop();
        }
        return MIN;
    }
};