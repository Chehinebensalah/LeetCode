/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int depth = -1;
    vector<vector<int>> v; 
    void getmaxdepth(Node* root,int h =0){
        if(root==nullptr) return ;
        depth = max(depth,h);
        for(auto child: root->children){
            getmaxdepth(child,h+1);
        }
    }
    void search(Node* root , int l = 0){
        if(root==nullptr) return ;
        v[l].push_back(root->val);
        for(auto child : root->children){
            search(child,l+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        getmaxdepth(root); 
        cout<<depth;
        v.resize(depth+1);
        search(root); 
        return v;
    }
};