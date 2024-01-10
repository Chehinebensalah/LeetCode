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
   
    vector<vector<int>> g;

    bool vis[100009];
    int distance[100009];
    
    int bfs(int pos){
        int d=-1;
        distance[pos]=0;
        vis[pos]=true; 
        queue<int> q; 
        q.push(pos);
        while(!q.empty()){
            
            int parent = q.front();
            q.pop();
            for(auto child : g[parent]){
                if(!vis[child]){
                    vis[child]=true;
                    distance[child]=distance[parent]+1;
                    d=max(d,distance[child]);
                    q.push(child);
                }
            }
        }
        return d;
    }
    
    void childandparent(TreeNode * r,int p){
        if(r==nullptr){
            return;
        }
        g[p].push_back(r->val);
        g[r->val].push_back(p);
        
        if(r->left!=nullptr){
            childandparent(r->left,r->val);
        }
         if(r->right!=nullptr){
            childandparent(r->right,r->val);
        }
    }
    
    int amountOfTime(TreeNode* r, int start) {
        g.resize(100009);
        if(r->right!=nullptr){
            childandparent(r->right,r->val);    
        }
        
        if(r->left!=nullptr){
            childandparent(r->left,r->val);    
        }
        memset(vis,false,sizeof(vis));
        int res = bfs(start);
        if(res==-1){
            return 0;
        }
        return res;
    }
};