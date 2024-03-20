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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=0;
        ListNode* ans = list1 ;
        ListNode* ans1 =list1 ;
        ListNode* ans2=list1;
        while(list1->next!=nullptr){
            i++;
            if(i==a){
                ans1=list1;
            }
            if(i==b+1){
                ans2 = list1;
            }
            list1=list1->next;
        }
        ans1->next=list2;
        while(list2!=nullptr){
            if(list2->next==nullptr){
                list2->next = ans2->next;
                break;
            }
            list2=list2->next;
        }
        return ans;
    }
};