# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @param x, an integer
    # @return a ListNode
    def partition(self, head, x):
        if not head:
            return head

        l_head = ListNode(None)
        tmp_l_head = l_head
        
        tmp_head = ListNode(Node)
        tmp_head.next = head
        tmp = tmp_head
        while tmp.next:
            if tmp.next.val < x:
                tmp_l_head.next = tmp.next
                tmp.next = tmp.next.next
                tmp_l_head = tmp_l_head.next
            else:
                #tmp.next.val >= x
                tmp = tmp.next
        
        if not l_head.next:
            return head
        else:
            tmp_l_head.next = tmp_head.next
            return l_head.next
        
        
        
            
        
        