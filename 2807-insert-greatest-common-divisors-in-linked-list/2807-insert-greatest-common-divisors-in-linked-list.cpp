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
    vector<int> v ; 
    vector<int> g; 
    void explore(ListNode* head){
        while(head!=nullptr){
            v.push_back(head->val); 
            head = head->next;
        }
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        explore(head);
        int n = v.size();
        for(int i = 0;i<n-1;i++){
            g.push_back(__gcd(v[i],v[i+1]));
        }
        int j=1;
        for(int i=0;i<g.size();i++){
            v.insert(v.begin()+j+i,g[i]);
            j++;
        }
        ListNode * L = new ListNode(v[0]);
        ListNode * ans  = L;
        for(int i=1;i<v.size();i++){
            L->next = new ListNode(v[i]);
            L = L->next; 
        }
        return ans; 
    }
};


/*
6   2   1
18  6  6  2  10   1  3 
0   1  2  3   4   5  6 
1   3   5 
0   1   2 
1   2   3 
*/