class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fut = NULL;

        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = fut;
            fut = curr->next;
       }

        return prev;
    }
};