/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode * , int> vis ;
        int pos = 0 ; 
        while(head != nullptr ){
            if(vis.find(head) != vis.end()) {
                return head;
            }else{
                vis[head] = pos;
            }
            pos++;
            head = head->next;
        }
        return nullptr;
    }
};