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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* new_n = new ListNode(); new_n->val =0;
        new_n->next = head;
        map< int ,ListNode*> m ; 
        int sum =0; 
        for(ListNode* node = new_n ; node!=nullptr ; node = node->next){
            sum+=node->val; 
            m[sum] = node ; 
        }
        sum =0;
        for(ListNode* node = new_n ;node!=nullptr ;node =node->next){
            sum+=node->val; 
            node->next = m[sum]->next;
        }
        return new_n->next; 
    }
};