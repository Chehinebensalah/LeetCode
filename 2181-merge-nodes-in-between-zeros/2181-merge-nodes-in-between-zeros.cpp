/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> values;
    void explore(ListNode* head){
        while(head!=nullptr){
            values.push_back(head->val);
            head=head->next;
        }
    }
    ListNode* mergeNodes(ListNode* head) {
        explore(head);
        int n = values.size();
        queue<int> q;
        for(int i=1;i<n;i++){
            values[i]+=values[i-1];
            if(values[i-1]==values[i]){
                q.push(values[i]);
                values[i]=0;
            }
            
        } 
        ListNode* ans = new ListNode ;
        ListNode* fans = ans;
        while(!q.empty()){
            ans->val = q.front();
            cout<<ans->val<<" ";
            q.pop();
            if(!q.empty()){
                ans->next = new ListNode;
                ans = ans->next;
            }
        }
        return fans;
    }
};