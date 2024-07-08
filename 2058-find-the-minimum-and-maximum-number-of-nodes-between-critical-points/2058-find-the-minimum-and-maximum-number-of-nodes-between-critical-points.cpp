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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> val ; 
        while(head!=nullptr){
            val.push_back(head->val);
            head=head->next;
        }
        int n =val.size();
        vector<int> helper; 
        if(n==2){
            return {-1,-1};
        }
        for(int i=1;i<n-1;i++){
            if((val[i]<val[i+1] && val[i]<val[i-1])||(val[i]>val[i+1] && val[i]>val[i-1])){
                helper.push_back(i);
            }
        }
        if(helper.size()<=1){
            return {-1,-1};
        }
        int mn = 1e7;
       
        for(int i=0;i<helper.size()-1;i++){
            mn = min(mn,helper[i+1]-helper[i]);
        }
        return {mn,helper[helper.size()-1]-helper[0]};

    }
};