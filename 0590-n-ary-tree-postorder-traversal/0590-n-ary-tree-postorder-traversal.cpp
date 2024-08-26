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
    vector<int> v; 
    void search(Node* root){
        if(root==nullptr) return ; 
        for(auto child : root->children){
            search(child);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        search(root); 
        return v; 
    }
};