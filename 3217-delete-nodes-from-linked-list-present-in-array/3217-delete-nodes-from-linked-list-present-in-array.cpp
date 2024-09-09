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
    vector<int> v;
    ListNode* NewNode() {
        if (v.empty())
            return nullptr;
        ListNode* head = new ListNode(v[0]);
        ListNode* curr = head;
        for (int i = 1; i < v.size(); ++i) {
            curr->next = new ListNode(v[i]);
            curr = curr->next;
        }
        return head;
    }
    void explore(ListNode* head, unordered_map<int, int> m) {
        while (head != nullptr) {
            if (m.find(head->val) == m.end()) {
                v.push_back(head->val);
            }
            head = head->next;
        }
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            m[nums[i]]++;
        explore(head, m);
        return NewNode();
    }
};